#include "../linkedlist/linkedlist.h"
#include <iostream>

LinkedList::Node* partition(LinkedList::Node* head, int x) {
  LinkedList::Node* begin = nullptr;
  LinkedList::Node* left = nullptr;
  LinkedList::Node* middle = nullptr;
  LinkedList::Node* right = nullptr;

  while(head) {
    if (head->data < x) {
      if (!left){
	left = begin = head;
      } else {
	left->next = head;
	left = left->next;
      }
    } else {
      if (!right){
	right = middle = head;
      } else {
	right->next = head;
        right = right->next;
      }
    }
    head = head->next;
  }

  if (left) left->next = middle;
  if (right) right->next = nullptr;
  return begin;
}

int main() {
  std::cout << "Enter a list of integers:" << std::endl;
  LinkedList::Node* list = LinkedList::read(std::cin);
  int x;
  std::cout << "Enter the partitioning element: ";
  std::cin >> x;
  list = partition(list, x);
  std::cout << "Partitioned: " << std::endl;
  LinkedList::print(list);
  LinkedList::destroy(list);
  return 0;
}
