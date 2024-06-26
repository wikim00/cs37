#include "sortedList.h"
int main()
{
SortedList list;
string name = "Med Mogasemi";
string name1 = "Bob Lee";
cout << "Inserting.\n";
if (!list.isFull())
list.insertItem(name);
if (!list.isFull())
list.insertItem(name1);
cout << "\n\nDisplaying the list:\n\n";
list.displayList();
if (!list.isEmpty())
{
list.deleteItem(name);
}
list.displayList();
return 0; }
