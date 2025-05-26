#include <cassert>
#include <ds/vector.hpp>
#include <iostream>

int main() {
  dsa::ds::vector<int> v;
  // Push some values
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  // Check size and content
  assert(v.size() == 3);
  assert(v[0] == 10);
  assert(v.at(1) == 20);
  assert(v.back() == 30);

  // Pop one and check again
  v.pop_back();
  assert(v.size() == 2);
  assert(v.back() == 20);

  // Clear and test empty state
  v.clear();
  assert(v.size() == 0);
  assert(v.empty());

  // Reserve and test capacity increase
  v.reserve(100);
  assert(v.capacity() >= 100);
  v.push_back(5);
  assert(v.front() == 5);

  // Test copy constructor
  dsa::ds::vector<int> v2 = v;
  assert(v2.size() == 1);
  assert(v2[0] == 5);

  // Test move constructor
  dsa::ds::vector<int> v3 = std::move(v2);
  assert(v3.size() == 1);
  assert(v2.size() == 0); // v2 is in moved-from state

  // Test assignment
  dsa::ds::vector<int> v4;
  v4 = v3;
  assert(v4[0] == 5);

  // Range-based for loop (iterator test)
  v4.push_back(7);
  int sum = 0;
  for (int val : v4) {
    sum += val;
  }
  assert(sum == 12);

  std::cout << "All tests passed.\n";

  dsa::ds::vector<int> myVect = {1, 2, 3, 4, 5, 6};
  std::cout << "My Vector: \n";
  std::cout << "[";
  bool first = true;
  for (int i : myVect) {
    (!first) ? std::cout << ", " << i : std::cout << i;
    first = false;
  }
  std::cout << "]\n";
  return 0;
}
