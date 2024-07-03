#ifndef SORTEDLIST_H
#define SORTEDLIST_H

class SortedList {
public:
    SortedList();
    void insertItem(int id);
    void deleteItem(int id);
    bool isEmpty() const;
    bool isFull() const;
    bool findItem(int id) const;
    void displayList() const;

private:
    static const int MAX_ITEMS = 100;
    int items[MAX_ITEMS];
    int length;
    int binarySearch(int id) const;
};

#endif // SORTEDLIST_H
