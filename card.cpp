// card.cpp
// Author: Rushil Mantri & Prasmit Kondawar
// Implementation of the classes defined in card.h
#include <iostream>
#include "card.h"

using namespace std;

int card::suitToRank() const {
    switch(this->suit) {
        case 'c': return 0;
        case 'd': return 1;
        case 's': return 2;
        case 'h': return 3;
    }
}

bool card::operator<(const card& rhs) const {
    if(this->suitToRank() != rhs.suitToRank()) return this->suitToRank() < rhs.suitToRank();
    return this->num < rhs.num;
}

bool card::operator==(const card& rhs) const {
    return (this->suit == rhs.suit) && (this->num == rhs.num);
}

ostream& operator<<(ostream& out, const card& obj) {
    string x = to_string(obj.num);
    if(x == "1") x = "a";
    if(x == "11") x = "j";
    if(x == "12") x = "q";
    if(x == "13") x = "k";

    out << obj.suit << " " << x << endl;
    return out;
}