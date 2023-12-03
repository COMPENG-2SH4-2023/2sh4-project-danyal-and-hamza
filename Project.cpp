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
    if (myGM->getInput() == 'k')
    {
        myFood->generateFood(myPlayer->getPlayerPos());
    }
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
    
    objPos tempFoodPos;
    myFood->getFoodPos(tempFoodPos);

    bool drawn;
    

    //check function works
    // MacUILib_printf("board size is %dx%d, playerpos is: <%d, %d>, + %c, score is: %d\n"
    //                 , myGM->getBoardSizeX(), 
    //                 myGM->getBoardSizeY(), 
    //                 tempBody.x, tempBody.y, tempBody.symbol
    //                 , myGM->getScore());
    
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
            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("#");
            }
            else if(j == tempFoodPos.x && i == tempFoodPos.y)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("\n");
        
    }

    MacUILib_printf("Player score: %d", myGM->getScore());

    MacUILib_printf("\n");
    if(myGM->getLoseFlagStatus())
    {
        MacUILib_printf("YOUVE LOST THE GAME");
        myGM->setExitTrue();
    }
    

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
