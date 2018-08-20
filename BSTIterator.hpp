/**
  * Partner1:
  * Name: Jiaqi Fan
  * PID: A12584051
  * Partner2:
  * Name: Xuanru Zhu
  * PID: A91064234
  * Date: 1/20/2017
  */
// this file is the BSTIterator.hpp
// this file is a combine of .h and .cpp which makes into .hpp
//this class holds the constructor and methods for BSTIterator. method such as pre-increment
// dereference opeator, and equality/ineuqality check 

#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>


// Notice this class extends the std::iterator class.
template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
  BSTIterator(BSTNode<Data>* curr);

  /** Dereference operator. */
  Data operator*() const;
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++();

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int);

  /** Equality test operator. */
  bool operator==(BSTIterator<Data> const & other) const;

  /** Inequality test operator. */ 
  bool operator!=(BSTIterator<Data> const & other) const;

};

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
template<typename Data>
BSTIterator<Data>::BSTIterator(BSTNode<Data>* curr) {
  // TODO
  // Remember the keyword "this" which stores a pointer to the calling object.
  // It will be helpful to distinguish between the parameter "curr" and the 
  // member variable "curr"
  this->curr = curr; //sign the value of member variable to calling object
}

/** Dereference operator. */
template<typename Data>
Data BSTIterator<Data>::operator*() const {
  return curr->data;
}
  
/** Pre-increment operator. */
template<typename Data>
BSTIterator<Data>& BSTIterator<Data>::operator++() {
  // Call the successor method of the BSTNode pointed to by curr.
  curr = curr->successor();
  return *this;
}

/** Post-increment operator. */
template<typename Data>
BSTIterator<Data> BSTIterator<Data>::operator++(int) {
  BSTIterator before = BSTIterator(curr);
  ++(*this);
  return before;
}

/** Equality test operator. */ // TODO
template<typename Data>
bool BSTIterator<Data>::operator==(BSTIterator<Data> const & other) const {
  // TODO
  // Notice that other is a reference and not a pointer, thus it cannot be null
  // Return true if other is NOT equal to the calling object
  // Two iterators are equal if they point to the same BSTNode in the same BST  
  if(this->curr == other.curr){ //check for equality
    return true; //euqal return true
  }
  else{
    return false; //else return false
  }
}

/** Inequality test operator. */ 
template<typename Data>
bool BSTIterator<Data>::operator!=(BSTIterator<Data> const & other) const {
  // TODO
  // Notice that other is a reference and not a pointer, thus it cannot be null
  // Return true if other is NOT equal to the calling object
  // Two iterators are equal if they point to the same BSTNode in the same BST
  if(this->curr != other.curr){ //check for inequality
    return true; //not equal return true
  }
  else{
    return false; //else return false
  }
}


#endif //BSTITERATOR_HPP
