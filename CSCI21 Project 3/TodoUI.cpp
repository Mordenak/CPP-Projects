#include "TodoUI.h"

TodoUI::TodoUI()
{
    uiTodoList = new TodoList;
}

TodoUI::TodoUI(string fileName)
{
    loadFile(fileName);
}

TodoUI::~TodoUI()
{
    delete uiTodoList;
}

void TodoUI::mainMenu(bool displayHelp)
{
    showArt("artfile.txt");
    pauseClear();
    if (displayHelp == true)
    {
        showHelp();
        pauseClear();
    }
    bool userChoosing = true;
    while (userChoosing != false)
    {
        cout << "Choose an option:\n\n";
        cout << "  [1] Create a new item\n";
        cout << "  [2] Edit an item\n";
        cout << "  [3] Delete an item\n";
        cout << "  [4] View all items\n";
        cout << "  [5] Delete all items\n";
        cout << "  [6] Save list\n";
        cout << "  [7] Retrieve list\n";
        cout << "  [8] Special functions\n\n";
        cout << "  [0] Exit\n\n";
        cout << " > ";
        int userChoice = uiReader.readInt(0,8);
        if (userChoice == 1)
        {
            cout << "Enter the text: ";
            string userString = uiReader.readString();
            cout << "Enter the priority: ";
            int userPriority = uiReader.readInt(1,5);
            TodoItem* newItem = new TodoItem(userString, userPriority);
            uiTodoList->addItem(newItem);
            clearScreen();
        }
        else if (userChoice == 2)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                cout << "Please enter the memo number you wish to edit (0 to exit): ";
                int userEdit = uiReader.readInt(0,uiTodoList->retrieveSize());
                if (userEdit != 0)
                {
                    cout << "You have chosen entry " << userEdit << " to edit.\n\n";
                    cout << *uiTodoList->retrieveItem(userEdit-1);
                    cout << "Please enter a new string (or leave blank to skip): ";
                    string editString = uiReader.readString();
                    if (editString != "")
                        uiTodoList->retrieveItem(userEdit-1)->setText(editString);
                    cout << "Please enter a new priority (0 to skip): ";
                    int editPriority = uiReader.readInt(0,5);
                    if (editPriority != 0)
                        uiTodoList->retrieveItem(userEdit-1)->setPriority(editPriority);
                    cout << "Is this item completed? (Y)es/(N)o: ";
                    char editCompleted = uiReader.readChar("YyNn");
                    if (toupper(editCompleted) == 'Y')
                        uiTodoList->retrieveItem(userEdit-1)->setCompleted(true);
                    else
                        uiTodoList->retrieveItem(userEdit-1)->setCompleted(false);
                }
                clearScreen();
            }
            else
            {
                cout << "There are currently no entries to edit.\n\n";
                pauseClear();
            }
        }
        else if (userChoice == 3)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                cout << "Please enter a memo number to delete (0 to exit): ";
                int deleteChoice = uiReader.readInt(0,uiTodoList->retrieveSize());
                if (deleteChoice != 0)
                {
                    cout << *uiTodoList->retrieveItem(deleteChoice-1);
                    cout << "Are you sure you want to delete memo entry " << deleteChoice << "? (Y)es/(N)o: ";
                    char confirmDelete = uiReader.readChar("YyNn");
                    if (toupper(confirmDelete) == 'Y')
                    {
                        uiTodoList->deleteItem(deleteChoice-1);
                        cout << "Successfully deleted entry " << deleteChoice << ".\n\n";
                        pauseClear();
                    }
                    else
                    {
                        cout << "Aborting deletion...\n\n";
                        pauseClear();
                    }
                }
            }
            else
            {
                cout << "There are currently no entries to delete.\n\n";
                pauseClear();
            }
        }
        else if (userChoice == 4)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                clearScreen();
                uiTodoList->print(cout, screenPause);
                screenPause();
            }
            else
            {
                cout << "There are currently no entries to view.\n\n";
                pauseClear();
            }
        }
        else if (userChoice == 5)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                cout << "You are about to delete ALL entries, continue? (Y)es/(N)o: ";
                char delContinue = uiReader.readChar("YyNn");
                if (toupper(delContinue) != 'N')
                {
                    while (uiTodoList->retrieveSize() > 0)
                        uiTodoList->deleteItem(0);
                    cout << "All items deleted.\n\n";
                    pauseClear();
                }
                else
                    cout << "Aborting deletion...\n\n";
            }
            else
            {
                cout << "There are currently no entries to delete.\n\n";
                pauseClear();
            }
        }
        else if (userChoice == 6)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                cout << "Enter a name for your file (leave blank to exit): ";
                string fileName = uiReader.readString();
                if (fileName != "")
                {
                    if (FooFile::save(fileName, *uiTodoList) == false)
                        cout << "Error in creating the file.\n\n";
                    else
                        cout << "Successfully created, " << fileName << "\n\n";
                }
                else
                    cout << "Aborting save operation...\n\n";
            }
            else
                cout << "There are currently no entries to save.\n\n";
            pauseClear();
        }
        else if (userChoice == 7)
        {
            #ifdef WIN32
            cout << "Available files for loading:\n";
            system("dir /w *.txt");
            #endif
            cout << "\n\nEnter the name of the file you wish to load (leave blank to exit): ";
            string fileToLoad = uiReader.readString();
            if (fileToLoad != "")
            {
                if (fileToLoad.find(".txt") != string::npos)
                {
                    if (uiTodoList->retrieveSize() != 0)
                        while (uiTodoList->retrieveSize() > 0)
                            uiTodoList->deleteItem(0);
                    loadFile(fileToLoad);
                }
                else
                    cout << "This is not a text file.\n\n";
            }
            else
                cout << "Aborting load operation...\n\n";
            pauseClear();
        }
        else if (userChoice == 8)
            specialMenu();
        else if (userChoice == 0)
            userChoosing = false;
    }
}

void TodoUI::specialMenu()
{
    bool userSpecialMenu = true;
    while (userSpecialMenu != false)
    {
        cout << "You currently have " << uiTodoList->retrieveSize() << " entries. " << (uiTodoList->retrieveCapacity() - uiTodoList->retrieveSize())<< " available.\n\n";
        cout << "Choose an option:\n\n";
        cout << "  [1] Search for keyword in entries\n";
        cout << "  [2] Remove entries by keyword\n";
        cout << "  [3] Remove completed items\n";
        cout << "  [4] Advanced sort\n\n";
        cout << "  [0] Back to main menu\n\n";
        cout << " > ";
        int userChoice = uiReader.readInt(0,4);
        if (userChoice == 1)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                bool keywordCheck = false;
                int keywordsFound = 0;
                cout << "Please enter a keyword to search for: ";
                string searchStr = uiReader.readString();
                for (int i = 0;i < uiTodoList->retrieveSize();i++)
                {
                    if (uiTodoList->retrieveItem(i)->hasKeyword(searchStr) != false)
                    {
                        keywordCheck = true;
                        keywordsFound++;
                        cout << "Found in entry: " << i+1 << endl;
                        cout << *uiTodoList->retrieveItem(i);
                        if (keywordsFound % 4 == 0)
                            screenPause();
                    }
                }
                if (keywordCheck == false)
                    cout << "Keyword not found.\n\n";
                pauseClear();
            }
            else
            {
                cout << "There are no entries to search through.\n\n";
                pauseClear();
            }
        }
        else if (userChoice == 2)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                bool keywordCheck = false;
                int keywordsFound = 0;
                cout << "Please enter a keyword to search for: ";
                string searchStr = uiReader.readString();
                for (int i = 0;i < uiTodoList->retrieveSize();i++)
                {
                    if (uiTodoList->retrieveItem(i)->hasKeyword(searchStr) != false)
                    {
                        keywordCheck = true;
                        keywordsFound++;
                        cout << "Found in entry: " << i+1 << endl;
                        cout << *uiTodoList->retrieveItem(i);
                        if (keywordsFound % 4 == 0)
                            screenPause();
                    }
                }
                if (keywordCheck == false)
                    cout << "Keyword not found.\n\n";
                else
                {
                    if (keywordsFound != 1)
                        cout << "Are you sure you want to delete these entries? (Y)es/(N)o";
                    else
                        cout << "Are you sure you want to delete this entry? (Y)es/(N)o";
                    char userRemove = uiReader.readChar("YyNn");
                    if (toupper(userRemove) != 'N')
                    {
                        cout << "\n";
                        for (int i = 0;i < uiTodoList->retrieveSize();i++)
                            if (uiTodoList->retrieveItem(i)->hasKeyword(searchStr) != false)
                                uiTodoList->deleteItem(i);
                        cout << "Successfully removed ";
                        if (keywordsFound != 1)
                            cout << keywordsFound << " entries.\n\n";
                        else
                            cout << keywordsFound << " entry.\n\n";
                        pauseClear();
                    }
                    else
                        cout << "Aborting deletion...\n\n";
                }
            }
            else
            {
                cout << "There are no entries to search through.\n\n";
                pauseClear();
            }
        }
        else if (userChoice == 3)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                int deletedItems = 0;
                cout << "Removing completed items...\n\n";
                for (int i = 0;i < uiTodoList->retrieveSize();i++)
                {
                    for (int x = 0;x < uiTodoList->retrieveSize();x++)
                    {
                        if (uiTodoList->retrieveItem(x)->getCompleted() != false)
                        {
                            uiTodoList->deleteItem(x);
                            deletedItems++;
                        }
                    }
                }
                cout << "Deleted " << deletedItems << " item(s).\n\n";
            }
            else
                cout << "There are no entries to remove.\n\n";
            pauseClear();
        }
        else if (userChoice == 4)
        {
            if (uiTodoList->retrieveSize() != 0)
            {
                cout << "Initiating advanced sort...\n\n";
                uiTodoList->advancedSort();
            }
            else
                cout << "There are no entries to run the advanced sort on.\n\n";
            pauseClear();
        }
        else if (userChoice == 0)
            userSpecialMenu = false;
    }
}

void TodoUI::loadFile(string fileName)
{
    uiTodoList = new TodoList;
    int count = 0;
    TodoItem** newList = FooFile::load(fileName, count);
    for (int i = 0;i < count;i++)
        uiTodoList->addItem(newList[i]);
    cout << "Successfully loaded " << fileName << "...\n\n";
    delete [] newList;
}

void TodoUI::showHelp()
{
    cout << " ------------------------------------------------------------------------------\n";
    cout << "\t\t\t    Todo-List Planner Help\n\n";
    cout << " This program simulates a todo-list planner. You will be able to manipulate the\n";
    cout << "list via the menu options.  You are also able to load files into the program\n";
    cout << "but please make sure they are properly formatted, else your data may not be\n";
    cout << "correct. You may also save a list for later use by specifying a name with a\n";
    cout << ".txt extension.\n\n";
    cout << " The special menu will provide you with additional options to sort your list\n";
    cout << "and remove completed items, or remove items by text.  As well as the option to\n";
    cout << "search your list for keywords for ease of access.\n\n\n";
}

void TodoUI::showArt(string artfile)
{
    ifstream fin(artfile.c_str());
    if (!fin.bad())
    {
        char nextchar = fin.get();
        while (nextchar != EOF)
        {
            cout << nextchar;
            nextchar = fin.get();
        }
        fin.close();
    }
    cout << "\n\n";
}

void TodoUI::pauseClear()
{
    screenPause();
    clearScreen();
}

void screenPause()
{
    CinReader uiReader;
    cout << "Please press ENTER to continue...";
    uiReader.readString();
}

void TodoUI::clearScreen()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
}
