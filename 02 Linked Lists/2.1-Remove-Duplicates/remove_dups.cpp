#include <iostream>
#include <sstream>
#include <unordered_map>

/* Note: to solve this problem in constant space, you would need to have a second pointer
   which scans the rest of the list for a duplicate of each element. This would take
   O(N^2) time. */

struct Node {
  int data;
  Node* next;

  Node(int data) : data(data),
		   next(nullptr) {}
};

Node* removeDuplicates(Node* head) {
  /* Keep track of how many times each element appears */
  std::unordered_map<int, int> counts;
  
  Node* curr = head;
  while (curr) {
    /* Increment the count of the current element */
    counts[curr->data]++;

    /* Check if the next element has occurred before */
    while (curr->next && counts[curr->next->data] > 0) {
      /* Delete/skip the duplicate */
      Node* next = curr->next;
      curr->next = curr->next->next;
      delete next;
    }
    /* Advance to the next node */
    curr = curr->next;
  }

  return head;
}

void printLinkedList(Node* head) {
  if (head) {
    std::cout << head->data << " ";
    printLinkedList(head->next);
  } else {
    std::cout << std::endl;
  }
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
  list = removeDuplicates(list);
  printLinkedList(list);
  return 0;
}
