#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    //constructor
    aList = new  objPos[ARRAY_MAX_CAP]; //256 elements on the heap
    listSize = 0; //nothing in list at start
    arrayCapacity = ARRAY_MAX_CAP;// how many elements can be in the list
}

objPosArrayList::~objPosArrayList()
{
    //destructor
    delete[] aList;
}

int objPosArrayList::getSize()
{

}

void objPosArrayList::insertHead(objPos thisPos)
{
    // move all elements one space to make space at front
    //shouldnt do anything if array is at max capacity
    if (listSize == arrayCapacity)
    {
        
    }
    for(int i = listSize; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]); //this shuffles the elements towards the tail
    }

    aList[0].setObjPos(thisPos);
    listSize++;
}   

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{
    for(int i = 0; i < listSize - 1; i++)
    {
        aList[i].setObjPos(aList[i+1]); //overwrite first element???
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    aList[listSize].setObjPos(0, 0, ' '); //empty string
    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]); // return head
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize - 1]); // return tail
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}