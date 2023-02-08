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
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/center.hpp>
#include <rlm/cellular/segment2_size.hpp>
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/cellular/shape_conversion.hpp>
#include <rlm/cellular/segment2_between.hpp>
#include <optional>

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_point2(const rl::point2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_point2(const rl::segment2<I>& segment) noexcept
{
    return rl::start(segment) == rl::end(segment);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_point2(const rl::box2<I>& box) noexcept
{
    return box.width == 1 && box.height == 1;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_point2(const rl::circle2<I, F>& circle) noexcept
{
    return circle.radius <= 1.5f && circle.radius >= 0.5f;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::point2<I>> rl::as_point2(const rl::point2<I>& point) noexcept
{
    return point;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::point2<I>> rl::as_point2(const rl::segment2<I>& segment) noexcept
{
    if (!rl::is_point2(segment))
    {
        return std::nullopt;
    }
    return rl::start(segment);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::point2<I>> rl::as_point2(const rl::box2<I>& box) noexcept
{
    if (!rl::is_point2(box))
    {
        return std::nullopt;
    }
    return rl::top_left(box);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::point2<I>> rl::as_point2(const rl::circle2<I, F>& circle) noexcept
{
    if (!rl::is_point2<I, F>(circle))
    {
        return std::nullopt;
    }
    return rl::center<I, F>(circle);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_segment2(const rl::point2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_segment2(const rl::segment2<I>& segment) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_segment2(const rl::box2<I>& box) noexcept
{
    return box.width == 1 || box.height == 1;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_segment2(const rl::circle2<I, F>& circle) noexcept
{
    return rl::is_point2<I, F>(circle);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::segment2<I>> rl::as_segment2(const rl::point2<I>& point) noexcept
{
    return
        rl::segment2<I>(
            point.x,
            point.y,
            point.x,
            point.y
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::segment2<I>> rl::as_segment2(const rl::segment2<I>& segment) noexcept
{
    return segment;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::segment2<I>> rl::as_segment2(const rl::box2<I>& box) noexcept
{
    if (!rl::is_segment2(box))
    {
        return std::nullopt;
    }
    return
        rl::segment2_between(
            rl::top_left(box),
            rl::bottom_right(box)
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::segment2<I>> rl::as_segment2(const rl::circle2<I, F>& circle) noexcept
{
    if (!rl::is_segment2<I, F>(circle))
    {
        return std::nullopt;
    }
    return
        rl::segment2_between(
            rl::center(circle),
            rl::center(circle)
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_box2(const rl::point2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_box2(const rl::segment2<I>& segment) noexcept
{
    return
        segment.start_x == segment.end_x ||
        segment.start_y == segment.end_y;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool is_box2(const rl::box2<I>& box) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_box2(const rl::circle2<I, F>& circle) noexcept
{
    return
        rl::is_point2(circle);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::box2<I>> rl::as_box2(const rl::point2<I>& point) noexcept
{
    return
        rl::box2<I>(
            point.x,
            point.y,
            1,
            1
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::box2<I>> rl::as_box2(const rl::segment2<I>& segment) noexcept
{
    if (!rl::is_box2(segment))
    {
        return std::nullopt;
    }
    return
        rl::box2(
            rl::left_x(segment),
            rl::top_y(segment),
            rl::width(segment),
            rl::height(segment)
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::box2<I>> rl::as_box2(const rl::box2<I>& box) noexcept
{
    return box;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::box2<I>> rl::as_box2(const rl::circle2<I, F>& circle) noexcept
{
    if (!rl::is_box2<I, F>(circle))
    {
        return std::nullopt;
    }
    return
        rl::box2<I>(
            circle.x,
            circle.y,
            1,
            1
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_circle2(const rl::point2<I>& point) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_circle2(const rl::segment2<I>& segment) noexcept
{
    return rl::is_point2<I, F>(segment);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_circle2(const rl::box2<I>& box) noexcept
{
    return
        (box.width == 1 && box.height == 1) ||
        (box.width == 3 && box.height == 3) ||
        (box.width == 5 && box.height == 5);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_circle2(const rl::circle2<I, F>& circle) noexcept
{
    return true;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::circle2<I, F>> rl::as_circle2(const rl::point2<I>& point) noexcept
{
    return
        rl::circle2<I, F>(
            point.x,
            point.y,
            0.5f
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::circle2<I, F>> rl::as_circle2(const rl::segment2<I>& segment) noexcept
{
    if (rl::is_circle2<I, F>(segment))
    {
        return std::nullopt;
    }
    return
        rl::circle2<I, F>(
            segment.start_x,
            segment.start_y,
            0.5f
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::circle2<I, F>> rl::as_circle2(const rl::box2<I>& box) noexcept
{
    if (box.width == 5 && box.height == 5)
    {
        return
            rl::circle2<I, F>(
                box.x + 1,
                box.y + 1,
                2.9f
            );
    }
    else if (box.width == 3 && box.height == 3)
    {
        return
            rl::circle2<I, F>(
                box.x + 1,
                box.y + 1,
                1.5f
            );
    }
    else if (box.width == 1 && box.height == 1)
    {
        return rl::circle2<I, F>(
            box.x,
            box.y,
            0.5f
        );
    }
    return std::nullopt;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr std::optional<rl::circle2<I, F>> rl::as_circle2(const rl::circle2<I, F>& circle) noexcept
{
    return circle;
}