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
#include <rlm/cellular/shape_conversion.hpp>
#include <rlm/cellular/distance_between.hpp>
#include <rlm/cellular/circle2_size.hpp>
#include <rlm/cellular/are_collinear.hpp>

// point2
template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::point2<I>& containing_point, const rl::point2<I>& contained_point) noexcept
{
    return containing_point == contained_point;
}

template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::point2<I>& containing_point, const rl::segment2<I>& contained_segment) noexcept
{
    const auto contained_segment_as_point_o = rl::as_point2<I>(contained_segment);
    return
        contained_segment_as_point_o.has_value() &&
        containing_point == contained_segment_as_point_o.value();
}

template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::point2<I>& containing_point, const rl::box2<I>& contained_box) noexcept
{
    const auto contained_box_as_point_o = rl::as_point2<I>(contained_box);
    return
        contained_box_as_point_o.has_value() &&
        containing_point == contained_box_as_point_o.value();
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_containing(const rl::point2<I>& containing_point, const rl::circle2<I, F>& contained_circle) noexcept
{
    const auto contained_circle_as_point_o = rl::as_point2<I, F>(contained_circle);
    return
        contained_circle_as_point_o.has_value() &&
        containing_point == contained_circle_as_point_o.value();
}

// segment2
template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::segment2<I>& containing_segment, const rl::point2<I>& contained_point) noexcept
{
    return
        rl::cross_z<I>(
            rl::start<I>(containing_segment),
            contained_point
        ) ==
        rl::cross_z<I>(
            rl::end<I>(containing_segment),
            contained_point
        );
}

template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::segment2<I>& containing_segment, const rl::segment2<I>& contained_segment) noexcept
{
    if (!rl::are_collinear<I>(containing_segment, contained_segment))
    {
        return false;
    }
    if(
        rl::right_x<I>(containing_segment) >= contained_segment.start_x &&
        rl::right_x<I>(containing_segment) >= contained_segment.end_x
    )
    {
        return false;
    }
    if (
        rl::left_x<I>(containing_segment) >= contained_segment.start_x &&
        rl::left_x<I>(containing_segment) <= contained_segment.end_x
    )
    {
        return false;
    }
    if (
        rl::bottom_y<I>(containing_segment) >= contained_segment.start_y &&
        rl::bottom_y<I>(contained_segment) >= contained_segment.end_y
    )
    {
        return false;
    }
    if (
        rl::top_y<I>(containing_segment) >= contained_segment.start_y &&
        rl::top_y<I>(containing_segment) <= contained_segment.end_y
    )
    {
        return false;
    }
    return true;
}

template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::segment2<I>& containing_segment, const rl::box2<I>& contained_box) noexcept
{
    return
        rl::is_point2<I>(
            contained_box
        ) &&
        rl::is_containing<I>(
            containing_segment,
            rl::top_left<I>(contained_box)
        ) &&
        rl::is_containing<I>(
            containing_segment,
            rl::top_right<I>(contained_box)
        ) &&
        rl::is_containing<I>(
            containing_segment,
            rl::bottom_left<I>(contained_box)
        ) &&
        rl::is_containing<I>(
            containing_segment,
            rl::bottom_right<I>(contained_box)
        );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_containing(const rl::segment2<I>& containing_segment, const rl::circle2<I, F>& contained_circle) noexcept
{
    return
        rl::tile_diameter<I, F>(contained_circle) == 1 &&
        rl::is_containing<I, F>(
            containing_segment,
            rl::center<I, F>(contained_circle)
        );
}

// box2
template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::box2<I>& containing_box, const rl::point2<I>& contained_point) noexcept
{
    return
        rl::left_x<I>(containing_box) <= contained_point.x &&
        rl::right_x<I>(containing_box) >= contained_point.x &&
        rl::left_x<I>(containing_box) <= contained_point.y &&
        rl::right_x<I>(containing_box) >= contained_point.y;
}

template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::box2<I>& containing_box, const rl::segment2<I>& contained_segment) noexcept
{
    return
        rl::left_x<I>(containing_box) <= rl::left_x<I>(contained_segment) &&
        rl::right_x<I>(containing_box) >= rl::right_x<I>(contained_segment) &&
        rl::top_y<I>(containing_box) <= rl::top_y<I>(contained_segment) &&
        rl::bottom_y<I>(containing_box) >= rl::bottom_y<I>(contained_segment);
}

template <rl::signed_integral I>
constexpr bool rl::is_containing(const rl::box2<I>& containing_box, const rl::box2<I>& contained_box) noexcept
{
    return
        rl::left_x<I>(containing_box) <= rl::left_x<I>(contained_box) &&
        rl::right_x<I>(containing_box) >= rl::right_x<I>(contained_box) &&
        rl::top_y<I>(containing_box) <= rl::top_y<I>(contained_box) &&
        rl::bottom_y<I>(containing_box) >= rl::bottom_y<I>(contained_box);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_containing(const rl::box2<I>& containing_box, const rl::circle2<I, F>& contained_circle) noexcept
{
    return
        rl::left_x<I>(containing_box) <= rl::left_x<I, F>(contained_circle) &&
        rl::right_x<I>(containing_box) >= rl::right_x<I, F>(contained_circle) &&
        rl::top_y<I>(containing_box) <= rl::top_y<I, F>(contained_circle) &&
        rl::bottom_y<I>(containing_box) >= rl::bottom_y<I, F>(contained_circle);
}

// circle2
template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_containing(const rl::circle2<I, F>& containing_circle, const rl::point2<I>& containing_segment) noexcept
{
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(containing_circle),
            containing_segment
        ) <
        containing_circle.radius;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_containing(const rl::circle2<I, F>& containing_circle, const rl::segment2<I>& contained_segment) noexcept
{
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(containing_circle),
            contained_segment
        ) <
        containing_circle.radius;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_containing(const rl::circle2<I, F>& containing_circle, const rl::box2<I>& contained_box) noexcept
{
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(containing_circle),
            contained_box
        ) <
        containing_circle.radius;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_containing(const rl::circle2<I, F>& containing_circle, const rl::circle2<I, F>& contained_circle) noexcept
{
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(containing_circle),
            contained_circle
        ) <
        containing_circle.radius;
}

template<
    typename I,
    typename F,
    rl::cellular_shape<I, F> Sa,
    rl::cellular_shape<I, F> Sb,
    rl::cellular_shape<I, F>... Ss
>
constexpr rl::box2<I> rl::is_containing(const Sa& containing_shape, const Sb& contained_shape_a, const Ss&... contained_shape_n) noexcept
{
    return
        rl::is_containing<I, F>(
            containing_shape,
            contained_shape_a
        ) &&
        rl::is_containing<I, F>(
            containing_shape,
            contained_shape_n...
        );
}

