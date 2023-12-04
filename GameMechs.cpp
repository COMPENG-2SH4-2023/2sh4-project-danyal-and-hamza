#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"

GameMechs::GameMechs()
{
    //set all initial values for when creating a set game board
    input = 0;
    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
    loseFlag = false;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    //set all initial values for when creating a gameboard of custom size
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    loseFlag = false;
    score = 0;
}

// do you need a destructor?

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    if (input == '`')
    {
        exitFlag = true;
    } 

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}


int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore(objPosArrayList* thisPlayerList)
{
    score++;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::printFinalMessage()
{
    if(!loseFlag && exitFlag)
    {
        MacUILib_printf("You have ended the game! Game Over!");
    }
    else if (loseFlag == true)
    {
        MacUILib_printf("You've lost the game. Game over!");
        exitFlag = true;
    }
    
}

void GameMechs::printInstructions()
{
    MacUILib_printf("Use WASD to control the movement of the player\n");
    MacUILib_printf("Pick up the food around the screen to gain score \n");
    MacUILib_printf("Occasionally, an X may spawn in, collect the X to get 5 points\n");
}