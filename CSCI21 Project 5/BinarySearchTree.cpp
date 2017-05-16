#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
    treeSize = 0;
}

int BinarySearchTree::getSize()
{
    return treeSize;
}

void BinarySearchTree::newNode(int newData)
{
    TreeNode<int>* temp = new TreeNode<int>;
    TreeNode<int>* parent;
    temp->setData(newData);
    temp->setLeft(NULL);
    temp->setRight(NULL);

    if (root != NULL)
    {
        TreeNode<int>* curr;
        curr = root;
        while (curr)
        {
            parent = curr;
            if (temp->getData() > curr->getData())
                curr = curr->getRight();
            else
                curr = curr->getLeft();
        }

        if (temp->getData() < parent->getData())
            parent->setLeft(temp);
        else
            parent->setRight(temp);

        cout << "NEW NODE ADDED\n";
        treeSize++;
    }
    else
    {
        root = temp;
        cout << "NEW NODE ADDED\n";
        treeSize++;
    }
}




void BinarySearchTree::print_inorder()
{
    inorder(root);
}

void BinarySearchTree::inorder(TreeNode<int>* p)
{
    if (p != NULL)
    {
        if (p->getLeft())
            inorder(p->getLeft());
        cout << " " << p->getData() << " ";
        if (p->getRight())
            inorder(p->getRight());
    }
}
