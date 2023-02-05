// SPDX-FileCopyrightText: 2023 Daniel Aimé Valcour <fosssweeper@gmail.com>
//
// SPDX-License-Identifier: MIT

/*
    Copyright (c) 2023 Daniel Aimé Valcour
    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef RLM_CELLULAR_DOT_HPP
#define RLM_CELLULAR_DOT_HPP

#include <rlm/concepts.hpp>

namespace rl
{
    template <rl::signed_integral I> struct point2;
    template <rl::signed_integral I> struct segment2;

    template <rl::signed_integral I = int>
    constexpr auto dot(const rl::point2<I>& a, const point2<I>& b) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr auto unit_dot(const rl::point2<I>& a, const point2<I>& b) noexcept;

    template <rl::signed_integral I = int>
    constexpr auto dot(const rl::point2<I>& a, const segment2<I>& b) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr auto unit_dot(const rl::point2<I>& a, const segment2<I>& b) noexcept;

    template <rl::signed_integral I = int>
    constexpr auto dot(const rl::segment2<I>& a, const point2<I>& b) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr auto unit_dot(const rl::segment2<I>& a, const point2<I>& b) noexcept;

    template <rl::signed_integral I = int>
    constexpr auto dot(const rl::segment2<I>& a, const segment2<I>& b) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr auto unit_dot(const rl::segment2<I>& a, const rl::segment2<I>& b) noexcept;
}  // namespace rl

#include <rlm/cellular/detail/dot.inl>

#endif