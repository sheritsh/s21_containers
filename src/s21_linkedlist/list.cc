#include "list.h"

#include <list>
#include <queue>
#include <random>
#include <stack>
#include <vector>

#include "stack.h"
int main() {
  {
    s21::list<double> test = {1, 2, 3};
    s21::list<double>::iterator it;
    it = test.end();
    test.insert(it, 4);
    --it;
    std::cout << *it;
    it = test.begin();
    for (int i = 0; i < 4; ++i) {
      std::cout << *it;
      ++it;
    }
  }
  std::cout << "\n\n";
  {
    std::list<double> test = {1, 2, 3};
    std::list<double>::iterator it;
    it = test.end();
    test.insert(it, 4);
    --it;
    std::cout << *it;
    it = test.begin();
    for (int i = 0; i < 4; ++i) {
      std::cout << *it;
      ++it;
    }
  }
  return 0;
}