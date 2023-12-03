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
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption(objPos snakeHead, objPos foodPos);
        void increasePlayerLength(objPos snakeHead);
        bool checkSelfCollision(objPos snakeHead);


    private:
        objPosArrayList* playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        Food* myFood;
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

};

#endif