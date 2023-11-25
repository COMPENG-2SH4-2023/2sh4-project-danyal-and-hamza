#include "GameMechs.h"
#include "MacUILib.h"

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
    if (MacUILib_hasChar()){
        input = MacUILib_getChar();
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

void GameMechs::incrementScore()
{
    //cant really do without the food thingy so leave for now...
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}
