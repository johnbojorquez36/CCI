#include <iostream>
#include <cstddef>
#include <utility>
#include <memory>
#include <string>
#include <queue>

/* Goal: implement an animal shelter of cats and dogs such that animals
   are adopted on a "first in, first out" basis.

   If we want to be able to dequeue the oldest dog or cat quickly, it's
   pretty obvious that we'll need to maintain two separate lists. If
   we only had one list, we would have to interate through to find the
   oldest dog/cat and remove them from the list. A problem arises when
   we want to adopt an animal of either type. With just a list of cats
   and a list of dogs, we have no way of knowing whether a dod arrived
   before a cat. This leaves us with some options. We could change the
   two lists to instead store pairs of an animal and the time the animal
   arrived. Each time an animal arrives, increment the current time.
   Another option is to maintain a 3rd list of all the animals in the
   shelter. We just have to make sure to update the corresponding dog
   or cat list when dequeueing an animal of any type. Seems a little more
   natural to just record the time the animal arrived. Think about this
   in real life, would you really want to maintain 3 separate lists?
*/

class Animal {
  std::string name;
public:
  Animal(std::string& name) : name(name) {}
  std::string getName() { return name; }
};

class Dog : public Animal {
public:
  Dog(std::string& name) : Animal(name) {}
};

class Cat : public Animal {
public:
  Cat(std::string& name) : Animal(name) {}
};

class AnimalShelter {
  size_t time = 0;
  std::queue<std::pair<std::shared_ptr<Dog>, std::size_t>> dogs;
  std::queue<std::pair<std::shared_ptr<Cat>, std::size_t>> cats;

public:

  void enqueue(std::shared_ptr<Dog> d) {
    dogs.push(std::pair<std::shared_ptr<Dog>, std::size_t>(d, time++));
  }

  void enqueue(std::shared_ptr<Cat> c) {
    cats.push(std::pair<std::shared_ptr<Cat>, std::size_t>(c, time++));
  }

  std::shared_ptr<Dog> dequeueDog() {
    if (dogs.empty()) throw "shelter has no dogs";
    std::shared_ptr<Dog> d = dogs.front().first;
    dogs.pop();
    return d;
  }

  std::shared_ptr<Cat> dequeueCat() {
    if (cats.empty()) throw "shelter has no cats";
    std::shared_ptr<Cat> c = cats.front().first;
    cats.pop();
    return c;
  }

  std::shared_ptr<Animal> dequeueAny() {
    std::shared_ptr<Animal> a;
    if (cats.empty() && dogs.empty()) throw "empty shelter";
    if (cats.empty() || dogs.front().second < cats.front().second) {
      a = dogs.front().first;
      dogs.pop();
    } else {
      a = cats.front().first;
      cats.pop();
    }
    return a;
  }  
};

void interactiveShelter(AnimalShelter& q) {
  std::cout << "Enter one of the following commands: " << std::endl
	    << "enqDog <name>" << std::endl
	    << "enqCat <name>" << std::endl
	    << "deqDog" << std::endl
	    << "deqCat" << std::endl
	    << "deq" << std::endl
	    << "quit" << std::endl;
  std::string command;
  std::cout << "\n> ";
  while (std::cin >> command) {
    try {
      if (command.compare("enqDog") == 0) {
	std::string name;
	std::cin >> name;
	q.enqueue(std::make_shared<Dog>(name)); 
      } else if (command.compare("enqCat") == 0) {
	std::string name;
	std::cin >> name;
	q.enqueue(std::make_shared<Cat>(name)); 
      } else if (command.compare("deqDog") == 0) {
	std::cout << q.dequeueDog()->getName() << std::endl; 
      } else if (command.compare("deqCat") == 0) {
	std::cout << q.dequeueCat()->getName() << std::endl; 
      } else if (command.compare("deq") == 0) {
	std::cout << q.dequeueAny()->getName() << std::endl; 
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
  AnimalShelter myShelter;
  interactiveShelter(myShelter);
  return 0;
}
