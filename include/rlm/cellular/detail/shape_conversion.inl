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
#include <rlm/cellular/cell_box2.hpp>
#include <rlm/cellular/cell_circle2.hpp>
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/center.hpp>
#include <rlm/cellular/cell_segment2_size.hpp>
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/cellular/shape_conversion.hpp>
#include <rlm/cellular/cell_segment2_between.hpp>
#include <optional>

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_vector2(const rl::cell_vector2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_vector2(const rl::cell_segment2<I>& segment) noexcept
{
    return rl::start(segment) == rl::end(segment);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_vector2(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return fixed_box.width == 1 && fixed_box.height == 1;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_vector2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return fixed_circle.radius <= 1.5f && fixed_circle.radius >= 0.5f;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_vector2<I>> rl::as_cell_vector2(const rl::cell_vector2<I>& point) noexcept
{
    return point;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_vector2<I>> rl::as_cell_vector2(const rl::cell_segment2<I>& segment) noexcept
{
    if (!rl::is_cell_vector2(segment))
    {
        return std::nullopt;
    }
    return rl::start(segment);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_vector2<I>> rl::as_cell_vector2(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    if (!rl::is_cell_vector2(fixed_box))
    {
        return std::nullopt;
    }
    return rl::top_left(fixed_box);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_vector2<I>> rl::as_cell_vector2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    if (!rl::is_cell_vector2<I, F>(fixed_circle))
    {
        return std::nullopt;
    }
    return rl::center<I, F>(fixed_circle);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_segment2(const rl::cell_vector2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_segment2(const rl::cell_segment2<I>& segment) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_segment2(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return fixed_box.width == 1 || fixed_box.height == 1;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_segment2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return rl::is_cell_vector2<I, F>(fixed_circle);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_segment2<I>> rl::as_cell_segment2(const rl::cell_vector2<I>& point) noexcept
{
    return
        rl::cell_segment2<I>(
            point.x,
            point.y,
            point.x,
            point.y
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_segment2<I>> rl::as_cell_segment2(const rl::cell_segment2<I>& segment) noexcept
{
    return segment;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_segment2<I>> rl::as_cell_segment2(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    if (!rl::is_cell_segment2(fixed_box))
    {
        return std::nullopt;
    }
    return
        rl::cell_segment2_between(
            rl::top_left(fixed_box),
            rl::bottom_right(fixed_box)
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_segment2<I>> rl::as_cell_segment2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    if (!rl::is_cell_segment2<I, F>(fixed_circle))
    {
        return std::nullopt;
    }
    return
        rl::cell_segment2_between(
            rl::center(fixed_circle),
            rl::center(fixed_circle)
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_box2(const rl::cell_vector2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_box2(const rl::cell_segment2<I>& segment) noexcept
{
    return
        segment.start_x == segment.end_x ||
        segment.start_y == segment.end_y;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_box2(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_box2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return
        rl::is_cell_vector2(circle);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_box2<I>> rl::as_cell_box2(const rl::cell_vector2<I>& point) noexcept
{
    return
        rl::cell_box2<I>(
            point.x,
            point.y,
            1,
            1
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_box2<I>> rl::as_cell_box2(const rl::cell_segment2<I>& segment) noexcept
{
    if (!rl::is_cell_box2(segment))
    {
        return std::nullopt;
    }
    return
        rl::cell_box2(
            rl::left_x(segment),
            rl::top_y(segment),
            rl::width(segment),
            rl::height(segment)
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_box2<I>> rl::as_cell_box2(const rl::cell_box2<I>& box) noexcept
{
    return box;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_box2<I>> rl::as_cell_box2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    if (!rl::is_cell_box2<I, F>(fixed_circle))
    {
        return std::nullopt;
    }
    return
        rl::cell_box2<I>(
            fixed_circle.x,
            fixed_circle.y,
            1,
            1
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_circle2(const rl::cell_vector2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_circle2(const rl::cell_segment2<I>& segment) noexcept
{
    return rl::is_cell_vector2<I, F>(segment);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_circle2(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return
        (fixed_box.width == 1 && fixed_box.height == 1) ||
        (fixed_box.width == 3 && fixed_box.height == 3) ||
        (fixed_box.width == 5 && fixed_box.height == 5);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_cell_circle2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_circle2<I, F>> rl::as_cell_circle2(const rl::cell_vector2<I>& point) noexcept
{
    return
        rl::cell_circle2<I, F>(
            point.x,
            point.y,
            0.5f
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_circle2<I, F>> rl::as_cell_circle2(const rl::cell_segment2<I>& segment) noexcept
{
    if (!rl::is_cell_circle2<I, F>(segment))
    {
        return std::nullopt;
    }
    return
        rl::cell_circle2<I, F>(
            segment.start_x,
            segment.start_y,
            0.5f
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_circle2<I, F>> rl::as_cell_circle2(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    if (fixed_box.width == 5 && fixed_box.height == 5)
    {
        return
            rl::cell_circle2<I, F>(
                fixed_box.x + 1,
                fixed_box.y + 1,
                2.9f
            );
    }
    else if (fixed_box.width == 3 && fixed_box.height == 3)
    {
        return
            rl::cell_circle2<I, F>(
                box.x + 1,
                box.y + 1,
                1.5f
            );
    }
    else if (fixed_box.width == 1 && fixed_box.height == 1)
    {
        return rl::cell_circle2<I, F>(
            fixed_box.x,
            fixed_box.y,
            0.5f
        );
    }
    return std::nullopt;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::cell_circle2<I, F>> rl::as_cell_circle2(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return fixed_circle;
}