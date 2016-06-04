#include <iostream>
#include <stack>

/* Goal: implement a stack which maintains a sorted order.

   It's easy to overcomplicate this one. Suppose you already have a
   sorted stack and you would like to insert an element. How would
   you find where the element belongs in the stack? Well, we could
   keep popping off elements until the element we're inserting is
   less than the top of the stack. We just need somewhere to keep
   the elements we popped off so we can push them back onto the stack.
   We can use another stack!
*/

template <typename T>
class SortStack {
  std::stack<T> data;

public:

  void push(T e) {
    std::stack<T> temp;
    while (!data.empty() && e > data.top()) {
      temp.push(data.top());
      data.pop();
    }
    data.push(e);
    while(!temp.empty()) {
      data.push(temp.top());
      temp.pop();
    }
  }

  void pop() {
    if (data.empty()) throw "empty stack";
    data.pop();
  }

  T top() {
    if (data.empty()) throw "empty stack";
    return data.top();
  }

  bool empty() {
    return data.empty();
  }
};


/******* For testing ******/

void interactiveSortStack(SortStack<int>& s) {
  std::cout << "Enter one of the following commands: " << std::endl
	    << "push <integer>" << std::endl
	    << "pop" << std::endl
	    << "top" << std::endl
	    << "empty" << std::endl
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
      } else if (command.compare("top") == 0) {
	std::cout << s.top() << std::endl;
      } else if (command.compare("empty") == 0) {
	std::cout << (s.empty() ? "true" : "false") << std::endl;
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
  SortStack<int> myStack;
  interactiveSortStack(myStack);
  return 0;
}
