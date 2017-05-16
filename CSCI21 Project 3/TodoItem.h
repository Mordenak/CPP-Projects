/**
 * CLASS NAME:          TodoItem
 * CLASS DESCRIPTION:   This class contains data members necessary for use in the TodoList class.
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
#include <string>
#include <sstream>

using namespace std;

/**
 *   A class for handling data.  TodoItem has functions to access and mutate its
 *   member variables which are one of each, string, bool and int.
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */
class TodoItem
{
    public:
        /**
         *  Constructor.
         *  Initializes data members to the following values:
         *  <ul>
         *  <li>text = "";</li>
         *  <li>priority = 1;</li>
         *  <li>completed = false;</li>
         *  </ul>
         */
        TodoItem();

        /**
         *  Overloaded Constructor.
         *  Initializes the data members according to the parameters, also calls the private scrub() function.
         * @param newText is the user input string being passed in to be set as the text data member
         * @param newPriority is the user input int being passed in to be set as the priority data member, default of 1
         * @param newCompleted is the user input bool being passed in to be set as the completed data memeber, default of false
         */
        TodoItem(string newText, int newPriority=1, bool newCompleted=false);

        /**
         *  Destructor.
         *  TodoItem performs no dynamic memory allocation, however is provided for thoroughness.
         */
        ~TodoItem();

        /**
         *  Set the text member variable.  Also calls the private scrub() function.
         * @param newText is the string being passed in to be set as the text data member
         */
        void setText(string newText);

        /**
         *  Returns the string within the text member variable.
         * @return a string which is contained in the text member variable
         */
        string getText();

        /**
         *  Set the priority member variable.
         * @param newPriority is the int being passed in to be set as the priority data member
         */
        void setPriority(int newPriority);

        /**
         *  Returns the int within the priority member variable.
         * @return an int which is contained in the priority member variable
         */
        int getPriority();

        /**
         *  Set the completed member variable.
         * @param newCompleted is the bool being passed in to be set as the completed data member
         */
        void setCompleted(bool newCompleted);

        /**
         *  Returns the bool within the completed member variable.
         * @return a bool which is contained in the completed member variable
         */
        bool getCompleted();

        /**
         *  Returns a bool based on whether or not the searchStr was found in the text member variable.
         *  Will return true if the searchStr was found, or false if it was not.
         * @param searchStr is the string that will be compared with find() within the text data member
         * @return a bool which will be based on the results of the find() function
         */
        bool hasKeyword(string searchStr);

        /**
         *  Overloaded << operator.
         *  Used to display all data members of the object in an easy method.
         * @param outs is a pass-by-reference of the stream being used for output
         * @param src is a pass-by-reference of the object that is to be output
         * @return an ostream which will contain the output data
         */
        friend ostream& operator<< (ostream& outs, const TodoItem& src);

        /**
         *  Compacts the data from the object into an ostringstream to be ready for output into a text file.
         * @return a string which will contain the object's data in a string format
         */
        string toFile();

    private:
        void scrub(); // Private function to clear the text member variable of any '@' characters and replace them with '#' for delimiting purposes later.

        string text; // Member variable containing the "text" of the object
        int priority; // Member variable containing the object's priority
        bool completed; // Member variable containing a boolean to acknowledge whether the object is completed or not
};
