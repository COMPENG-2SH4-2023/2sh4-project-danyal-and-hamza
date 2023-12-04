#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs* thisGMRef)
{
    srand(time(NULL));                 // Seeding the random integer generation function with current time
    foodPos.setObjPos(-1, -1, 'o');   // Initializing the food position
    thisGM = thisGMRef;               //need reference to GM
    foodBucket = new objPosArrayList();
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
}

Food::~Food()  // Destructor
{
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    objPos tempFoodPos;
    for(int j = 0; j < 3; j++)
    {
        if (j < rand() % 2)
        {
            foodPos.symbol = 'X';
        }
        else
        {
            foodPos.symbol = 'o';
        }
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
            for (int i = 0; i < foodBucket->getSize(); i++)
            {
                foodBucket->getElement(tempFoodPos, i);
                if(foodPos.isPosEqual(&tempFoodPos))
                {
                    posTaken = true; //ensures that the newly generated food do not overlap
                    break;
                }
                
            }

        } while (posTaken);//repeat while there are duplicate positions
        foodBucket->insertHead(foodPos);
        foodBucket->removeTail();
    }

}

objPosArrayList* Food::getFoodPos()
{
    return foodBucket;  // Return the food position (self explanatory)
    
}