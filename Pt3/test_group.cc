#include "group.h"

#include <type_traits>

static_assert(std::is_same<Op<A, A, A, B, A, B, B, A>::result, B>::value,
              "AAABABBA = B");
