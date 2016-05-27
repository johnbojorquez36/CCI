#include <iostream>
#include <sstream>

struct Node {
  int data;
  Node* next;

  Node(int data) : data(data),
		   next(nullptr) {}
};

Node* kthToLast(Node* head, int k) {
  Node* lead = head;
  Node* follow = lead;

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

Node* readLinkedList(std::istream& in) {
  Node* head = nullptr;
  Node* curr = head;
  std::string line;
  getline(in, line);
  std::stringstream ss(line);
  int x;
  while(ss >> x) {
    Node* n = new Node(x);
    if (head) {
      curr->next = n;
      curr = n;
    } else {
      head = curr = n;
    }
  }

  return head;
}

int main() {
  std::cout << "Enter a list of integers:" << std::endl;
  Node* list = readLinkedList(std::cin);
  std::cout << "Enter k (integer > 0): ";
  int k;
  std::cin >> k;
  Node* knode = kthToLast(list, k);
  std::cout << "Kth to last element with k=" << k << ": ";
  if (knode) std::cout << knode->data << std::endl;
  else std::cout << "null" << std::endl;
  return 0;
}
