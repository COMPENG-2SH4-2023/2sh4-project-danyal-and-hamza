#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "GameMechs.h"

using namespace std;


class Food
{
    private:
        objPos foodPos;   // Food position of the objPos type

    public:
        
        Food();
        ~Food();
        
        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
};

#endif