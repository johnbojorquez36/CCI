#include "../linkedlist/linkedlist.h"
#include <iostream>

bool intersection(LinkedList::Node* list1, LinkedList::Node* list2) {
  LinkedList::Node* scout1 = list1;
  LinkedList::Node* scout2 = list2;
  
  while (scout1 || scout2) {
    if (scout1 == scout2) return true;
    if (scout1) scout1 = scout1->next;
    else scout1 = list2;
    if (scout2) scout2 = scout2->next;
    else scout2 = list1;
  }

  return false;
}

/* Function used for testing */
LinkedList::Node* getNode(LinkedList::Node* head, int i) {
  if (i <= 0) return nullptr;
  while (i-- > 0 && head) head = head->next;
  return (head ? head : nullptr);
}

LinkedList::Node* getTail(LinkedList::Node* head) {
  if (!head) return nullptr;
  while(head->next) head = head->next;
  return head;
}

int main() {
  
  std::cout << "Enter a list of integers:" << std::endl;
  LinkedList::Node* list1 = LinkedList::read(std::cin);
  std::cout << "Enter the index of for intersection (0 for no intersection): ";
  int i;
  std::cin >> i;
  std::getchar();
  std::cout << "Enter a another list of integers:" << std::endl;
  LinkedList::Node* list2 = LinkedList::read(std::cin);
  if (i > 0) {
    LinkedList::Node* inode = getNode(list1, i);
    LinkedList::Node* tail = getTail(list2);
    if (!inode) {
      std::cout << "Invalid node." << std::endl;
      return -1;
    }
    if (tail) tail->next = inode;
    else list2 = inode;
  }

  std::cout << "The lists " << (intersection(list1, list2) ? "do" : "don't")
	    << " intersect" << std::endl;
  return 0;
}
