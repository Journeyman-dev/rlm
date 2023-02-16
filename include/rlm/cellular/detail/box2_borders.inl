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
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/segment2.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <rlm/cellular/reverse.hpp>
#include <rlm/cellular/border_corners.hpp>
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/rotation_motion.hpp>
#include <cassert>
#include <optional>

template<rl::signed_integral I>
constexpr rl::segment2<I> rl::left_border(const rl::box2<I>& box, rl::RotationMotion rotation_motion) noexcept
{
    return rl::left_border_trimmed(box, rl::BorderCorners::All, rotation_motion).value();
}

template<rl::signed_integral I>
constexpr rl::segment2<I> rl::right_border(const rl::box2<I>& box, rl::RotationMotion rotation_motion) noexcept
{
    return rl::right_border_trimmed(box, rl::BorderCorners::All, rotation_motion).value();
}

template<rl::signed_integral I>
constexpr rl::segment2<I> rl::top_border(const rl::box2<I>& box, rl::RotationMotion rotation_motion) noexcept
{
    return rl::top_border_trimmed(box, rl::BorderCorners::All, rotation_motion).value();
}

template<rl::signed_integral I>
constexpr rl::segment2<I> rl::bottom_border(const rl::box2<I>& box, rl::RotationMotion rotation_motion) noexcept
{
    return rl::bottom_border_trimmed(box, rl::BorderCorners::All, rotation_motion).value();
}

template<rl::signed_integral I>
constexpr std::optional<rl::segment2<I>> rl::left_border_trimmed(
    const rl::box2<I>& box,
    rl::BorderCorners border_corners,
    rl::RotationMotion rotation_motion
) noexcept
{
    assert(!rl::is_degenerate(box) && "degenerate box2");
    const I bottom_depth =
        (
            (border_corners & rl::BorderCorners::Bottom) == rl::BorderCorners::Bottom ||
            (border_corners & rl::BorderCorners::CounterClockwise) == rl::BorderCorners::CounterClockwise ||
            (border_corners & rl::BorderCorners::Left) == rl::BorderCorners::Left
        ) ? 0 : 1;
    const I top_depth =
        (
            (border_corners & rl::BorderCorners::Top) == rl::BorderCorners::Top ||
            (border_corners & rl::BorderCorners::Clockwise) == rl::BorderCorners::Clockwise ||
            (border_corners & rl::BorderCorners::Left) == rl::BorderCorners::Left
        ) ? 0 : 1;
    if (box.height - bottom_depth - top_depth <= 0)
    {
        return std::nullopt;
    }
    const rl::segment2<I> border(
        rl::left_x(box),
        rl::bottom_y(box) - bottom_depth,
        rl::left_x(box),
        rl::top_y(box) + top_depth
    );
    if (rotation_motion == rl::RotationMotion::CounterClockwise)
    {
        return rl::reverse(border);
    }
    return border;
}

template<rl::signed_integral I>
constexpr std::optional<rl::segment2<I>> rl::right_border_trimmed(
    const rl::box2<I>& box,
    rl::BorderCorners border_corners,
    rl::RotationMotion rotation_motion
) noexcept
{
    assert(!rl::is_degenerate(box) && "degenerate box2");
    const I top_depth =
        (
            (border_corners & rl::BorderCorners::Top) == rl::BorderCorners::Top ||
            (border_corners & rl::BorderCorners::CounterClockwise) == rl::BorderCorners::CounterClockwise ||
            (border_corners & rl::BorderCorners::Right) == rl::BorderCorners::Right
        ) ? 0 : 1;
    const I bottom_depth =
        (
            (border_corners & rl::BorderCorners::Bottom) == rl::BorderCorners::Bottom ||
            (border_corners & rl::BorderCorners::Clockwise) == rl::BorderCorners::Clockwise ||
            (border_corners & rl::BorderCorners::Right) == rl::BorderCorners::Right
        ) ? 0 : 1;
    if (box.height - top_depth - bottom_depth <= 0)
    {
        return std::nullopt;
    }
    const rl::segment2<I> border(
        rl::right_x(box),
        rl::top_y(box) + top_depth,
        rl::right_x(box),
        rl::bottom_y(box) - bottom_depth
    );
    if (rotation_motion == rl::RotationMotion::CounterClockwise)
    {
        return rl::reverse(border);
    }
    return border;
}

template<rl::signed_integral I>
constexpr std::optional<rl::segment2<I>> rl::top_border_trimmed(
    const rl::box2<I>& box,
    rl::BorderCorners border_corners,
    rl::RotationMotion rotation_motion
) noexcept
{
    assert(!rl::is_degenerate(box) && "degenerate box2");
    const I left_depth =
        (
            (border_corners & rl::BorderCorners::Left) == rl::BorderCorners::Left ||
            (border_corners & rl::BorderCorners::CounterClockwise) == rl::BorderCorners::CounterClockwise ||
            (border_corners & rl::BorderCorners::Top) == rl::BorderCorners::Top
        ) ? 0 : 1;
    const I right_depth =
        (
            (border_corners & rl::BorderCorners::Right) == rl::BorderCorners::Right ||
            (border_corners & rl::BorderCorners::Clockwise) == rl::BorderCorners::Clockwise ||
            (border_corners & rl::BorderCorners::Top) == rl::BorderCorners::Top
        ) ? 0 : 1;
    if (box.width - left_depth - right_depth <= 0)
    {
        return std::nullopt;
    }
    const rl::segment2<I> border(
        rl::left_x(box) + left_depth,
        rl::top_y(box),
        rl::right_x(box) - right_depth,
        rl::top_y(box)
    );
    if (rotation_motion == rl::RotationMotion::CounterClockwise)
    {
        return rl::reverse(border);
    }
    return border;
}

template<rl::signed_integral I>
constexpr std::optional<rl::segment2<I>> rl::bottom_border_trimmed(
    const rl::box2<I>& box,
    rl::BorderCorners border_corners,
    rl::RotationMotion rotation_motion
) noexcept
{
    assert(!rl::is_degenerate(box) && "degenerate box2");
    const I right_depth =
        (
            (border_corners & rl::BorderCorners::Right) == rl::BorderCorners::Right ||
            (border_corners & rl::BorderCorners::CounterClockwise) == rl::BorderCorners::CounterClockwise ||
            (border_corners & rl::BorderCorners::Bottom) == rl::BorderCorners::Bottom
        ) ? 0 : 1;
    const I left_depth =
        (
            (border_corners & rl::BorderCorners::Left) == rl::BorderCorners::Left ||
            (border_corners & rl::BorderCorners::Clockwise) == rl::BorderCorners::Clockwise ||
            (border_corners & rl::BorderCorners::Bottom) == rl::BorderCorners::Bottom
        ) ? 0 : 1;
    if (box.width - right_depth - left_depth <= 0)
    {
        return std::nullopt;
    }
    const rl::segment2<I> border(
        rl::right_x(box) - right_depth,
        rl::bottom_y(box),
        rl::left_x(box) + left_depth,
        rl::bottom_y(box)
    );
    if (rotation_motion == rl::RotationMotion::CounterClockwise)
    {
        return rl::reverse(border);
    }
    return border;
}

