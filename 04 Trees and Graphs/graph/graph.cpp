#include "graph.h"

std::unordered_map<std::string, std::shared_ptr<Node>>::iterator Graph::begin() {
  return nodes.begin();
}

std::unordered_map<std::string, std::shared_ptr<Node>>::iterator Graph::end() {
  return nodes.end();
}

void DirectedGraph::connect(std::string a, std::string b) {
  std::shared_ptr<Node> n;
  std::shared_ptr<Node> m;

  if (nodes.find(a) != nodes.end()) {
    n = nodes[a];
  } else {
    n = std::make_shared<Node>(a);
    nodes[a] = n;
  }

  if (nodes.find(b) != nodes.end()) {
    m = nodes[b];
  } else {
    m = std::make_shared<Node>(b);
    nodes[b] = m;
  }

  n->addAdjacentNode(m);
}

void UndirectedGraph::connect(std::string a, std::string b) {
  std::shared_ptr<Node> n;
  std::shared_ptr<Node> m;

  if (nodes.find(a) != nodes.end()) {
    n = nodes[a];
  } else {
    n = std::make_shared<Node>(a);
    nodes[a] = n;
  }

  if (nodes.find(b) != nodes.end()) {
    m = nodes[b];
  } else {
    m = std::make_shared<Node>(b);
    nodes[b] = m;
  }

  n->addAdjacentNode(m);
  m->addAdjacentNode(n);
}

void Node::addAdjacentNode(std::shared_ptr<Node> n) {
  adjacentNodes.push_back(n);
}

std::vector<std::shared_ptr<Node>>& Node::adjacencyList() {
  return adjacentNodes;
}

std::istream& operator>>(std::istream& in, Graph& g) {
  std::string a, b;
  while (in >> a && in >> b) g.connect(a, b);
  return in;
}

