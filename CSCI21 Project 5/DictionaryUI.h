/**
 * CLASS NAME:          DictionaryUI
 * CLASS DESCRIPTION:   ---
 *
 * PROGRAMMER NAME:     Nicholas J. Solwick
 * Date created:        5/06/2012
 * Last date modified:  5/18/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#pragma once
#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#include "Word.h"

using namespace std;

/**
 *   ---
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

class DictionaryUI
{
    public:

        static void print(Word w, int tabs);

        DictionaryUI();

        void interpret(string newText);

        void clearScreen();

        void mainMenu();

    private:

        Dictionary* aTree;

};
