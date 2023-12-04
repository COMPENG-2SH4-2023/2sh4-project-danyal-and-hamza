#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

using namespace std;


class Food
{
    private:
        // Food position of the objPos type
        objPos foodPos;

        //reference to GameMechs class
        GameMechs* thisGM;

        //creating a pointer to foodBucket that is of objPosArrayList type
        objPosArrayList* foodBucket;

        //creating a bool to represent if a position is taken wihtin the objPosArrayLists for random position generation 
        bool posTaken;

        //temp pos to take position of elements in player array
        objPos tempPos;

        //temporary positions of food elements in food bucket
        objPos tempFoodPos;
    public:
        //constructor and deconstructor
        //initilizse food with reference to GM to use border
        Food(GameMechs* thisGMRef);

        //destructor
        ~Food();

        //generate the food while blocking off the player position and the rest of the player body for the snake head
        void generateFood(objPosArrayList* blockOff); //update this for the playerList
    
        //get the list of food elements and their positions
        objPosArrayList* getFoodPos();
};

#endif