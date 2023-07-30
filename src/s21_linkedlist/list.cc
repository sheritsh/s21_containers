#include "list.h"

#include <list>

int main() {
  s21::List<double> test = {1, 2, 3, 4};
  s21::List<double>::iterator it;
  it = test.begin();
  std::cout << test.front() << "\n";
  test.insert(it, 100);
  std::cout << test.front() << "\n";
  test.insert(it, 102);
  std::cout << test.front() << "\n";
  test.pop_front();
  std::cout << test.front() << "\n";
  
  // for (int i = 0; i < 10; ++i) {
  //   test.push_front(i + 1);
  //   std::cout << test.front() << std::endl;
  // }
  // s21::List<double>::iterator it;
  // // for (it = test.begin(); it != test.end(); ++it) {
  // //   std::cout << *it << " ";
  // // }
  // s21::List<double>::iterator it2;
  // it = test.begin();
  // it2 = test.begin();
  // std::cout << (it == it2 ? "true\n" : "false\n");
  // it2++;
  // std::cout << (it == it2 ? "true\n" : "false\n");
  //   std::list<double> test2;
  //     for (int i = 0; i < 10; ++i) {
  //     test2.push_front(i + 1);
  //     std::cout << test2.front() << std::endl;
  //     test2.pop_front();
  //   }
  //   std::list<double>::iterator it2;
  return 0;
}