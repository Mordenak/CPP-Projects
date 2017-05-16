#include "Dictionary.h"

Dictionary::Dictionary()
{
    root = NULL;
    treeSize = 0;
}

int Dictionary::getSize()
{
    return treeSize;
}

void Dictionary::insert(Word mWord)
{
    insert (mWord, root);
}

void Dictionary::insert(Word mWord, DictionaryNode<Word>*& findNode)
{
    if (findNode == NULL)
    {
        findNode = new DictionaryNode<Word>(mWord);
        treeSize++;
    }
    else if (mWord < findNode->getData())
        insert(mWord, findNode->getLeft());
    else if (mWord > findNode->getData())
        insert(mWord, findNode->getRight());
    else if (mWord == findNode->getData())
        ++findNode->getData();
}

bool Dictionary::bst_remove(Word& targetWord)
{
    return (bst_remove(root, targetWord));
}

bool Dictionary::bst_remove(DictionaryNode<Word>*& findNode, Word& targetWord) // const problem here
{
    if (findNode != NULL)
    {
        if (targetWord < findNode->getData())
            return bst_remove(findNode->getLeft(), targetWord);
        else if (targetWord > findNode->getData())
            return bst_remove(findNode->getRight(), targetWord);
        else
        {
            if (findNode->getLeft() != NULL)
            {
                DictionaryNode<Word>* temp = findNode;
                findNode = findNode->getRight();
                delete temp;
                treeSize--;
            }
            else
            {
                bst_remove_max(findNode->getLeft(), findNode->getData());
            }
            return true;
        }
    }
}

void Dictionary::bst_remove_max(DictionaryNode<Word>*& findNode, Word& targetWord)
{
    if (findNode->getRight() == NULL)
    {
        DictionaryNode<Word>* temp = findNode;
        targetWord = findNode->getData();
        findNode = findNode->getLeft();
        delete temp;
        treeSize--;
    }
    else
    {
        bst_remove_max(findNode->getRight(), targetWord);
    }
}

int Dictionary::wordCount(Word searchWord)
{
    int temp = 0;
    return wordCount(root, searchWord, temp);
}

int Dictionary::wordCount(DictionaryNode<Word>*& findNode, Word searchWord, int& tempCount)
{
    if (findNode != NULL)
    {
        tempCount = wordCount(findNode->getLeft(), searchWord, tempCount);
        if (searchWord == findNode->getData())
        {
            tempCount += findNode->getData().getCount();
        }
        tempCount = wordCount(findNode->getRight(), searchWord, tempCount);
    }
    return tempCount;
}

void Dictionary::clear()
{
    clear(root);
}

void Dictionary::clear(DictionaryNode<Word>*& someNode)
{
    if (someNode != NULL)
    {
        clear(someNode->getLeft());
        clear(someNode->getRight());
        delete someNode;
        someNode = NULL;
    }
}

void Dictionary::printInorder()
{
    printInorder(root);
}

void Dictionary::printInorder(DictionaryNode<Word>* findNode)
{
    if (findNode != NULL)
    {
            printInorder(findNode->getLeft());
            cout << " " << findNode->getData().getWord() << "(" << findNode->getData().getCount() << ") ";
            printInorder(findNode->getRight());
    }
}

void Dictionary::printReverse()
{
    printReverse(root);
}

void Dictionary::printReverse(DictionaryNode<Word>* findNode)
{
    if (findNode != NULL)
    {
            printInorder(findNode->getRight());
            cout << " " << findNode->getData().getWord() << "(" << findNode->getData().getCount() << ") ";
            printInorder(findNode->getLeft());
    }
}

void Dictionary::printAll()
{
    posNumber = 0;
    printAll(root);
}

void Dictionary::printAll(DictionaryNode<Word>* findNode)
{
    if (findNode != NULL)
    {
        printAll(findNode->getLeft());
        cout << findNode->getData().getWord() << endl;
        posNumber++;
        if (posNumber % 10 == 0)
        {
            cout << "Press ENTER to continue\n";
            string trash;
            getline(cin, trash);
        }
        printAll(findNode->getRight());
    }
}

void Dictionary::showStructure (void (*f)(Word, int))
{
	showStructure(root, f, 0);
}

void Dictionary::showStructure (DictionaryNode<Word>* someNode, void (*f)(Word, int), int depth)
{
	if (someNode != NULL)
	{
		showStructure(someNode->getRight(), f, depth+1);
		f(someNode->getData(), depth);
		showStructure(someNode->getLeft(), f, depth+1);
	}
}
