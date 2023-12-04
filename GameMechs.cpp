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

// do you need a destructor? --- NO

bool GameMechs::getExitFlagStatus()
{
    //return the status of the exit flag
    return exitFlag;
}

char GameMechs::getInput()
{
    //if there is a char input detected, store the char into input
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    //if the input is escape, exit the game
    if (input == 27)
    {
        exitFlag = true;
    } 

    //return the input
    return input;
}

int GameMechs::getBoardSizeX()
{
    //return the x parameter of the board
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    //return the y parameter of the board
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    //set the exit flag to true
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    //set the input into a chosen input
    input = this_input;
}

void GameMechs::clearInput()
{
    //clear the input
    input = 0;
}


int GameMechs::getScore()
{
    //return the score
    return score;
}

void GameMechs::incrementScore(int a)
{
    //increment the score by a
    score += a;
}

bool GameMechs::getLoseFlagStatus()
{
    //return the lose flag status
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    //set lose flag to true
    loseFlag = true;
}

void GameMechs::printFinalMessage()
{
    if(!loseFlag && exitFlag)
    {
        //if youve lost the game...
        MacUILib_printf("You have ended the game! Game Over!\n");
        MacUILib_printf("Your score was: %d", score);
    }
    else if (loseFlag == true)
    {
        //if you exit the game...
        MacUILib_printf("You've lost the game. Game over!\n");
        MacUILib_printf("Your score was: %d", score);
    }
    
}

void GameMechs::printInstructions()
{
    //print the instructions onto the screen
    MacUILib_printf("Use WASD to control the movement of the player\n");
    MacUILib_printf("Press esc to end the game\n");
    MacUILib_printf("Pick up the food around the screen to gain score \n");
    MacUILib_printf("Occasionally, an X may spawn in, collect the X to get 5 points\n");
}