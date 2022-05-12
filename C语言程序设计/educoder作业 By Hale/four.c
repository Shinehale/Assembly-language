/*
 * File name:  poker1.c
 * Author:     Wei Liu, liuwei@hust.edu.cn
 * Date:       2019-9-1
 * Description:  Poker Game version 4: find series for one player by pointer
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************
// Constants used for this program
// **************************************
//
// Constant for the cards
#define CARD_ALL_NUM      52    
#define CARD_FACE_RANGE   13
#define CARD_SUIT_RANGE   4
//
// Constant for the game
#define PLAYER_CARD_NUM   18
//
// Constant for array index in cardFaceStat[CARD_FACE_RANGE][3]
#define FACESTAT_FACE     0
#define FACESTAT_SEQ1     1
#define FACESTAT_COUNT    2
//
// Constant for the array size
#define ARRAY_SEQ_SIZE    13
#define ARRAY_COMB_SIZE   13
//
// Constant for comb setting
#define COMB_TYPE_NUM     4
#define COMB_SERIES_MIN_LENGTH      3
#define COMB_SERIES_MAX_LENGTH      10
//
// Micro function for card calculation
#define getCardFaceByID(x)  ( (x) / CARD_SUIT_RANGE + 1 )
#define getCardSuitByID(x)  ( (x) % CARD_SUIT_RANGE + 1 )

// **************************************
// Data types used for this program
// **************************************
//
// struct CombinationCards describe a group of cards
typedef struct {
    int typeId;
    int seqArray[ARRAY_SEQ_SIZE];
    int seqNum;
    int maxFace;
} Comb;

enum COMBTYPE { TYPE_NULL = 0, TYPE_SINGLE, TYPE_PAIR, TYPE_TRIPLET, TYPE_SERIES, TYPE_BOMB };

// **************************************
// Functions used for this program
// **************************************
//
// Function to randomly draw cards to player array
void drawCards( int allCards[], int onePlayerCards[] );
void sortCards( int onePlayerCards[] );
int  countCards( int onePlayerCards[], int cardFaceStat[][3] );
void cloneCards( int cardsSrc[], int cardsDst[] );

//
// Function to create combination array, upgrade for different user
int  planCards( int onePlayerCards[], int cardFaceStat[][3], Comb foundComb[] );
//
// Function to find the min value Comb, upgrade for different user
int  getMinGroup ( int onePlayerCards[], int cardFaceStat[][3], Comb *foundComb, int groupSize );
//
// Function to find the min value series, new function for series Comb
int  getMinSeries( int onePlayerCards[], int cardFaceStat[][3], Comb *foundComb, int seriesSize );

//
// Function to display card information
void displayOneCard( int cardId );
void displayOneComb( int playerCards[], Comb oneComb );
void displayPlayerCards( char playerName, int playerCards[] );
void displayPlayerStat( char playerName, int cardFaceStat[][3] );
void displayPlayerPlan( char playerName, int playerCards[], Comb foundComb[], int foundCombNum );

//
// Constants to display card information
const char faceStr[][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const char suitStr[][2] = {"1","2","3","4"};

int main()
{
    printf("\nPoker Game version 4: find series for one player by pointer\n");

    // Declare allCards[] and those arrays for player A
    int allCards[CARD_ALL_NUM] = {0};
    int cardA[PLAYER_CARD_NUM] = {0};
    int cardFaceStatA[CARD_FACE_RANGE][3] = {{0}};

    // Draw the cards to one player
    int SEED;
    scanf("%d",&SEED);
    srand(SEED);
    
    drawCards( allCards, cardA );
    sortCards( cardA );
    printf("\nDraw results:\n");
    displayPlayerCards( 'A', cardA );
    countCards( cardA, cardFaceStatA );
    printf("\nCount results:\n");
    displayPlayerStat( 'A', cardFaceStatA );
    
    // Declare a temp array for planning
    int planA[PLAYER_CARD_NUM] = {0};
    cloneCards( cardA, planA );
    // Find the combinations
    Comb combArrayA[ARRAY_COMB_SIZE];
    int foundCombNum =  planCards( planA, cardFaceStatA, combArrayA );
    printf("\nPlan results:\n");
    displayPlayerPlan( 'A', cardA, combArrayA, foundCombNum );
    printf("  Total %d combinations are found in Player_%c.\n\n", foundCombNum, 'A' );

    return 0;
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

void displayPlayerCards( char playerName, int cards[] )
{
    printf("  Player_%c: %2s", playerName, "[");

    int i;
    for ( i = 0; i < PLAYER_CARD_NUM - 1; i ++ )
    {
        displayOneCard( cards[i] );
        printf(",");
    }
    displayOneCard( cards[i] );
    printf("]\n");

    return;
}


void displayPlayerStat( char playerName, int faceStat[][3] )
{

    printf("  Player_%c:  cardFaceStat\n", playerName );
    int i;

    printf("%10s:  [", "face");
    for ( i = 0; i < CARD_FACE_RANGE - 1; i ++ )
    {
        if ( faceStat[i][FACESTAT_FACE] < 0 )
        {
            printf(" -,");
        }
        else
        {
            printf("%2s,", faceStr[ faceStat[i][FACESTAT_FACE] - 1 ] );
        }
    }
    if ( faceStat[i][FACESTAT_FACE] < 0 )
    {
        printf(" - ");
    }
    else
    {
        printf("%2s ", faceStr[ faceStat[i][FACESTAT_FACE] - 1 ] );
    }
    printf("]\n");

    printf("%10s:  [", "seq1");
    for ( i = 0; i < CARD_FACE_RANGE - 1; i ++ )
    {
        printf("%2d,", faceStat[i][FACESTAT_SEQ1] );
    }
    printf("%2d ]\n", faceStat[i][FACESTAT_SEQ1] );

    printf("%10s:  [", "count");
    for ( i = 0; i < CARD_FACE_RANGE - 1; i ++ )
    {
        printf("%2d,", faceStat[i][FACESTAT_COUNT] );
    }
    printf("%2d ]\n", faceStat[i][FACESTAT_COUNT] );
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


void displayPlayerPlan( char playerName, int playerCards[], Comb combArray[], int combNum )
{
    printf("  Player_%c:  {", playerName );

    int i;
    for ( i = 0; i < combNum - 1; i ++ )
    {
        displayOneComb( playerCards, combArray[i]);
        printf(",");
    }
    displayOneComb( playerCards, combArray[i]);
    printf("}\n");

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


// **********************************************
// << Your source code starts here >>
//

int planCards( int cards[], int cardFaceStat[][3], Comb combArray[] )
{
    int tot=0;
    int ope[CARD_FACE_RANGE][3];
    for (int i=0;i<CARD_FACE_RANGE;i++) ope[i][0]=cardFaceStat[i][0];
    for (int i=0;i<CARD_FACE_RANGE;i++) ope[i][1]=cardFaceStat[i][1];
    for (int i=0;i<CARD_FACE_RANGE;i++) ope[i][2]=cardFaceStat[i][2];
    Comb new_;
    while (getMinGroup(cards,ope,&new_,4)){
        combArray[tot]=new_;
        tot++;
    }
    for (int i=10;i>=3;i--){
        while (getMinSeries(cards,ope,&new_,i)){
            combArray[tot]=new_;
            tot++;
        }
    }
    while (getMinGroup(cards,ope,&new_,3)){
        combArray[tot]=new_;
        tot++;
    }
    while (getMinGroup(cards,ope,&new_,2)){
        combArray[tot]=new_;
        tot++;
    }
    while (getMinGroup(cards,ope,&new_,1)){
        combArray[tot]=new_;
        tot++;
    }
    return tot;
}


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
            foundComb->maxFace=i+1;
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
            foundComb->maxFace=i+seriesSize+1;
            break;
        }
   }
   if (flag) return 1;
   else return 0;
}


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
    for (int i=1;i<PLAYER_CARD_NUM;i++)
        for (int j=0;j<PLAYER_CARD_NUM-1;j++){
            if (cards[j]>cards[j+1]){
                int temp=cards[j];
                cards[j]=cards[j+1];
                cards[j+1]=temp;
            }
        }
}


int countCards( int cardId[], int faceStat[][3] )
{
    int tot_dif=0;
    int faceArr[CARD_FACE_RANGE]={0};
    for (int i=0;i<PLAYER_CARD_NUM;i++){
        int face=getCardFaceByID(cardId[i])-1;
        faceArr[face]++;
    }
    for (int i=0;i<CARD_FACE_RANGE;i++){
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