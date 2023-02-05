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

#pragma once

#include <rlm/concepts.hpp>
#include <rlm/cellular/concepts.hpp>

namespace rl
{
    template <rl::signed_integral I>
    struct point2;
    template <rl::signed_integral I>
    struct segment2;
    template <rl::signed_integral I>
    struct box2;
    template <rl::signed_integral I, rl::floating_point F>
    struct circle2;

    // point2
    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::point2<I>& containing_point, const rl::point2<I>& contained_point) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::point2<I>& containing_point, const rl::segment2<I>& contained_segment) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::point2<I>& containing_point, const rl::box2<I>& contained_box) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool is_containing(const rl::point2<I>& containing_point, const rl::circle2<I, F>& contained_circle) noexcept;

    // segment2
    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::segment2<I>& containing_segment, const rl::point2<I>& contained_point) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::segment2<I>& containing_segment, const rl::segment2<I>& contained_segment) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::segment2<I>& containing_segment, const rl::box2<I>& contained_box) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool is_containing(const rl::segment2<I>& containing_segment, const rl::circle2<I, F>& contained_circle) noexcept;

    // box2
    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::box2<I>& containing_box, const rl::point2<I>& contained_box) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::box2<I>& containing_box, const rl::segment2<I>& contained_segment) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool is_containing(const rl::box2<I>& containing_box, const rl::box2<I>& contained_box) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool is_containing(const rl::box2<I>& containing_box, const rl::circle2<I, F>& contained_circle) noexcept;

    // circle2
    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool is_containing(const rl::circle2<I, F>& containing_circle, const rl::point2<I>& contained_point) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool is_containing(const rl::circle2<I, F>& containing_circle, const rl::segment2<I>& contained_segment) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool is_containing(const rl::circle2<I, F>& containing_circle, const rl::box2<I>& contained_box) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool is_containing(const rl::circle2<I, F>& containing_circle, const rl::circle2<I, F>& contained_circle) noexcept;

    template<
        typename I = int,
        typename F = float,
        rl::cellular_shape<I, F> Sa,
        rl::cellular_shape<I, F> Sb,
        rl::cellular_shape<I, F>... Ss
    >
    constexpr rl::box2<I> is_containing(const Sa& containing_shape, const Sb& contained_shape_a const Ss&... contained_shape_n) noexcept;
}  // namespace rl

#include <rlm/cellular/detail/is_containing.inl>

