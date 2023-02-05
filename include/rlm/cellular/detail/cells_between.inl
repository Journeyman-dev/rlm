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

#ifndef RLM_CELLULAR_CELLS_BETWEEN_INL
#define RLM_CELLULAR_CELLS_BETWEEN_INL

#include <rlm/concepts.hpp>
#include <rlm/cellular/point2.hpp>
#include <rlm/cellular/segment2.hpp>
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/circle2.hpp>

// point2
template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::point2<I>& point_a, const rl::point2<I>& point_b) noexcept
{
    return std::floor(rl::distance_between(point_a, point_b));
}

template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::point2<I>& point, const rl::segment2<I>& segment) noexcept
{
    return std::floor(rl::distance_between(point, segment));
}

template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::point2<I>& point, const rl::box2<I>& box) noexcept
{
    return std::floor(rl::distance_between(point, box));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr I rl::cells_between(const rl::point2<I>& point, const rl::circle2<I, F>& circle) noexcept
{
    return std::floor(rl::distance_between(point, circle));
}

// segment2
template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::segment2<I>& segment, const rl::point2<I>& point) noexcept
{
    return std::floor(rl::distance_between(segment, point));
}

template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept
{
    return std::floor(rl::distance_between(segment_a, segment_b));
}

template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::segment2<I>& segment, const rl::box2<I>& box) noexcept
{
    return std::floor(rl::distance_between(segment, box));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr I rl::cells_between(const rl::segment2<I>& segment, const rl::circle2<I, F>& circle) noexcept
{
    return std::floor(rl::distance_between(segment, circle));
}

// box2
template <rl::signed_integral>
constexpr I rl::cells_between(const rl::box2<I>& box, const rl::point2<I>& box) noexcept
{
    return std::floor(rl::distance_between(box, box));
}

template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::box2<I>& box, const rl::segment2<I>& segment) noexcept
{
    return std::floor(rl::distance_between(box, segment));
}

template <rl::signed_integral I>
constexpr I rl::cells_between(const rl::box2<I>& box_a, const rl::box2<I>& box_b) noexcept
{
    return std::floor(rl::distance_between(box_a, box_b));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr I rl::cells_between(const rl::box2<I>& box, const rl::circle2<I, F>& circle) noexcept
{
    return std::floor(rl::distance_between(box, circle));
}

// circle2
template <rl::signed_integral I, rl::floating_point F>
constexpr I rl::cells_between(const rl::circle2<I, F>& circle, const rl::point2<I>& box) noexcept
{
    return std::floor(rl::distance_between(circle, box));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr I rl::cells_between(const rl::circle2<I, F>& circle, const rl::segment2<I>& segment) noexcept
{
    return std::floor(rl::distance_between(circle, segment));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr I rl::cells_between(const rl::circle2<I, F>& circle, const rl::box2<I>& box) noexcept
{
    return std::floor(rl::distance_between(circle, box));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr I rl::cells_between(const rl::circle2<I, F>& circle_a, const rl::circle2<I, F>& circle_b) noexcept
{
    return std::floor(rl::distance_between(circle_a, circle_b));
}

#endif