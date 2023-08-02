#include "queue.h"

int main() {
  s21::queue<int> myList;
  myList.push(1);
  myList.push(5);

  // Append elements 2, 3, and 4 to the end of the list
  myList.insert_many_back(2, 3, 4);

  // Print the list after insertion
  for (int i = 0; i < 5; ++i) {
    std::cout << myList.front() << std::endl;
    myList.pop();
  }
  std::cout << std::endl;

  // Output: 1 5 2 3 4
  return 0;
}