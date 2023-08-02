#include "list.h"

#include <list>
#include <queue>
#include <random>
#include <stack>
#include <vector>

#include "stack.h"

int main() {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(5);
  myList.push_back(9);

  // Insert elements 2, 3, and 4 before the second element (5)
  auto it = myList.begin();
  ++it;
  std::cout << "it is: " << *it << std::endl;
  myList.insert_many(it, 2, 3, 4);
  std::cout << "it is: " << *it << std::endl;
  // Print the list after insertion
  for (const auto& val : myList) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  // Output: 1 2 3 4 5 9

  return 0;
}