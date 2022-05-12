#include <stdio.h>
#include <stdlib.h>
#include "poker.h"



void drawCards(int allCards[], int playerCards[])
{

	int i, numDrawed;

    for ( i = 0, numDrawed = 0; i < CARD_ALL_NUM; i ++ )
    {
        numDrawed += allCards[i];
    }
    if ( CARD_ALL_NUM - numDrawed < PLAYER_CARD_NUM )
    {
        // Not enough cards to draw
        printf("Error!\n\n");
        exit(1);
    }
    
    int face, suit, cardId;
    for ( i = 0; i < PLAYER_CARD_NUM; i ++ )
    {
        do
        {
            face = rand() % CARD_FACE_RANGE + 1;
            suit = rand() % CARD_SUIT_RANGE + 1;
            cardId = (face - 1) * CARD_SUIT_RANGE + (suit -1 );
        } while ( allCards[cardId] == 1 );
        
        playerCards[i] = cardId;
        allCards[cardId] = 1;
    }
    
    return;
}


void sortCards( int cards[] )
{
    for (int i=0;i<PLAYER_CARD_NUM;i++)
    	if (getCardFaceByID(cards[i])==1||getCardFaceByID(cards[i])==2) cards[i]+=52;
	for (int i=1;i<PLAYER_CARD_NUM;i++)
        for (int j=0;j<PLAYER_CARD_NUM-1;j++){
            if (cards[j]>cards[j+1]){
                int temp=cards[j];
                cards[j]=cards[j+1];
                cards[j+1]=temp;
            }
        }
    for (int i=0;i<PLAYER_CARD_NUM;i++)
    	if (getCardFaceByID(cards[i])==14||getCardFaceByID(cards[i])==15) cards[i]-=52;
}


int countCards( int cardId[], int faceStat[][3] )
{
    int tot_dif=0;
    int faceArr[CARD_FACE_RANGE]={0};
    for (int i=0;i<PLAYER_CARD_NUM;i++){
        int face=getCardFaceByID(cardId[i])-1;
        faceArr[face]++;
    }
    for (int i=2;i<CARD_FACE_RANGE;i++){
        if (faceArr[i]>0){
            faceStat[tot_dif][0]=i+1;
            faceStat[tot_dif][2]=faceArr[i];
            tot_dif++;
        }
    }
	for (int i=0;i<2;i++){
        if (faceArr[i]>0){
            faceStat[tot_dif][0]=i+1;
            faceStat[tot_dif][2]=faceArr[i];
            tot_dif++;
        }
    }
    for (int i=1;i<tot_dif;i++)
        faceStat[i][1]=faceStat[i-1][1]+faceStat[i-1][2];
    for (int i=tot_dif;i<CARD_FACE_RANGE;i++){
        faceStat[i][0]=-1;
        faceStat[i][1]=0;
        faceStat[i][2]=0;
    }
    return tot_dif;
}


void cloneCards(int cardsSrc[], int cardsDst[])
{
    int i;

    for ( i = 0; i < PLAYER_CARD_NUM; i ++ )
    {
        cardsDst[i] = cardsSrc[i];
    }

    return;
}



