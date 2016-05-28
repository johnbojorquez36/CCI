#include "../linkedlist/linkedlist.h"
#include <iostream>

/* A few ways I can think of doing this:
 * 1. Reverse list and compare with stack of elems
 *    O(n) time, O(n) space
 * 2. Add first half of elements to stack, and compare with rest
 *    O(n) time, O(n) space
 * 3. Reverse second half of list, and compare both halfs
 *    O(n) time, O(1) space
 */

bool isPalindrome(LinkedList::Node* head) {
  if (!head) return true;
  int length = LinkedList::length(head);
  int middle = length / 2;

  LinkedList::Node* prev = nullptr;
  LinkedList::Node* curr = head;
  LinkedList::Node* next = head->next;

  /* Reverse the second half */
  for (int i = 0; i < length; ++i) {
    if (i > middle) curr->next = prev;
    prev = curr;
    if (next) curr = next;
    if (next) next = next->next;
  }

  for (int i = 0; i < middle; ++i) {
    if (head->data != curr->data) return false;
    head = head->next;
    curr = curr->next;
  }

  return true;
}


int main() {
  std::cout << "Enter a list of integers:" << std::endl;
  LinkedList::Node* list = LinkedList::read(std::cin);
  std::cout << "The list " << (isPalindrome(list) ? "is" : "isn't") << " a palindrome." << std::endl;
  return 0;
}
