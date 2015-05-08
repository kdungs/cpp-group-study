#include "group.h"

#include <type_traits>

static_assert(std::is_same<Op<A, A>::result, A>::value, "A × A = A");
static_assert(std::is_same<Op<A, B>::result, B>::value, "A × B = B");
static_assert(std::is_same<Op<B, A>::result, B>::value, "B × A = B");
static_assert(std::is_same<Op<B, B>::result, A>::value, "B × B = A");

using res = Op<A, Op<B, Op<A, Op<A, Op<B, A>::result>::result>::result>::result>::result;
static_assert(std::is_same<res, A>::value, "Test");
