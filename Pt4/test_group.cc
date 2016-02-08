#include "group.h"

#include <iostream>
#include <type_traits>

static_assert(std::is_same<Op<A, A, A, B, A, B, B, A>::result, B>::value,
              "AAABABBA = B");

void print(A) { std::cout << "A\n"; }
void print(B) { std::cout << "B\n"; }

int main() {
  using result = Op<A, B, A, B>::result;
  print(result{});
}
