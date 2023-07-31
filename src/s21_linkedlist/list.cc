#include "list.h"

#include <list>
#include <vector>

int main() {
  {
    s21::List<double> test = {1, 2, 3, 4};
    s21::List<double> test2;
    test2 = test;
    std::cout << "=======\n";
    s21::List<double> test3;
    test3 = std::move(test2);
    s21::List<double>::iterator it;
    it = test3.begin();
    test3.insert(it, 12);
    std::cout << test3.front() << "\n";
    --it;
    std::cout << test3.front() << "\n";
    test3.erase(it);
    std::cout << test3.front();
    s21::List<double>::const_iterator cist;
    cist = test3.begin();
    std::cout << "\n cist : " << *cist;
  }
  {
    std::cout << "\n================\n";
    std::list<int> listint;
    std::cout << listint.max_size() << "\n";
    std::list<double> listdouble;
    std::cout << listdouble.max_size() << "\n";
    std::list<std::vector<std::string>> liststring;
    std::cout << liststring.max_size() << "\n";
  }
  {
    std::cout << "\n================\n";
    s21::List<int> listint;
    std::cout << listint.max_size() << "\n";
    s21::List<double> listdouble;
    std::cout << listdouble.max_size() << "\n";
    s21::List<std::vector<std::string>> liststring;
    std::cout << liststring.max_size() << "\n";
  }
  // s21::List<double> test3;
  // test3 = std::move(test2);

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