/**
 * CLASS NAME:          Controller
 * CLASS DESCRIPTION:   This class provides the overall structure of the LinkedList and Node classes, by
 *                      utilizing the functions from those classes to manipulate a vector and a doubly
 *                      linked list.
 *
 * PROGRAMMER NAME:     Nicholas J. Solwick
 * Date created:        4/10/2012
 * Last date modified:  5/04/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "LinkedList.h"

using namespace std;

/**
 *   A class for parsing a string from input and passing it through a decision tree to use functions to
 *   manipulate either a vector or a doubly linked list.
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

class Controller
{
    public:
        /**
         *  Constructor.
         *  Initializes data members to the following values:
         *  <ul>
         *  <li>cVector = NULL;</li>
         *  <li>cList = NULL;</li>
         *  </ul>
         */
        Controller();

        /**
         *  This function passes a string to be interpreted by a decision tree to manipulate a vector and a
         *  doubly linked list.
         * @param input is a string which will be parsed and interpreted as commands for the program
         */
        void parseCommand(string input);

    private:

        vector<int>* cVector; // pointer to a vector of ints
        LinkedList<int>* cList; // pointer to a linked list of ints
};
