#include <stdio.h>
#include <stdlib.h>
#include "poker.h"

// **********************************************
// << Your source code starts here >>
//

int getMinGroup( int cards[], int cardFaceStat[][3], Comb *foundComb, int groupSize )
{
    int flag=0;
    for (int i=0;i<CARD_FACE_RANGE;i++){
        if (cardFaceStat[i][2]==groupSize){
            flag=1;
            foundComb->typeId=groupSize;
            foundComb->seqNum=groupSize;
            for (int j=0;j<groupSize;j++){
                if (i==12||cardFaceStat[i+1][0]==-1) foundComb->seqArray[j]=cardFaceStat[i][1]+(PLAYER_CARD_NUM-cardFaceStat[i][1]-cardFaceStat[i][2])+j;
                else foundComb->seqArray[j]=cardFaceStat[i][1]+(cardFaceStat[i+1][1]-cardFaceStat[i][1]-cardFaceStat[i][2])+j;
            }
            cardFaceStat[i][2]-=groupSize;
            foundComb->maxFace=cardFaceStat[i][0];
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
        if (check==0){
            flag=1;
            foundComb->typeId=5;
            foundComb->seqNum=seriesSize;
            for (int j=0;j<seriesSize;j++){
                if (i+j==12||cardFaceStat[i+j+1][0]==-1) foundComb->seqArray[j]=cardFaceStat[i+j][1]+(PLAYER_CARD_NUM-cardFaceStat[i+j][1]-cardFaceStat[i+j][2]);
                else foundComb->seqArray[j]=cardFaceStat[i+j][1]+(cardFaceStat[i+j+1][1]-cardFaceStat[i+j][1]-cardFaceStat[i+j][2]);
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

//
// << Your source code stops here >>
// **********************************************

