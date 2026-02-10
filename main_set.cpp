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
  int num;
  if(isdigit(s[1])) num = stoi(string{s[1]});

  switch(s[1]) {
    case 'a': num = 1;
    case 'j': num = 11;
    case 'q': num = 12;
    case 'k': num = 13;
  }
  
  return card(s[0], num);
}

void game(set<card>& player1, set<card>& player2) {
  //implement logic
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
