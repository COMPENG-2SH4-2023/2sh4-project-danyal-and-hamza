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
        objPos foodPos;   // Food position of the objPos type
        GameMechs* thisGM;
        objPosArrayList* foodBucket;
        bool posTaken;
        objPos tempPos; //temp pos to take position of elements in player array
        objPos tempFoodPos; //temporary positions of food elements in food bucket
    public:
        
        Food(GameMechs* thisGMRef); //initilizse food with reference to GM to use border
        ~Food();
        void generateFood(objPosArrayList* blockOff); //update this for the playerList
        //need to accept player body array list
        //go through each element in the array to make sure nothing overlaps
        


        objPosArrayList* getFoodPos(); //get the list of food elements and their positions
};

#endif