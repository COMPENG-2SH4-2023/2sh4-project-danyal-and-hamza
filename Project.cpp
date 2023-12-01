#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM; //create global regerence to game mechanics class
Player* myPlayer; //create global reference to player class
Food* snakeFood;  // Creates a global reference to the Food class, referred to as snakeFood

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
    myPlayer = new Player(myGM);

    // Setting up food
    snakeFood = new Food;     // Allocating the Food object to the heap
    // snakeFood->generateFood( Whatever the player's position is );

}

void GetInput(void)
{

}

void RunLogic(void)
{
    //update player direction
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    //exit game logic
    if (myGM->getInput() == '`')
    {
        myGM->setExitTrue();
    }

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos tempPos;

    myPlayer->getPlayerPos(tempPos);

    //check function works
    MacUILib_printf("board size is %dx%d, playerpos is: <%d, %d>, + %c, score is: %d\n"
                    , myGM->getBoardSizeX(), 
                    myGM->getBoardSizeY(), 
                    tempPos.x, tempPos.y, tempPos.symbol
                    , myGM->getScore());

    for (int i = 0; i < myGM->getBoardSizeY(); i++){ //i is for the # of rows or the y values
        for (int j = 0; j < myGM->getBoardSizeX(); j++){ // j is for the # of columns or in this case the x value
            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1){
                MacUILib_printf("#");
            }
            else if(j == tempPos.x && i == tempPos.y){
                MacUILib_printf("%c", tempPos.symbol);
            }
            else{
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("\n");
        
    }
    
    
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    delete myGM;
    delete myPlayer; //for now... 

    delete snakeFood;  // Deallocating the Food object from the heap
  
    MacUILib_uninit();
}
