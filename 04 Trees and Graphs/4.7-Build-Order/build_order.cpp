#include "graph.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <map>

/* Goal: implement an algorithm with will construct an order to build
   projects given the list of dependencies.

   It seems pretty obvious that the dependencies closely resemble edges
   in a directed graph, with the projects being the nodes. What does an
   edge between a and b really mean? Well, it makes sense to say an edge
   exists going from a to b if project a being built means project b can
   then be built, or "b depends on a". So which project do we build first?
   The one with no dependencies! This means that we just need to look
   for a node with 0 incoming edges. Once we build this project, all
   projects that depended on it now have one less dependency.
*/

std::vector<std::string>
buildOrder(std::vector<std::pair<std::string, std::string>>& dependencies) {
  std::shared_ptr<Graph> g = std::make_shared<DirectedGraph>();
  std::vector<std::string> order;
  std::unordered_map<std::shared_ptr<Node>, int> incoming;
  
  for (std::pair<std::string, std::string>& p : dependencies) {
    g->connect(p.second, p.first);
    ++incoming[g->lookup(p.first)];
  }

  for (std::pair<std::string, std::shared_ptr<Node>> n : *g) {
    if (incoming[n.second] == 0) {
      order.push_back(n.second->getID());
    }
  }
 
  if (order.empty()) throw "No valid build order";
  int nextToBuild = 0;
  
  while (nextToBuild < order.size()) {
    for (std::shared_ptr<Node>& n : g->lookup(order[nextToBuild])->adjacencyList()) {
      if (--incoming[n] == 0) order.push_back(n->getID());
    }
    ++nextToBuild;
  }
  
  if (order.size() != incoming.size()) throw "No valid order";
  
  return order;
}

/***** For testing *****/
std::vector<std::pair<std::string, std::string>>
  readDependencies(std::istream& in) {
  std::vector<std::pair<std::string, std::string>> dependencies;
  std::string line;
  std::getline(in, line);
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == '(') {
      ++i;
      std::string label1 = "";
      std::string label2 = "";
      while (i < line.size() && line[i] != ',') label1 += line[i++];
      while (i < line.size() && line[++i] == ' ');
      while (i < line.size() && line[i] != ')') label2 += line[i++];
      dependencies.push_back(std::pair<std::string, std::string>
			     (label1, label2));
    }
  }
  return dependencies;
}

int main() {
  std::cout << "Enter list of dependencies:" << std::endl;
  std::vector<std::pair<std::string, std::string>> dependencies
    = readDependencies(std::cin);
  try {
    std::vector<std::string> order = buildOrder(dependencies);
    std::cout << "Build order:" << std::endl;
    for (std::string s : order) {
      std::cout << s << ", ";
    }
    std::cout << "\b\b " << std::endl;
  } catch (const char * msg) {
    std::cout << msg << std::endl;
  }
  return 0;
}
