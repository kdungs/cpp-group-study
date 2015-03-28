#include "group1.h"
#include "group2.h"

#include <iostream>

auto test1() -> void  {
  using namespace Group1;

  auto x = A * Element::A * Element::B * Element::C * Element::D * Element::B;
  std::cout << x << '\n';
}

auto test2() -> void {
  using namespace Group2;

  auto x = A{} * A{} * B{} * C{} * D{} * B{};
  std::cout << x << '\n';
}

int main() {
 test1();
 test2();
}
