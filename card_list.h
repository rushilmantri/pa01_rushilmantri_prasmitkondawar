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
        Card* findNode(char s, int n, Card* root) const;
        bool insert(Card* toIns, Card* root); 
        void clear(Card* root);
    public:
        CardBST();
        ~CardBST();
        bool insert(char s, int n);
        bool remove(char s, int n);
        bool contains(char s, int n) const;
        void printInOrder();
        void playGame(CardBST& alice, CardBST& bob);
        friend ostream& operator<<(ostream& out, const CardBST::Card& obj);

        class iterator {
            private:
                Card* curr;
                CardBST* tree;
                Card* successor(Card* node);
                Card* predecessor(Card* node);
                friend class CardBST;
            public:
                iterator(Card* c, CardBST* t): curr(c), tree(t) {}
                iterator& operator++();
                iterator& operator--();
                bool operator==(const iterator& rhs) const;
                bool operator!=(const iterator& rhs) const;
                const Card& operator*() const;
        };

        iterator begin();
        iterator rbegin();
        iterator end();
        iterator rend();
};

#endif