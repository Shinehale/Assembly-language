#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

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
#define PLAYER_NUM        4
#define PLAYER_CARD_NUM   13
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
// File: card.h
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


#endif // POKER_H_INCLUDED

