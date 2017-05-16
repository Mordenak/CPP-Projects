#include "DictionaryUI.h"

DictionaryUI::DictionaryUI()
{
    aTree = new Dictionary;
}

void DictionaryUI::interpret(string newText)
{
    for (int i = 0;i < newText.length();i++)
    {
        if(ispunct(newText[i]))
        {
            newText.erase(i,1);
        }
    }
    Word newWord(newText);
    aTree->insert(newWord);
}

void DictionaryUI::mainMenu()
{
    cout << "Welcome\n";
    int userChoice = 0;
    bool userChoosing = true;
    while (userChoosing != false)
    {
        cout << "\nTree size is " << aTree->getSize() << endl;
        cout << "Please choose an option:\n\n";
        cout << "\t[1] - Locate a word and display it's count\n";
        cout << "\t[2] - Locate a word and remove it\n";
        cout << "\t[3] - Display all words\n";
        cout << "\t[4] - Display all words starting with a certain letter\n\n";
        cout << "\t[0] - Exit the program.\n";
        cin >> userChoice;
        cin.ignore(256, '\n');
        if (userChoice == 1)
        {
            cout << "Please enter the word you would like to search for: ";
            string userInput;
            getline(cin, userInput);
            Word temp(userInput);
            if (aTree->wordCount(temp) != 0)
                cout << userInput << " found " << aTree->wordCount(temp) << " times.\n";
            else
                cout << userInput << " not found.\n";
        }
        else if (userChoice == 2)
        {
            cout << "Please enter the word to delete: ";
            string userInput;
            getline(cin, userInput);
            Word temp(userInput);
            if (aTree->bst_remove(temp) != false)
                cout << userInput << " removed properly.\n";
            else
                cout << userInput << " not found.\n";
        }
        else if (userChoice == 3)
        {
            aTree->printAll();
        }
        else if (userChoice == 4)
        {
            // Unfinished
        }
        else if (userChoice == 0)
        {
            userChoosing = false;
        }
        else
        {
            clearScreen();
            cout << "Not a valid choice, try again.\n";
        }
    }
}

void DictionaryUI::print (Word w, int tabs)
{
	for (int i=0; i<tabs; i++)
		cout << "        ";
	cout << tabs << w.getWord() << endl;
}

void DictionaryUI::clearScreen()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
}
