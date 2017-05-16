/**
 * CLASS NAME:          Node
 * CLASS DESCRIPTION:   This class contains the data members necessary for use in the LinkedList class. It
 *                      represents the nodes in a doubly linked list.
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
#include <string>

using namespace std;

/**
 *   A class for handling Nodes of a doubly Linked List.  Node has functions to access and mutate its
 *   member variable, which is a templated type allowing the user to choose which data type to use.
 *   @author Nicholas J. Solwick
 *   @version 1.0
 */

template <class T>
class Node
{
    public:
        /**
         *  Constructor.
         *  Initializes data members to the following values:
         *  <ul>
         *  <li>next = NULL;</li>
         *  <li>prev = NULL;</li>
         *  </ul>
         */
        Node()
        {
            next = NULL;
            prev = NULL;
        }

        /**
         *  Overloaded Constructor.
         *  Initializes the data members according to the parameter newData.
         * @param newData is the templated type being passed into be set as the data member variable
         */
        Node(T newData)
        {
            data = newData;
        }

        /**
         *  Destructor.
         *  The Node class performs no dynamic memory allocation, however destructor provided for thoroughness.
         */
        ~Node()
        {
        }

        /**
         *  Sets the next member variable to the parameter newNext which is a templated Node type.
         * @param newNext is the templated Node type pointer that will be stored in the next member variable
         */
        void setNext(Node<T>* newNext)
        {
            next = newNext;
        }

        /**
         *  Sets the prev member variable to the parameter newPrev which is a templated Node type.
         * @param newPrev is the templated Node type pointer that will be stored in the prev member variable
         */
        void setPrev(Node<T>* newPrev)
        {
            prev = newPrev;
        }

        /**
         *  Sets the data member variable to the parameter newData which is a templated type.
         * @param newData is the templated type that will be stored in the data member variable
         */
        void setData(T newData)
        {
            data = newData;
        }

        /**
         *  Returns the value in the next member variable, which should be a Node pointer.
         * @return a pointer to a Node object
         */
        Node* getNext()
        {
            return next;
        }

        /**
         *  Returns the value in the prev member variable, which should be a Node pointer.
         * @return a pointer to a Node object
         */
        Node* getPrev()
        {
            return prev;
        }

        /**
         *  Returns the value in the data member variable, which is a templated type.
         * @return the templated type in the member variable data
         */
        T getData()
        {
            return data;
        }

    private:

        T data; // the "data" of the Node
        Node<T>* next; // the pointer to the "next" Node in the list
        Node<T>* prev; // the pointer to the "previous" Node in the list
};
