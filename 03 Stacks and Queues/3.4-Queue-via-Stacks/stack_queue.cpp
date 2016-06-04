#include <iostream>
#include <stack>

/* Goal: implement a queue using only two stacks.
   
   Alright, suppose we already have a queue of elements in one of the 
   stacks. Now suppose we would like to dequeue. Well, the element 
   that we wish to dequeue is at the bottom of the first stack. So,
   we would need to remove all of the elements from the first stack
   and temporariily push them onto the second stack, to get to the bottom
   element. When we are done, we push them back onto the first stack. 
   We would have to do something similar for our front() function. This
   would take O(n) time per call to dequeue/front. Can we do better?
   Well, asymptotically, not really, but I think we can make some minor
   improvements. Suppose after we just dequeued an element, we would like
   to dequeue k more times. Since we take all the elements from the
   temporary stack and put them back into the first stack, we'll have to
   repeat this process k times, taking O(kn) time to complete. What 
   if we left them in the temporary stack? That is, after dequeuing an
   element from the bottom of the first stack, leave all of the other
   elements in the second stack. Doing this will allow us to perform
   k more dequeues in O(k) time since the element we wish to dequeue
   will just be at the top of the second stack. When we perform an
   enqueue, we just push to the first stack. Let's implement this.
*/


/* A queue made out of stacks. Very original name :) */
template <typename T>
class StackQueue {
  
  std::stack<T> enqStack; // The stack where we enqueue elements
  std::stack<T> deqStack; // The stack where we dequeue elements

  /* These will allow us to perform front() and back() in O(1) time */
  T frontElem;
  T backElem;

public:

  void enqueue(T e) {
    if (empty()) frontElem = e;
    enqStack.push(e);
    backElem = e;
  }

  void dequeue() {
    if (empty()) throw "empty queue";
    /* We may have to transfer elements from enqStack to deqStack */
    if (deqStack.empty()) {
      while (!enqStack.empty()) {
	T e = enqStack.top();
	enqStack.pop();
	deqStack.push(e);
      } 
    }
    deqStack.pop();
    if (!deqStack.empty()) frontElem = deqStack.top();
  }

  T front() {
    if (empty()) throw "empty queue";
    return frontElem;
  }

  T back() {
    if (empty()) throw "empty queue";
    return backElem;
  }

  bool empty() {
    return enqStack.empty() && deqStack.empty();
  }
};


/******* For testing ******/

void interactiveQueue(StackQueue<int>& q) {
  std::cout << "Enter one of the following commands: " << std::endl
	    << "enq <integer>" << std::endl
	    << "deq" << std::endl
	    << "front" << std::endl
	    << "back" << std::endl
	    << "quit" << std::endl;
  std::string command;
  std::cout << "\n> ";
  while (std::cin >> command) {
    try {
      if (command.compare("enq") == 0) {
	int x;
	std::cin >> x;
	q.enqueue(x);
      } else if (command.compare("deq") == 0) {
	q.dequeue();
      } else if (command.compare("front") == 0) {
	std::cout << q.front() << std::endl; 
      } else if (command.compare("back") == 0) {
	std::cout << q.back() << std::endl; 
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
  StackQueue<int> myQueue;
  interactiveQueue(myQueue);
  return 0;
}
