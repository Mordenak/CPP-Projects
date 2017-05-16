/*
 * String and Number cruncer
 * This program will take input from the user in the form of a string and 5 integers and then process the input in various ways.
 *
 * Nicholas J. Solwick
 * Date created: 1/24/2012
 * Last date modified: 2/10/2012
 *
 * SOURCES USED
 */

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
 * This is the stringCount function which is used to count the number of
 * alphabetic and numeric characters in a string.
 * @param countString is the string being passed into the function
 * @param alphaCount is the integer being passed to count alphabetic characters
 * @param digitCount is the integer being passed to count numeric characters
 */
void stringCount(string countString, int& alphaCount, int& digitCount);

/*
 * This is the chaosCase function which alternates the case of each character of
 * the string that is passed into it.
 * @param alterString is the string being passed into the function to be altered
 * @return the string after it is altered by the function
 */
string chaosCase(string alterString);

/*
 * This is the wordCount function which counts how many words are in the string
 * being passed into the function, by counting the number of space characters.
 * @param countString is the string being passed into the function
 * @return an int that is the number of "words" found
 */
int wordCount(string countString);

/*
 * This is the averageNum function which averages the integers in an array.
 * @param numArray[] is the array being passed into the function
 * @param sizeOfArray is the size of the array being passed into the function
 * @return a double that contains the average of the array of ints
 */
double averageNum(int numArray[], int sizeOfArray);

/*
 * This is the lowValue function which finds the lowest value in an array of
 * integers.
 * @param numArray[] is the array being passed into the function
 * @param sizeOfArray is the size of the array being passed into the function
 * @return an int which contains the lowest value evaluated
 */
int lowValue(int numArray[], int sizeOfArray);

/*
 * This is the highValue function which finds the highest value in an array of
 * integers.
 * @param numArray[] is the array being passed into the function
 * @param sizeOfArray is the size of the array being passed into the function
 * @return an int which contains the highest value evaluated
 */
int highValue(int numArray[], int sizeOfArray);

/*
 * This is the isPrime function which determines whether an integer is a prime
 * number or not.
 * @param userInt is the integer being passed into the function to be checked
 * @return a bool which will be true if the number is prime, false otherwise
 */
bool isPrime(int userInt);

/*
 * This is the findChar function which searches a string for a user defined
 * character and returns the number of times that character was found.
 * @param userString the string being passed into the function to be checked
 * @param searchChar is the user entered character to search the string for
 * @return an int that contains the number of times searchChar was found
 */
int findChar(string userString, char searchChar);

/*
 * This is the charCount function which finds the most common character in a
 * string.
 * @param userString is the string being passed into the function
 * @return a char which contains the most common character in the string
 */
char charCount(string userString);

/*
 * This is the wordReplace function which replaces a word in a string with
 * another user inputed string.
 * @param userString is the string that will have a piece replaced
 * @param findString is the word in userString that will be replaced
 * @param replaceString is the word that will replace findString in userString
 * @return a string which will contain the new string
 */
string wordReplace(string userString, string findString, string replaceString);

/*
 * This is a simple welcomeHeader function which displays the function name at
 * the top of the console.
 */
void welcomeHeader();

/*
 * This is a simple function to clear the screen.
 */
void clearScreen();

/*
 * This is the program's main function/entry point.
 */
int main()
{
	const int arraySize = 5;
	string userString;
	char userContinue = 'z';
	int userNumbers[arraySize];
	int alphaCount = 0;
	int digitCount = 0;
	bool userQuit = false;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	while (userQuit != true)
	{
		alphaCount = 0;
		digitCount = 0;
		clearScreen();
		welcomeHeader();
		cout << "   Welcome! First I will need you to please enter a string:\n> ";
		getline (cin, userString);
		cout << "Your string was: " << userString << "\n";

		cout << "Please fill an array of 5 integers, one at a time,\n";
		for (int i = 0;i < arraySize;i++)
		{
			cout << "Number " << (i+1) << ": ";
			cin >> userNumbers[i];
		}
		cout << "The integers you entered were: ";
		for (int i = 0;i < arraySize;i++)
		{
			if (i != (arraySize - 1 ))
				cout << userNumbers[i] << ", ";
			else
				cout << userNumbers[i] << "\n";
		}
		
		clearScreen();
		welcomeHeader();
		stringCount(userString, alphaCount, digitCount);
		cout << "There were " << alphaCount << " alphabetic characters in your string.\n";
		cout << "There were " << digitCount << " digits in your string.\n";
		
		cout << "The chaos case of your string earlier is: " << chaosCase(userString) << endl;
		
		cout << "The number of words in your string is: " << wordCount(userString) << endl;
		
		cout << "The average of your array of integers is: " << averageNum(userNumbers, arraySize) << endl;
		
		cout << "The lowest value you entered was: " << lowValue(userNumbers, arraySize) << endl;
		
		cout << "The highest value you entered was: " << highValue(userNumbers, arraySize) << endl;
		
		for (int i = 0;i < arraySize;i++)
		{
			if (isPrime(userNumbers[i]) == true)
				cout << userNumbers[i] << " is a prime.\n";
			else
				cout << userNumbers[i] << " is not a prime.\n";
		}
		
		string trash;
		cin.ignore(256,'\n');
		cout << "\n                              Press ENTER to continue...\n";
		getline (cin, trash);
		
		cout << "Your string: " << userString << endl;
		cout << "Please enter a character to search for in your string:\n> ";
		char userChoice = 'z';
		cin >> userChoice;
		cin.ignore(256,'\n');
		
		clearScreen();
		welcomeHeader();
		cout << "You searched for, " << userChoice << " and it was found: " << findChar(userString, userChoice) << " time(s).\n";
		
		cout << "The most common character was: " << charCount(userString) << endl;
		
		cout << "Please select a word to replace in your string:\n";
		cout << "Your string: " << userString << "\n> ";
		string findWord;
		cin >> findWord;
		while (userString.find(findWord) == string::npos)
		{
			cout << "Word not found in your string.\n";
			cout << "Please re-enter a valid word:\n";
			cin >> findWord;
		}
		cout << "Now please enter a word to replace it with:\n> ";
		string replaceWord;
		cin >> replaceWord;
		
		string resultString = wordReplace(userString, findWord, replaceWord);
		if (resultString != userString)
			cout << "Your new string is: " << resultString << endl;
		else
			cout << "\nIncorrect inputs, no changes were made.\n";

		cout << "Would you like to exit? (Y)es (N)o\n";
		bool correctInput = false;
		while (correctInput != true)
		{
			cin >> userContinue;
			if (toupper(userContinue) == 'Y')
			{
				userQuit = true;
				correctInput = true;
			}
			else if (toupper(userContinue) != 'N')
			{
				cout << "Please enter correct input.\n";
			}
			else
			{
				correctInput = true;
				clearScreen();
			}
		}
		cin.ignore(256,'\n');
	}
	return 0;
}

void stringCount(string countString, int& alphaCount, int& digitCount)
{
	int stringLength = countString.length();
	for (int i = 0;i < stringLength;i++)
	{
		if (isalpha(countString[i]))
			alphaCount++;
		else if (isdigit(countString[i]))
			digitCount++;
	}
}

string chaosCase(string alterString)
{
	int stringLength = alterString.length();
	for (int i = 0;i < stringLength;i++)
	{
		if (i % 2 == 0 && i != 1)
		{
			alterString[i] = toupper(alterString[i]);
		}
			else if (i % 2 != 0)
		{
			alterString[i] = tolower(alterString[i]);
		}
	}

	return alterString;
}

int wordCount(string countString)
{
	int wordCount = 1;
	int stringLength = countString.length();
	for (int i = 0;i < stringLength;i++)
	{
		if (isspace(countString[i]))
			wordCount++;
	}
	return wordCount;
}

double averageNum(int numArray[], int sizeOfArray)
{
	double average = 0;
	for (int i = 0;i < sizeOfArray;i++)
	{
		average += numArray[i];
	}
	return (average/sizeOfArray);
}

int lowValue(int numArray[], int sizeOfArray)
{
	int lowValue = numArray[0];
	for (int i = 0;i < sizeOfArray;i++)
	{
		if (numArray[i] < lowValue)
			lowValue = numArray[i];
	}
	return lowValue;
}

int highValue(int numArray[], int sizeOfArray)
{
	int highValue = numArray[0];
	for (int i = 0;i < sizeOfArray;i++)
	{
		if (numArray[i] > highValue)
			highValue = numArray[i];
	}
	return highValue;
}

bool isPrime(int userInt)
{
	bool isPrime = true;
	for (int i = 2;i < userInt;i++)
	{
		if (userInt % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime == true && userInt != 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int findChar(string userString, char searchChar)
{
	int finds = 0;
	for (int i = 0;i < userString.length();i++)
	{
		if (searchChar == userString[i])
		{
			finds++;
		}
	}
	return finds;
}

char charCount(string userString)
{
	int availableAlpha[26] = {0};
	int highestIndex = 0;
	for (int i = 0;i < userString.length();i++)
	{
		availableAlpha[(toupper(userString[i]) - 65)]++;
	}
	for (int i = 0;i < 26;i++)
	{
		if (availableAlpha[i] > availableAlpha[highestIndex])
			highestIndex = i;
	}
	highestIndex = highestIndex + 65;
	return (char)highestIndex;
}

string wordReplace(string userString, string findString, string replaceString)
{
	userString.replace(userString.find(findString),findString.length(),replaceString);
	return userString;
}

void welcomeHeader()
{
	cout << "     +--------------------------------------------------------------------+\n";
	cout << "     |              The amazing string and number cruncher!               |\n";
	cout << "     +--------------------------------------------------------------------+\n\n";
}

void clearScreen()
{
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
}