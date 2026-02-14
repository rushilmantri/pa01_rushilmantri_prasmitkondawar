#include <iostream>
#include <sstream>
#include <string>
#include "card_list.h"

using namespace std;

void testCheck(bool condition, const string& testName, const string& desc, int expected, int actual) {
    if (condition) {
        cout << testName << ": " << desc << " - PASSED" << endl;
    } else {
        cout << testName << ": " << desc << " - FAILED" << endl;
        cout << "  Expected: " << expected << ", Got: " << actual << endl;
    }
}

void testCheckBool(bool condition, const string& testName, const string& desc, bool expectedBool) {
    if (condition) {
        cout << testName << ": " << desc << " - PASSED" << endl;
    } else {
        cout << testName << ": " << desc << " - FAILED" << endl;
        cout << "  Expected: " << (expectedBool ? "true" : "false") << ", Got: " << (!expectedBool ? "true" : "false") << endl;
    }
}


void test_insert_empty_tree() {
    CardBST bst;
    bool result1 = bst.insert('c', 5);
    testCheckBool(result1 == true, "test_insert_empty_tree", "insert into empty tree returns true", true);
    bool result2 = bst.contains('c', 5);
    testCheckBool(result2 == true, "test_insert_empty_tree", "contains finds inserted card", true);
}

void test_insert_single_node() {
    CardBST bst;
    bool result1 = bst.insert('h', 10);
    testCheckBool(result1 == true, "test_insert_single_node", "insert h10 returns true", true);
    bool result2 = bst.contains('h', 10);
    testCheckBool(result2 == true, "test_insert_single_node", "contains h10 returns true", true);
    bool result3 = bst.contains('h', 9);
    testCheckBool(result3 == false, "test_insert_single_node", "contains h9 returns false", false);
}

void test_insert_multiple_nodes() {
    CardBST bst;
    bool r1 = bst.insert('c', 5);
    testCheckBool(r1 == true, "test_insert_multiple_nodes", "insert c5 returns true", true);
    bool r2 = bst.insert('d', 7);
    testCheckBool(r2 == true, "test_insert_multiple_nodes", "insert d7 returns true", true);
    bool r3 = bst.insert('s', 3);
    testCheckBool(r3 == true, "test_insert_multiple_nodes", "insert s3 returns true", true);
    bool r4 = bst.contains('c', 5);
    testCheckBool(r4 == true, "test_insert_multiple_nodes", "contains c5 returns true", true);
    bool r5 = bst.contains('d', 7);
    testCheckBool(r5 == true, "test_insert_multiple_nodes", "contains d7 returns true", true);
    bool r6 = bst.contains('s', 3);
    testCheckBool(r6 == true, "test_insert_multiple_nodes", "contains s3 returns true", true);
}

void test_insert_duplicate() {
    CardBST bst;
    bool r1 = bst.insert('h', 13);
    testCheckBool(r1 == true, "test_insert_duplicate", "first insert h13 returns true", true);
    bool r2 = bst.insert('h', 13);
    testCheckBool(r2 == false, "test_insert_duplicate", "duplicate insert h13 returns false", false);
    bool r3 = bst.contains('h', 13);
    testCheckBool(r3 == true, "test_insert_duplicate", "contains h13 returns true", true);
}

void test_insert_maintains_order() {
    CardBST bst;
    bst.insert('c', 1);
    bst.insert('c', 13);
    bst.insert('c', 7);
    bool r1 = bst.contains('c', 1);
    testCheckBool(r1 == true, "test_insert_maintains_order", "contains c1 returns true", true);
    bool r2 = bst.contains('c', 7);
    testCheckBool(r2 == true, "test_insert_maintains_order", "contains c7 returns true", true);
    bool r3 = bst.contains('c', 13);
    testCheckBool(r3 == true, "test_insert_maintains_order", "contains c13 returns true", true);
}


void test_contains_empty_tree() {
    CardBST bst;
    bool r1 = bst.contains('c', 5);
    testCheckBool(r1 == false, "test_contains_empty_tree", "contains c5 on empty tree returns false", false);
    bool r2 = bst.contains('d', 10);
    testCheckBool(r2 == false, "test_contains_empty_tree", "contains d10 on empty tree returns false", false);
}

void test_contains_single_element() {
    CardBST bst;
    bst.insert('s', 9);
    bool r1 = bst.contains('s', 9);
    testCheckBool(r1 == true, "test_contains_single_element", "contains s9 returns true", true);
    bool r2 = bst.contains('s', 8);
    testCheckBool(r2 == false, "test_contains_single_element", "contains s8 returns false", false);
}

void test_contains_multiple_elements() {
    CardBST bst;
    bst.insert('c', 2);
    bst.insert('d', 5);
    bst.insert('h', 12);
    bool r1 = bst.contains('c', 2);
    testCheckBool(r1 == true, "test_contains_multiple_elements", "contains c2 returns true", true);
    bool r2 = bst.contains('d', 5);
    testCheckBool(r2 == true, "test_contains_multiple_elements", "contains d5 returns true", true);
    bool r3 = bst.contains('h', 12);
    testCheckBool(r3 == true, "test_contains_multiple_elements", "contains h12 returns true", true);
    bool r4 = bst.contains('c', 3);
    testCheckBool(r4 == false, "test_contains_multiple_elements", "contains c3 returns false", false);
}

void test_contains_different_suits() {
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('d', 5);
    bst.insert('s', 5);
    bst.insert('h', 5);
    bool r1 = bst.contains('c', 5);
    testCheckBool(r1 == true, "test_contains_different_suits", "contains c5 returns true", true);
    bool r2 = bst.contains('d', 5);
    testCheckBool(r2 == true, "test_contains_different_suits", "contains d5 returns true", true);
    bool r3 = bst.contains('s', 5);
    testCheckBool(r3 == true, "test_contains_different_suits", "contains s5 returns true", true);
    bool r4 = bst.contains('h', 5);
    testCheckBool(r4 == true, "test_contains_different_suits", "contains h5 returns true", true);
}

void test_contains_nonexistent() {
    CardBST bst;
    bst.insert('c', 1);
    bst.insert('d', 10);
    bool r1 = bst.contains('c', 2);
    testCheckBool(r1 == false, "test_contains_nonexistent", "contains c2 returns false", false);
    bool r2 = bst.contains('h', 1);
    testCheckBool(r2 == false, "test_contains_nonexistent", "contains h1 returns false", false);
}


void test_remove_empty_tree() {
    CardBST bst;
    bool r1 = bst.remove('c', 5);
    testCheckBool(r1 == false, "test_remove_empty_tree", "remove from empty tree returns false", false);
}

void test_remove_single_node() {
    CardBST bst;
    bst.insert('h', 7);
    bool r1 = bst.remove('h', 7);
    testCheckBool(r1 == true, "test_remove_single_node", "remove h7 returns true", true);
    bool r2 = bst.contains('h', 7);
    testCheckBool(r2 == false, "test_remove_single_node", "contains h7 after remove returns false", false);
}

void test_remove_nonexistent_card() {
    CardBST bst;
    bst.insert('c', 5);
    bool r1 = bst.remove('c', 6);
    testCheckBool(r1 == false, "test_remove_nonexistent_card", "remove c6 returns false", false);
    bool r2 = bst.remove('d', 5);
    testCheckBool(r2 == false, "test_remove_nonexistent_card", "remove d5 returns false", false);
}

void test_remove_leaf_node() {
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('c', 3);
    bst.insert('c', 7);
    bool r1 = bst.remove('c', 3);
    testCheckBool(r1 == true, "test_remove_leaf_node", "remove leaf c3 returns true", true);
    bool r2 = bst.contains('c', 3);
    testCheckBool(r2 == false, "test_remove_leaf_node", "contains c3 after remove returns false", false);
    bool r3 = bst.contains('c', 5);
    testCheckBool(r3 == true, "test_remove_leaf_node", "contains c5 still returns true", true);
}

void test_remove_node_with_children() {
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('c', 3);
    bst.insert('c', 7);
    bst.insert('c', 1);
    bst.insert('c', 9);
    bool r1 = bst.remove('c', 5);
    testCheckBool(r1 == true, "test_remove_node_with_children", "remove root c5 returns true", true);
    bool r2 = bst.contains('c', 5);
    testCheckBool(r2 == false, "test_remove_node_with_children", "contains c5 after remove returns false", false);
    bool r3 = bst.contains('c', 3);
    testCheckBool(r3 == true, "test_remove_node_with_children", "contains c3 still returns true", true);
    bool r4 = bst.contains('c', 7);
    testCheckBool(r4 == true, "test_remove_node_with_children", "contains c7 still returns true", true);
}

void test_print_empty_tree() {
    CardBST bst;
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    bst.printInOrder();
    cout.rdbuf(old);
    bool result = (buffer.str() == "");
    testCheckBool(result, "test_print_empty_tree", "print empty tree outputs nothing", true);
}

void test_print_single_node() {
    CardBST bst;
    bst.insert('c', 5);
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    bst.printInOrder();
    cout.rdbuf(old);
    bool result = (buffer.str().find('c') != string::npos);
    testCheckBool(result, "test_print_single_node", "print contains 'c'", true);
}

void test_print_multiple_nodes() {
    CardBST bst;
    bst.insert('d', 5);
    bst.insert('c', 5);
    bst.insert('h', 5);
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    bst.printInOrder();
    cout.rdbuf(old);
    string result = buffer.str();
    bool r1 = (result.find('c') != string::npos);
    testCheckBool(r1, "test_print_multiple_nodes", "print contains 'c'", true);
    bool r2 = (result.find('d') != string::npos);
    testCheckBool(r2, "test_print_multiple_nodes", "print contains 'd'", true);
    bool r3 = (result.find('h') != string::npos);
    testCheckBool(r3, "test_print_multiple_nodes", "print contains 'h'", true);
}

void test_print_inorder_correct() {
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('c', 3);
    bst.insert('c', 7);
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    bst.printInOrder();
    cout.rdbuf(old);
    string result = buffer.str();
    size_t pos3 = result.find("3");
    size_t pos5 = result.find("5");
    size_t pos7 = result.find("7");
    bool ordered = (pos3 < pos5 && pos5 < pos7);
    testCheckBool(ordered, "test_print_inorder_correct", "print order is 3 < 5 < 7", true);
}

void test_iterator_empty_tree() {
    CardBST bst;
    bool r1 = (bst.begin() == bst.end());
    testCheckBool(r1, "test_iterator_empty_tree", "begin() == end() for empty tree", true);
    bool r2 = (bst.rbegin() == bst.rend());
    testCheckBool(r2, "test_iterator_empty_tree", "rbegin() == rend() for empty tree", true);
}

void test_iterator_single_node() {
    CardBST bst;
    bst.insert('h', 5);
    auto it = bst.begin();
    bool r1 = (it != bst.end());
    testCheckBool(r1, "test_iterator_single_node", "begin() != end()", true);
    int num = (*it).num;
    bool r2 = (num == 5);
    testCheck(r2, "test_iterator_single_node", "first element num is 5", 5, num);
    ++it;
    bool r3 = (it == bst.end());
    testCheckBool(r3, "test_iterator_single_node", "after increment it == end()", true);
}

void test_iterator_multiple_nodes_forward() {
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('c', 3);
    bst.insert('c', 7);
    auto it = bst.begin();
    int n1 = (*it).num;
    testCheck(n1 == 3, "test_iterator_multiple_nodes_forward", "first element is 3", 3, n1);
    ++it;
    int n2 = (*it).num;
    testCheck(n2 == 5, "test_iterator_multiple_nodes_forward", "second element is 5", 5, n2);
    ++it;
    int n3 = (*it).num;
    testCheck(n3 == 7, "test_iterator_multiple_nodes_forward", "third element is 7", 7, n3);
    ++it;
    bool r4 = (it == bst.end());
    testCheckBool(r4, "test_iterator_multiple_nodes_forward", "after third increment it == end()", true);
}

void test_iterator_multiple_nodes_reverse() {
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('c', 3);
    bst.insert('c', 7);
    auto it = bst.rbegin();
    int n1 = (*it).num;
    testCheck(n1 == 7, "test_iterator_multiple_nodes_reverse", "rbegin element is 7", 7, n1);
    --it;
    int n2 = (*it).num;
    testCheck(n2 == 5, "test_iterator_multiple_nodes_reverse", "second reverse element is 5", 5, n2);
    --it;
    int n3 = (*it).num;
    testCheck(n3 == 3, "test_iterator_multiple_nodes_reverse", "third reverse element is 3", 3, n3);
    --it;
    bool r4 = (it == bst.rend());
    testCheckBool(r4, "test_iterator_multiple_nodes_reverse", "after third decrement it == rend()", true);
}

void test_iterator_increment_past_end() {
    CardBST bst;
    bst.insert('c', 5);
    auto it = bst.begin();
    ++it;
    bool r1 = (it == bst.end());
    testCheckBool(r1, "test_iterator_increment_past_end", "after increment it == end()", true);
    ++it;
    bool r2 = (it == bst.end());
    testCheckBool(r2, "test_iterator_increment_past_end", "incrementing past end stays at end()", true);
}

void test_iterator_comparison() {
    CardBST bst;
    bst.insert('c', 5);
    bst.insert('d', 5);
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    bool r1 = (it1 == it2);
    testCheckBool(r1, "test_iterator_comparison", "two begin() iterators are equal", true);
    ++it2;
    bool r2 = (it1 != it2);
    testCheckBool(r2, "test_iterator_comparison", "after increment iterators are not equal", true);
}

void test_playgame_common_cards() {
    CardBST alice, bob;
    alice.insert('c', 5);
    alice.insert('d', 7);
    bob.insert('c', 5);
    bob.insert('h', 2);
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    alice.playGame(alice, bob);
    cout.rdbuf(old);
    bool r1 = !alice.contains('c', 5);
    testCheckBool(r1, "test_playgame_common_cards", "alice no longer has c5", true);
    bool r2 = !bob.contains('c', 5);
    testCheckBool(r2, "test_playgame_common_cards", "bob no longer has c5", true);
}

void test_playgame_empty_hand() {
    CardBST alice, bob;
    bob.insert('c', 5);
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    alice.playGame(alice, bob);
    cout.rdbuf(old);
    bool r1 = bob.contains('c', 5);
    testCheckBool(r1, "test_playgame_empty_hand", "bob still has c5 when alice is empty", true);
}

void test_playgame_no_common_cards() {
    CardBST alice, bob;
    alice.insert('c', 5);
    alice.insert('d', 7);
    bob.insert('h', 2);
    bob.insert('s', 10);
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    alice.playGame(alice, bob);
    cout.rdbuf(old);
    bool r1 = alice.contains('c', 5);
    testCheckBool(r1, "test_playgame_no_common_cards", "alice still has c5", true);
    bool r2 = bob.contains('h', 2);
    testCheckBool(r2, "test_playgame_no_common_cards", "bob still has h2", true);
}

int main() {
    cout << "=== Running BST Insert Tests ===" << endl;
    test_insert_empty_tree();
    test_insert_single_node();
    test_insert_multiple_nodes();
    test_insert_duplicate();
    test_insert_maintains_order();
    
    cout << "\n=== Running BST Contains Tests ===" << endl;
    test_contains_empty_tree();
    test_contains_single_element();
    test_contains_multiple_elements();
    test_contains_different_suits();
    test_contains_nonexistent();
    
    cout << "\n=== Running BST Remove Tests ===" << endl;
    test_remove_empty_tree();
    test_remove_single_node();
    test_remove_nonexistent_card();
    test_remove_leaf_node();
    test_remove_node_with_children();
    
    cout << "\n=== Running Print/Display Tests ===" << endl;
    test_print_empty_tree();
    test_print_single_node();
    test_print_multiple_nodes();
    test_print_inorder_correct();
    
    cout << "\n=== Running Iterator Tests ===" << endl;
    test_iterator_empty_tree();
    test_iterator_single_node();
    test_iterator_multiple_nodes_forward();
    test_iterator_multiple_nodes_reverse();
    test_iterator_increment_past_end();
    test_iterator_comparison();
    
    cout << "\n=== Running PlayGame Tests ===" << endl;
    test_playgame_common_cards();
    test_playgame_empty_hand();
    test_playgame_no_common_cards();
    
    cout << "\n=== All tests completed! ===" << endl;
    return 0;
}
