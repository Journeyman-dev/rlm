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

#ifndef RLM_CELLULAR_DISTANCE_BETWEEN_INL
#define RLM_CELLULAR_DISTANCE_BETWEEN_INL

#include <rlm/concepts.hpp>
#include <rlm/cellular/point2.hpp>
#include <rlm/cellular/segment2.hpp>

// point2
template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point_a, const rl::point2<I>& point_b) noexcept
{
    rl::magnitude<I, F>(point_a - point_b);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point, const rl::segment2<I>& segment) noexcept
{
    const auto segment_as_point_o = rl::as_point2(segment)
    if (segment_as_point_o.has_value())
    {
        return rl::distance<I, F>(point, segment_as_point_o.value());
    }
    if (
        rl::dot(
            rl::translation(segment),
            rl::start(segment) - point
        ) < 0
    )
    {
        return rl::distance_between<I, F>(rl::end(segment), point);
    }
    if (
        rl::dot(
            rl::translation(segment),
            rl::end(segment) - point
        ) > 0
    )
    {
        return rl::distance_between<I, F>(rl::start(segment), point);
    }
    const I numerator = std::abs(
        ((segment.end_x - segment.start_x) * (segment.start_y - point.y)) -
        ((segment.start_x - point.x) * (segment.end_y - segment.start_y));
    return static_cast<F>(numerator) / rl::length(segment);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point, const rl::box2<I>& box) noexcept
{
    return rl::magnitude<I, F>(
        rl::point2<I>(
            rl::clamp(point.x, rl::left_x(box), rl::right_x(box)),
            rl::clamp(point.y, rl::top_y(box), rl::bottom_y(box))
        )
    );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point, const rl::circle2<I, F>& circle) noexcept
{
    return
        rl::max(
            rl::distance_between(
                point,
                rl::center(circle)
            ) - circle.radius,
            static_cast<F>(0)
        );
}

// segment2
template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment, const rl::point2<I>& point) noexcept
{
    return rl::distance_between(point, segment);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept
{
    if (rl::is_parallel(segment_a, segment_b))
    {
        if (rl::is_vertical(segment))
        {
            return std::abs(segment_a.start_x - segment_b.start_x);
        }
        else
        {
            return rl::abs(
                rl::y_intercept(segment) - rl::y_intercept(segment_b);
            )
        }
    }
    else
    {
        return rl::min(
            rl::distance_between(
                rl::start(segment_a),
                segment_b
            ),
            rl::distance_between(
                rl::end(segment_a),
                segment_b
            ),
            rl::distance_between(
                rl::start(segment_b),
                segment_a
            ),
            rl::distance_between(
                rl::end(segment_b),
                segment_a
            )
        );
    }
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment, const rl::box2<I>& box) noexcept
{
    if (rl::is_intersecting<I>(segment, box))
    {
        return static_cast<F>(0);
    }
    return
        rl::min(
                rl::distance_between<I, F>(
                    segment,
                    rl::left_border(box)
                ),
                rl::distance_between<I, F>(
                    segment,
                    rl::right_border(box)
                ),
                rl::distance_between<I, F>(
                    segment,
                    rl::top_border(box)
                ),
                rl::distance_between<I, F>(
                    segment,
                    rl::bottom_border(box)
                )
            )
        )
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment, const rl::circle2<I, F>& circle) noexcept
{
    if (rl::intersects<I, F>(segment, circle))
    {
        return static_cast<F>(0);
    }
    const auto unit_dot = rl::unit_dot<I, F>(segment, circle);
    const auto closest_segment_point = rl::point2<I>(
        segment.start_x + (unit_dot * (segment.end_x - segment.start_x)),
        segment.start_y + (unit_dot * (segment.end_y - segment.start_y))
    );
    if (!rl::is_containing(segment, closest_segment_point)) return static_cast<F>(0);
    return rl::distance_between(cpsest_segment_p, circle);
}

// box2
template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box, const rl::point2<I>& point) noexcept
{
    return rl::distance_between<I, F>(point, box);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box, const rl::segment2<I>& segment) noexcept
{
    return rl::distance_between<I, F>(segment, box);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box_a, const rl::box2<I>& box_b) noexcept
{
    const auto bounds = rl::bounding_box2(box_a, box_b);
    const auto inner_width = rl::max(bounds.width - box_a.width - box_b.width, 0);
    const auto inner_height = rl::max(bounds.height - box_a.height - box_b.height, 0);
    return std::sqrt(static_cast<F>((inner_width * inner_width) + (inner_height * inner_height)));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box, const rl::circle2<I, F>& circle) noexcept
{
    return rl::max(
        rl::distance_between(
            box,
            rl::center(circle)
        ) - circle.radius,
        static_cast<F>(0)
    );
}

// circle2
template <rl::signed_integral I, rl::floating_point F>
constexpr F distance_between(const rl::circle2<I, F>& circle, const rl::point2<I>& box) noexcept
{
    return rl::distance_between(box, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F distance_between(const rl::circle2<I, F>& circle, const rl::segment2<I>& segment) noexcept
{
    return rl::distance_between(segment, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F distance_between(const rl::circle2<I, F>& circle, const rl::box2<I>& box) noexcept
{
    return rl::distance_between(box, circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F distance_between(const rl::circle2<I, F>& circle_a, const rl::circle2<I, F>& circle_b) noexcept
{
    return rl::max<F>(
        rl::distance_between<I, F>(
            rl::center(circle_a),
            rl::center(circle_b)
        ) - (circle_a.radius + circle_b.radius),
        static_cast<F>(0)
    );
}

#endif