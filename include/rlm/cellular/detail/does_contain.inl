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
#include <rlm/cellular/cell_circle2_size.hpp>
#include <rlm/cellular/are_collinear.hpp>
#include <rlm/configuration.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>

// cell_vector2
template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_vector2<I>& containing_point, const rl::cell_vector2<I>& contained_point) noexcept
{
    return containing_point == contained_point;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_vector2<I>& containing_point, const rl::cell_segment2<I>& contained_segment) noexcept
{
    const auto contained_segment_as_point_o = rl::as_cell_vector2<I>(contained_segment);
    return
        contained_segment_as_point_o.has_value() &&
        containing_point == contained_segment_as_point_o.value();
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_vector2<I>& containing_point, const rl::cell_box2<I>& contained_box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_contained_box, contained_box);
    const auto contained_box_as_point_o = rl::as_cell_vector2<I>(fixed_contained_box);
    return
        contained_box_as_point_o.has_value() &&
        containing_point == contained_box_as_point_o.value();
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_vector2<I>& containing_point, const rl::cell_circle2<I, F>& contained_circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_contained_circle, contained_circle);
    const auto contained_circle_as_point_o = rl::as_cell_vector2<I, F>(fixed_contained_circle);
    return
        contained_circle_as_point_o.has_value() &&
        containing_point == contained_circle_as_point_o.value();
}

// cell_segment2
template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_segment2<I>& containing_segment, const rl::cell_vector2<I>& contained_point) noexcept
{
    return
        rl::are_collinear<I>(
            containing_segment,
            contained_point
        ) &&
        contained_point.x >= rl::left_x(containing_segment) &&
        contained_point.y <= rl::right_x(containing_segment) &&
        contained_point.y >= rl::top_y(containing_segment) &&
        contained_point.y <= rl::bottom_y(containing_segment);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_segment2<I>& containing_segment, const rl::cell_segment2<I>& contained_segment) noexcept
{
    if (
        !rl::are_collinear<I>(containing_segment, contained_segment)
    )
    {
        return false;
    }
    if (
        rl::left_x<I>(containing_segment) > rl::left_x<I>(contained_segment)
    )
    {
        return false;
    }
    if(
        rl::right_x<I>(containing_segment) < rl::right_x<I>(contained_segment)
    )
    {
        return false;
    }
    if (
        rl::top_y<I>(containing_segment) > rl::top_y<I>(contained_segment)
    )
    {
        return false;
    }
    if (
        rl::bottom_y<I>(containing_segment) < rl::bottom_y<I>(contained_segment)
    )
    {
        return false;
    }
    return true;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_segment2<I>& containing_segment, const rl::cell_box2<I>& contained_box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_contained_box, contained_box);
    return
        rl::is_cell_vector2<I>(
            fixed_contained_box
        ) &&
        rl::does_contain<I>(
            containing_segment,
            rl::top_left<I>(fixed_contained_box)
        ) &&
        rl::does_contain<I>(
            containing_segment,
            rl::top_right<I>(fixed_contained_box)
        ) &&
        rl::does_contain<I>(
            containing_segment,
            rl::bottom_left<I>(fixed_contained_box)
        ) &&
        rl::does_contain<I>(
            containing_segment,
            rl::bottom_right<I>(fixed_contained_box)
        );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_segment2<I>& containing_segment, const rl::cell_circle2<I, F>& contained_circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_contained_circle, contained_circle);
    return
        (rl::tile_diameter<I, F>(fixed_contained_circle) == 1) &&
        rl::does_contain<I, F>(
            containing_segment,
            rl::center<I, F>(fixed_contained_circle)
        );
}

// cell_box2
template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_box2<I>& containing_box, const rl::cell_vector2<I>& contained_point) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_box, containing_box);
    return
        rl::left_x<I>(fixed_containing_box) <= contained_point.x &&
        rl::right_x<I>(fixed_containing_box) >= contained_point.x &&
        rl::left_x<I>(fixed_containing_box) <= contained_point.y &&
        rl::right_x<I>(fixed_containing_box) >= contained_point.y;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_box2<I>& containing_box, const rl::cell_segment2<I>& contained_segment) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_box, containing_box);
    return
        rl::left_x<I>(fixed_containing_box) <= rl::left_x<I>(contained_segment) &&
        rl::right_x<I>(fixed_containing_box) >= rl::right_x<I>(contained_segment) &&
        rl::top_y<I>(fixed_containing_box) <= rl::top_y<I>(contained_segment) &&
        rl::bottom_y<I>(fixed_containing_box) >= rl::bottom_y<I>(contained_segment);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_box2<I>& containing_box, const rl::cell_box2<I>& contained_box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_box, containing_box);
    RLM_HANDLE_DEGENERACY(fixed_contained_box, contained_box);
    return
        rl::left_x<I>(fixed_containing_box) <= rl::left_x<I>(fixed_contained_box) &&
        rl::right_x<I>(fixed_containing_box) >= rl::right_x<I>(fixed_contained_box) &&
        rl::top_y<I>(fixed_containing_box) <= rl::top_y<I>(fixed_contained_box) &&
        rl::bottom_y<I>(fixed_containing_box) >= rl::bottom_y<I>(fixed_contained_box);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_box2<I>& containing_box, const rl::cell_circle2<I, F>& contained_circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_box, containing_box);
    RLM_HANDLE_DEGENERACY(fixed_contained_circle, contained_circle);
    return
        rl::left_x<I>(fixed_containing_box) <= rl::left_x<I, F>(fixed_contained_circle) &&
        rl::right_x<I>(fixed_containing_box) >= rl::right_x<I, F>(fixed_contained_circle) &&
        rl::top_y<I>(fixed_containing_box) <= rl::top_y<I, F>(fixed_contained_circle) &&
        rl::bottom_y<I>(fixed_containing_box) >= rl::bottom_y<I, F>(fixed_contained_circle);
}

// cell_circle2
template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_circle2<I, F>& containing_circle, const rl::cell_vector2<I>& containing_segment) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_circle, containing_circle);
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(fixed_containing_circle),
            containing_segment
        ) <
        fixed_containing_circle.radius;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_circle2<I, F>& containing_circle, const rl::cell_segment2<I>& contained_segment) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_circle, containing_circle);
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(fixed_containing_circle),
            contained_segment
        ) <
        fixed_containing_circle.radius;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_circle2<I, F>& containing_circle, const rl::cell_box2<I>& contained_box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_circle, containing_circle);
    RLM_HANDLE_DEGENERACY(fixed_contained_box, contained_box);
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(fixed_containing_circle),
            fixed_contained_box
        ) <
        fixed_containing_circle.radius;
}

template <rl::signed_integral I, rl::floating_point F>
constexpr bool rl::does_contain(const rl::cell_circle2<I, F>& containing_circle, const rl::cell_circle2<I, F>& contained_circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_circle, containing_circle);
    RLM_HANDLE_DEGENERACY(fixed_contained_circle, contained_circle);
    return
        rl::distance_between<I, F>(
            rl::center<I, F>(fixed_containing_circle),
            rl::center<I, F>(fixed_contained_circle)
        ) <
        fixed_containing_circle.radius - fixed_contained_circle.radius;
}

template<
    typename I,
    typename F,
    rl::cellular_shape<I, F> Sa,
    rl::cellular_shape<I, F> Sb,
    rl::cellular_shape<I, F>... Ss
>
constexpr rl::cell_box2<I> rl::does_contain(const Sa& containing_shape, const Sb& contained_shape_a, const Ss&... contained_shape_n) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_containing_shape, containing_shape);
    RLM_HANDLE_DEGENERACY(fixed_contained_shape_a, contained_shape_a);
    return
        rl::does_contain<I, F>(
            fixed_containing_shape,
            fixed_contained_shape_a
        ) &&
        rl::does_contain<I, F>(
            fixed_containing_shape,
            contained_shape_n...
        );
}

