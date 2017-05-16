/**
 * CLASS NAME:          Word
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
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 *   ---
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

class Word
{
    public:

        Word(string newWord);

        string getWord();

        void setWord(string newWord);

        int getCount();

        bool operator> (const Word& src);

        bool operator< (const Word& src);

        bool operator== (const Word& src);

        Word& operator++ ();

    private:

        string word;
        int count;
};
