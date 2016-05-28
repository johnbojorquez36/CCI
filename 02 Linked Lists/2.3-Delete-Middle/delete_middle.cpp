#include "../linkedlist/linkedlist.h"
#include <iostream>
#include <sstream>

void deleteMiddle(LinkedList::Node* n) {
  LinkedList::Node* next = n->next; /* Get the next guy */
  n->data = next->data; /* Replace the members of node to delete */
  n->next = next->next; /* Cut the next guy from the list */
  delete next;          /* Delete him */
}

/* Function used for testing */
LinkedList::Node* getMiddleNode(LinkedList::Node* head, int i) {
  if (i <= 0) return nullptr;
  while (i-- > 0 && head) head = head->next;
  return (head && head->next ? head : nullptr);
}

int main() {
  std::cout << "Enter a list of integers:" << std::endl;
  LinkedList::Node* list = LinkedList::read(std::cin);
  std::cout << "Enter the index of the node to delete: ";
  int i;
  std::cin >> i;
  LinkedList::Node* dnode = getMiddleNode(list, i);
  if (!dnode) {
    std::cout << "Invalid node." << std::endl;
    return -1;
  }

  deleteMiddle(dnode);
  LinkedList::print(list);
  LinkedList::destroy(list);
  return 0;
}
