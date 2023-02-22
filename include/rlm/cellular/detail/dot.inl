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
#include <rlm/cellular/cell_vector2.hpp>
#include <rlm/cellular/cell_segment2.hpp>
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/translation.hpp>
#include <rlm/cellular/distance_between.hpp>

template<rl::signed_integral I>
constexpr I rl::dot(const rl::cell_vector2<I>& point_a, const cell_vector2<I>& point_b) noexcept
{
    return (point_a.x * point_b.x) + (point_a.y * point_b.y);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr F rl::unit_dot(const rl::cell_vector2<I>& point_a,
                         const cell_vector2<I>& point_b) noexcept
{
    if (point_a == point_b) { return static_cast<F>(0); }
    return static_cast<F>(rl::dot<I>(point_a, point_b)) /
           (rl::distance_between<I, F>(point_a, point_b) *
            rl::distance_between<I, F>(point_a, point_b));
}

template<rl::signed_integral I>
constexpr I rl::dot(const rl::cell_vector2<I>& point, const cell_segment2<I>& segment) noexcept
{
    return ((point.x - segment.start_x) * (segment.end_x - segment.start_x)) +
           ((point.y - segment.start_y) * (segment.end_y - segment.start_y));
}

template<rl::signed_integral I, rl::floating_point F>
constexpr F rl::unit_dot(const rl::cell_vector2<I>& point, const cell_segment2<I>& segment) noexcept
{
    if (point == rl::start<I>(segment) && point == rl::end<I>(segment))
    {
        return static_cast<F>(0);
    }
    return static_cast<F>(rl::dot<I>(point, segment)) /
           (rl::distance_between<I, F>(point, segment) *
            rl::distance_between<I, F>(point, segment));
}

template<rl::signed_integral I>
constexpr I rl::dot(const rl::cell_segment2<I>& segment, const cell_vector2<I>& point) noexcept
{
    return rl::dot<I>(point, segment);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr F rl::unit_dot(const rl::cell_segment2<I>& segment, const cell_vector2<I>& point) noexcept
{
    return rl::unit_dot<I, F>(point, segment);
}

template<rl::signed_integral I>
constexpr I rl::dot(const rl::cell_segment2<I>& segment_a,
                    const cell_segment2<I>& segment_b) noexcept
{
    return rl::dot<I>(rl::translation(segment_a), rl::translation(segment_b));
}

template<rl::signed_integral I, rl::floating_point F>
constexpr F rl::unit_dot(const rl::cell_segment2<I>& segment_a,
                         const rl::cell_segment2<I>& segment_b) noexcept
{
    return rl::unit_dot<I, F>(rl::translation(segment_a), rl::translation(segment_b));
}
