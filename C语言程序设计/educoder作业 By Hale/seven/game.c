#include <stdio.h>
#include <stdlib.h>
#include "poker.h"

// **********************************************
// << Your source code starts here >>
//

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

// Play the game, multiple players interact
void playGame( Player players[] )
{
    Comb lst;
    int  pos,flag=0,which=0;//flag表示当前谁是赢家，which表示当前谁在出牌
    int Upflag=0;
    while (players[0].cardNum!=0&&players[1].cardNum!=0&&players[2].cardNum!=0&&players[3].cardNum!=0){
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
        which%=4;
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
    if (i!=4) printf(" \n");
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

//
// << Your source code stops here >>
// **********************************************

