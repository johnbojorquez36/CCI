#include "graph.h"

bool routeExists(std::shared_ptr<Node>& n, std::shared_ptr<Node>& m) {
  if (n == m) return true; // a route exists
  n->visit();
  bool route = false;
  for (std::shared_ptr<Node>& v : n->adjacencyList()) {
    if (!v->isVisited()) {
      route |= routeExists(v, m);
    }
  }
  return route;
}

int main() {
  /* Get the starting and finishing nodes */
  std::string a, b;
  std::cout << "Enter the starting node: ";
  std::cin >> a;
  std::cout << "Enter the finishing node: ";
  std::cin >> b;
  
  std::cout << "Enter a graph:" << std::endl;
  /* Create a graph */
  DirectedGraph g;
  std::cin >> g;
  
  std::shared_ptr<Node> n = g.lookup(a);
  std::shared_ptr<Node> m = g.lookup(b);
  if (!n || !m) {
    std::cout << "invalid nodes" << std::endl;
    return -1;
  }
  std::cout << "A route " << (routeExists(n, m) ? "exists." :
			      "does not exist.") << std::endl;
  return 0;
}
