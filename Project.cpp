#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

//create global regerence to game mechanics class
GameMechs* myGM;

//create global reference to player class
Player* myPlayer;

//create a global reference to food class
Food* myFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
    
}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    //set up board and player
    myGM = new GameMechs(30, 15);
    myFood = new Food(myGM);
    myPlayer = new Player(myGM, myFood);
    
    //generate food and pass in player objPosArrayList
    myFood->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    //get the input from the GameMechs class
    myGM->getInput();
}

void RunLogic(void)
{
    //update player direction
    myPlayer->updatePlayerDir();
    
    //move the player
    myPlayer->movePlayer();

    //clear the player input
    myGM->clearInput();
}

void DrawScreen(void)
{
    //clear the screen
    MacUILib_clearScreen();

    //initialize varivles to be used throughout the draw screen function
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPosArrayList* foodBucket = myFood->getFoodPos();
    objPos tempFoodList;

    bool drawn;
    
    //i is for the # of rows or the y values
    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        // j is for the # of columns or in this case the x value
        for (int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            //set drawn to false, indicating that nothing was drawn yet at this location
            drawn = false;

            //iterate through all elements in the objPosArrayList for Player
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                //save the element at k of Player objPosArrayList into tempPos
                playerBody->getElement(tempBody, k);

                //check if the coordinates of the player match the coordinates of the screen
                if(tempBody.x == j && tempBody.y == i)
                {
                    //print the body symbol into that location
                    MacUILib_printf("%c", tempBody.symbol);

                    //set drawn to true
                    drawn = true;

                    //break out of the for loop to avoid unneccesary looping 
                    break;
                }

            }
            if(drawn) //if player body is drawn, go to next iteration
            {
                continue;
            }

            //iterate through all elements in the objPosArrayList for food
            for(int k = 0; k < foodBucket->getSize(); k++)
            {
                //save the element at k of Food objPosArrayList into tempFoodPos
                foodBucket->getElement(tempFoodList, k);

                //check if the coordinates of the player match the coordinates of the screen
                if(tempFoodList.x == j && tempFoodList.y == i)
                {
                    //print the body symbol into that location
                    MacUILib_printf("%c", tempFoodList.symbol);

                    //set drawn to true
                    drawn = true;

                    //break out of the for loop to avoid unneccesary looping 
                    break;
                }

            }

            if(drawn) //if player body is drawn, go to next iteration
            {
                continue;
            }

            //check if the i or j values match the given border values
            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                //print border character if they do
                MacUILib_printf("#");
            }
            else
            {
                //print open space if not
                MacUILib_printf(" ");
            }
            
        }
        //print new line for next iteration
        MacUILib_printf("\n");
        
    }
    //print the instructions and player score onto the screen
    myGM->printInstructions();
    MacUILib_printf("Player score: %d\n", myGM->getScore());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    //print the final message indicating whether the player lost the game or exited the game
    myGM->printFinalMessage();
  
    MacUILib_uninit();

    //remove heap instances
    delete myGM;
    delete myPlayer; 
    delete myFood;
}
