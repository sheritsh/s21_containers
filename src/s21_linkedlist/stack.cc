#include "stack.h"

#include <stack>

int main() {
  s21::stack<int> myList;
  myList.push(1);
  myList.push(5);

  // Append elements 2, 3, and 4 to the end of the list
  myList.insert_many_front(2, 3, 4);

  // Print the list after insertion
  for (int i = 0; i < 5; ++i) {
    std::cout << myList.top() << std::endl;
    myList.pop();
  }
  std::cout << std::endl;

  // Output: 4 3 2 1 5
  return 0;
}