// tests.cpp
// Comprehensive test suite for CardBST and playGame function
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include "card_list.h"

using namespace std;


int passCount = 0;
int failCount = 0;

void printTest(const string& testName) {
    cout << "  " << testName << " ";
}

void passTest() {
    cout << "passed" << endl;
    passCount++;
}

void failTest(const string& reason) {
    cout << "failed (" << reason << ")" << endl;
    failCount++;
}

void testInsertEmptyTree() {
    printTest("Insert into empty tree");
    CardBST bst;
    bool result = bst.insert('c', 5);
    if (result && bst.contains('c', 5)) {
        passTest();
    } else {
        failTest("insert/contains failed");
    }
}

void testInsertSingleCard() {
    printTest("Insert single card");
    CardBST bst;
    bst.insert('h', 10);
    if (bst.contains('h', 10) && !bst.contains('h', 9)) {
        passTest();
    } else {
        failTest("single card insert failed");
    }
}

void testInsertMultipleCards() {
    printTest("Insert multiple cards");
    CardBST bst;
    bst.insert('c', 3);
    bst.insert('d', 5);
    bst.insert('h', 10);
    bst.insert('s', 7);
    
    if (bst.contains('c', 3) && bst.contains('d', 5) && 
        bst.contains('h', 10) && bst.contains('s', 7)) {
        passTest();
    } else {
        failTest("multiple insert failed");
    }
}

void testInsertDuplicateCard() {
    printTest("Insert duplicate card returns false");
    CardBST bst;
    bst.insert('c', 5);
    bool result = bst.insert('c', 5);
    if (!result) {
        passTest();
    } else {
        failTest("duplicate insert should return false");
    }
}

void testInsertCardsOrderedByValue() {
    printTest("Insert cards ordered by suit then value");
    CardBST bst;
    bst.insert('h', 13);
    bst.insert('c', 2);
    bst.insert('d', 5);
    bst.insert('s', 1);
    
    if (bst.contains('c', 2) && bst.contains('d', 5) && 
        bst.contains('h', 13) && bst.contains('s', 1)) {
        passTest();
    } else {
        failTest("ordering insert failed");
    }
}

void testRemoveFromEmptyTree() {
    printTest("Remove from empty tree returns false");
    CardBST bst;
    bool result = bst.remove('c', 5);
    if (!result) {
        passTest();
    } else {
        failTest("remove from empty should return false");
    }
}

void testRemoveSingleNode() {
    printTest("Remove single node from tree");
    CardBST bst;
    bst.insert('c', 5);
    bool result = bst.remove('c', 5);
    if (result && !bst.contains('c', 5)) {
        passTest();
    } else {
        failTest("single node remove failed");
    }
}

void testRemoveLeafNode() {
    printTest("Remove leaf node");
    CardBST bst;
    bst.insert('c', 3);
    bst.insert('d', 5);
    bst.insert('h', 10);
    bst.remove('d', 5);
    if (!bst.contains('d', 5) && bst.contains('c', 3) && bst.contains('h', 10)) {
        passTest();
    } else {
        failTest("leaf node remove failed");
    }
}

void testRemoveNodeWithOneChild() {
    printTest("Remove node with one child");
    CardBST bst;
    bst.insert('d', 5);
    bst.insert('c', 3);
    bst.insert('d', 7);
    bst.remove('d', 5);
    if (!bst.contains('d', 5) && bst.contains('c', 3) && bst.contains('d', 7)) {
        passTest();
    } else {
        failTest("remove node with one child failed");
    }
}

void testRemoveNodeWithTwoChildren() {
    printTest("Remove node with two children");
    CardBST bst;
    bst.insert('d', 5);
    bst.insert('c', 3);
    bst.insert('d', 7);
    bst.insert('c', 2);
    bst.insert('d', 6);
    bst.remove('d', 5);
    if (!bst.contains('d', 5) && bst.contains('c', 3) && 
        bst.contains('d', 7) && bst.contains('c', 2) && bst.contains('d', 6)) {
        passTest();
    } else {
        failTest("remove node with two children failed");
    }
}

void testRemoveNonexistentCard() {
    printTest("Remove non-existent card returns false");
    CardBST bst;
    bst.insert('c', 5);
    bool result = bst.remove('h', 10);
    if (!result && bst.contains('c', 5)) {
        passTest();
    } else {
        failTest("remove nonexistent should return false");
    }
}

void testContainsEmptyTree() {
    printTest("Contains on empty tree returns false");
    CardBST bst;
    if (!bst.contains('c', 5)) {
        passTest();
    } else {
        failTest("empty tree contains should return false");
    }
}

void testContainsSingleCard() {
    printTest("Contains finds single card");
    CardBST bst;
    bst.insert('d', 10);
    if (bst.contains('d', 10) && !bst.contains('d', 9)) {
        passTest();
    } else {
        failTest("single card contains failed");
    }
}

void testContainsMultipleCards() {
    printTest("Contains with multiple cards");
    CardBST bst;
    bst.insert('c', 3);
    bst.insert('d', 5);
    bst.insert('h', 10);
    bst.insert('s', 7);
    
    if (bst.contains('c', 3) && bst.contains('d', 5) && 
        bst.contains('h', 10) && bst.contains('s', 7) && !bst.contains('c', 1)) {
        passTest();
    } else {
        failTest("multiple card contains failed");
    }
}

void testContainsAfterRemoval() {
    printTest("Contains after removal");
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('d', 10);
    bst.remove('c', 5);
    if (!bst.contains('c', 5) && bst.contains('d', 10)) {
        passTest();
    } else {
        failTest("contains after removal failed");
    }
}

void testContainsDifferentSuits() {
    printTest("Contains distinguishes different suits");
    CardBST bst;
    bst.insert('c', 5);
    if (bst.contains('c', 5) && !bst.contains('d', 5) && 
        !bst.contains('h', 5) && !bst.contains('s', 5)) {
        passTest();
    } else {
        failTest("suit distinction failed");
    }
}

void testIteratorEmptyTree() {
    printTest("Iterator on empty tree (begin == end)");
    CardBST bst;
    auto begin_it = bst.begin();
    auto end_it = bst.end();
    if (begin_it == end_it) {
        passTest();
    } else {
        failTest("begin != end on empty tree");
    }
}

void testIteratorEmptyTreeReverse() {
    printTest("Iterator on empty tree (rbegin == rend)");
    CardBST bst;
    auto rbegin_it = bst.rbegin();
    auto rend_it = bst.rend();
    if (rbegin_it == rend_it) {
        passTest();
    } else {
        failTest("rbegin != rend on empty tree");
    }
}

void testIteratorSingleNode() {
    printTest("Iterator with single node");
    CardBST bst;
    bst.insert('c', 5);
    
    auto it = bst.begin();
    bool found = (it != bst.end());
    bool correct = false;
    if (found) {
        correct = ((*it).suit == 'c' && (*it).num == 5);
    }
    
    ++it;
    bool at_end = (it == bst.end());
    
    if (found && correct && at_end) {
        passTest();
    } else {
        failTest("single node iterator failed");
    }
}

void testIteratorMultipleNodesInOrder() {
    printTest("Iterator forward traversal of multiple nodes");
    CardBST bst;
    bst.insert('d', 5);
    bst.insert('c', 3);
    bst.insert('h', 10);
    
    auto it = bst.begin();
    bool c3_correct = ((*it).suit == 'c' && (*it).num == 3);
    ++it;
    bool d5_correct = ((*it).suit == 'd' && (*it).num == 5);
    ++it;
    bool h10_correct = ((*it).suit == 'h' && (*it).num == 10);
    ++it;
    bool at_end = (it == bst.end());
    
    if (c3_correct && d5_correct && h10_correct && at_end) {
        passTest();
    } else {
        failTest("forward traversal order incorrect");
    }
}

void testIteratorReverseTraversal() {
    printTest("Iterator reverse traversal");
    CardBST bst;
    bst.insert('d', 5);
    bst.insert('c', 3);
    bst.insert('h', 10);
    
    auto it = bst.rbegin();
    bool h10_correct = ((*it).suit == 'h' && (*it).num == 10);
    --it;
    bool d5_correct = ((*it).suit == 'd' && (*it).num == 5);
    --it;
    bool c3_correct = ((*it).suit == 'c' && (*it).num == 3);
    --it;
    bool at_rend = (it == bst.rend());
    
    if (h10_correct && d5_correct && c3_correct && at_rend) {
        passTest();
    } else {
        failTest("reverse traversal order incorrect");
    }
}

void testIteratorComparison() {
    printTest("Iterator comparison operators");
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('d', 10);
    
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    bool equal = (it1 == it2);
    
    ++it1;
    bool not_equal = (it1 != it2);
    
    if (equal && not_equal) {
        passTest();
    } else {
        failTest("iterator comparison failed");
    }
}

void testIteratorIncrementPastEnd() {
    printTest("Iterator increment at end is safe");
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('d', 10);
    
    auto it = bst.begin();
    ++it;
    ++it;
    bool at_end = (it == bst.end());
    
    if (at_end) {
        passTest();
    } else {
        failTest("should reach end");
    }
}

void testIteratorDecrementPastRend() {
    printTest("Iterator decrement at rend is safe");
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('d', 10);
    
    auto it = bst.rbegin();
    --it;
    --it;
    bool at_rend = (it == bst.rend());
    
    if (at_rend) {
        passTest();
    } else {
        failTest("should reach rend");
    }
}

void testIteratorFullTraversal() {
    printTest("Iterator full forward traversal");
    CardBST bst;
    bst.insert('d', 7);
    bst.insert('c', 3);
    bst.insert('h', 10);
    
    int count = 0;
    for(auto it = bst.begin(); it != bst.end(); ++it) {
        count++;
    }
    
    if (count == 3) {
        passTest();
    } else {
        failTest("traversal count incorrect");
    }
}

void testIteratorReverseFullTraversal() {
    printTest("Iterator full reverse traversal");
    CardBST bst;
    bst.insert('d', 7);
    bst.insert('c', 3);
    bst.insert('h', 10);
    
    int count = 0;
    for(auto it = bst.rbegin(); it != bst.rend(); --it) {
        count++;
    }
    
    if (count == 3) {
        passTest();
    } else {
        failTest("reverse traversal count incorrect");
    }
}

void testPlayGameBothPlayersWithCommonCards() {
    printTest("PlayGame with both players having common cards");
    CardBST alice, bob;
    
    alice.insert('c', 3);
    alice.insert('h', 5);
    alice.insert('d', 10);
    
    bob.insert('c', 2);
    bob.insert('c', 3);
    bob.insert('d', 10);
    bob.insert('h', 1);
    
    stringstream ss;
    streambuf* cout_backup = cout.rdbuf(ss.rdbuf());
    playGame(alice, bob);
    cout.rdbuf(cout_backup);
    
    if (!alice.contains('c', 3) && !bob.contains('c', 3) &&
        alice.contains('h', 5) && bob.contains('c', 2)) {
        passTest();
    } else {
        failTest("common cards not properly removed");
    }
}

void testPlayGameOnePlayerEmpty() {
    printTest("PlayGame with one player having empty hand");
    CardBST alice, bob;
    
    alice.insert('c', 5);
    
    stringstream ss;
    streambuf* cout_backup = cout.rdbuf(ss.rdbuf());
    playGame(alice, bob);
    cout.rdbuf(cout_backup);
    
    if (alice.contains('c', 5)) {
        passTest();
    } else {
        failTest("alice's card should remain");
    }
}

void testPlayGameNoCommonCards() {
    printTest("PlayGame with no common cards");
    CardBST alice, bob;
    
    alice.insert('c', 5);
    alice.insert('d', 10);
    
    bob.insert('h', 1);
    bob.insert('s', 13);
    
    stringstream ss;
    streambuf* cout_backup = cout.rdbuf(ss.rdbuf());
    playGame(alice, bob);
    cout.rdbuf(cout_backup);
    
    string output = ss.str();
    bool no_matches = (output.find("picked matching card") == string::npos);
    bool alice_intact = (alice.contains('c', 5) && alice.contains('d', 10));
    bool bob_intact = (bob.contains('h', 1) && bob.contains('s', 13));
    
    if (no_matches && alice_intact && bob_intact) {
        passTest();
    } else {
        failTest("cards should remain with no matches");
    }
}

void testPlayGameAllCardsMatch() {
    printTest("PlayGame where all cards match");
    CardBST alice, bob;
    
    alice.insert('c', 3);
    alice.insert('d', 5);
    
    bob.insert('c', 3);
    bob.insert('d', 5);
    
    stringstream ss;
    streambuf* cout_backup = cout.rdbuf(ss.rdbuf());
    playGame(alice, bob);
    cout.rdbuf(cout_backup);
    
    auto alice_it = alice.begin();
    auto bob_it = bob.begin();
    
    if (alice_it == alice.end() && bob_it == bob.end()) {
        passTest();
    } else {
        failTest("all cards should be removed");
    }
}

void testPlayGameComplexScenario() {
    printTest("PlayGame complex scenario");
    CardBST alice, bob;
    
    alice.insert('h', 3);
    alice.insert('s', 10);
    alice.insert('c', 1);
    alice.insert('c', 3);
    alice.insert('s', 5);
    alice.insert('h', 10);
    alice.insert('d', 1);
    
    bob.insert('c', 2);
    bob.insert('d', 1);
    bob.insert('h', 10);
    bob.insert('c', 3);
    bob.insert('d', 11);
    bob.insert('s', 10);
    bob.insert('h', 1);
    
    stringstream ss;
    streambuf* cout_backup = cout.rdbuf(ss.rdbuf());
    playGame(alice, bob);
    cout.rdbuf(cout_backup);
    
    string output = ss.str();
    bool has_matches = (output.find("picked matching card") != string::npos);
    
    if (has_matches) {
        passTest();
    } else {
        failTest("complex scenario should have matches");
    }
}

int main() {
    
    // insert tests
    cout << "insert tests: " << endl;
    testInsertEmptyTree();
    testInsertSingleCard();
    testInsertMultipleCards();
    testInsertDuplicateCard();
    testInsertCardsOrderedByValue();
    cout << endl;
    
    // remove tests
    cout << "remove tests: " << endl;
    testRemoveFromEmptyTree();
    testRemoveSingleNode();
    testRemoveLeafNode();
    testRemoveNodeWithOneChild();
    testRemoveNodeWithTwoChildren();
    testRemoveNonexistentCard();
    cout << endl;
    
    // contains tests
    cout << "contains tests: " << endl;
    testContainsEmptyTree();
    testContainsSingleCard();
    testContainsMultipleCards();
    testContainsAfterRemoval();
    testContainsDifferentSuits();
    cout << endl;
    
    // iterator tests
    cout << "iterator tests: " << endl;
    testIteratorEmptyTree();
    testIteratorEmptyTreeReverse();
    testIteratorSingleNode();
    testIteratorMultipleNodesInOrder();
    testIteratorReverseTraversal();
    testIteratorComparison();
    testIteratorIncrementPastEnd();
    testIteratorDecrementPastRend();
    testIteratorFullTraversal();
    testIteratorReverseFullTraversal();
    cout << endl;
    
    // playgame tests
    cout << "playgame tests: " << endl;
    testPlayGameBothPlayersWithCommonCards();
    testPlayGameOnePlayerEmpty();
    testPlayGameNoCommonCards();
    testPlayGameAllCardsMatch();
    testPlayGameComplexScenario();
    cout << endl;
    
    cout << "tests passed: " << passCount << endl;
    cout << "tests failed: " << failCount << endl;    
}
