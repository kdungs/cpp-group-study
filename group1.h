#ifndef GROUP_H
#define GROUP_H

#include <cassert>
#include <memory>
#include <ostream>

namespace Group1 {
enum class Element { A, B, C, D };

static const auto A = Element::A;
static const auto B = Element::B;
static const auto C = Element::C;
static const auto D = Element::D;

auto operator*(Element lhs, Element rhs) noexcept -> Element {
  switch (lhs) {
    case A:
      switch (rhs) {
        case A:
          return A;
        case B:
          return B;
        case C:
          return C;
        case D:
          return D;
        default:
          assert(false);
      }
    case B:
      switch (rhs) {
        case A:
          return B;
        case B:
          return A;
        case C:
          return D;
        case D:
          return C;
        default:
          assert(false);
      }
    case C:
      switch (rhs) {
        case A:
          return C;
        case B:
          return D;
        case C:
          return B;
        case D:
          return A;
        default:
          assert(false);
      }
    case D:
      switch (rhs) {
        case A:
          return D;
        case B:
          return C;
        case C:
          return A;
        case D:
          return B;
        default:
          assert(false);
      }
    default:
      assert(false);
  }
}

auto show(Element e) noexcept -> std::string {
  switch (e) {
    case A:
      return "A";
    case B:
      return "B";
    case C:
      return "C";
    case D:
      return "D";
    default:
      assert(false);
  }
}

auto operator<<(std::ostream& os, Element e) -> std::ostream & {
  return (os << show(e));
}
}

#endif  // GROUP_H
