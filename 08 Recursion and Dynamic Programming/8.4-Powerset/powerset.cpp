#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void powerSet(std::vector<int>& set, int i, std::vector<int> subset, std::vector<std::vector<int> >& pset) {
  if (i == set.size()) {
    pset.push_back(subset);
    return;
  }

  /* Don't include S[i]*/
  powerSet(set, i+1, subset, pset);

  /* Include S[i] */
  std::vector<int> cpSubset(subset);
  cpSubset.push_back(set[i]);
  powerSet(set, i+1, cpSubset, pset);
}

std::vector<std::vector<int> > powerSet(std::vector<int>& set) {
  std::vector<int> subset;
  std::vector<std::vector<int> > powerset;
  powerSet(set, 0, subset, powerset);
  return powerset;
}

std::vector<int> readVector(std::istream& in) {
  std::string line;
  std::vector<int> v;
  getline(in, line);
  std::stringstream ss(line);
  int x;
  while(ss >> x) v.push_back(x);
  return v;
}

int main() {
  std::cout << "Enter a set of distinct integers: " << std::endl;
  std::vector<int> set = readVector(std::cin);
  std::vector<std::vector<int> > powerset = powerSet(set);
  for (std::vector<int>& subset : powerset) {
    std::cout << "{";
    for (int x : subset) {
      std::cout << x << ", ";
    }
    std::cout << (subset.empty()? "}" : "\b\b}") << std::endl;
  }
  return 0;
}
    
