#include "Word.h"


Word::Word(string newWord)
: word(newWord), count(1)
{
}

string Word::getWord()
{
    return word;
}

void Word::setWord(string newWord)
{
    word = newWord;
}

int Word::getCount()
{
    return count;
}

bool Word::operator> (const Word& src)
{
    string srcCopy = src.word;
    string thisCopy = this->word;
    std::transform(srcCopy.begin(), srcCopy.end(), srcCopy.begin(), ::toupper);
    std::transform(thisCopy.begin(), thisCopy.end(), thisCopy.begin(), ::toupper);
    return (thisCopy > srcCopy);
}

bool Word::operator< (const Word& src)
{
    string srcCopy = src.word;
    string thisCopy = this->word;
    std::transform(srcCopy.begin(), srcCopy.end(), srcCopy.begin(), ::toupper);
    std::transform(thisCopy.begin(), thisCopy.end(), thisCopy.begin(), ::toupper);
    return (thisCopy < srcCopy);
}

bool Word::operator== (const Word& src)
{
    string srcCopy = src.word;
    string thisCopy = this->word;
    std::transform(srcCopy.begin(), srcCopy.end(), srcCopy.begin(), ::toupper);
    std::transform(thisCopy.begin(), thisCopy.end(), thisCopy.begin(), ::toupper);
    return (thisCopy == srcCopy);
}

Word& Word::operator++ ()
{
    count++;
    return (*this);
}

