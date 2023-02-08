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
#include <rlm/cellular/point2.hpp>
#include <rlm/cellular/segment2.hpp>
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/circle2.hpp>
#include <rlm/cellular/center.hpp>
#include <rlm/cellular/does_contain.hpp>
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/dot.hpp>
#include <rlm/cellular/box2_borders.hpp>
#include <rlm/cellular/are_collinear.hpp>
#include <rlm/cellular/segment2_formula.hpp>
#include <rlm/cellular/shape_edges.hpp>

// point2
template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::point2<I>& point_a, const rl::point2<I>& point_b) noexcept
{
    return point_a == point_b;
}

template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::point2<I>& point, const rl::segment2<I>& segment) noexcept
{
    return
        rl::does_contain<I>(
            segment,
            point
        );
}

template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::point2<I>& point, const rl::box2<I>& box) noexcept
{
    return
        rl::does_contain<I>(
            box,
            point
        );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::do_intersect(const rl::point2<I>& point, const rl::circle2<I, F>& circle) noexcept
{
    return
        rl::does_contain<I>(
            circle,
            point
        );
}

// segment2
template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::segment2<I>& segment, const rl::point2<I>& point) noexcept
{
    return rl::do_intersect<I>(point, segment);
}

template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept
{
    const auto cross_z = rl::cross_z<I>(segment_a, segment_b);
    if (cross_z == 0)
    {
        // the segments are parallel
        if (rl::y_intercept(segment_a) != rl::y_intercept(segment_b))
        {
            return false;
        }
        if (
            (
                segment_a.start_x >= segment_b.start_x &&
                segment_a.start_x <= segment_b.end_x
            ) ||
            (
                segment_a.end_x >= segment_b.start_x &&
                segment_a.end_x <= segment_b.end_x
            ) ||
            (
                segment_b.start_x >= segment_a.start_x &&
                segment_b.start_x <= segment_a.end_x
            ) ||
            (
                segment_b.end_x >= segment_a.start_x &&
                segment_b.end_x <= segment_a.end_x
            )
        )
        {
            return true;
        }
        return false;
    }
    const double intersection_lerp_x =
        static_cast<double>(
            (
                (segment_b.end_x - segment_b.start_x) *
                (segment_a.start_y - segment_b.start_y)
            ) *
            (
                (segment_b.end_y - segment_b.start_y) *
                (segment_a.start_x - segment_b.start_x)
            )
        ) / static_cast<double>(cross_z);
    const double intersection_lerp_y =
        static_cast<double>(
            (
                (segment_a.end_x - segment_a.start_x) *
                (segment_a.start_y - segment_b.start_y)
            ) *
            (
                (segment_a.end_y - segment_a.start_y) *
                (segment_a.start_x - segment_b.start_x)
            )
        ) / static_cast<double>(cross_z);
    return
        intersection_lerp_x >= 0 &&
        intersection_lerp_x <= 1 &&
        intersection_lerp_y >= 0 &&
        intersection_lerp_y <= 1;
}

template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::segment2<I>& segment, const rl::box2<I>& box) noexcept
{
    return
        rl::does_contain<I>(
            box,
            segment
        ) ||
        rl::do_intersect<I>(
            segment,
            rl::left_border<I>(box)
        ) ||
        rl::do_intersect<I>(
            segment,
            rl::right_border<I>(box)
        ) ||
        rl::do_intersect<I>(
            segment,
            rl::top_border<I>(box)
        ) ||
        rl::do_intersect<I>(
            segment,
            rl::bottom_border<I>(box)
        );

}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::do_intersect(const rl::segment2<I>& segment, const rl::circle2<I, F>& circle) noexcept
{
    if (
        rl::do_intersect<I, F>(
            rl::start<I, F>(segment),
            circle
        ) ||
        rl::do_intersect<I, F>(
            rl::end<I, F>(segment),
            circle
        )
    )
    {
        return true;
    }
    const auto unit_dot = rl::unit_dot<I, F>(segment, rl::center<I, F>(circle));
    rl::point2<I> closest_segment_point(
        segment.start_x + (unit_dot * (segment.end_x - segment.start_x)),
        segment.start_y + (unit_dot * (segment.end_y - segment.start_y))
    );
    if (!rl::does_contain<I>(segment, closest_segment_point)) return false;
    return rl::does_contain<I, F>(circle, closest_segment_point);
}

// box2
template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::box2<I>& box, const rl::point2<I>& point) noexcept
{
    return rl::do_intersect(point, box);
}

template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::box2<I>& box, const rl::segment2<I>& segment) noexcept
{
    return rl::do_intersect(segment, box);
}

template <rl::signed_integral I>
constexpr bool rl::do_intersect(const rl::box2<I>& box_a, const rl::box2<I>& box_b) noexcept
{
    return
        rl::left_x<I>(box_a) <= rl::right_x<I>(box_b) &&
        rl::right_x<I>(box_a) >= rl::left_x<I>(box_b) &&
        rl::top_y<I>(box_a) <= rl::bottom_y<I>(box_b) &&
        rl::bottom_y<I>(box_a) >= rl::top_y<I>(box_b);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::do_intersect(const rl::box2<I>& box, const rl::circle2<I, F>& circle) noexcept
{
    return
        rl::distance_between<I, F>(
            box,
            rl::center<I, F>(circle)
        ) - circle.radius <= circle.radius;
}

// circle2
template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::do_intersect(const rl::circle2<I, F>& circle, const rl::point2<I>& point) noexcept
{
    return rl::do_intersect<I, F>(point, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::do_intersect(const rl::circle2<I, F>& circle, const rl::segment2<I>& segment) noexcept
{
    return rl::do_intersect<I, F>(segment, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::do_intersect(const rl::circle2<I, F>& circle, const rl::box2<I>& box) noexcept
{
    return rl::do_intersect<I, F>(box, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::do_intersect(const rl::circle2<I, F>& circle_a, const rl::circle2<I, F>& circle_b) noexcept
{
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(circle_a),
            rl::center<I, F>(circle_b)
        ) <=
        circle_a.radius + circle_b.radius;
}

