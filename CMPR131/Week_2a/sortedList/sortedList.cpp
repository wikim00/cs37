#include "SortedList.h"

SortedList::SortedList() { length = 0; }
SortedList::~SortedList() {};

//insert item function
void SortedList::insertItem(string item)
{
    int location = 0;
    location = binarySearch(item);
    for (int i = length; i > location; i--)
    {
        name[i] = name[i - 1];
    }
    name[location] = item;
    length++;
}

bool SortedList::isFull()const
{
    return (length == SIZE);
}

bool SortedList::isEmpty()const
{
    return (length == 0);
}

void SortedList::deleteItem(string name)
{
    int location = 0;
    location = linearSearch(name);
    if (location < length)
    {
        for (int i = location + 1; i < length; i++)
    {
        name[i - 1] = name[i];
    }
    length--;
    }
    else
    cout << "The name is not in the list.\n\n";
}

//linear search
int SortedList::linearSearch(string names)
{
    int location = 0;
    while ((names > name[location]) && (location < length))
    {
        location++;
    }
    return location;
}

//print list
void SortedList::displayList()const
{
    for (int i = 0; i < length; i++)
    {
        cout << name[i] << endl;
    }
}

//binary search function
int SortedList::binarySearch(string item)
{
    int first = 0;
    int midPoint = 0;
    int last = length - 1;
    while (true)
    {
        if (first > last)
        {
            return first;
        }
        midPoint = (first + last) / 2;
        if (item == name[midPoint])
        {
            return midPoint;
        }
        else if (item > name[midPoint])
        {
            first = (midPoint + 1);
        }
        else if (item < name[midPoint])
        {
            last = (midPoint - 1);
        }
    }
}