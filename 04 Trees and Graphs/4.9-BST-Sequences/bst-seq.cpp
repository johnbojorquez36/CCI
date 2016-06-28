#include "tree.h"
#include <iostream>
#include <list>
#include <memory>

/* Goal: Given a BST created by traversing an array from left to right
   and inserting each element, print all possible arrays.

   The idea is to split this problem into two smaller sub-problems. If we
   can get all possible sequences for the left and right subtrees, we can
   form a solution. The root must be the first element in the sequence. The
   rest of the sequence can be formed by enumerating ever possible shuffle
   (maintaining relative order) of the left and right sequences.
*/

typedef std::shared_ptr<Tree::BinaryNode> PBNode;

void stableShuffle(std::list<int>& seqA, std::list<int>& seqB,
		   std::list<int>& prefix, std::list<std::list<int>>& shuffledSeqs) {
  if (seqA.size() == 0 || seqB.size() == 0) {
    std::list<int> shuffledSeq(prefix);
    for (int x : seqA) shuffledSeq.push_back(x);
    for (int x : seqB) shuffledSeq.push_back(x);
    shuffledSeqs.push_back(shuffledSeq);
  } else {
    int headA = seqA.front();
    seqA.pop_front();
    prefix.push_back(headA);
    stableShuffle(seqA, seqB, prefix, shuffledSeqs);
    seqA.push_front(headA);
    prefix.pop_back();

    int headB = seqB.front();
    seqB.pop_front();
    prefix.push_back(headB);
    stableShuffle(seqA, seqB, prefix, shuffledSeqs);
    seqB.push_front(headB);
    prefix.pop_back();
  }
}

std::list<std::list<int>> bstSequences(PBNode root) {
  std::list<std::list<int>> result;
  
  if (!root) {
    result.push_back(std::list<int>());
    return result;
  }

  std::list<int> prefix;
  
  prefix.push_back(root->val);
  
  std::list<std::list<int>> leftSequences = bstSequences(root->left);
  std::list<std::list<int>> rightSequences = bstSequences(root->right);

  for (std::list<int> leftSeq : leftSequences) {
    for (std::list<int> rightSeq : rightSequences) {
      std::list<std::list<int>> shuffledSeqs;
      stableShuffle(leftSeq, rightSeq, prefix, shuffledSeqs);
      for (std::list<int> seq : shuffledSeqs) result.push_back(seq);
    }
  }

  return result;
}

int main() {
    std::cout << "Enter the array representation of a binary tree "
	    << "(ex. 1 3 4 null 8): "
	    << std::endl;
    std::shared_ptr<Tree::BinaryNode> root = Tree::read(std::cin);
    std::list<std::list<int>> bstSeqs = bstSequences(root);
    std::cout << "BST Sequences: " << std::endl;
    for (std::list<int> seq : bstSeqs) {
      for (int x : seq) std::cout << x << ", ";
      std::cout << "\b\b " << std::endl;
    }
      
    return 0;
}
