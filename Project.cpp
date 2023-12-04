#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM; //create global regerence to game mechanics class
Player* myPlayer; //create global reference to player class
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
    
    //makeshift solution, change it afterwards
    myFood->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    //update player direction
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPosArrayList* foodBucket = myFood->getFoodPos();
    objPos tempFoodList;

    bool drawn;
    
    for (int i = 0; i < myGM->getBoardSizeY(); i++)//i is for the # of rows or the y values
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++)// j is for the # of columns or in this case the x value
        {
            drawn = false;
            //iterate through all elements in the list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }

            }
            if(drawn) //if player body is drawn, go to next iteration
            {
                continue;
            }

            for(int k = 0; k < foodBucket->getSize(); k++)
            {
                foodBucket->getElement(tempFoodList, k);
                if(tempFoodList.x == j && tempFoodList.y == i)
                {
                    MacUILib_printf("%c", tempFoodList.symbol);
                    drawn = true;
                    break;
                }

            }

            if(drawn) //if player body is drawn, go to next iteration
            {
                continue;
            }

            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("#");
            }
            else
            {
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("\n");
        
    }
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
    myGM->printFinalMessage();
  
    MacUILib_uninit();

    //remove heap instances
    delete myGM;
    delete myPlayer; 
    delete myFood;
}
