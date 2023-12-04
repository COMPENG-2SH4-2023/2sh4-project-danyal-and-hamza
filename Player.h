#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();

        objPosArrayList* getPlayerPos();

        //functions that deal with the movement of the player
        void updatePlayerDir();
        void movePlayer();
        
        //functions that deal with how the player reacts to collisions
        bool checkFoodConsumption(objPos snakeHead, objPosArrayList* foodBucket);
        void increasePlayerLength(objPos snakeHead);
        bool checkSelfCollision(objPos snakeHead);


    private:
        objPosArrayList* playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms and food classes
        Food* myFood;
        GameMechs* mainGameMechsRef;

        //bool to check if a special food is consumed
        bool specialFoodConsumed;

};

#endif