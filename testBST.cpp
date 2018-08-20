/**
  * Partner1:
  * Name: Jiaqi Fan
  * PID: A12584051
  * Partner2:
  * Name: Xuanru Zhu
  * PID: A91064234
  * Date: 1/20/2017
  */
// this file holdes all the tests for BSTInt, and BSTIterator, and BST.hpp
// we tested many edge cases to make sure the code is fine. we also passed
// all the valgrind checks to make sure there is not memory leaks.

#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);
    /* Create an STL vector of ascending ints */
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    /* Create an instance of BST holding int */
    BSTInt b;
    /* Create an instance of a empty BST */
    BSTInt b1;
    /* Create an instance of another unbalanced BST */
    BSTInt b2;
    /* Create an instance of another BST for testing duplicate insertion*/
    BSTInt b3;
    /* Create an instance of another BST for testing height*/
    BSTInt b4;
    b4.insert(5);  
    /* this is the test for empty tree*/
	bool emptyT = b.empty();
	if (!emptyT) {
		cout << "empty function wrong" << endl;
                return -1;
	}

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }
    
    /* this is the test for not empty tree*/
	emptyT = b.empty();
	if (emptyT) {
		cout << "empty function wrong" << endl;
	}

    // another test for insert
    for(int item : v1) {
        bool pr1 = b2.insert(item);
        if(! pr1 ) { 
            cout << "Incorrect bool return value when inserting " << item 
		 << " when having an unbalanced tree." << endl;
            return -1;
        }
    }
    
    // test for duplicate insert
    bool pr2 = b3.insert(1);
    if(!pr2){
            cout << "Incorrect bool return value when inserting " << 1
                 << endl;
            return -1;
    }
    pr2 = b3.insert(1);
    if(pr2){
            cout << "Incorrect bool return value when inserting " << 1 
		 << " when inserting duplicate insert." << endl;
            return -1;
    }
	
    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
    
    // More test for find
    if(b.find(99)){
      cout << "Incorrect return value when finding " << 99 << endl;
      return -1;
    }
    if(b.find(-39)){
      cout << "Incorrect return value when finding " << -39 << endl;
      return -1;
    }

    // Test for empty BST
    if(b1.find(1)){
      cout << "empty BST Incorrect return value when finding " << 1 << endl;
      return -1;
    }
    
    if(b1.find(-1)){
      cout << "empty BST Incorrect return value when finding " << -1 << endl;
      return -1;
    }

    /* Test find return value. */
    // Test the items that are already in an unbalanced tree
    for(int item : v1) {
        if(!b2.find(item)) {
            cout << "Incorrect return value when finding " << item 
		 << " in an unbalanced tree" << endl;
            return -1;
        }
    }

    /* Test size. */
    cout << "Size is: " << b1.size() << endl;
    if (b1.size() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }
    /* Test size. */
    cout << "Size is: " << b2.size() << endl;
    if (b2.size() != v1.size()) {
	cout << "... which is incorrect." << endl;
	return -1;
    }
    /*test for BST height*/
    int tH1 = b2.height();
    if (tH1 != 4) {
	cout << "the height is not correct should be 4" << endl;
	return -1;
    }
    /*test for BST height*/
    int tH2 = b1.height();
    if (tH2 != -1) {
	cout << "the height is not correct should be -1" << endl;
	return -1;
    }
    /*test for BST height*/
    int tH3 = b4.height();
    if (tH3 != 0) {
	cout << "the height is not correct should be 0" << endl;
	return -1;
    }
    /*test for BST height*/
    int tH4 = b.height();
    if (tH4 != 2) {
	cout << "the height is not correct should be 2" << endl;
	return -1;
    }
    /*test for BST height*/
    int tH5 = b3.height();
    if (tH5 != 0) {
        cout << "the height is not correct should be 0" << endl;
        return -1;
    }

    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }

    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.
    
    v1.push_back(-1);
    v1.push_back(-2);
    v1.push_back(-3);
    v1.push_back(-4);
    /* more test for insert with negative numbers */
    BST<int> btemp2;
    for (int item : v1) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting Negative Numbers to existing BST" << item << " into the int template-based BST2...";
        auto p2 = btemp2.insert(item);
        if (*(p2.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p2.first) << endl;
            return -1;
        }
        if (!p2.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p2.second << endl;
            return -1;
        }
        cout << "success! inserted negative number" << endl;
	// after the insert btemp2 should have 1,2,3,4,5,-1,-2,-3,-4
    }
    // test for inserting dupe item
    auto p3 = btemp2.insert(1);
    if(p3.second){
	cout << "Wrong boolean returned. When insert dupe items. Expected False but got " 
                 << p3.second << endl;
            return -1;
    }

        // Now test finding the elements we just put in
    for (int item: v1) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp2.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success! Find for btemp2" << endl;
    }

    // test for items that is not in BST
    BSTIterator<int> foundIt2 = btemp2.find(10);
    if (foundIt2 != BSTIterator<int> (NULL)){
        cout << "This item should not be find" << endl;
        return -1;
    }
    cout << "Test for item not in the BST success" << endl;

    // Sort the vector, to compare with inorder iteration on the BST
    v1.push_back(100); //added more elements to the my test vector
    v1.push_back(34);
    v1.push_back(26);
    v1.push_back(-56);
    v1.push_back(475);
    v1.push_back(-666);
    // add all the elements into the my Btemp2 to do more test
    btemp2.insert(100);
    btemp2.insert(34);
    btemp2.insert(26);
    btemp2.insert(-56);
    btemp2.insert(475);
    btemp2.insert(-666);
    // after adding all the stuff the test begins below
    sort(v1.begin(),v1.end());
    cout << "traversal using iterator..." << endl;
    auto vit2 = v1.begin();
    auto ven2 = v1.end();
    auto en2 = btemp2.end();
    auto it2 = btemp2.begin();
    for(; vit2 != ven2; ++vit2) { //compare from the bst to the vector
        if(! (it2 != en2) ) {
            cout << *it2 << "," << *vit2 
                 << ": Early termination of (temp BST 2) iteration." << endl;
            return -1;

        }
        cout << *it2 << endl;
        if(*it2 != *vit2) {
            cout << *it2 << "," << *vit2 
                 << ": Incorrect inorder iteration of (temp BST 2)." << endl;
            return -1;
        }
        ++it2;
    }
    cout << "test success for temp bst 2!" << endl;
	
    cout << "All tests passed!" << endl;
    return 0;
}
