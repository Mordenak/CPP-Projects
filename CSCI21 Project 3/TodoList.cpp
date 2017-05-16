#include "TodoList.h"

TodoList::TodoList()
{
    arrayCapacity = 25;
    arraySize = 0;
    itemList = new TodoItem*[arrayCapacity];
    for (int i = 0;i < arrayCapacity;i++)
        itemList[i] = NULL;
}

TodoList::~TodoList()
{
    for (int i = 0;i < arrayCapacity;i++)
        if (itemList[i] != NULL)
        {
            delete itemList[i];
            itemList[i] = NULL;
        }
    delete [] itemList;
}

void TodoList::addItem(TodoItem* createItem)
{
    int nullCheck = arrayCapacity;

    for (int i = 0;i < arrayCapacity;i++)
    {
        if (itemList[i] != NULL) // check how many pointers aren't NULL to determine if there's
            nullCheck--;         // an available index to point to a new object
    }

    if (nullCheck == 0)          // if there are no NULL pointers in the array, increase capacity and add the item
    {
        TodoItem** newList;
        newList = new TodoItem*[arrayCapacity];
        newList = itemList;
        increaseCapacity();
        itemList = new TodoItem*[arrayCapacity];

        for (int i = 0;i < arrayCapacity;i++)
            itemList[i] = NULL;

        for (int i = 0;i < arraySize;i++)
            itemList[i] = newList[i];

        for (int i = 0;i < arrayCapacity;i++)
        {
            if (itemList[i] == NULL)
            {
                itemList[i] = createItem;
                arraySize++;
                break;
            }
        }
    }
    else
    {
        for (int i = 0;i < arrayCapacity;i++)
        {
            if (itemList[i] == NULL)
            {
                itemList[i] = createItem;
                arraySize++;
                break;
            }
        }
    }
    sortArray();
}

void TodoList::deleteItem(int itemIndex)
{
    delete itemList[itemIndex];
    itemList[itemIndex] = NULL;
    arraySize--;
    packArray();
    sortArray();
}

TodoItem* TodoList::retrieveItem(int itemIndex)
{
    return this->itemList[itemIndex];
}

int TodoList::retrieveSize()
{
    return arraySize;
}

int TodoList::retrieveCapacity()
{
    return arrayCapacity;
}

void TodoList::sortArray()
{
    TodoItem* temp;
    for (int i = 0;i < retrieveSize();i++)  // retrieveSize()-1 to prevent the loop from indexing out of bounds
    {
        for (int x = i;x < retrieveSize();x++)
        {
            if (itemList[x]->getPriority() > itemList[i]->getPriority())
            {
                temp = itemList[i];
                itemList[i] = itemList[x];
                itemList[x] = temp;
            }
        }
    }
}

void TodoList::advancedSort()
{
    TodoItem* tempObj;
    for (int i = 0;i < retrieveSize();i++)
    {
        if (itemList[i]->getCompleted() == true)
        {
            for (int x = (retrieveSize()-1);x > i;x--)
            {
                if (itemList[x]->getCompleted() == false)
                {
                    tempObj = itemList[i];
                    itemList[i] = itemList[x];
                    itemList[x] = tempObj;
                    break;
                }
            }
        }
    }

    bool sortCheck = true;
    for (int i = 0;i < retrieveSize();i++)
    {
        if (itemList[i]->getCompleted() == true)
        {
            if (i < (retrieveSize()-1))
            {
                if (itemList[i+1]->getCompleted() != true)
                    sortCheck = false;
            }
            else
            {
                if (itemList[(retrieveSize()-1)]->getCompleted() != true)
                    sortCheck = false;
            }
        }
    }

    if (sortCheck != true)
        cout << "Sorting failed...\n\n";
    else
        cout << "Sorting completed.\n\n";

    bool foundComplete = false;
    for (int i = 0;i < retrieveSize();i++) // go through the array
    {
        if (itemList[i]->getCompleted() == true) // iterate til you find a true completed
        {
            foundComplete = true;
            for (int x = i;x < retrieveSize()-1;x++) // start a new loop to compare the found object with the array within non completed objects
            {
                for (int y = 0;y < (i-1);y++)
                {
                    if (itemList[y+1]->getText()[0] < itemList[y]->getText()[0])
                    {
                        tempObj = itemList[y];
                        itemList[y] = itemList[y+1];
                        itemList[y+1] = tempObj;
                    }
                }
            }
            for (int x = 0;x < i;x++)
            {
                for (int y = i;y < retrieveSize()-1;y++)
                {
                    if (itemList[y+1]->getText()[0] < itemList[y]->getText()[0])
                    {
                        tempObj = itemList[y];
                        itemList[y] = itemList[y+1];
                        itemList[y+1] = tempObj;
                    }
                }
            }
            break;
        }
    }

    if (foundComplete == false) // there are no completed objects, which means just sort the array
    {
        for (int i = 0;i < retrieveSize();i++)
        {
            for (int x = 0;x < retrieveSize()-1;x++)
            {
                if (itemList[x+1]->getText()[0] < itemList[x]->getText()[0])
                {
                    tempObj = itemList[x];
                    itemList[x] = itemList[x+1];
                    itemList[x+1] = tempObj;
                }
            }
        }
    }
}

string TodoList::toFile()
{
    string newStr;
    ostringstream oss;

    for (int i = 0;i < arraySize;i++)
        oss << itemList[i]->toFile();

    newStr = oss.str();
    return newStr;
}

void TodoList::increaseCapacity() //private functions
{
    arrayCapacity += 10;
}

void TodoList::packArray() //private functions
{
    for (int i = 0;i < arraySize;i++)
    {
        if (itemList[i] == NULL)
        {
            itemList[i] = itemList[i+1];
            itemList[i+1] = NULL;
        }
    }
}

void TodoList::print (ostream& outs, void (*f)())
{
    for (int i = 0;i < arraySize;i++)
    {
        if (itemList[i] != NULL)
        {
            cout << "    *----------------------------------------------------------------------*\n";
            cout << "                                      ENTRY " << (i+1) << "\n";
            cout << *itemList[i];
            if ((i+1)%4 == 0 && i != arraySize-1)
                f();
        }
    }
}
