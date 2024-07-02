#include "UnsortedList.h"

void insertItem(UnsortedList& list, int);
void deleteItem(UnsortedList);
int main()
{
    UnsortedList list;

    int number = 0;
    int id = 0;
    char answer = ' ';

    cout << "Inserting ID numbers. \n";
    cout << "How many id numbers";
    cin >> number;

    if (number > 0)
    {
        for (int i = 0; i < number; i++)
        {
            cout << "please enter the id: ";
            cin >> id;
            insertItem(list, id);
        }
    }

    else
    {
        cout << "the number must be greater than zero. \n\n";
    }

    cout << "\nDisplaying the List:\n";
    list.displayList();

    cout << "Would you like to delete any item from the list? ";
    cin >> answer;

    while(toupper(answer) == 'Y')
    {
        cout << 'please enter the id to be deleted: ' << endl;
        cin >> id;
        deleteItem(list,id);

        if (list.isEmpty)
            break;
    
        cout << "anymore to delete? ";
        cin >> answer;
    }

    cout << "\nDisplaying the list after deleting\n"
    list.displayList();

    return 0;
}

void insertItem(UnsortedList& list, int id);
{
    if(!list.isFull())
    {
        list.insertItem(id);
    }
}

void deleteItem(UnsortedList);
{
    if (!list.isEmpty())
    {
        list.deleteItem(id);
    }
    else
        cout << "The list is empty.\n\n";
}