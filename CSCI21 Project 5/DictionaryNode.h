/**
 * CLASS NAME:          DictionaryNode
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
#include "Word.h"


using namespace std;

/**
 *   ---
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

template <class T>
class DictionaryNode
{
    public:

        DictionaryNode(T newData)
        : data(newData), left(NULL), right(NULL)
        {
        }

        void setLeft(DictionaryNode* newLeft)
        {
            left = newLeft;
        }

        void setRight(DictionaryNode* newRight)
        {
            right = newRight;
        }

        DictionaryNode* getLeft() const
        {
            return left;
        }

        DictionaryNode*& getLeft()
        {
            return left;
        }

        DictionaryNode* getRight() const
        {
            return right;
        }

        DictionaryNode*& getRight()
        {
            return right;
        }

        T getData() const
        {
            return data;
        }

        T& getData()
        {
            return data;
        }

        void setData(T newData)
        {
            data = newData;
        }

    private:

        T data;
        DictionaryNode* left;
        DictionaryNode* right;
};
