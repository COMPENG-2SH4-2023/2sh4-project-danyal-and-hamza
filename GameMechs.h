#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

#include "MacUILib.h"

using namespace std;


class GameMechs
{
    private:
        char input; //create a char that holds the player input
        bool exitFlag;//exit flag for when the player loses or exits the game
        bool loseFlag; //Lose flag for when the player loses the game
        int score; //implement as you eat apples or whatever
        
        //board parameters
        int boardSizeX;
        int boardSizeY;

    public:
        //constructor functions
        GameMechs();
        GameMechs(int boardX, int boardY);
        
        //no destructor needed
        
        //getter and setter of the exit flag
        bool getExitFlagStatus();
        void setExitTrue();

        //getter and setter of the lose flag
        bool getLoseFlagStatus();
        void setLoseFlag();

        //getter for score and incrementer of score
        int getScore();
        void incrementScore(int a);

        //get the input, set the input to a specific character, and clear the input
        char getInput();
        void setInput(char this_input);
        void clearInput();

        //getter of the board parameters
        int getBoardSizeX();
        int getBoardSizeY();

        //just to print the messages at end of game
        void printFinalMessage();
        
        //print the instructions for the player
        void printInstructions();
};

#endif