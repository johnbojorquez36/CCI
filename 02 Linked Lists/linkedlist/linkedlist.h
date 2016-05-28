#pragma once
#include <iostream>

namespace LinkedList {
  
  struct Node {
    int data;
    Node* next;
    Node(int data) : data(data),
		     next(nullptr) {}
  };

  void destroy(Node* list);

  void print(Node* list);

  Node* read(std::istream& in);

}
