/**
 * CLASS NAME:          TodoList
 * CLASS DESCRIPTION:   This class contains a dynamic instance of an array of pointers to TodoItem and
 *                      functions to control the array and access it's elements for use in the TodoUI
 *                      class.
 *
 * PROGRAMMER NAME:     Nicholas J. Solwick
 * Date created:        2/28/2012
 * Last date modified:  4/6/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#pragma once
#include <iostream>
#include "TodoItem.h"
#include "CinReader.h"

using namespace std;

/**
 *   A class for handling an array of TodoItem*.  TodoList provides functions
 *   to adjust the array as well as retrieving the elements within the array.
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */
class TodoList
{
    public:
        /**
         *  Constructor.
         *  Initializes data members to the following values:
         *  <ul>
         *  <li>arrayCapacity = 25;</li>
         *  <li>arraySize = 0;</li>
         *  <li>itemList = new TodoItem*[arrayCapacity];</li>
         *  </ul>
         */
        TodoList();

        /**
         *  Destructor.
         *  Deletes the following data members:
         *  <ul>
         *  <li>itemList elements</li>
         *  <li>itemList array</li>
         *  </ul>
         */
        ~TodoList();

        /**
         *  Places the array in a ostringstream using a for loop and TodoItem's toFile() as a helper function.
         * @return a string which contains the data members in string format of all the objects of the array itemList.
         */
        string toFile();

        /**
         *  Adds an item to the array into the next "open" element of the array, as well as calls increaseCapacity() when
         *  necessary to increase the capacity of the array to allow more elements.
         * @param createItem is the TodoItem* object being passed in to be placed in the itemList array.
         */
        void addItem(TodoItem* createItem);

        /**
         *  Deletes an item from the array and then calls the packArray() and sortArray() functions to correct the array's
         *  positioning after a deletion to ensure there are no "blank" spaces between elements.
         * @param itemIndex is the index of the object being deleted
         */
        void deleteItem(int itemIndex);

        /**
         *  Retrieves an item from the itemList array and returns it.
         * @param itemIndex is the index of the object that is being retrieved
         * @return a TodoItem* which is the object being retrieved from the array
         */
        TodoItem* retrieveItem(int itemIndex);

        /**
         *  This function simply returns the int value from the arraySize member variable.
         * @return an int which contains the int value from arraySize
         */
        int retrieveSize();

        /**
         *  This function simple returns the int value from the arrayCapacity member variable.
         * @return an int which contains the int value from arrayCapacity
         */
        int retrieveCapacity();

        /**
         *  This function serves as the overloaded << operator for the TodoList class, however
         *  it provides a screen pause for each 4th element for better output, that the overloaded operator could
         *  not provide, and therefore is more desired.
         * @param outs is the ostream being passed-by-reference to contain the output
         * @param (*f)() is the function being passed as a parameter to be used within the function
         */
        void print (ostream& outs, void (*f)());

        /**
         *  This function sorts the itemList array based on each elements priority member variable, higher being placed first
         */
        void sortArray();

        /**
         *  This functions runs through a couple algorithms to sort the itemList array first based on it's completed member
         *  variable, and then alphabetically within each set of completed/non-completed items.
         */
        void advancedSort();

    private:
        void increaseCapacity(); // Private function to increase the array's capacity by 10
        void packArray(); // Private function to "shift-down" the array's elements after a deletion to ensure no "blank" elements between "non-blank" elements

        int arraySize; // Private member that contains the current number of objects in the array
        int arrayCapacity; // Private member that contains the available amount of objects allowed in the array

        TodoItem** itemList;  // The dynamic array of TodoItem pointers, aka the actual list of TodoItems
};

