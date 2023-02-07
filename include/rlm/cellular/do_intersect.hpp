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
    constexpr bool do_intersect(const rl::point2<I>& point_a, const rl::point2<I>& point_b) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::point2<I>& point, const rl::segment2<I>& segment) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::point2<I>& point, const rl::box2<I>& box) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool do_intersect(const rl::point2<I>& point, const rl::circle2<I, F>& circle) noexcept;

    // segment2
    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::segment2<I>& segment, const rl::point2<I>& point) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::segment2<I>& segment, const rl::box2<I>& box) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool do_intersect(const rl::segment2<I>& segment, const rl::circle2<I, F>& circle) noexcept;

    // box2
    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::box2<I>& box, const rl::point2<I>& point) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::box2<I>& box, const rl::segment2<I>& segment) noexcept;

    template <rl::signed_integral I = int>
    constexpr bool do_intersect(const rl::box2<I>& box_a, const rl::box2<I>& box_b) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool do_intersect(const rl::box2<I>& box, const rl::circle2<I, F>& circle) noexcept;

    // circle2
    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool do_intersect(const rl::circle2<I, F>& circle, const rl::point2<I>& point) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool do_intersect(const rl::circle2<I, F>& circle, const rl::segment2<I>& segment) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool do_intersect(const rl::circle2<I, F>& circle, const rl::box2<I>& box) noexcept;

    template <rl::signed_integral I = int, rl::floating_point F = float>
    constexpr bool do_intersect(const rl::circle2<I, F>& circle_a, const rl::circle2<I, F>& circle_b) noexcept;
}  // namespace rl

#include <rlm/cellular/detail/do_intersect.inl>

