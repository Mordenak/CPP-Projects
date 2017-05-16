#include "Controller.h"

Controller::Controller()
{
    cList = NULL;
    cVector = NULL;
}

void Controller::parseCommand(string input)
{
    string cCommand;
    string cTarget;
    int cmdData = 0;

    if (input[0] != '#')
    {
        if(input.length() == 3)
        {
            cTarget = input[2];
            cCommand = input[0];
        }
        else if(input.length() > 3)
        {
            cTarget = input[2];
            cCommand = input[0];

            int dataPos = 4; //First postion of the data to be extracted within the string
            ostringstream extractData;
            for(unsigned int i = dataPos;i < input.length();i++)
            {
                extractData << input[i];
            }
            istringstream(extractData.str()) >> cmdData;
        }

        if (cTarget == "V")
        {
            if (cCommand == "C")
            {
                cVector = new vector<int>;
                cout << "VECTOR CREATED\n";
            }
            if (cVector != NULL)
            {
                if (cCommand == "L")
                {
                    cVector->clear();
                    cout << "VECTOR CLEARED\n";
                }
                else if (cCommand == "D")
                {
                    delete cVector;
                    cVector = NULL;
                    cout << "VECTOR DELETED\n";
                }
                else if (cCommand == "A")
                {
                    cVector->push_back(cmdData);
                    cout << "VALUE " << cmdData << " ADDED\n";
                }
                else if (cCommand == "E")
                {
                    bool valueFound = false;
                    for (vector<int>::iterator i = cVector->begin();i != cVector->end();i++)
                    {
                        if ((*i) == cmdData)
                        {
                            cVector->erase(i);
                            valueFound = true;
                            i--;
                        }
                    }
                    if (valueFound != false)
                        cout << "VALUE " << cmdData << " ELIMINATED\n";
                    else
                        cout << "VALUE " << cmdData << " NOT FOUND\n";
                }
                else if (cCommand == "R")
                {
                    int counter = 0;
                    vector<int>::iterator iter = cVector->begin();
                    if (cmdData > 0 && cmdData < cVector->size())
                    {
                        for (int i = 0;i != cmdData;i++)
                        {
                            counter++;
                            iter++;
                        }
                        cVector->erase(iter);
                        cout << "VALUE AT " << counter << " REMOVED\n";
                    }
                    else
                        cout << "INVALID REMOVAL INDEX " << cmdData << endl;
                }
                else if (cCommand == "G")
                {
                    if (cmdData > 0 && cmdData < cVector->size())
                        cout << "VALUE AT " << cmdData << " IS " << (*cVector)[cmdData] << endl;
                    else
                        cout << "INVALID GET INDEX " << cmdData << endl;
                }
                else if (cCommand == "N")
                {
                    cout << "VECTOR SIZE IS " << cVector->size() << endl;
                }
                else if (cCommand == "P")
                {
                    if (cVector->size() != 0)
                    {
                        cout << "VECTOR CONTENTS: ";
                        for (vector<int>::iterator i = cVector->begin();i != cVector->end();i++)
                            cout << *i << " ";
                        cout << endl;
                    }
                    else
                        cout << "VECTOR EMPTY\n";
                }
            }
            else
                cout << "MUST CREATE VECTOR INSTANCE\n";
        }
        if (cTarget == "L")
        {
            if (cCommand == "C")
            {
                cList = new LinkedList<int>;
                cout << "LIST CREATED\n";
            }
            else
            {
                if (cList != NULL)
                {
                    if (cCommand == "D")
                    {
                        delete cList;
                        cout << "LIST DELETED\n";
                        cList = NULL;
                    }
                    else if (cCommand == "I")
                    {
                        if (cList->insertElement(cmdData) != false)
                            cout << "VALUE " << cmdData << " INSERTED\n";
                    }
                    else if (cCommand == "F")
                    {
                        if (cList->pushFront(cmdData) != false);
                            cout << "VALUE " << cmdData << " ADDED TO FRONT\n";
                    }
                    else if (cCommand == "B")
                    {
                        if (cList->pushBack(cmdData) != false)
                            cout << "VALUE " << cmdData << " ADDED TO BACK\n";
                    }
                    else if (cCommand == "L")
                    {
                        if (cList->clearList() != false)
                            cout << "LIST CLEARED\n";
                    }
                    else if (cCommand == "E")
                    {
                        if (cList->eliminateData(cmdData) != false)
                            cout << "VALUE " << cmdData << " ELIMINATED\n";
                        else
                            cout << "VALUE " << cmdData << " NOT FOUND\n";
                    }
                    else if (cCommand == "R")
                    {
                        if (cList->removeElement(cmdData) != false)
                            cout << "VALUE " << cmdData << " REMOVED\n";
                        else
                            cout << "VALUE " << cmdData << " NOT FOUND\n";
                    }
                    else if (cCommand == "G")
                    {
                        if (cList->retrieveElement(cmdData) != false)
                            cout << "VALUE " << cmdData << " FOUND\n";
                        else
                            cout << "VALUE " << cmdData << " NOT FOUND\n";
                    }
                    else if (cCommand == "N")
                    {
                        cout << "LIST SIZE IS " << cList->getSize() << endl;
                    }
                    else
                    {
                        if (cList->getHead() != NULL)
                        {
                            if (cCommand == "T")
                            {
                                if (cList->removeFront() != false)
                                    cout << "REMOVED FRONT\n";
                            }
                            else if (cCommand == "K")
                            {
                                if (cList->removeBack() != false)
                                    cout << "REMOVED BACK\n";
                            }

                            else if (cCommand == "P")
                            {
                                cout << "LIST CONTENTS: ";
                                cList->printList();
                            }
                        }
                        else
                            cout << "LIST EMPTY\n";
                    }
                }
                else
                    cout << "MUST CREATE LIST INSTANCE\n";
            }
        }
    }
}
