#include "test.h"

int main() {
  s21::Listt<int> test;
  test.push_front(10);
  test.push_front(101);
  test.push_front(1011);
  s21::Listt<int>::iterator it;
  it = test.begin();
  it++;
  std::cout << *it;
  return 0;
}