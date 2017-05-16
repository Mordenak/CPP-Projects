/**
 * CLASS NAME:          Dictionary
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
#include "DictionaryNode.h"


using namespace std;

/**
 *   ---
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

class Dictionary
{
    public:

        Dictionary();

        void insert(Word mWord);

        bool bst_remove(Word& targetWord);

        int wordCount(Word searchWord);

        void printInorder();

        void printReverse();

        void printAll();

        int getSize();

        void clear();

        void showStructure (void (*f)(Word, int));

    private:

        DictionaryNode<Word>* root;

        int posNumber;

        int treeSize;

        void insert(Word mWord, DictionaryNode<Word>*& findNode);

        bool bst_remove(DictionaryNode<Word>*& findNode, Word& targetWord); // const problem here

        void bst_remove_max(DictionaryNode<Word>*& findNode, Word& targetWord);

        int wordCount(DictionaryNode<Word>*& findNode, Word searchWord, int& tempCount);

        void clear(DictionaryNode<Word>*& someNode);

        void printInorder(DictionaryNode<Word>* findNode);

        void printReverse(DictionaryNode<Word>* findNode);

        void printAll(DictionaryNode<Word>* findNode);

        void showStructure (DictionaryNode<Word>* someNode, void (*f)(Word, int), int depth);
};
