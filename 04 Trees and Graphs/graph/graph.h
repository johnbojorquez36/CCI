#pragma once
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include <iostream>

class Node {
  std::string id;
  bool visited;
  std::vector<std::shared_ptr<Node>> adjacentNodes;
    
public:
  Node(std::string id) : id(id) {}
  void visit() { visited = true; }
  bool isVisited() { return visited; }
  void addAdjacentNode(std::shared_ptr<Node>);
  std::vector<std::shared_ptr<Node>>& adjacencyList();
};

class Graph {
protected:
  std::unordered_map<std::string, std::shared_ptr<Node>> nodes;

public:
  virtual void connect(std::string v, std::string w) = 0;
  std::shared_ptr<Node> lookup(std::string s) { return nodes[s]; }
  std::unordered_map<std::string, std::shared_ptr<Node>>::iterator begin();
  std::unordered_map<std::string, std::shared_ptr<Node>>::iterator end(); 
};
    
class DirectedGraph : public Graph {
public:
  void connect(std::string v, std::string w);
};

class UndirectedGraph : public Graph {
public:
  void connect(std::string v, std::string w);
};

std::istream& operator>>(std::istream& in, Graph& g);


