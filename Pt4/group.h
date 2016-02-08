#pragma once

template <typename T> struct result_t { using result = T; };

struct A : result_t<A> {};
struct B : result_t<B> {};

template <typename...> struct Op {};
template <> struct Op<A, A> : A {};
template <> struct Op<A, B> : B {};
template <> struct Op<B, A> : B {};
template <> struct Op<B, B> : A {};

template <typename LHS, typename... RHS>
struct Op<LHS, RHS...> : Op<typename LHS::result, typename Op<RHS...>::result> {};
