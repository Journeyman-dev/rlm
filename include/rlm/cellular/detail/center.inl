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
#include <rlm/cellular/segment2_direction.hpp>
#include <rlm/cellular/segment2_size.hpp>
#include <rlm/cellular/shape_edges.hpp>

template<rl::signed_integral I>
constexpr rl::segment2<I> rl::center(const rl::segment2<I>& segment) noexcept
{
    const auto center_change_wide = rl::width(segment) % 2 == 0 ? 1 : 0;
    const auto center_change_tall = rl::height(segment) % 2 == 0 ? 1 : 0;
    rl::segment2<I> result;
    if (rl::goes_right(segment))
    {
        result.start_x = segment.start_x + rl::width(segment) / 2;
        result.end_x = result.start_x + center_change_wide;
    }
    else
    {
        result.start_x = segment.start_x - rl::width(segment) / 2;
        result.end_x = result.start_x - center_change_wide;
    }
    if (rl::goes_down(segment))
    {
        result.start_y = segment.start_y + rl::height(segment) / 2;
        result.end_y = result.start_y + center_change_tall;
    }
    else
    {
        result.start_y = segment.start_y - rl::height(segment) / 2;
        result.end_y = result.start_y - center_change_tall;
    }
    return result;
}

template<rl::signed_integral I>
constexpr rl::box2<I> rl::center(const rl::segment2<I>& box) noexcept
{
    return rl::box2<I>(
        box.x + box.width / 2,
        box.y + box.height / 2,
        (box.width % 2 == 0) ? 1 : 2,
        (box.height % 2 == 0) ? 1 : 2
    );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr rl::point2<I> rl::center(const rl::circle2<I, F>& circle) noexcept
{
    return rl::point2<I>(
        circle.x,
        circle.y
    );
}

