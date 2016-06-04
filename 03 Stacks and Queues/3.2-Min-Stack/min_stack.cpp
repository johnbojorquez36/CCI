#include <iostream>
#include <stack>

/* Goal: implement a stack such that getting the minimum element takes 
   only O(1) time

   Well, intuitively, we know that if we want to calculate the minimum
   element in O(1) time we just need to keep track of this somewhere and
   update the value each time we push/pop.

   Great, seems easy enough. We'll just have a member variable min, which
   holds the minimum element at any given moment. Each time we push an 
   element onto the stack, we'll compare it with min, and update if
   necessary. Cool, are we done?

   Not exactly. What happens if we pop the minimum element? Oh no, now we
   have to figure out what the next smallest element is. Well, we knew what
   that element was at some point, but now we have long forgotten it. It 
   seems that we need to keep track of some sort of history of minimum 
   elements. So we need some data structure where we can get the last minimum 
   element in O(1) time, and if we remove that element, we need to be able 
   to get the previous minimum element in a similar way. Sounds like
   we could just use another stack! Let's implement this. 
*/

template <typename T>
class MinStack {
  std::stack<T> data;
  std::stack<T> mins;

public:
  void push(T e) {
    if (mins.empty() || e <= mins.top()) mins.push(e);
    data.push(e);
  }

  void pop() {
    if (!mins.empty() && mins.top() == data.top()) mins.pop();
    data.pop();
  }

  T top() {
    return data.top();
  }

  T min() {
    return mins.top();
  }

  bool empty() {
    return data.empty();
  }
};

/* Now let's test this */
/* Made a nice simple CLI for managing a stack of ints */
void interactiveMinStack(MinStack<int>& s) {
  std::cout << "Enter one of the following commands: " << std::endl
	    << "push <integer>" << std::endl
	    << "pop" << std::endl
	    << "top" << std::endl
	    << "min" << std::endl
	    << "quit" << std::endl;
  std::string command;
  std::cout << "\n> ";
  while (std::cin >> command) {
    if (command.compare("push") == 0) {
      int x;
      std::cin >> x;
      s.push(x);
    } else if (command.compare("pop") == 0) {
      if (!s.empty()) s.pop();
      else std::cout << "empty" << std::endl;
    } else if (command.compare("top") == 0) {
      if (!s.empty()) std::cout << s.top() << std::endl;
      else std::cout << "empty" << std::endl;
    } else if (command.compare("min") == 0) {
      if (!s.empty()) std::cout << s.min() << std::endl;
      else std::cout << "empty" << std::endl;
    } else if (command.compare("quit") == 0) {
      break;
    } else {
      std::cout << "invalid command." << std::endl;
    }
    std::cout << "> ";
  }
}

int main() {
  MinStack<int> myStack;
  interactiveMinStack(myStack);
  return 0;
}
