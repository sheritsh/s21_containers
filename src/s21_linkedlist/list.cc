#include "list.h"

#include <list>
#include <queue>
#include <random>
#include <stack>
#include <vector>

#include "stack.h"

int main() {
  s21::list<int> our_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::list<int> our_copy(std::move(our_list));
  std::list<int> std_copy(std::move(std_list));
  return 0;
}