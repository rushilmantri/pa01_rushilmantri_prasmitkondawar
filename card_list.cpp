// card_list.cpp
// Author: Rushil Mantri & Prasmit Kondawar
// Implementation of the classes defined in card_list.h
#include <iostream>
#include <string>
#include "card_list.h"

using namespace std;

// CARD FUNCTIONS

int CardBST::Card::suitToRank() const {
    switch(this->suit) {
        case 'c': return 0;
        case 'd': return 1;
        case 's': return 2;
        case 'h': return 3;
        default: return -1; //will never reach here hopefully
    }
}

bool CardBST::Card::operator==(const Card& rhs) const {
    return (this->suit == rhs.suit) && (this->num == rhs.num);
}

bool CardBST::Card::operator<(const Card& rhs) const {
    if(this->suit != rhs.suit) return this->suitToRank() < rhs.suitToRank();
    return this->num < rhs.num;
}

ostream& operator<<(ostream& out, const CardBST::Card& obj) {
    string x = "";
    switch(obj.num) {
        case 1: x = "a"; break;
        case 11: x = "j"; break;
        case 12: x = "q"; break;
        case 13: x = "k"; break;
        default: x = to_string(obj.num);
    }

    out << obj.suit << " " << x << endl;
    return out;
}

// ITERATOR FUNCTIONS

CardBST::Card* CardBST::iterator::successor(Card* node) {
    if(!node) return nullptr;
    if(node->right) {
        Card* p = node->right;
        while(p && p->left) {
            p = p->left;
        }
        return p;
    }

    Card* p = node->parent;
    while(p && node == p->right) {
        node = p;
        p = p->parent;
    }
    return p;
}

CardBST::Card* CardBST::iterator::predecessor(Card* node) {
    if(!node) return nullptr;
    if(node->left) {
        Card* p = node->left;
        while(p && p->right) {
            p = p->right;
        }
        return p;
    }

    Card* p = node->parent;
    while(p && node == p->left) {
        node = p;
        p = p->parent;
    }
    return p;
}

CardBST::iterator& CardBST::iterator::operator--() {
    if(!this->curr) {
        Card* node = tree->root;
        if(node) {
            while(node->right) {
                node = node->right;
            }
        }
        this->curr = node;
    }
    else this->curr = predecessor(this->curr);
    return *this;
}

CardBST::iterator& CardBST::iterator::operator++() {
    if(!this->curr) {
        Card* node = tree->root;
        if(node) {
            while(node->left) {
                node = node->left;
            }
        }
        this->curr = node;
    }
    else this->curr = successor(this->curr);
    return *this;
}

bool CardBST::iterator::operator==(const iterator& rhs) const {
    return this->curr == rhs.curr;
}

const CardBST::Card& CardBST::iterator::operator*() const {
    return *curr;
}

// CARD BST FUNCTIONS

CardBST::CardBST() {
    this->root = nullptr;
}

CardBST::~CardBST() {
    clear(this->root);
}

void CardBST::clear(Card* root) {
    if(!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
}

bool CardBST::insert(char s, int n) {
    if(contains(s, n)) return false;
    Card* newCard = new Card(s, n);
    if(!root) {
        this->root = newCard;
        return true;
    }

    return insert(newCard, this->root);
}

bool CardBST::insert(Card* toIns, Card* root) {
    if(*toIns < *root) {
        if(!root->left) {
            root->left = toIns;
            toIns->parent = root;
            return true;
        }
        else return insert(toIns, root->left);
    }
    else if(*root < *toIns) {
        if(!root->right) {
            root->right = toIns;
            toIns->parent = root;
            return true;
        }
        else return insert(toIns, root->right);
    }
    else return false;
}

bool CardBST::contains(char s, int n) const {
    return contains(s, n, this->root);
}

bool CardBST::contains(char s, int n, Card* root) const {
    if(!root) return false;

    Card target(s, n);

    if(target == *root) return true;
    if(target < *root) return contains(s, n, root->left);
    else return contains(s, n, root->right);
}

bool remove(char s, int n) {
    //implement this
}

CardBST::iterator CardBST::begin() {
    Card* node = this->root;
    if(!node) return iterator(nullptr, this);
    while(node->left) node = node->left;
    return iterator(node, this);
}

CardBST::iterator CardBST::rbegin() {
    Card* node = this->root;
    if(!node) return iterator(nullptr, this);
    while(node->right) node = node->right;
    return iterator(node, this);
}

CardBST::iterator CardBST::end() {
    return iterator(nullptr, this);
}

CardBST::iterator CardBST::rend() {
    return iterator(nullptr, this);
}