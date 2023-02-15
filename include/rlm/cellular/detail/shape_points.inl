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
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/cellular/is_degenerate.hpp>
#include <cassert>

template<rl::signed_integral I>
constexpr rl::point2<I> rl::start(const rl::segment2<I>& segment) noexcept
{
    return
        rl::point2<I>(
            segment.start_x,
            segment.start_y
        );
}

template<rl::signed_integral I>
constexpr rl::point2<I> rl::end(const rl::segment2<I>& segment) noexcept
{
    return
        rl::point2<I>(
            segment.end_x,
            segment.end_y
        );
}

template<rl::signed_integral I>
constexpr rl::point2<I> rl::top_left(const rl::box2<I>& box) noexcept
{
    assert(!rl::is_degenerate(box) && "getting top_left of degenerate box2");
    return
        rl::point2<I>(
            rl::left_x(box),
            rl::top_y(box)
        );
}

template<rl::signed_integral I>
constexpr rl::point2<I> rl::top_right(const rl::box2<I>& box) noexcept
{
    assert(!rl::is_degenerate(box) && "getting top_right of degenerate box2");
    return
        rl::point2<I>(
            rl::right_x(box),
            rl::top_y(box)
        );
}

template<rl::signed_integral I>
constexpr rl::point2<I> rl::bottom_left(const rl::box2<I>& box) noexcept
{
    assert(!rl::is_degenerate(box) && "getting bottom_left of degenerate box2");
    return
        rl::point2<I>(
            rl::left_x(box),
            rl::bottom_y(box)
        );
}

template<rl::signed_integral I>
constexpr rl::point2<I> rl::bottom_right(const rl::box2<I>& box) noexcept
{
    assert(!rl::is_degenerate(box) && "getting bottom_right of degenerate box2");
    return
        rl::point2<I>(
            rl::right_x(box),
            rl::bottom_y(box)
        );
}

