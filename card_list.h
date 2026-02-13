// card_list.h
// Author: Rushil Mantri & Prasmit Kondawar
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include <iostream>

using namespace std;

class CardBST {
    private:
        struct Card {
            char suit;
            int num;
            Card *left, *right, *parent;
            Card(char s, int n): suit(s), num(n), left(nullptr), right(nullptr), parent(nullptr) {}
            int suitToRank() const;
            bool operator==(const Card& rhs) const;
            bool operator<(const Card& rhs) const;
            friend ostream& operator<<(ostream& out, const Card& obj);
        };

        Card* root;

        //private helpers
        bool contains(char s, int num, Card* root) const;
        bool insert(Card* toIns, Card* root); 
        void clear(Card* root);

    public:
        CardBST();
        ~CardBST();
        bool insert(char s, int n);
        bool remove(char s, int n);
        bool contains(char s, int num) const;
        friend ostream& operator<<(ostream& out, const CardBST::Card& obj);

};

#endif