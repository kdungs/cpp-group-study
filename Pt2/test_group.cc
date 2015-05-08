#include "group.h"

#include <type_traits>

static_assert(std::is_same<Op<Op<A, B>, Op<B, A>>::result, A>::value,
              "(AB)(BA) = A");

static_assert(std::is_same<Op<Op<A, B>, B>::result, A>::value,
              "(AB)B = A");

using x = Op<Op<Op<Op<Op<A, B>, A>, A>, B>, A>::result;
static_assert(std::is_same<x, A>::value, "ABAABA = A");
