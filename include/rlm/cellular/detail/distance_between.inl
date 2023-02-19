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
#include <rlm/cellular/bounding_box2.hpp>
#include <rlm/cellular/dot.hpp>
#include <rlm/cellular/shape_conversion.hpp>
#include <rlm/clamp.hpp>
#include <rlm/cellular/are_parallel.hpp>
#include <rlm/cellular/do_intersect.hpp>
#include <rlm/cellular/segment2_direction.hpp>
#include <rlm/cellular/segment2_formula.hpp>
#include <rlm/cellular/box2_borders.hpp>
#include <rlm/configuration.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <optional>

// point2
template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point_a, const rl::point2<I>& point_b) noexcept
{
    return rl::magnitude<I, F>(point_a - point_b);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point, const rl::segment2<I>& segment) noexcept
{
    const auto segment_as_point_o = rl::as_point2<I>(segment);
    if (segment_as_point_o.has_value())
    {
        return rl::distance_between<I, F>(point, segment_as_point_o.value());
    }
    if (
        rl::dot<I>(
            rl::translation<I>(segment),
            rl::start<I>(segment) - point
        ) < 0
    )
    {
        return rl::distance_between<I, F>(rl::end<I>(segment), point);
    }
    if (
        rl::dot<I>(
            rl::translation<I>(segment),
            rl::end<I>(segment) - point
        ) > 0
    )
    {
        return rl::distance_between<I, F>(rl::start(segment), point);
    }
    const I numerator =
        std::abs(
            ((segment.end_x - segment.start_x) * (segment.start_y - point.y)) -
            ((segment.start_x - point.x) * (segment.end_y - segment.start_y))
        );
    return static_cast<F>(numerator) / rl::length(segment);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point, const rl::box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    if (rl::does_contain(fixed_box, point))
    {
        return static_cast<F>(0);
    }
    return rl::magnitude<I, F>(
        rl::point2<I>(
            point.x < rl::left_x(fixed_box) ?
            rl::left_x(fixed_box) - point.x :
            point.x > rl::right_x(fixed_box) ?
            point.x - rl::right_x(fixed_box) :
            point.x,
            point.y < rl::top_y(fixed_box) ?
            rl::top_y(fixed_box) - point.y :
            point.y > rl::bottom_y(fixed_box) ?
            point.y - rl::bottom_y(fixed_box) :
            point.y
        )
    );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::point2<I>& point, const rl::circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return
        rl::max<F>(
            rl::distance_between<I, F>(
                point,
                rl::center<I, F>(fixed_circle)
            ) - fixed_circle.radius,
            static_cast<F>(0)
        );
}

// segment2
template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment, const rl::point2<I>& point) noexcept
{
    return rl::distance_between<I, F>(point, segment);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept
{
    if (rl::are_parallel<I>(segment_a, segment_b))
    {
        if (rl::is_vertical<I>(segment_a))
        {
            return std::abs(segment_a.start_x - segment_b.start_x);
        }
        else
        {
            return
                std::abs(
                    rl::y_intercept<I>(segment_a) -
                    rl::y_intercept<I>(segment_b)
                );
        }
    }
    else
    {
        return rl::min<F>(
            rl::distance_between<I, F>(
                rl::start<I>(segment_a),
                segment_b
            ),
            rl::distance_between<I, F>(
                rl::end<I>(segment_a),
                segment_b
            ),
            rl::distance_between<I, F>(
                rl::start<I>(segment_b),
                segment_a
            ),
            rl::distance_between<I, F>(
                rl::end<I>(segment_b),
                segment_a
            )
        );
    }
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment, const rl::box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    if (rl::do_intersect<I>(segment, fixed_box))
    {
        return static_cast<F>(0);
    }
    return
        rl::min<F>(
            rl::distance_between<I, F>(
                segment,
                rl::left_border<I>(fixed_box)
            ),
            rl::distance_between<I, F>(
                segment,
                rl::right_border<I>(fixed_box)
            ),
            rl::distance_between<I, F>(
                segment,
                rl::top_border<I>(fixed_box)
            ),
            rl::distance_between<I, F>(
                segment,
                rl::bottom_border<I>(fixed_box)
            )
        );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::segment2<I>& segment, const rl::circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    if (rl::do_intersect<I, F>(segment, fixed_circle))
    {
        return static_cast<F>(0);
    }
    const auto unit_dot = rl::unit_dot<I, F>(segment, rl::center(fixed_circle));
    const auto closest_segment_point = rl::point2<I>(
        segment.start_x + (unit_dot * (segment.end_x - segment.start_x)),
        segment.start_y + (unit_dot * (segment.end_y - segment.start_y))
    );
    if (!rl::does_contain<I>(segment, closest_segment_point)) return static_cast<F>(0);
    return rl::distance_between<I, F>(closest_segment_point, fixed_circle);
}

// box2
template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box, const rl::point2<I>& point) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return rl::distance_between<I, F>(point, fixed_box);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box, const rl::segment2<I>& segment) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return rl::distance_between<I, F>(segment, fixed_box);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box_a, const rl::box2<I>& box_b) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box_a, box_a);
    RLM_HANDLE_DEGENERACY(fixed_box_b, box_b);
    const auto bounds = rl::bounding_box2<I, F>(fixed_box_a, fixed_box_b);
    const auto inner_width = rl::max<I>(bounds.width - fixed_box_a.width - fixed_box_b.width, 0);
    const auto inner_height = rl::max<I>(bounds.height - fixed_box_a.height - fixed_box_b.height, 0);
    return std::sqrt(static_cast<F>((inner_width * inner_width) + (inner_height * inner_height)));
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::box2<I>& box, const rl::circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return rl::max<F>(
        rl::distance_between<I, F>(
            fixed_box,
            rl::center<I, F>(fixed_circle)
        ) - fixed_circle.radius,
        static_cast<F>(0)
    );
}

// circle2
template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::circle2<I, F>& circle, const rl::point2<I>& point) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return rl::distance_between<I, F>(point, fixed_circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::circle2<I, F>& circle, const rl::segment2<I>& segment) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return rl::distance_between<I, F>(segment, fixed_circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::circle2<I, F>& circle, const rl::box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return rl::distance_between<I, F>(fixed_box, fixed_circle);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::distance_between(const rl::circle2<I, F>& circle_a, const rl::circle2<I, F>& circle_b) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle_a, circle_a);
    RLM_HANDLE_DEGENERACY(fixed_circle_b, circle_b);
    return rl::max<F>(
        rl::distance_between<I, F>(
            rl::center<I, F>(fixed_circle_a),
            rl::center<I, F>(fixed_circle_b)
        ) - static_cast<F>(fixed_circle_a.radius + fixed_circle_b.radius),
        static_cast<F>(0)
    );
}

