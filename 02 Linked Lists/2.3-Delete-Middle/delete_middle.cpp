#include <iostream>
#include <sstream>

struct Node {
  int data;
  Node* next;

  Node(int data) : data(data),
		   next(nullptr) {}
};

void deleteMiddle(Node* n) {
  Node* next = n->next; /* Get the next guy */
  n->data = next->data; /* Replace the members of node to delete */
  n->next = next->next; /* Cut the next guy from the list */
  delete next;          /* Delete him */
}

/* Function used for testing */
Node* getMiddleNode(Node* head, int i) {
  if (i <= 0) return nullptr;
  while (i-- > 0 && head) head = head->next;
  return (head && head->next ? head : nullptr);
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
  std::cout << "Enter the index of the node to delete: ";
  int i;
  std::cin >> i;
  Node* dnode = getMiddleNode(list, i);
  if (!dnode) {
    std::cout << "Invalid node." << std::endl;
    return -1;
  }

  deleteMiddle(dnode);
  printLinkedList(list);
  return 0;
}
