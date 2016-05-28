#include "../linkedlist/linkedlist.h"
#include <iostream>
#include <sstream>
#include <unordered_map>

/* Note: to solve this problem in constant space, you would need to have a second pointer
   which scans the rest of the list for a duplicate of each element. This would take
   O(N^2) time. */

LinkedList::Node* removeDuplicates(LinkedList::Node* head) {
  /* Keep track of how many times each element appears */
  std::unordered_map<int, int> counts;
  
  LinkedList::Node* curr = head;
  while (curr) {
    /* Increment the count of the current element */
    counts[curr->data]++;

    /* Check if the next element has occurred before */
    while (curr->next && counts[curr->next->data] > 0) {
      /* Delete/skip the duplicate */
      LinkedList::Node* next = curr->next;
      curr->next = curr->next->next;
      delete next;
    }
    /* Advance to the next node */
    curr = curr->next;
  }

  return head;
}

int main() {
  std::cout << "Enter a list of integers:" << std::endl;
  LinkedList::Node* list = LinkedList::read(std::cin);
  list = removeDuplicates(list);
  LinkedList::print(list);
  LinkedList::destroy(list);
  return 0;
}
