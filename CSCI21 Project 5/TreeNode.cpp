#include "TreeNode.h"

TreeNode::TreeNode()
{
    left = NULL;
    right = NULL;
    data = 0;
}

TreeNode* TreeNode::getLeft()


void TreeNode::setLeft(TreeNode* newLeft)
{
    left = newLeft;
}

TreeNode* TreeNode::getRight()
{
    return right;
}

void TreeNode::setRight(TreeNode* newRight)
{
    right = newRight;
}

int TreeNode::getData()
{
    return data;
}

void TreeNode::setData(int newData)
{
    data = newData;
}
