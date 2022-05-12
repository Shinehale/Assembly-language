#include <stdio.h>
#include <stdlib.h>
#include "poker.h"

int getpriGroup(int cards[],int cardFaceStat[][3],Comb *foundComb,int type){
	int flag=0;
	if (type==8){// this is for 3+3+2+2;for example  333+444+55+66
		for (int i=0;i<CARD_FACE_RANGE-1;i++){
			if (cardFaceStat[i][0]==2||cardFaceStat[i][0]==-1) continue;
			if (cardFaceStat[i+1][0]==2||cardFaceStat[i+1][0]==-1) continue;
			if (cardFaceStat[i+1][0]!=cardFaceStat[i][0]+1&&cardFaceStat[i][0]!=13) continue;
			if (cardFaceStat[i+1][2]!=3||cardFaceStat[i][2]!=3) continue;
			int pos1=-1,pos2=-1;
			for (int j=0;j<CARD_FACE_RANGE;j++){
				if (j==i||j==i+1) continue;
				if (cardFaceStat[j][2]==2) {
					if (pos1!=-1) {
						pos2=j;
						break;
					}
					else pos1=j; 
				}
			}
			if (pos1!=-1&&pos2!=-1) flag=1;
			else continue;
			foundComb->typeId=8;
			foundComb->maxFace=cardFaceStat[i+1][0];
			foundComb->seqNum=10;
			for (int j=0;j<2;j++)
            	foundComb->seqArray[j]=cardFaceStat[pos1][1]+j;
			for (int j=0;j<2;j++)
            	foundComb->seqArray[j+2]=cardFaceStat[pos2][1]+j;
            for (int j=0;j<3;j++)
            	foundComb->seqArray[j+4]=cardFaceStat[i][1]+j;
			for (int j=0;j<3;j++)
				foundComb->seqArray[j+7]=cardFaceStat[i+1][1]+j;
			cardFaceStat[i][2]-=3;
			cardFaceStat[i+1][2]-=3;
			cardFaceStat[pos1][2]-=2;
			cardFaceStat[pos2][2]-=2;
			break;
		}
	}
	if (type==7){//this is for 3+1; for example 444+3
		for (int i=0;i<CARD_FACE_RANGE;i++){
			if (cardFaceStat[i][2]!=3) continue;
			int pos=-1;
			for (int j=0;j<CARD_FACE_RANGE;j++){
				if (i==j) continue;
				if (cardFaceStat[j][2]!=1)  continue;
				pos=j;
				break;
			}
			if (pos==-1) continue;
			flag=1;
			foundComb->maxFace=cardFaceStat[i][0];
			foundComb->seqNum=4;
			foundComb->typeId=7;
			for (int j=0;j<3;j++)
			foundComb->seqArray[j]=cardFaceStat[i][1]+j;
			foundComb->seqArray[3]=cardFaceStat[pos][1];
			cardFaceStat[i][2]-=3;
			cardFaceStat[pos][2]-=1;
			break;
		}
	}
	if (type==6){
		for (int size=8;size>=3;size--){
			int flg=0;
			for (int i=0;i<CARD_FACE_RANGE-size;i++){
				int check=0;
				for (int j=0;j<size-1;j++){
					if (cardFaceStat[i+j][2]!=2) check=1;
					if (cardFaceStat[i+j][0]+1!=cardFaceStat[i+j+1][0]) check=1;
				}
				if (cardFaceStat[i+size-1][2]!=2) check=1;
				if (check==1) continue;
				flag=1;
				printf("%d",i);
				foundComb->maxFace=cardFaceStat[i+size-1][0];
				foundComb->typeId=6;
				foundComb->seqNum=2*size;
				for (int j=0;j<size;j++){
					foundComb->seqArray[2*j]=cardFaceStat[i+j][1];
					foundComb->seqArray[2*j+1]=cardFaceStat[i+j][1]+1;
					cardFaceStat[i+j][2]-=2;
				}
				flg=1;
				break;
			}
			if (flg==1) break;
		}
	}
	if (flag==0) return 0;
	else return 1;
} 

int getMinGroup( int cards[], int cardFaceStat[][3], Comb *foundComb, int groupSize )
{
    int flag=0;
    for (int i=0;i<CARD_FACE_RANGE;i++){
        if (cardFaceStat[i][2]==groupSize){
            flag=1;
            foundComb->typeId=groupSize;
            foundComb->seqNum=groupSize;
            foundComb->maxFace=cardFaceStat[i][0];
            for (int j=groupSize;j>0;j--)
            	foundComb->seqArray[j-1]=cardFaceStat[i][1]+cardFaceStat[i][2]-j;
            cardFaceStat[i][2]-=groupSize;
            break;
        }
   }
   if (flag) return 1;
   else return 0;
}


int getMinSeries( int cards[], int cardFaceStat[][3], Comb *foundComb, int seriesSize )
{
    int flag=0;
   for (int i=0;i<CARD_FACE_RANGE-seriesSize;i++){
        int check=0; 
        for (int j=0;j<seriesSize;j++){
            if (cardFaceStat[i+j][0]!=cardFaceStat[i][0]+j) check=1;
            if (cardFaceStat[i+j][2]==0) check=1;
        }
        for (int j=0;j<seriesSize;j++)
        if (cardFaceStat[i+j][0]==2) check=1;
        if (check==0){
            flag=1;
            foundComb->typeId=5;
            foundComb->seqNum=seriesSize;
            for (int j=0;j<seriesSize;j++){
                foundComb->seqArray[j]=cardFaceStat[i+j][1]+cardFaceStat[i+j][2]-1;
                cardFaceStat[i+j][2]-=1;
            }
            foundComb->maxFace=cardFaceStat[i][0]+seriesSize-1;
            break;
        }
   }
   if (flag) return 1;
   else return 0;
}


void displayOneComb( int cardId[], Comb oneComb )
{
    printf("[");

    int i;
    for ( i = 0; i < oneComb.seqNum - 1; i ++ )
    {
        displayOneCard( cardId[ oneComb.seqArray[i] ] );
        printf(",");
    }
    if( oneComb.seqNum == 0 )
    {
        printf(" ]" );
    } else {
        displayOneCard( cardId[ oneComb.seqArray[i] ] );
        printf("]" );
    }
}

