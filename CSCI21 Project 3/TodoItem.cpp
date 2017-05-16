#include "TodoItem.h"

TodoItem::TodoItem()
{
    text = "";
    priority = 1;
    completed = false;
}

TodoItem::TodoItem(string newText, int newPriority, bool newCompleted)
{
    text = newText;
    priority = newPriority;
    completed = newCompleted;
    scrub();  // scrub the text of @'s
}

TodoItem::~TodoItem()
{

}

void TodoItem::setText(string newText)
{
    text = newText;
    scrub();
}

string TodoItem::getText()
{
    return text;
}

void TodoItem::setPriority(int newPriority)
{
    priority = newPriority;
}

int TodoItem::getPriority()
{
    return priority;
}

void TodoItem::setCompleted(bool newCompleted)
{
    completed = newCompleted;
}

bool TodoItem::getCompleted()
{
    return completed;
}

bool TodoItem::hasKeyword(string searchStr)
{
    string searchTemp = searchStr;
    string textTemp = text;
    for (unsigned int i = 0;i < searchTemp.length();i++)
        searchTemp[i] = tolower(searchTemp[i]);
    for (unsigned int i = 0;i < textTemp.length();i++)
        textTemp[i] = tolower(textTemp[i]);
    if (textTemp.find(searchTemp) != string::npos)
        return true;
    return false;
}

ostream& operator<< (ostream& outs, const TodoItem& src)
{
    outs << "    ------------------------------------------------------------------------\n"
         << "\tPriority: " << src.priority << "\t\t\t\tCompleted?: ";
    if (src.completed == true)
        outs << "Yes\n";
    else
        outs << "No\n";
    outs << "\tText: " << src.text << "\n";
    outs << "    ------------------------------------------------------------------------\n";
    return outs;
}

string TodoItem::toFile()
{
    string newStr;
    stringstream oss;
    oss << getText() << "@" << getPriority() << "@" << getCompleted() << endl;
    newStr = oss.str();
    return newStr;
}

void TodoItem::scrub() //private
{
    for (unsigned int i = 0;i < text.length();i++)
        if (text[i] == '@')
            text[i] = '#';
}
