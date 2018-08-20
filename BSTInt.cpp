/**
  * Partner1:
  * Name: Jiaqi Fan
  * PID: A12584051
  * Partner2:
  * Name: Xuanru Zhu
  * PID: A91064234
  * Date: 1/20/2017
  */
// this file is the basically same from BST.hpp
// this time the header .h file and method .cpp files are separate
//this class holds the methods such as insert, deleteall, find, and empty for a BST
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  
  while (curr) { // while while loop base case is wrong which cause the bug for insert
    if (item < curr->data) {
      if(!curr->left){
        break;
      }
      curr = curr->left;
    }
    else if (curr->data < item) {
      if(!curr->right){
        break;
      }
      curr = curr->right;
    }
    else {
      return false;
    }
  }

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else {
    curr->right = newNode;
    newNode->parent = curr;
  }

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

/** Helper method to find height of a non empty tree */
//this method use recurrsion
int findHeight(BSTNodeInt* n){
  if(n->left == NULL && n->right == NULL){ //base case if both left and right are empty
    return 0;
  }
  else if(n->left == NULL){ //if the left is empty check the right side
    return 1 + findHeight(n->right);
  }
  else if(n->right == NULL){ //if the rightside is empty check left side
    return 1 + findHeight(n->left);
  }
  else{
    int leftH = 0; // initialize left height
    int rightH = 0; // initialize right height
    leftH = findHeight(n->left); // call the recurrsion on left
    rightH = findHeight(n->right); // call the recurrsion on right
    if(leftH >= rightH){ //check which side is higher
      return 1 + leftH; //return the height
    }
    else{
      return 1 + rightH; //return the height
    }
  }
}
  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */
int BSTInt::height() const
{
  // TODO
  if(!root){
    return -1;
  }
  int height = 0;
  height = findHeight(root); //call the helper method to find height
  return height; //return the height
}

/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  // TODO
  if(!root){ //if the root is emppty return true
    return true;
  }
  else{
    return false; //else return false
  }
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  // TODO
  if(n != NULL){ //base case for recurrsion 
    deleteAll(n->left); //recurrion delete all left side elements in tree
    deleteAll(n->right); // recurrsion on the right
    delete n; //call delete
  }
}
