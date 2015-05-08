#ifndef GROUP_H
#define GROUP_H

struct A {};
struct B {};

template <typename LHS, typename RHS>
struct Op {};

template <>
struct Op<A, A> {
  using result = A;
};

template <>
struct Op<A, B> {
  using result = B;
};

template <>
struct Op<B, A> {
  using result = B;
};

template <>
struct Op<B, B> {
  using result = A;
};

#endif  // GROUP_H
