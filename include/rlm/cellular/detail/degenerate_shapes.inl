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

#include <rlm/cellular/cell_box2.hpp>
#include <rlm/cellular/cell_circle2.hpp>
#include <rlm/max.hpp>
#include <rlm/concepts.hpp>

template<rl::signed_integral I>
constexpr bool rl::is_degenerate(const rl::cell_vector2<I>& point) noexcept
{
    return false;
}

template<rl::signed_integral I>
constexpr bool rl::is_degenerate(const rl::cell_segment2<I>& segment) noexcept
{
    return false;
}

template<rl::signed_integral I>
constexpr bool rl::is_degenerate(const rl::cell_box2<I>& box) noexcept
{
    return box.width <= 0 || box.height <= 0;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_degenerate(const rl::cell_circle2<I, F>& circle) noexcept
{
    return circle.radius < 0.5;
}

template<rl::signed_integral I>
constexpr rl::cell_vector2<I> rl::fix_degeneracy(const rl::cell_vector2<I>& point) noexcept
{
    return point;
}

template<rl::signed_integral I>
constexpr rl::cell_segment2<I> rl::fix_degeneracy(const rl::cell_segment2<I>& segment) noexcept
{
    return segment;
}

template<rl::signed_integral I>
constexpr rl::cell_box2<I> rl::fix_degeneracy(const rl::cell_box2<I>& box) noexcept
{
    return
        rl::cell_box2(
            box.x,
            box.y,
            rl::max(box.width, 1),
            rl::max(box.height, 1)
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr rl::cell_circle2<I, F> rl::fix_degeneracy(const rl::cell_circle2<I, F>& circle) noexcept
{
    return
        rl::cell_circle2<I, F>(
            circle.x,
            circle.y,
            rl::max(circle.radius, 0.5f)
        );
}

