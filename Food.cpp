#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs* thisGMRef)
{
    // Seeding the random integer generation function with current time
    srand(time(NULL));
    
    // Initializing the food position
    foodPos.setObjPos(-1, -1, 'o');
    
    //need reference to GM
    thisGM = thisGMRef;

    //create food bucket onto the heap
    foodBucket = new objPosArrayList();

    //put 3 initial foodPos objects into the list just to initilize it
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
}

Food::~Food()  // Destructor
{
    //delete the foodBucket list off the heap
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    //create a temporary food variable to hold the food objects
    objPos tempFoodPos;

    //a for loop that iterates for the amount of food objects you want on the screen at once
    for(int j = 0; j < 3; j++)
    {
        //either have 0 or 1 special object on the screen at one time
        if (j < rand() % 2)
        {
            //a special object will have the symbol of X
            foodPos.symbol = 'X';
        }
        else
        {
            //a nonspecial object will have the symbol of o
            foodPos.symbol = 'o';
        }
        do 
        {
            //set the position taken bool to false every iteration
            posTaken = false;

            //generate x and y positions inside of the border
            foodPos.x = rand() % (thisGM->getBoardSizeX() - 2) + 1;
            foodPos.y = rand() % (thisGM->getBoardSizeY() - 2) + 1;

            //check if position of food overlaps with player.
            for (int i = 0; i < blockOff->getSize(); i++)
            {
                //store element i into temp objPos
                blockOff->getElement(tempPos, i);
                
                if(foodPos.isPosEqual(&tempPos))
                {
                    //if generated positions are the same as any value in player array list
                    //set postaken to true
                    posTaken = true;
                    
                    //break out of the for loop to get rid of any unnecessary iterations
                    break;
                }
            }
            for (int i = 0; i < foodBucket->getSize(); i++)
            {
                //store foodBucket element i into tempFoodPos object
                foodBucket->getElement(tempFoodPos, i);
                
                //if generated positions are the same as any value in player array list
                //set postaken to true
                if(foodPos.isPosEqual(&tempFoodPos))
                {
                    //ensures that the newly generated food do not overlap
                    posTaken = true;

                    //break out of the for loop to get rid of any unnecessary iterations
                    break;
                }
                
            }

        } while (posTaken);//repeat while there are duplicate positions

        //insert foodPos after making sure it doesnt overlap with any existing position into foodBucket
        foodBucket->insertHead(foodPos);

        //get rid of pre-existing elements in foodBucket to be replaced with new ones
        foodBucket->removeTail();
    }

}

objPosArrayList* Food::getFoodPos()
{
    //return the foodBucket objPosArrayList
    return foodBucket;
    
}