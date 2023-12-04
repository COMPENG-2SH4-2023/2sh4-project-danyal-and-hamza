#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    //setting up reference to GameMechs and Food Classes for use in Player class
    mainGameMechsRef = thisGMRef;
    myFood = thisFood;
    
    //setting initial player direction to STOP, indicating that its not moving
    myDir = STOP;

    //create a temprary object that is used throughout the class
    objPos tempPos;

    //set the initial coordinates of tempPos
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, 
                      mainGameMechsRef->getBoardSizeY()/2, 1); // sets character initilization

    //create a new player objArrayList and add tempPos into it
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    // delete the player list from the heap
    delete playerPosList;

}

objPosArrayList* Player::getPlayerPos()
{
       // return the reference to the playerPos array list
       return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    //get input from game mechanism class
    char input = mainGameMechsRef->getInput();

    //change direction of player accordingly
    switch(input) 
    {
        case 'w':
        case 'W':
                if (myDir != DOWN){
                    myDir = UP;
                }
                break;
            case 's':
            case 'S':
                if (myDir != UP){
                    myDir = DOWN;
                }
                break; 
            case 'a':
            case 'A':
                if (myDir != RIGHT){
                    myDir = LEFT;
                }
                break;
                

            case 'd':
            case 'D':
                if (myDir != LEFT){
                    myDir = RIGHT;
                }
            default:
                break;

    }

}

bool Player::checkFoodConsumption(objPos snakeHead, objPosArrayList* foodBucket)
{
    //create a temporary obeject that will store the food positon of every element in foodBucket
    objPos tempFoodPos;
    for(int i = 0; i < foodBucket->getSize(); i++) //iterate through foodBucket
    {
        //set the flag to false to stop any repeating score increase of 5
        specialFoodConsumed = false;
        
        //store the foodBucket object at element i into tempFoodPos
        foodBucket->getElement(tempFoodPos, i);

        //check if the food that was consumed is a special food
        if (tempFoodPos.isPosEqual(&snakeHead) && tempFoodPos.symbol == 'X')
        {
            specialFoodConsumed = true;
            return true;
        }
        //check if normal food was consumed
        else if (tempFoodPos.isPosEqual(&snakeHead))
        {
            return true;
        }
    }
    return false;
}

void Player::increasePlayerLength(objPos snakeHead)
{
    //if special food is consumed, increase player score by 5 TOTAL
    if (specialFoodConsumed)
    {
        mainGameMechsRef->incrementScore(4);
    }

    //add another elemnt into the player array list to increase its length and increase player score by 1
    playerPosList->insertHead(snakeHead);
    myFood->generateFood(playerPosList);
    mainGameMechsRef->incrementScore(1);
}

bool Player::checkSelfCollision(objPos snakeHead)
{
    //create a temporary postion to be used in this function
    objPos tempPos;

    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(tempPos, i);
        if(snakeHead.isPosEqual(&tempPos))
        {
            return true; //if theres a collision, return true
        }
    }
    return false; //if theres not a collision, return false
}

void Player::movePlayer()
{
    objPos currentHead; //holds pos of current head
    playerPosList->getHeadElement(currentHead);

    //stores the position of the food into foodPos
    objPosArrayList* foodBucket = myFood->getFoodPos();

    // PPA3 Finite State Machine logic
    if(myDir == RIGHT)
    {
        currentHead.x += 1;
    }
    else if (myDir == LEFT)
    {
        currentHead.x -= 1;
    }
    else if (myDir == DOWN)
    {
        currentHead.y += 1;
    }
    else if (myDir == UP)
    {
        currentHead.y -= 1;
    }

    //border wrap around
    if (currentHead.x == mainGameMechsRef->getBoardSizeX() - 1)
    {
        currentHead.x = 1;
    }
    if (currentHead.y == mainGameMechsRef->getBoardSizeY() - 1)
    {
        currentHead.y = 1;
    }
    if (currentHead.x == 0)
    {
        currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
    }
    if (currentHead.y == 0)
    {
        currentHead.y = mainGameMechsRef->getBoardSizeY() - 2;
    }
    
    //check if food is consumed, increase length if it is
    //if not, proceed by removing tail and adding to the head
    if(checkFoodConsumption(currentHead, foodBucket))
    {
       increasePlayerLength(currentHead);
    }
    else
    {
        playerPosList->insertHead(currentHead);
        playerPosList->removeTail();
    }

    // check if the snake collides with itself
    //      if yes, set lose flag to true and exit flag to true to end the game
    if(checkSelfCollision(currentHead))
    {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }
}