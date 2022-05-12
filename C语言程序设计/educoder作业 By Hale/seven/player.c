#include <stdio.h>
#include <stdlib.h>
#include "poker.h"

const char faceStr[][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const char suitStr[][2] = {"1","2","3","4"};


// Initiallize one player
void initializePlayer(Player* ptrPlayer, char playerName)
{
    ptrPlayer->playerName = playerName ;
    ptrPlayer->cardNum = PLAYER_CARD_NUM;
    ptrPlayer->combNum = 0;
    ptrPlayer->faceNum = 0;

    int i;
    for ( i = 0; i < PLAYER_CARD_NUM; i ++ )
    {
        ptrPlayer->cardIdPlay[i] = -1;
        ptrPlayer->cardIdPlan[i] = -1;
    }
    for ( i = 0; i < CARD_FACE_RANGE; i ++ )
    {
        ptrPlayer->cardFaceStat[i][FACESTAT_FACE] = -1;
        ptrPlayer->cardFaceStat[i][FACESTAT_COUNT]= 0;
        ptrPlayer->cardFaceStat[i][FACESTAT_SEQ1] = 0;
    }

    int j;
    Comb *ptrComb = NULL;
    int  *ptrSeq = NULL;
    for ( i = 0, ptrComb = ptrPlayer->combArray; i < ARRAY_COMB_SIZE; i ++, ptrComb ++ )
    {
        ptrComb->typeId = TYPE_NULL;
        ptrComb->seqNum = 0;
        ptrComb->maxFace = -1;

        for ( j = 0, ptrSeq = ptrComb->seqArray; j < ARRAY_SEQ_SIZE; j ++, ptrSeq ++ )
        {
            *ptrSeq = -1;
        }
    }
}


void displayOneCard( int cardId )
{
    if ( cardId < 0 )
    {
        printf("%4s", " ---");   // nagetive ID indicates the state of played card
        return;
    }

    int face = getCardFaceByID(cardId);
    int suit = getCardSuitByID(cardId);
    printf("%2s.%1s", faceStr[ face - 1 ], suitStr[ suit - 1 ] );

    return;
}


void planCombs( Player* ptrPlayer )
{
   	int tot=0;
    int ope[CARD_FACE_RANGE][3];
    for (int i=0;i<CARD_FACE_RANGE;i++) ope[i][0]=ptrPlayer->cardFaceStat[i][0];
    for (int i=0;i<CARD_FACE_RANGE;i++) ope[i][1]=ptrPlayer->cardFaceStat[i][1];
    for (int i=0;i<CARD_FACE_RANGE;i++) ope[i][2]=ptrPlayer->cardFaceStat[i][2];
    for (int i=0;i<ARRAY_COMB_SIZE;i++) ptrPlayer->used[i]=0;//对排列进行重置

    Comb new_;
    while (getMinGroup(ptrPlayer->cardIdPlay,ope,&new_,4)){
        ptrPlayer->combArray[tot]=new_;
        tot++;
    }
    for (int i=10;i>=3;i--){
        while (getMinSeries(ptrPlayer->cardIdPlay,ope,&new_,i)){
            ptrPlayer->combArray[tot]=new_;
            tot++;
        }
    }
    while (getMinGroup(ptrPlayer->cardIdPlay,ope,&new_,3)){
        ptrPlayer->combArray[tot]=new_;
        tot++;
    }
    while (getMinGroup(ptrPlayer->cardIdPlay,ope,&new_,2)){
        ptrPlayer->combArray[tot]=new_;
        tot++;
    }
    while (getMinGroup(ptrPlayer->cardIdPlay,ope,&new_,1)){
        ptrPlayer->combArray[tot]=new_;
        tot++;
    }
    ptrPlayer->combNum=tot;
}



int  getNextComb( Player* ptrPlayer )
{
   for (int i=0;i<ptrPlayer->combNum;i++)
        if (ptrPlayer->used[i]==0){
            return i;
        }
    return -1;
}


int  getBiggerComb(Player* ptrPlayer, Comb* ptrTargetComb, int *needUpdate)
{
    for (int i=0;i<ptrPlayer->combNum;i++)
        if (ptrPlayer->used[i]==0&&ptrPlayer->combArray[i].typeId==ptrTargetComb->typeId){
            if (ptrPlayer->combArray[i].seqNum==ptrTargetComb->seqNum){
                if (ptrPlayer->combArray[i].maxFace>ptrTargetComb->maxFace){
                    return i;
                }
            }
            if (ptrPlayer->combArray[i].typeId==5){
                if (ptrPlayer->combArray[i].seqNum>ptrTargetComb->seqNum&&ptrPlayer->combArray[i].maxFace>ptrTargetComb->maxFace){
                    int new_que[ARRAY_SEQ_SIZE]={0};
                    Comb new_;
                    int pos=0,length=ptrTargetComb->seqNum,check=0;
                    for (int j=0;j<ptrPlayer->combArray[i].seqNum;j++)
                        if ( ptrTargetComb->maxFace-ptrTargetComb->seqNum+2==getCardFaceByID(ptrPlayer->cardIdPlay[ptrPlayer->combArray[i].seqArray[j]]))
                            check=j;
                    if (check) pos=check;
                    for (int j=0;j<length;j++)
                        new_que[j]=ptrPlayer->combArray[i].seqArray[pos+j];
                    new_.seqNum=length;
                    for (int j=0;j<length;j++)
                        new_.seqArray[j]=new_que[j];
                    new_.maxFace=getCardFaceByID(ptrPlayer->cardIdPlay[new_que[length-1]]);
                    new_.typeId=5;
                    ptrPlayer->combArray[i]=new_;
                    *needUpdate=1;
                    return i;
                }
            }
        }
    return -1;
}


void playOneComb(Player* ptrPlayer, int combSeq )
{
    displayPlayerPlay(ptrPlayer,combSeq);
    if (combSeq!=-1){
        int num=ptrPlayer->combArray[combSeq].seqNum;
        ptrPlayer->used[combSeq]=1;
        ptrPlayer->cardNum-=num;
        for (int i=0;i<num;i++){
            for (int j=0;j<CARD_FACE_RANGE;j++)
                if (ptrPlayer->cardFaceStat[j][0]==getCardFaceByID(ptrPlayer->cardIdPlay[ptrPlayer->combArray[combSeq].seqArray[i]]) ){
                    ptrPlayer->cardFaceStat[j][2]--;
                }
        }
    }
}




void updatePlayer( Player* ptrPlayer )
{
    planCombs(ptrPlayer);
    displayPlayerPlan(ptrPlayer);
}


void displayPlayerCards( Player* ptrPlayer )
{
    printf("  Player_%c: %2s", ptrPlayer->playerName, "[");

    int i;
    for ( i = 0; i < PLAYER_CARD_NUM - 1; i ++ )
    {
        displayOneCard( ptrPlayer->cardIdPlay[i] );
        printf(",");
    }
    displayOneCard( ptrPlayer->cardIdPlay[i] );
    printf(" ]\n");

    return;
}


void displayPlayerStat( Player* ptrPlayer )
{

    printf("  Player_%c:  cardFaceStat\n", ptrPlayer->playerName );
    int i;

    printf("%10s:  [", "face");
    for ( i = 0; i < CARD_FACE_RANGE - 1; i ++ )
    {
        if ( ptrPlayer->cardFaceStat[i][FACESTAT_FACE] < 0 )
        {
            printf(" -,");
        }
        else
        {
            printf("%2s,", faceStr[ ptrPlayer->cardFaceStat[i][FACESTAT_FACE] - 1 ] );
        }
    }
    if ( ptrPlayer->cardFaceStat[i][FACESTAT_FACE] < 0 )
    {
        printf(" - ");
    }
    else
    {
        printf("%2s ", faceStr[ ptrPlayer->cardFaceStat[i][FACESTAT_FACE] - 1 ] );
    }
    printf("]\n");

    printf("%10s:  [", "seq1");
    for ( i = 0; i < CARD_FACE_RANGE - 1; i ++ )
    {
        printf("%2d,", ptrPlayer->cardFaceStat[i][FACESTAT_SEQ1] );
    }
    printf("%2d ", ptrPlayer->cardFaceStat[i][FACESTAT_SEQ1] );
    printf("]\n");

    printf("%10s:  [", "count");
    for ( i = 0; i < CARD_FACE_RANGE - 1; i ++ )
    {
        printf("%2d,", ptrPlayer->cardFaceStat[i][FACESTAT_COUNT] );
    }
    printf("%2d ", ptrPlayer->cardFaceStat[i][FACESTAT_COUNT] );
    printf("]\n");
}


void displayPlayerPlan( Player* ptrPlayer )
{
    printf("  Player_%c:  {", ptrPlayer->playerName );

    int i;
    for ( i = 0; i < ptrPlayer->combNum - 1; i ++ )
    {
        displayOneComb( ptrPlayer->cardIdPlay, ptrPlayer->combArray[i]);
        printf(",");
    }
    displayOneComb( ptrPlayer->cardIdPlay, ptrPlayer->combArray[i]);
    printf(" }\n");

}


void displayPlayerPlay( Player* ptrPlayer, int combSeq )
{
    if ( combSeq >= 0 )
    {
        printf("  Player_%c: play ", ptrPlayer->playerName );
        displayOneComb( ptrPlayer->cardIdPlay, ptrPlayer->combArray[combSeq] );
        printf("\n");
    }
    else
    {
        printf("  Player_%c: give up\n", ptrPlayer->playerName );
    }
}

