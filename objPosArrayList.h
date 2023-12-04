#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 450

#include "objPos.h"

class objPosArrayList
{
    private:
        //create an objPos list
        objPos* aList;

        //create a variable to track list size
        int listSize;

        //create a varaible that holds the array capacity
        int arrayCapacity;

    public:
        //constructor and destructor
        objPosArrayList();
        ~objPosArrayList();

        //getter of the size of the list
        int getSize();

        //insert an object to the head of the list
        void insertHead(objPos thisPos);

        //insert an object to the tail of the list
        void insertTail(objPos thisPos);

        //remove an object from the head of the list
        void removeHead();

        //remove an object from the tail of the list
        void removeTail();
        
        //getter of the head element, tail element, and element at index
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);
};

#endif