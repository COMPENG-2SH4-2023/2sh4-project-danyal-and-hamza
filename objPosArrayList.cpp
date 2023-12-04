#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    //constructor
    //30x15 elements on the heap
    aList = new  objPos[ARRAY_MAX_CAP];

    //nothing in list at start, so list size is 0
    listSize = 0;

    // how many elements can be in the list
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    //destructor
    delete[] aList;
}

int objPosArrayList::getSize()
{
    //return the size of the LIST
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //move all elements one space to make space at front
    //shouldnt do anything if array is at max capacity
    if (listSize == arrayCapacity)
    {
        return;
    }
    for(int i = listSize; i > 0; i--)
    {
        //this shuffles the elements towards the tail
        aList[i].setObjPos(aList[i-1]);
    }

    //set the head to an thisPos object
    aList[0].setObjPos(thisPos);

    //increase the list size
    listSize++;
}   

void objPosArrayList::insertTail(objPos thisPos)
{
    //insert thisPos object to the tail of the list if array isnt at max capacity
    if (listSize == arrayCapacity)
    {
        return;
    }
    aList[listSize].setObjPos(thisPos);

    //increase the size of the list
    listSize++;
}

void objPosArrayList::removeHead()
{
    //shuffle all obects in list to the left, overwriting the head element
    for(int i = 0; i < listSize - 1; i++)
    {
        aList[i].setObjPos(aList[i+1]);
    }

    //decrease the list size
    listSize--;
}

void objPosArrayList::removeTail()
{
    //remove the tail element and replace it with an empty string
    aList[listSize].setObjPos(0, 0, ' ');

    //decrease list size
    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    //return the head element of the list as an object
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    //return the tail element of the list as an object
    returnPos.setObjPos(aList[listSize - 1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    //return the element in list at index as an object.
    returnPos.setObjPos(aList[index]);
}