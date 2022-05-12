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
#define PLAYER_CARD_NUM   13
//
// Constant for array index in cardFaceStat[CARD_FACE_RANGE][3]
#define FACESTAT_FACE     0
#define FACESTAT_SEQ1     1
#define FACESTAT_COUNT    2
//
// Micro function for card calculation
#define getCardFaceByID(x)  ( (x) / CARD_SUIT_RANGE + 1 )
#define getCardSuitByID(x)  ( (x) % CARD_SUIT_RANGE + 1 )

// **************************************
// Functions used for this program
// **************************************
//
// Function to randomly draw cards to player array
void drawCards( int allCards[], int onePlayerCards[] );
void sortCards(int onePlayerCards[]);
int  countCards( int onePlayerCards[], int cardFaceStat[][3] );

//
// Function to display card information
void displayOneCard( int cardId);
void displayPlayerCards( char playerName, int playerCards[] );
void displayPlayerStat( char playerName, int cardFaceStat[][3] );

//
// Constants to display card information
const char faceStr[][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const char suitStr[][2] = {"1","2","3","4"};


int main()
{
    printf("Poker Game version 2: count the cards of one player\n");

    // Declare allCards[] to indicate whether one card has been drawn (1) or not (0). 
    int allCards[CARD_ALL_NUM] = {0};

    // Declare player[] to record the value of cards that are drawn to this player
    int cardA[PLAYER_CARD_NUM] = {0};

    // Declare cardFaceStat[][3] to count the faces
    // cardFaceStat[][FACESTAT_FACE]: the appeared card face, default -1
    // cardFaceStat[][FACESTAT_SEQ1]: the first card seq with that face, default 0 
    // cardFaceStat[][FACESTAT_COUNT]:the appearance count of that face, default 0
    //
    int cardFaceStatA[CARD_FACE_RANGE][3] = {{0}};
    int SEED;
    scanf("%d",&SEED);
    // Draw the cards to one player
    srand(SEED);
    drawCards( allCards, cardA );
    printf("\nDraw results:\n");
    displayPlayerCards( 'A', cardA );

    // Sort the cards 
    sortCards( cardA );
    printf("\nSort results:\n");
    displayPlayerCards( 'A', cardA );

    // Count the distinct faces in cards 
    int foundFaceNum =  countCards(cardA, cardFaceStatA );
    printf("\nCount results:\n");
    displayPlayerStat( 'A', cardFaceStatA );
    printf("  Total %d distinct faces are found in Player_%c.\n\n", foundFaceNum, 'A' );

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
    for ( i = 0; i < PLAYER_CARD_NUM - 1 ; i ++ )
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
    printf("- ]\n");

    printf("%10s:  [", "seq1");
    for ( i = 0; i < CARD_FACE_RANGE -1 ; i ++ )
    {
        printf("%2d,", faceStat[i][FACESTAT_SEQ1] );
    }
    printf("%2d ]\n", faceStat[i][FACESTAT_SEQ1]);

    printf("%10s:  [", "count");
    for ( i = 0; i < CARD_FACE_RANGE -1 ; i ++ )
    {
        printf("%2d,", faceStat[i][FACESTAT_COUNT] );
    }
    printf("%2d ]\n", faceStat[i][FACESTAT_COUNT]);
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

// **********************************************
// << Your source code starts here >>
//

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
