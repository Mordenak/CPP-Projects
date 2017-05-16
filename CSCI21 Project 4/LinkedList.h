/**
 * CLASS NAME:          LinkedList
 * CLASS DESCRIPTION:   This class provides the structure of a doubly linked list, using the Node class.
 *
 * PROGRAMMER NAME:     Nicholas J. Solwick
 * Date created:        4/10/2012
 * Last date modified:  5/04/2012
 *
 * SOURCES USED
 *      "Absolute C++", Walter Savitch
 *      Boyd Trolinger
 *      cplusplus.com
 */

#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

/**
 *   A class for managing a doubly Linked List.  LinkedList provides functions to manipulate a doubly linked
 *   list as follows: push back, push front, insert, retrieve, remove, eliminate, remove front, remove back,
 *   clear, print, and size.
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

template <class T>
class LinkedList
{
    public:
        /**
         *  Constructor.
         *  Initializes data members to the following values:
         *  <ul>
         *  <li>text = "";</li>
         *  <li>priority = 1;</li>
         *  <li>completed = false;</li>
         *  </ul>
         */
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        /**
         *  Destructor.
         *  Deletes the following data members:
         *  <ul>
         *  <li>head</li>
         *  <li>tail</li>
         *  <li>All nodes between head and tail</li>
         *  </ul>
         */
        ~LinkedList()
        {
            while (head != NULL)
            {
                if (head != NULL)
                {
                    Node<T>* temp = tail;
                    if (tail->getPrev() != NULL)
                    {
                        tail = tail->getPrev();
                        tail->setNext(NULL);
                        delete temp;
                    }
                    else
                    {
                        delete head;
                        delete tail;
                        head = NULL;
                        tail = NULL;
                    }
                }
            }
        }

        /**
         *  This function provides the ability to add Nodes to the back of the Linked List.
         * @param newData is the templated type that will be inserted into the Node being added to the back of the list
         * @return a bool which will be true if the node was added correctly or false if it did not
         */
        bool pushBack(T newData)
        {
            Node<T>* tempNode = new Node<T>;
            tempNode->setData(newData);
            tempNode->setNext(NULL);
            if (head == NULL)
            {
                head = tempNode;
                tail = tempNode;
                tempNode->setPrev(NULL);
                return true;
            }
            else
            {
                Node<T>* finder = head;
                while (finder->getNext() != NULL)
                    finder = finder->getNext();
                finder->setNext(tempNode);
                tempNode->setPrev(finder);
                tail = tempNode;
                return true;
            }
            return false;
        }

        /**
         *  This function provides the ability to add Nodes to the front of the Linked List.
         * @param newData is the templated type that will be inserted into the Node being added to the front of the list
         * @return a bool which will be true if the node was added correctly or false if it did not
         */
        bool pushFront(T newData)
        {
            Node<T>* tempNode = new Node<T>;
            tempNode->setData(newData);
            tempNode->setPrev(NULL);
            if (head == NULL)
            {
                head = tempNode;
                tail = tempNode;
                tempNode->setNext(NULL);
                return true;
            }
            else
            {
                Node<T>* finder = head;
                finder->setPrev(tempNode);
                tempNode->setNext(finder);
                head = tempNode;
                return true;
            }
            return false;
        }

        /**
         *  This function provides the ability to insert Nodes to the list in an ascending order.
         * @param newData is the templated type that will be inserted into the Node being inserted into the list
         * @return a bool which will be true if the node was added correctly or false if it did not
         */
        bool insertElement(T newData)
        {
            Node<T>* insertNode = new Node<T>;
            insertNode->setData(newData);
            if (head != NULL)
            {
                Node<T>* tempNode = new Node<T>;
                tempNode = head;
                while (tempNode->getNext() != NULL)
                {
                    if (newData > tempNode->getData())
                        tempNode = tempNode->getNext();
                    else if (tempNode == head)
                        return (pushFront(newData));
                    else
                    {
                        tempNode->getPrev()->setNext(insertNode);  // hook up temp->getPrev() to it's next as insertNode
                        insertNode->setPrev(tempNode->getPrev());  // set insertNode's prev to tempNode's prev
                        tempNode->setPrev(insertNode);             // set tempNode's prev to insertNode
                        insertNode->setNext(tempNode);             // set insertNode's next to tempNode'
                        return true;
                    }
                }
                if (tempNode == tail && getSize() > 1) // do this check on the size to ensure you're not trying to access a NULL pointer
                {
                    if (newData < tail->getData())
                    {
                        insertNode->setPrev(tempNode->getPrev()); // this algorithm will not work if you have 1 element
                        insertNode->setNext(tempNode);
                        tempNode->getPrev()->setNext(insertNode);
                        tempNode->setPrev(insertNode);
                        return true;
                    }
                    else
                        return (pushBack(newData));
                }
                else
                {
                    if (newData < head->getData())
                        return (pushFront(newData));
                    else
                        return (pushBack(newData));
                }
            }
            else
                return (pushFront(newData));
            return false;
        }

        /**
         *  This function will search the Linked List for a match to the data member variable.
         * @param searchData is the templated type that will be compared to the data of the Nodes in the List
         * @return a bool which will be true if the value was found, or false if it was not
         */
        bool retrieveElement(T searchData)
        {
            Node<T>* tempNode = head;
            if (head != NULL)
            {
                if (searchData == head->getData())
                    return true;
                else if (searchData == tail->getData())
                    return true;
                else
                {
                    while (tempNode->getNext() != NULL)
                    {
                        if (tempNode->getData() != searchData)
                            tempNode = tempNode->getNext();
                        else
                            return true;
                    }
                }
            }
            return false;
        }

        /**
         *  This function provides the ability to remove Nodes from the list based on their data member's value.
         * @param removeData is the data of the Node to be found and removed from the list
         * @return a bool which will be true if the node was removed correctly, or false if it did not
         */
        bool removeElement(T removeData)
        {
            Node<T>* tempNode = head;
            if (head != NULL)
            {
                if (removeData == head->getData())
                    return (removeFront());
                else if (removeData == tail->getData())
                    return (removeBack());
                else
                {
                    while (tempNode->getNext() != NULL)
                    {
                        if (tempNode->getData() != removeData)
                            tempNode = tempNode->getNext();
                        else
                        {
                            tempNode->getNext()->setPrev(tempNode->getPrev());
                            tempNode->getPrev()->setNext(tempNode->getNext());
                            delete tempNode;
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        /**
         *  This function is similar to the remove function, however it will remove all occurences of the value
         *  of removeData.
         * @param removeData is the value of the Node(s) to be found and removed from the list.
         * @return a bool which will be true if any number of Nodes were removed, or false if none were removed.
         */
        bool eliminateData(T removeData)
        {
            bool dataFound = false;
            for (int i = 0;i != getSize();i++)
            {
                if (removeElement(removeData))
                {
                    i--;
                    dataFound = true;
                }
            }
            if (dataFound != true)
                return false;
            else
                return true;
        }

        /**
         *  This function provides the ability to remove the first Node in the linked list.
         * @return a bool which will be true if the first node was removed successfully or false otherwise.
         */
        bool removeFront()
        {
            Node<T>* temp = head;
            if (head->getNext() != NULL)
            {
                head = head->getNext();
                head->setPrev(NULL);
                delete temp;
                return true;
            }
            else
            {
                delete head;
                head = NULL;
                tail = NULL;
                return true;
            }
            return false;
        }

        /**
         *  This function provides the ability to remove the last Node in the linked list.
         * @return a bool which will be true if the last node was removed successfully or false otherwise.
         */
        bool removeBack()
        {
            Node<T>* temp = tail;
            if (tail->getPrev() != NULL)
            {
                tail = tail->getPrev();
                tail->setNext(NULL);
                delete temp;
                return true;
            }
            else
            {
                delete tail;
                head = NULL;
                tail = NULL;
                return true;
            }
            return false;
        }

        /**
         *  This function provides the ability to remove all the Nodes in the list with one function call.
         * @return a bool which will be true if successful or false if it failed
         */
        bool clearList()
        {
            while (head != NULL)
            {
                if (head != NULL)
                {
                    Node<T>* temp = tail;
                    if (tail->getPrev() != NULL)
                    {
                        tail = tail->getPrev();
                        tail->setNext(NULL);
                        delete temp;
                    }
                    else
                    {
                        delete tail;
                        head = NULL;
                        tail = NULL;
                    }
                }
                else
                    return false;
            }
            return true;
        }

        /**
         *  This function will simply display the contents of the Linked List by iterating through the Nodes.
         */
        void printList()
        {
            Node<T>* finder = head;
            while (finder != NULL)
            {
                cout << finder->getData() << " ";
                finder = finder->getNext();
            }
            cout << endl;
        }

        /**
         *  This function will count the number of Nodes that are attached to the list and return the number.
         * @return an int which will contain the number of the Nodes in the Linked List
         */
        int getSize()
        {
            int counter = 0;
            Node<T>* finder = head;
            while (finder != NULL)
            {
                finder = finder->getNext();
                counter++;
            }
            return counter;
        }

        /**
         *  This function will simply return the head member variable pointer.
         * @return a pointer from the head member variable
         */
        Node<T>* getHead()
        {
            return head;
        }

    private:

        Node<T>* head; // the first Node of the Linked List - a sentinel
        Node<T>* tail; // the last Node of the Linked List - a sentinel
};
