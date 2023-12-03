#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs* thisGMRef)
{
    srand(time(NULL));                 // Seeding the random integer generation function with current time
    foodPos.setObjPos(-1, -1, 'o');   // Initializing the food position
    thisGM = thisGMRef;               //need reference to GM
}

Food::~Food()  // Destructor
{

}

void Food::generateFood(objPosArrayList* blockOff)
{
    do 
    {
        posTaken = false;

        //generate positions
        foodPos.x = rand() % (thisGM->getBoardSizeX() - 2) + 1;    // Obtain a random x value within the border
        foodPos.y = rand() % (thisGM->getBoardSizeY() - 2) + 1;    // Obtain a random y value within the border

        //check if positision of food overlaps with player.
        for (int i = 0; i < blockOff->getSize(); i++)
        {
            blockOff->getElement(tempPos, i); //store element i into temp objPos 
            if(foodPos.isPosEqual(&tempPos))
            {
                //if generated positions are the same as any value in player array list
                //set postaken to true
                posTaken = true;
                break;
            }
        }

    } while (posTaken);//repeat while there are duplicate positions

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol);  // Return the food position (self explanatory)
    
}