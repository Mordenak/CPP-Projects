/**
 * CLASS NAME:          TodoUI
 * CLASS DESCRIPTION:   This class manages the overall use of the TodoList and TodoItem classes, by providing
 *                      a user interface that allows the user to manipulate it's child classes.
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
#include <fstream>
#include "TodoList.h"
#include "TodoItem.h"
#include "CinReader.h"
#include "foofile.h"

using namespace std;

/**
 *   A class for handling user input.  TodoUI provides menu options for the
 *   user to manipulate the TodoList class.
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */
class TodoUI
{
    public:
        /**
         *  Constructor.
         *  Initializes data members to the following values:
         *  <ul>
         *  <li>uiTodoList = new TodoList;</li>
         *  </ul>
         */
        TodoUI();

        /**
         *  Overloaded Constructor.
         *  Initializes the data members from a file identified by the fileName parameter, to be used in conjunction with the
         *  private loadFile() function.
         * @param fileName is the name of the file to be loaded into the program, in string format
         */
        TodoUI(string fileName);

        /**
         *  Destructor.
         *  Deletes the following data members:
         *  <ul>
         *  <li>uiTodoList</li>
         *  </ul>
         */
        ~TodoUI();

        /**
         *  This is the main menu of the TodoUI class which provides most of the functionality of the class to the user via
         *  a menu of options.  It will also call the showHelp() function if the displayHelp parameter is true.
         * @param displayHelp is a bool that determines whether the program started with help arguments or not
         */
        void mainMenu(bool displayHelp);

        /**
         *  This is the special menu of the TodoUI class which provides additional functionality of the class to the user via
         *  an additional menu of options to run optional functions.
         */
        void specialMenu();

        /**
         *  This function simply clears the screen for the user for better output.
         */
        void clearScreen();

        /**
         *  This function combines the functionality of clearScreen() and screenPause() into a single function, by calling
         *  both functions.
         */
        void pauseClear();

        /**
         *  This function triggers if the program started with the arguments ? or HELP (case insensitive) and provides the user
         *  with information on how to properly use the program.
         */
        void showHelp();

        /**
         *  This function displays a text file, used to output ASCII art into the program.
         * @param artfile is the file name being displayed
         */
        void showArt(string artfile);

    private:
        CinReader uiReader; // Private member CinReader for input handling
        TodoList* uiTodoList; // Private member that is a pointer of TodoList class type to give access through TodoUi

        void loadFile(string fileName); // Private function to load data from a file and properly convert it into the uiTodoList
};

#ifndef CALLBACK_SECTION
#define CALLBACK_SECTION
void screenPause(); // Simple function to pause input by using the CinReader function readString()
#endif
