/**
 * PROGRAM NAME:            Text Parser
 * PROGRAM DESCRIPTION:     ---
 *
 * PROGRAMMER NAME:         Nicholas J. Solwick
 * Date created:            5/06/2012
 * Last date modified:      5/18/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "DictionaryUI.h"

using namespace std;

int main(int argc, char** argv)
{
    DictionaryUI* mainUI = new DictionaryUI;

    if (argc != 2)
        cout << "USAGE: test.exe FILENAME";
    else
    {
        string nextLine;
        string file = argv[1];
        ifstream fin(file.c_str());
        if(!fin.fail())
        {
            cout << "Successfully loaded " << file << endl;
            while(fin >> nextLine)
            {
                mainUI->interpret(nextLine);
            }
            fin.close();
        }
    }

    mainUI->mainMenu();

    return 0;
}
