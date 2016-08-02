#include <vector>
#include <queue>
#include <string>

class Caller {
  int phoneNumber;
  std::string name;
public:
  Caller(int number, std::string name);
  int getNumber();
  std::string getName();
};

class Call {
  int level;
  Caller caller;
  
public:
  Call(int level, Caller caller);
  int getLevel();
  Caller getCaller();
  void reply(std::string msg);
};

class Employee {
protected:
  std::string name;
  int level;
  bool available;

public:
  Employee(int level, std::string name);
  virtual void answerCall(Call c) = 0;
  bool isAvailable();
};

class Respondant : Employee {
public:
  void answerCall(Call c);
};

class Manager : Employee {
public:
  void answerCall(Call c);
};

class Director : Employee {
public:
  void answerCall(Call c);
};

class CallCenter {
  /* Lists of employees by level of authority */
  std::vector<std::vector<Employee*>> employees;
  /*List of queues by level required to handle */
  std::vector<std::queue<Call*>> queues;

public:
  CallCenter(int numRespondants, int numManagers, int numDirectors);
  Employee* getNextAvailable(Call c);
  void dispatchCall(Call c);
};
