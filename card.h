// card.h
// Author: Rushil Mantri & Prasmit Kondawar
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class card {
    private:
        char suit;
        int num;
    public:
        card(char s, int n) : suit(s), num(n) {}
        int suitToRank() const;
        bool operator<(const card& rhs) const; // so that set can sort cards how i want automatically
        bool operator==(const card& rhs) const;
        friend ostream& operator<<(ostream& out, const card& obj);
};

#endif
