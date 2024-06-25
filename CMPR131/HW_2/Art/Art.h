#ifndef ART_H
#define ART_H

#include <string>
using namespace std;

class Art {
protected:
    string id;
    string title;
    string artist;
    string genre;
    int year;
    double price;

public:
    Art(string id, string title, string artist, string genre, int year, double price)
        : id(id), title(title), artist(artist), genre(genre), year(year), price(price) {}

    virtual ~Art() {}
    
    virtual void showArt() const = 0; // Pure virtual function
};

#endif
