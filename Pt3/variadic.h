#ifndef VARIADIC_H
#define VARIADIC_H

template <typename T>
T sum(T lhs, T rhs) {
  return lhs + rhs;
}

template <typename T, typename... Ts>
T sum(T head, Ts... tail) {
  return head + sum(tail...);
}

#endif  // VARIADIC_H
