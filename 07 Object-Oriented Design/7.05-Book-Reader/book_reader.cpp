#include <string>
#include <vector>
#include <map>

class Book {
  std::string title;
  std::string author;
  std::string information;
  std::vector<std::string> pages;
  
public:
  Book(std::string title, std::string author, std::string info,
       std::vector<std::string> pages);
  std::string getPage(int i);
  int numPages() { return pages.size(); }
};

class Library {
  std::map<int, Book*> books; // Each book has a unique ID

public:
  void addBook(int id, Book* b);
  void removeBook(int id);
  void removeBook(Book* b);
};

class User {
  int id;
  std::string information;
  std::string subscriptionType;

public:
  int getID();
  std::string getInformation();
  std::string getSubscriptionType();
  void setInformation(std::string info);
  void setSubscriptionType(std::string sub);
};

class UserManager {
  std::map<int, User*> users;

public:
  void addUser(int id, User* u);
  void removeUser(int id);
  void removeUser(User* u);
};

class Reader {
  Book* currentBook;
  int currentPage;

public:
  void setBook(Book* book);
  void displayPage(int i);
  void displayNextPage() {
    if (currentPage < currentBook->numPages()-1)
      displayPage(++currentPage);
  }
  
  void displayPreviousPage() {
    if (currentPage > 0)
      displayPage(--currentPage);
  }
  
  Book* getCurrentBook();
};

class OnlineReaderSystem {
  UserManager userManager;
  Library library;
  Reader reader;
  User currentUser;

public:
  UserManager& getUserManager();
  Library& getLibrary();
  Reader& getReader();
  User& getCurrentUser();
  void setCurrentUser(User* u);
  void displayBook(Book* b) {
    reader.setBook(b);
    reader.displayPage(0);
  }
};




