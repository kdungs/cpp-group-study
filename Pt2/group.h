#ifndef GROUP_H
#define GROUP_H

struct A { using result = A; };
struct B { using result = B; };

template <typename LHS, typename RHS>
struct Op {
  using result =
      typename Op<typename LHS::result, typename RHS::result>::result;
};

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
