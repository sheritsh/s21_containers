#include "list.h"

#include <list>
#include <queue>
#include <random>
#include <stack>
#include <vector>

#include "stack.h"
int main() {
  {
  s21::list<int> my_list1;
  my_list1.insert(my_list1.end(), 5);

  }
  std::cout << "\n\n";
  {
  std::list<int> std_list1;
  std_list1.insert(std_list1.end(), 5);
  }
  return 0;
}