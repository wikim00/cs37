#include "UnsortedList.h"
#include <iostream>
#include <iomanip>

UnsortedList::UnsortedList() { 
    length = 0; 
}

UnsortedList::~UnsortedList() {}

void UnsortedList::insertItem(int id) {
    if (isFull()) {
        std::cout << "List is full. Cannot insert the number.\n";
    } else {
        numbers[length] = id;
        length++;
    }
}

bool UnsortedList::isFull() const {
    return (length == SIZE);
}

bool UnsortedList::isEmpty() const {
    return (length == 0);
}

void UnsortedList::deleteItem(int id) {
    int location = 0;

    // Linear search for item
    while (location < length && id != numbers[location]) {
        location++;
    }

    if (location < length) { // Item has been found
        // The last item in the list is assigned to numbers[location]
        numbers[location] = numbers[length - 1];
        length--;
    } else { // Item is not in the list
        std::cout << "Id is not in the list.\n";
    }
}

void UnsortedList::displayList() const {
    if (isEmpty()) {
        std::cout << "the list is empty\n";
    } else {
        for (int location = 0; location < length; location++) {
            std::cout << numbers[location] << std::endl;
        }
    }
}
