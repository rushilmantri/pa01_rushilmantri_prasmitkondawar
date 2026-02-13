// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include "card.h"

using namespace std;

card convertStringToCard(string s) { // because ace, jack, queen, and king are not numbers
  if(!isdigit(s[1])) {
    int num;
    switch(s[1]) {
      case 'a': num = 1; break;
      case 'j': num = 11; break;
      case 'q': num = 12; break;
      case 'k': num = 13; break;
    }
    return card(s[0], num);
  }

  char x = s[0];
  s.erase(0, 1);
  return card(x, stoi(s));
}

void game(set<card>& player1, set<card>& player2) {
  bool game = true;
  auto it1 = player1.begin();
  auto it2 = player2.rbegin();
  bool p1_turn = true;


  while(game) {
    if(p1_turn) {
      if(it1 != player1.end()) {
        if(player2.find(*it1) != player2.end()) {
          cout << "Alice picked matching card " << *it1 << endl;
          player1.erase(*it1);
          auto x = player2.find(*it1);
          player2.erase(x);
          it1 = player1.begin();
          p1_turn = false;
        }
        else it1++;
      }
      else game = false;
    }
    if(!p1_turn) {
      if(it2 != player2.rend()) {
        if(player1.find(*it2) != player1.end()) {
          cout << "Bob picked matching card " << *it2 << endl;
          player1.erase(*it2);
          auto to_del = *it2;
          player2.erase(to_del);
          it2 = player2.rbegin();
          p1_turn = true;
        }
        else it2++;
      }
      else game = false;
    }
  }

  it1 = player1.begin();
  auto it3 = player2.begin();

  cout << "Alice's cards: " << endl;
  while(it1 != player1.end()) { cout << *it1; it1++; }
  cout << "Bob's cards: " << endl;
  while(it3 != player2.end()) { cout << *it3; it3++; }
}

int main(int argv, char** argc) {
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  set<card> player1;
  while (getline (cardFile1, line) && (line.length() > 0)) {
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    player1.insert(convertStringToCard(line));
  }
  cardFile1.close();

  set<card> player2;
  while (getline (cardFile2, line) && (line.length() > 0)) {
    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    player2.insert(convertStringToCard(line));
  }
  cardFile2.close();
  
  game(player1, player2);

  return 0;
}