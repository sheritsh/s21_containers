#include "deque.h"

#include <iostream>

int main() {
  s21::deque<double> test;
  for (int i = 0; i < 10; i++) {
    test.push_front(i + 1);
    std::cout << test.front() << std::endl;
  }
  s21::deque<double>::iterator it;
  for (it = test.begin(); it != test.end(); ++it) {
    std::cout << *it << " ";
  }
  it = test.begin();
  std::cout << "\n" << *it << " ";
  it++;
  std::cout << "\n" << *it << " ";
}