// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "card_list.h"

using namespace std;

int getNum(const string& s) { 
  if(!isdigit(s[1])) {
    switch(s[1]) {
      case 'a': return 1;
      case 'j': return 11;
      case 'q': return 12;
      case 'k': return 13;
    }
  }

  return stoi(s.substr(1));
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
  CardBST player1;
  while (getline (cardFile1, line) && (line.length() > 0)) {
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    player1.insert(line[0], getNum(line));
  }
  cardFile1.close();

  CardBST player2;
  while (getline (cardFile2, line) && (line.length() > 0)){
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    player2.insert(line[0], getNum(line));
  }
  cardFile2.close();

  playGame(player1, player2);
  
  return 0;
}