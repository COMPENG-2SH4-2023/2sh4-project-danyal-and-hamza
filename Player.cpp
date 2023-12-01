#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP; // initial state of stop

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, 
                        mainGameMechsRef->getBoardSizeY()/2, '@'); // sets character initilization


}


Player::~Player()
{
    // delete any heap members here
    // empty for now, need in iteration 3


}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    
    // return the reference to the playerPos arrray list ... later
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    //get inpuit from game mechanism class probably

    char input = mainGameMechsRef->getInput(); //use the get input from GameMech for input

    switch(input) 
    {
        case 'w':
                if (myDir != DOWN){
                    myDir = UP;
                }
                break;
            // Add more key processing here
            case 's':
                if (myDir != UP){
                    myDir = DOWN;
                }
                break;
            // Add more key processing here   
            case 'a':
                if (myDir != RIGHT){
                    myDir = LEFT;
                }
                break;
                

            case 'd':
                if (myDir != LEFT){
                    myDir = RIGHT;
                }
            default:
                break;

    }

    mainGameMechsRef->clearInput(); //clear input char right after changing states


}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if(myDir == RIGHT)
    {
        playerPos.x += 1;       // Right increments positively
    }
    else if (myDir == LEFT)
    {
        playerPos.x -= 1;       // Left increments negatively
    }
    else if (myDir == DOWN)
    {
        playerPos.y += 1;       // Down increments positively
    }
    else if (myDir == UP)
    {
        playerPos.y -= 1;       // Up increments negatively
    }

    //border wrap around
    if (playerPos.x == mainGameMechsRef->getBoardSizeX() - 1)
    {
        playerPos.x = 1;
    }
    if (playerPos.y == mainGameMechsRef->getBoardSizeY() - 1)
    {
        playerPos.y = 1;
    }
    if (playerPos.x == 0)
    {
        playerPos.x = mainGameMechsRef->getBoardSizeX() - 1;
    }
    if (playerPos.y == 0)
    {
        playerPos.y = mainGameMechsRef->getBoardSizeY() - 1;
    }
    
    //updates player posistion based on logic.
}

