#include "list.h"

#include <list>
#include <queue>
#include <random>
#include <stack>
#include <vector>

#include "stack.h"
int main() {
  {
    // s21::stack<std::string> s21_stack_1 = {"aboba", "shleppa", "amogus",
    //                                        "abobus"};
    // s21::stack<std::string> s21_stack_2 = {"shtirlits", "vovochka", "poruchik"};
    // s21::stack<std::string> s21_stack_3 = {"aboba", "shleppa", "amogus",
    //                                        "abobus"};
    // s21::stack<std::string> s21_stack_4 = {"shtirlits", "vovochka", "poruchik"};
    s21::deque<std::string> test = {"first", "second", "third"};
    std::cout << test.front();
    // s21_stack_1.swap(s21_stack_2);

    // std::cout << s21_stack_1.size() << " " << s21_stack_4.size();
    // std::cout << s21_stack_2.size() << " " << s21_stack_3.size();
    // for (auto i = 0; i < 4; i++) {
    //   std::cout << s21_stack_3.top() << " " << s21_stack_2.top();
    //   std::cout << s21_stack_3.size() << " " << s21_stack_2.size();
    //   s21_stack_3.pop(), s21_stack_2.pop();
    // }
    // for (auto i = 0; i < 3; i++) {
    //   std::cout << s21_stack_1.top() << " " << s21_stack_4.top();
    //   std::cout << s21_stack_1.size() << " " << s21_stack_4.size();
    //   s21_stack_1.pop(), s21_stack_4.pop();
    // }
  }
  return 0;
}