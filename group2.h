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

template <>
struct Mult<Elements::A, Elements::A> {
  using type = Elements::A;
};
template <>
struct Mult<Elements::A, Elements::B> {
  using type = Elements::B;
};
template <>
struct Mult<Elements::A, Elements::C> {
  using type = Elements::C;
};
template <>
struct Mult<Elements::A, Elements::D> {
  using type = Elements::D;
};

template <>
struct Mult<Elements::B, Elements::A> {
  using type = Elements::B;
};
template <>
struct Mult<Elements::B, Elements::B> {
  using type = Elements::A;
};
template <>
struct Mult<Elements::B, Elements::C> {
  using type = Elements::D;
};
template <>
struct Mult<Elements::B, Elements::D> {
  using type = Elements::C;
};

template <>
struct Mult<Elements::C, Elements::A> {
  using type = Elements::C;
};
template <>
struct Mult<Elements::C, Elements::B> {
  using type = Elements::D;
};
template <>
struct Mult<Elements::C, Elements::C> {
  using type = Elements::B;
};
template <>
struct Mult<Elements::C, Elements::D> {
  using type = Elements::A;
};

template <>
struct Mult<Elements::D, Elements::A> {
  using type = Elements::D;
};
template <>
struct Mult<Elements::D, Elements::B> {
  using type = Elements::C;
};
template <>
struct Mult<Elements::D, Elements::C> {
  using type = Elements::A;
};
template <>
struct Mult<Elements::D, Elements::D> {
  using type = Elements::B;
};

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
