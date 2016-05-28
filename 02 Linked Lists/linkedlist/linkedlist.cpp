#include "linkedlist.h"
#include <sstream>

void LinkedList::print(LinkedList::Node* head) {
  if (head) {
    std::cout << head->data << " ";
    print(head->next);
  } else {
    std::cout << std::endl;
  }
}

LinkedList::Node* LinkedList::read(std::istream& in) {
  LinkedList::Node* head = nullptr;
  LinkedList::Node* curr = head;
  std::string line;
  getline(in, line);
  std::stringstream ss(line);
  int x;
  while(ss >> x) {
    LinkedList::Node* n = new Node(x);
    if (head) {
      curr->next = n;
      curr = n;
    } else {
      head = curr = n;
    }
  }

  return head;
}

void LinkedList::destroy(LinkedList::Node* head) {
  if (!head) return;  
  Node* curr = head;
  Node* next = curr->next;
  
  while (curr) {
    delete curr;
    curr = next;
    if (next) next = next->next;
  }
}
