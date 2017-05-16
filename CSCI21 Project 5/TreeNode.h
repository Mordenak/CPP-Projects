/**
 * CLASS NAME:          ---
 * CLASS DESCRIPTION:   ---
 *
 * PROGRAMMER NAME:     Nicholas J. Solwick
 * Date created:        5/06/2012
 * Last date modified:  5/06/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#pragma once
#include <iostream>

using namespace std;

/**
 *   ---
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

template <class T>
class TreeNode
{
    public:

        TreeNode()
        {
            left = NULL;
            right = NULL;
            data = 0;
        }

        TreeNode* getLeft()
        {
            return left;
        }


        void setLeft(TreeNode* newLeft)
        {
            left = newLeft;
        }

        TreeNode* getRight()
        {
            return right;
        }

        void setRight(TreeNode* newRight)
        {
            right = newRight;
        }

        T getData()
        {
            return data;
        }

        void setData(T newData)
        {
            data = newData;
        }

    private:

        TreeNode* left;
        TreeNode* right;
        T data;
};
