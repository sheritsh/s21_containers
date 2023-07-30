#ifndef blabla
#define blabla

#include <iostream>

#include "deque.h"

namespace s21 {
template <class T>
class Listt : public deque<T> {
 public:
  Listt() : deque<T>(){};
};
}  // namespace s21

#endif  // blabla