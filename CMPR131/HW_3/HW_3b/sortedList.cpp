#include "SortedList.h"
#include <iostream>
using namespace std;

SortedList::SortedList() : length(0) {}

void SortedList::insertItem(int id) {
    if (isFull()) {
        cout << "The list is full – cannot insert the number." << endl;
        return;
    }

    int pos = 0;
    while (pos < length && items[pos] < id) {
        pos++;
    }

    for (int i = length; i > pos; i--) {
        items[i] = items[i - 1];
    }

    items[pos] = id;
    length++;
}

void SortedList::deleteItem(int id) {
    if (isEmpty()) {
        cout << "The list is empty. Cannot delete item." << endl;
        return;
    }

    int pos = binarySearch(id);
    if (pos == -1) {
        cout << "Item is not in the list." << endl;
        return;
    }

    for (int i = pos; i < length - 1; i++) {
        items[i] = items[i + 1];
    }

    length--;
    cout << "Item has been deleted." << endl;
}

bool SortedList::isEmpty() const {
    return length == 0;
}

bool SortedList::isFull() const {
    return length == MAX_ITEMS;
}

bool SortedList::findItem(int id) const {
    return binarySearch(id) != -1;
}

void SortedList::displayList() const {
    for (int i = 0; i < length; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int SortedList::binarySearch(int id) const {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (items[mid] == id) {
            return mid;
        } else if (items[mid] < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
