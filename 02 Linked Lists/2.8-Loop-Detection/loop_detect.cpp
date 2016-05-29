#include "../linkedlist/linkedlist.h"
#include <iostream>

LinkedList::Node* findLoop(LinkedList::Node* head) {
  LinkedList::Node* fast = head;
  LinkedList::Node* slow = head;
  bool loopFound = false;

  do {
    if (!fast || !fast->next) return nullptr;
    fast = (loopFound ? fast->next : fast->next->next);
    slow = slow->next;
    if (fast == slow && !loopFound) {
      slow = head;
      loopFound = true;
    } 
  } while (fast != slow);
  
  return fast;
}

/************ Functions used for testing ****************/

LinkedList::Node* getNode(LinkedList::Node* head, int i) {
  if (i < 0) return nullptr;
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
  LinkedList::Node* list = LinkedList::read(std::cin);
  int i;
  std::cout << "Enter the position of the loop beginning: " << std::endl;
  std::cin >> i;
  LinkedList::Node* tail = getTail(list);
  LinkedList::Node* n = getNode(list, i);
  if (!n) {
    std::cout << "Invalid loop position" << std::endl;
    return -1;
  }
  if (tail) tail->next = getNode(list, i);
  
  LinkedList::Node* loopBegin = findLoop(list);
  if (loopBegin) std::cout << "The loop starts at node " << loopBegin->data;
  else std::cout << "There is no loop" << std::endl;
  std::cout << std::endl;
  return 0;
}

