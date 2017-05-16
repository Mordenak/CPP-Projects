/**
 * PROGRAM NAME:            TodoList Planner
 * PROGRAM DESCRIPTION:     The TodoList Planner program simulates a todo list style planner that allows the user
 *                          to add, edit, delete, view, sort, save and load a list of items that contain text,
 *                          priority and whether or not it is completed.
 *
 * PROGRAMMER NAME:         Nicholas J. Solwick
 * Date created:            2/28/2012
 * Last date modified:      4/6/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "TodoUI.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        string arg = argv[1];
        if (arg.find(".txt") != string::npos)
        {
            TodoUI mainUI(arg);
            mainUI.mainMenu(false);
        }
        else
        {
            bool foundHelp = false;
            if (arg == "?")
            {
                foundHelp = true;
            }
            else
            {
                for (unsigned int i = 0;i < arg.length();i++)
                    arg[i] = tolower(arg[i]);

                if (arg == "help")
                {
                    foundHelp = true;
                }
            }
            TodoUI mainUI;
            mainUI.mainMenu(foundHelp);
        }
    }
    else
    {
        TodoUI mainUI;
        mainUI.mainMenu(false);
    }
    return 0;
}
