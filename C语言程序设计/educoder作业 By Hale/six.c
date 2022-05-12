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
// Constant for the game and players
// constraints: PLAYER_CARD_NUM * PLAYER_NUM <= CARD_ALL_NUM
#define PLAYER_NUM        3
#define PLAYER_CARD_NUM   17
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
// Constant for combinations
#define COMB_TYPE_NUM     4
#define COMB_SERIES_MIN_LENGTH      3
#define COMB_SERIES_MAX_LENGTH      10  // should be smaller than PLAYER_CARD_NUM
//
// Constant for display
#define DISPLAY_CARDPLAY     0
#define DISPLAY_FACESTAT     1
#define DISPLAY_COMBLIST     2
//
// Micro function for card calculation
#define getCardFaceByID(x)  ( (x) / CARD_SUIT_RANGE + 1 )
#define getCardSuitByID(x)  ( (x) % CARD_SUIT_RANGE + 1 )
//
// Constants to display card information
const char faceStr[][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const char suitStr[][2] = {"1","2","3","4"};

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

//
// Struct Player describe the cards in a player's hand
typedef struct
{
    char playerName;
    int  cardIdPlay[PLAYER_CARD_NUM];
    int  cardIdPlan[PLAYER_CARD_NUM];
    int  cardNum;
    int  cardFaceStat[CARD_FACE_RANGE][3];
    int  faceNum;
    Comb combArray[ARRAY_COMB_SIZE];
    int  combNum;
    int  used[ARRAY_COMB_SIZE];
} Player;

enum COMBTYPE { TYPE_NULL = 0, TYPE_SINGLE, TYPE_PAIR, TYPE_TRIPLET, TYPE_SERIES, TYPE_BOMB };

// **************************************
// Functions used for this program
// **************************************
//
// Functions related to cards
void drawCards( int allCards[], int onePlayerCards[] );
void sortCards( int onePlayerCards[] );
void cloneCards(int cardsSrc[], int cardsDst[]);
int  countCards( int onePlayerCards[], int cardFaceStat[][3] );
void displayOneCard( int cardId );

//
// Function related to card combinations
int  getMinGroup ( int onePlayerCards[], int cardFaceStat[][3], Comb *foundComb, int groupSize );
int  getMinSeries( int onePlayerCards[], int cardFaceStat[][3], Comb *foundComb, int seriesSize );
void displayOneComb( int cardId[], Comb oneComb );

//
// Functions related to one player
void initializePlayer(Player* ptrPlayer, char playerName );
void planCombs( Player* ptrPlayer );
int  getNextComb( Player* ptrPlayer );
int  getBiggerComb( Player* ptrPlayer, Comb* ptrTargetComb, int *needUpdate );
void playOneComb( Player* ptrPlayer, int comSeq );
void updatePlayer( Player* ptrPlayer );
void displayPlayerCards( Player* ptrPlayer );
void displayPlayerStat( Player* ptrPlayer );
void displayPlayerPlan( Player* ptrPlayer );
void displayPlayerPlay( Player* ptrPlayer, int combSeq );

//
// Functions related to multiple players, or the whole game
void initializeGame( Player playerArray[] );
void prepareGame( int allCards[], Player playerArray[] );
void planGame( Player playerArray[] );
void playGame( Player playerArray[] );
void reportGame( Player playerArray[] );
void displayGame( Player playerArray[], int displayMode );

int main()
{
    printf("\nPoker Game version 6: Multiple player interact with each other \n");

    // Declare and initialize the playerArray in type of Player
    Player playerArray[PLAYER_NUM];
    initializeGame( playerArray );

    // Prepare the game: draw cards
    int allCards[CARD_ALL_NUM] = {0};
    int SEED;
    scanf("%d",&SEED);
    srand(SEED);
    prepareGame( allCards, playerArray );
    //printf("\nDraw results:\n");
    //displayGame( playerArray, DISPLAY_CARDPLAY );
    //printf("\nCount results:\n");
    //displayGame( playerArray, DISPLAY_FACESTAT );

    // Plan and play the game
    planGame( playerArray );
    printf("\nPlan results:\n");
    displayGame( playerArray, DISPLAY_COMBLIST);
    printf("\nPlay the game:\n");
    playGame( playerArray );
    printf("Game results:\n");
    reportGame( playerArray );

    return 0;
}


// Initialize the player array, set the array initial values
void initializeGame(Player players[])
{
    int i;
    Player* ptrPlayer = players;
    for ( i = 0; i < PLAYER_NUM; i ++ )
    {
        initializePlayer(ptrPlayer, 'A' + i );
        ptrPlayer ++;
    }
}


// Draw cards to players, counting cards for them
void prepareGame( int allCards[], Player players[] )
{
    int i;
    Player* ptrPlayer;
    for ( i = 0, ptrPlayer = players; i < PLAYER_NUM; i ++, ptrPlayer ++ )
    {
        drawCards( allCards, ptrPlayer->cardIdPlay );
        sortCards( ptrPlayer->cardIdPlay );
        cloneCards( ptrPlayer->cardIdPlay, ptrPlayer->cardIdPlan );
        countCards( ptrPlayer->cardIdPlan, ptrPlayer->cardFaceStat );
    }
}


// Plan combiniations for players
void planGame( Player players[] )
{
    int i;
    Player* ptrPlayer;
    for ( i = 0, ptrPlayer = players; i < PLAYER_NUM; i ++, ptrPlayer ++ )
    {
        planCombs( ptrPlayer );
    }
}


// Report the game results
void reportGame( Player players[] )
{
    int i ;
    Player *ptrPlayer ;
    for ( i = 0, ptrPlayer = players ; i < PLAYER_NUM; i ++, ptrPlayer ++ )
    {
        if ( ptrPlayer->cardNum > 0 )
        {
            printf("  Player_%c remains %d cards.\n", ptrPlayer->playerName, ptrPlayer->cardNum );
        }
        else if ( ptrPlayer->cardNum == 0 )
        {
            printf("  Player_%c is the winner.\n", ptrPlayer->playerName );
        }
    }
    printf(" \n");
}


void displayGame( Player players[], int displayMode )
{
    // array of function pointers, demostrate the usage of pointer to functions
    void (*displayPlayerFunctionArray[3]) (Player *ptrPlayer)
         = { displayPlayerCards, displayPlayerStat, displayPlayerPlan };

    int i;
    Player *ptrPlayer;
    for ( i = 0, ptrPlayer = players; i < PLAYER_NUM; i ++, ptrPlayer ++ )
    {
        displayPlayerFunctionArray[ displayMode ] ( ptrPlayer );
    } // end of for
}


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
    printf("]\n");

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

void playGame( Player players[] )
{
    Comb lst;
    int  pos,flag=0,which=0;//flag表示当前谁是赢家，which表示当前谁在出牌
    int Upflag=0;
    while (players[0].cardNum!=0&&players[1].cardNum!=0&&players[2].cardNum!=0){
        if (flag==which){
            pos=getNextComb(&players[which]);
            playOneComb(&players[which],pos);
            lst=players[which].combArray[pos];
        }
        else{
            pos=getBiggerComb(&players[which],&lst,&Upflag);
            playOneComb(&players[which],pos);
            if (pos>=0){
                flag=which;
                lst=players[which].combArray[pos];
            }
            if (Upflag) {
                updatePlayer(&players[which]);
                Upflag=0;
            }
        }
        which++;
        which%=3;
    }
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


void updatePlayer( Player* ptrPlayer )
{
    planCombs(ptrPlayer);
    displayPlayerPlan(ptrPlayer);
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
//
// << Your source code stops here >>
// **********************************************

 
