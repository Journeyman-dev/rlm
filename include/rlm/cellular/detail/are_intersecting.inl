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

// point2
template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::point2<I>& point_a, const rl::point2<I>& point_b) noexcept
{
    return point_a == point_b;
}

template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::point2<I>& point, const rl::segment2<I>& segment) noexcept
{
    return
        rl::is_containing(
            segment,
            point
        );
}

template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::point2<I>& point, const rl::box2<I>& box) noexcept
{
    return
        rl::is_containing(
            box,
            point
        );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::are_intersecting(const rl::point2<I>& point, const rl::circle2<I, F>& circle) noexcept
{
    return
        rl::is_containing(
            circle,
            point
        );
}

// segment2
template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::segment2<I>& segment, const rl::point2<I>& point) noexcept
{
    return rl::are_intersecting(point, segment);
}

template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept
{
    auto collinear_points_are_surrounding =
        [](
            const rl::point2<I>& surrounding_a,
            const rl::point2<I>& surrounding_b,
            const rl::point2<I>& surrounded
        )
        {
            return
                surrounded.x <= rl::max(surrounding_a.x, surrounding_b.x) &&
                surrounded.x >= rl::min(surrounding_a.x, surrounding_b.x) &&
                surrounded.y <= rl::max(surrounding_a.y, surrounding_b.y) &&
                surrounded.y > -rl::min(surrounding_a.y, surrounding_b.y);
        };
    auto points_are_collinear_and_surrounding =
        [](
            const rl::point2<I>& surrounding_a,
            const rl::point2<I>& surrounding_b,
            const rl::point2<I>& surrounded
        )
        {
            return
                rl::are_collinear(
                    surrounding_a,
                    surrounding_b,
                    surrounded
                ) &&
                collinear_points_are_surrounding(
                    surrounding_a,
                    surrounding_b,
                    surrounded
                );
        };
    if (
        points_are_collinear_and_surrounding(
            rl::start(segment_a),
            rl::start(segment_b),
            rl::end(segment_a)
        ) ||
        points_are_collinear_and_surrounding(
            rl::start(segment_a),
            rl::start(segment_b),
            rl::end(segment_b)
        ) ||
        points_are_collinear_and_surrounding(
            rl::end(segment_a),
            rl::end(segment_b),
            rl::start(segment_a)
        ) ||
        points_are_collinear_and_surrounding(
            rl::end(segment_a),
            rl::end(segment_b),
            rl::start(segment_b)
    )
    {
        return true;
    }
    return false;
    )
}

template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::segment2<I>& segment, const rl::box2<I>& box) noexcept
{
    return
        rl::is_containing(
            box,
            segment
        ) ||
        rl::is_intersecting(
            segment,
            rl::left_border(box)
        ) ||
        rl::is_intersecting(
            segment,
            rl::right_border(box)
        ) ||
        rl::is_intersecting(
            segment,
            rl::top_border(box)
        ) ||
        rl::is_intersecting(
            segment,
            rl::bottom_border(box)
        );

}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::are_intersecting(const rl::segment2<I>& segment, const rl::circle2<I, F>& circle) noexcept
{
    if (
        rl::are_intersecting(
            rl::start(segment),
            circle
        ) ||
        rl::are_intersecting(
            rl::end(segment),
            circle
        )
    )
    {
        return true;
    }
    const auto unit_dot = rl::unit_dot(segment, rl::center(circle));
    rl::point2<I> closest_segment_point(
        segment.start_x + (unit_dot * (segment.end_x - segment.start_x)),
        segment.start_y + (unit_dot * (segment.end_y - segment.start_y))
    );
    if (!rl::is_containing(segment, closest_segment_point)) return false;
    return rl::is_containing(circle, closest_segment_point);
}

// box2
template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::box2<I>& box, const rl::point2<I>& point) noexcept
{
    return rl::are_intersecting(point, box);
}

template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::box2<I>& box, const rl::segment2<I>& segment) noexcept
{
    return rl::are_intersecting(segment, box);
}

template <rl::signed_integral I>
constexpr bool rl::are_intersecting(const rl::box2<I>& box_a, const rl::box2<I>& box_b) noexcept
{
    return
        rl::left_x(containing_box) <= rl::right_x(contained_box) &&
        rl::right_x(containing_box) >= rl::left_x(contained_box) &&
        rl::top_y(containing_box) <= rl::bottom_y(contained_box) &&
        rl::bottom_y(containing_box) >= rl::top_y(contained_box);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::are_intersecting(const rl::box2<I>& box, const rl::circle2<I, F>& circle) noexcept
{
    return
        rl::distance_between<I, F>(
            box,
            rl::center(circle)
        ) - circle.radius <= b.radius;
}

// circle2
template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::are_intersecting(const rl::circle2<I, F>& circle, const rl::point2<I>& point) noexcept
{
    return rl::are_intersecting(point, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::are_intersecting(const rl::circle2<I, F>& circle, const rl::segment2<I>& segment) noexcept
{
    return rl::are_intersecting(segment, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::are_intersecting(const rl::circle2<I, F>& circle, const rl::box2<I>& box) noexcept
{
    return rl::are_intersecting(box, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::are_intersecting(const rl::circle2<I, F>& circle_a, const rl::circle2<I, F>& circle_b) noexcept
{
    return
        rl::distance_between<I, F>(
            rl::center(circle_a),
            rl::center(circle_b)
        ) <=
        circle_a.radius + circle_b.radius;
}

