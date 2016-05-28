#include "../linkedlist/linkedlist.h"
#include <iostream>
#include <sstream>

LinkedList::Node* kthToLast(LinkedList::Node* head, int k) {
  LinkedList::Node* lead = head;
  LinkedList::Node* follow = lead;

  /* Advance leading pointer by k nodes.
     On a side note, here's how I like to think of this:
     Suppose you're with a friend, on one side of a river. For some reason,
     you want to end up k feet from the other side, but you don't know how
     wide the river is. So, you cut yourself a rope which is k feet long
     and have your friend swim out into the river until the rope is taut.
     You now have your friend swim to the other side, pulling you along.
     When he reaches the other side, you will be k feet away from that side. */
  while (lead) {
    lead = lead->next;
    if (k-- <= 0) follow = follow->next;
  }
  if (k > 0) return nullptr;
  return follow;
}

int main() {
  std::cout << "Enter a list of integers:" << std::endl;
  LinkedList::Node* list = LinkedList::read(std::cin);
  std::cout << "Enter k (integer > 0): ";
  int k;
  std::cin >> k;
  LinkedList::Node* knode = kthToLast(list, k);
  std::cout << "Kth to last element with k=" << k << ": ";
  if (knode) std::cout << knode->data << std::endl;
  else std::cout << "null" << std::endl;
  LinkedList::destroy(list);
  return 0;
}
