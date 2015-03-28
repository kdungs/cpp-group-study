#ifndef GROUP2_H
#define GROUP2_H

#include <ostream>

namespace Group2 {

namespace Elements {
class A {};
class B {};
class C {};
class D {};
}

template <typename LHS, typename RHS>
struct Mult {};

#define DEFINE_RELATION(X, Y, Z)          \
  template <>                             \
  struct Mult<Elements::X, Elements::Y> { \
    using type = Elements::Z;             \
  }
DEFINE_RELATION(A, A, A);
DEFINE_RELATION(A, B, B);
DEFINE_RELATION(A, C, C);
DEFINE_RELATION(A, D, D);
DEFINE_RELATION(B, A, B);
DEFINE_RELATION(B, B, A);
DEFINE_RELATION(B, C, D);
DEFINE_RELATION(B, D, C);
DEFINE_RELATION(C, A, C);
DEFINE_RELATION(C, B, D);
DEFINE_RELATION(C, C, B);
DEFINE_RELATION(C, D, A);
DEFINE_RELATION(D, A, D);
DEFINE_RELATION(D, B, C);
DEFINE_RELATION(D, C, A);
DEFINE_RELATION(D, D, B);
#undef DEFINE_RELATION

template <typename T>
class Element {
 public:
  using type = T;
  template <typename U, typename R = typename Mult<T, U>::type>
  auto operator*(Element<U>) -> Element<R> {
    return {};
  }
};
using A = Element<Elements::A>;
using B = Element<Elements::B>;
using C = Element<Elements::C>;
using D = Element<Elements::D>;

auto operator<<(std::ostream& os, const A&) -> std::ostream & {
  return (os << 'A');
}
auto operator<<(std::ostream& os, const B&) -> std::ostream & {
  return (os << 'B');
}
auto operator<<(std::ostream& os, const C&) -> std::ostream & {
  return (os << 'C');
}
auto operator<<(std::ostream& os, const D&) -> std::ostream & {
  return (os << 'D');
}
}

#endif  // GROUP2_H
