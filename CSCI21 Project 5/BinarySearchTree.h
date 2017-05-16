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
#include <cstdlib>
#include "TreeNode.h"

using namespace std;

/**
 *   ---
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

class BinarySearchTree
{
    public:

        BinarySearchTree();

        void newNode(int newData);

        void print_inorder();

        void inorder(TreeNode<int>* p);

        int getSize();


    private:

        TreeNode<int>* root;
        int treeSize;
};
