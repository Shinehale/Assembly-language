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
#define PLAYER_CARD_NUM   8

//
// Micro function for card calculation
#define getCardFaceByID(x)  ( (x) / CARD_SUIT_RANGE + 1 )
#define getCardSuitByID(x)  ( (x) % CARD_SUIT_RANGE + 1 )

// **************************************
// Functions used for this program
// **************************************
//
// Function to randomly draw cards to player array
void drawCards(int allCards[], int onePlayerCard[]);
//
// Function to display card information
void displayOneCard(int cardId);
void displayPlayerCards(char playerName, int playerCards[]);


int main()
{
    printf("Poker Game version 1: draw cards to players\n");

    // Declare allCards[] to indicate whether one card has been drawn (1) or not (0). 
    // Use value 0 to indicate availabe state, 1 to indicate drawn state
    //
    int allCards[CARD_ALL_NUM] = {0};

    // Declare card[] to record the value of cards that are drawn to this player
    // Use card id of     0  ,1  ,2  ,3  ,4  ,5  ,6  , ... ,48 ,49 ,50 ,51
    // to indicate card:  A.1,A.2,A.3,A.4,2.1,2.2,2.3, ... ,K.1,K.2,K.3,K.4
    //
    int cardA[PLAYER_CARD_NUM] = {0};
    int cardB[PLAYER_CARD_NUM] = {0};
    int SEED;
    scanf("%d",&SEED);
    // Draw the cards to one player and display the results
    srand(SEED);
    drawCards(allCards, cardA );
    displayPlayerCards( 'A', cardA );
    drawCards(allCards, cardB );
    displayPlayerCards( 'B', cardB );

    return 0;
}


void displayOneCard( int cardId )
{
	if ( cardId < 0 )
	{
		// nagetive value indicates the state of played card
		printf("%4s", " ---");
		return;
	}

    int face = getCardFaceByID( cardId );
    int suit = getCardSuitByID( cardId );
    if ( face == 1 )
    {
        printf(" %c.%1d", 'A', suit);
    } 
    else if ( face >= 2 && face <= 10 )
    {
        printf("%2d.%1d", face, suit);
    }
    else if ( face == 11 )
    {
        printf(" %c.%1d", 'J', suit);
    }
    else if ( face == 12 )
    {
        printf(" %c.%1d", 'Q', suit);
    }
    else if ( face == 13 )
    {
        printf(" %c.%1d", 'K', suit);
    }
    return ;
}


void displayPlayerCards(char playerName, int cards[] )
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

void drawCards(int allCards[], int onePlayerCard[]){
    int tot=8;
    while (tot){
        int sum=0;
        for (int i=0;i<=CARD_ALL_NUM;i++)
            sum+=allCards[i];
        if (sum==CARD_ALL_NUM) {
            printf("“Error!\n\n");
            exit(1);
        }
        int new_value=rand()%CARD_ALL_NUM;
        if (allCards[new_value]==0){
            allCards[new_value]=1;
            onePlayerCard[8-tot]=new_value;
            tot--;
        }
        else continue;
    }
}