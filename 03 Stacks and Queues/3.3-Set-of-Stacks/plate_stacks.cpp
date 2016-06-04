#include <iostream>
#include <vector>
#include <stack>

/* This problem is pretty straight forward. We just need a set
   of stacks. Each time a stack reaches capacity, we make a new
   one and add it to the set. If we want to implement the popAt()
   function, then we should probably support constant time access
   to any of the stacks. A vector would be perfect for this.
*/

template <typename T>
class PlateStack {
  int capacity;
  std::stack<T> data;

public:
  PlateStack(int capacity) :
    capacity(capacity) {}
  
  void push(T e) {
    if (!full()) data.push(e);
  }

  void pop() {
    data.pop();
  }

  T top() {
    return data.top();
  }

  bool empty() {
    return data.empty();
  }

  bool full() {
    return data.size() >= capacity;
  }
};

template <typename T>
class SetOfStacks {
  std::vector<PlateStack<T>> stacks;
  int capacity;

public:
  SetOfStacks(int capacity) :
    capacity(capacity) {}
  
  void push(T e) {
    if (stacks.empty() || stacks.back().full()) {
      stacks.push_back(PlateStack<T>(capacity));
    }
    stacks.back().push(e);
  }

  void pop() {
    if (stacks.empty()) throw "empty set";
    stacks.back().pop();
    if (stacks.back().empty()) stacks.pop_back();
  }

  T top() {
    if (stacks.empty()) throw "empty set";
    return stacks.back().top();
  }

  void popAt(int i) {
    if (i < 0 || i >= stacks.size()) throw "index out of bounds";
    stacks[i].pop();
    if (stacks[i].empty()) stacks.erase(stacks.begin() + i);
  }
};

/******* For testing ******/

void interactiveSetOfStacks(SetOfStacks<int>& s) {
  std::cout << "Enter one of the following commands: " << std::endl
	    << "push <integer>" << std::endl
	    << "pop" << std::endl
	    << "popat <index>" << std::endl
	    << "top" << std::endl
	    << "quit" << std::endl;
  std::string command;
  std::cout << "\n> ";
  while (std::cin >> command) {
    try {
      if (command.compare("push") == 0) {
	int x;
	std::cin >> x;
	s.push(x);
      } else if (command.compare("pop") == 0) {
	s.pop();
      } else if (command.compare("popat") == 0) {
	int i;
	std::cin >> i;
        s.popAt(i);
      } else if (command.compare("top") == 0) {
	std::cout << s.top() << std::endl;
      } else if (command.compare("quit") == 0) {
	break;
      } else {
	std::cout << "invalid command." << std::endl;
      }
    } catch (const char* msg) {
      std::cout << msg << std::endl;
    }
    std::cout << "> ";
  }
}

int main() {
  std::cout << "Enter a stack capacity: ";
  int c;
  std::cin >> c;
  SetOfStacks<int> myStacks(c);
  interactiveSetOfStacks(myStacks);
  return 0;
}


