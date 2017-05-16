/**
 * PROGRAM NAME:            The Amazing String Parser
 * PROGRAM DESCRIPTION:     This program will take input from a text file and will parse it by each string, which will be
 *                          broken down and passed into a decision tree to perform functions based on the "commands"
 *                          extracted from the string, as well as ancillary data.  This program will dynamically allocate
 *                          a doubly linked list and a vector which will then be manipulated by the commands from the
 *                          input file.  The LinkedList and Node classes are templated to allow the admin to choose the
 *                          type of data to be manipulated.
 *
 * PROGRAMMER NAME:         Nicholas J. Solwick
 * Date created:            4/10/2012
 * Last date modified:      5/04/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#include <iostream>
#include <fstream>
#include "Controller.h"

using namespace std;

int main(int argc, char** argv)
{
    Controller mainControl;

    if (argc != 2)
        cout << "USAGE: test.exe FILENAME";
    else
    {
        string file = argv[1];
        ifstream fin(file.c_str());
        if(!fin.fail())
        {
            string nextLine;
            char nextChar = fin.get();
            while(nextChar != EOF)
            {
                if(nextChar == '\n')
                {
                    mainControl.parseCommand(nextLine);
                    nextLine = "";
                }
                else
                    nextLine += nextChar;
                nextChar = fin.get();
            }
            if(nextLine.length() > 0)
                mainControl.parseCommand(nextLine);
            fin.close();
        }
    }
    return 0;
}
