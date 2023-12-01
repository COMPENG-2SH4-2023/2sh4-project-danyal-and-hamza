#include "Food.h"
#include "MacUILib.h"

Food::Food()
{
    srand(time(NULL));                 // Seeding the random integer generation function with current time
    foodPos.setObjPos(-1, -1, 'o');   // Initializing the food position
}

Food::~Food()  // Destructor
{

}

void Food::generateFood(objPos blockOff)
{
    do {
        
        foodPos.x = rand() % (20 - 2) + 1;    // Obtain a random x value within the border
        foodPos.y = rand() % (10 - 2) + 1;    // Obtain a random y value within the border
        foodPos.symbol = 'o';                         // Set the symbol at that (x,y) coordinate to be a lower case "o"

    } while (foodPos.isPosEqual(&blockOff));           // If the generated position is the same as the blockOff position, find another position

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;  // Return the food position (self explanatory)
}