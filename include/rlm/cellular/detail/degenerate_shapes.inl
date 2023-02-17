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

#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/circle2.hpp>
#include <rlm/concepts.hpp>

template<rl::signed_integral I>
constexpr bool rl::is_degenerate(const rl::point2<I>& point) noexcept
{
    return false;
}

template<rl::signed_integral I>
constexpr bool rl::is_degenerate(const rl::segment2<I>& segment) noexcept
{
    return false;
}

template<rl::signed_integral I>
constexpr bool rl::is_degenerate(const rl::box2<I>& box) noexcept
{
    return box.width <= 0 || box.height <= 0;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::is_degenerate(const rl::circle2<I, F>& circle) noexcept
{
    return circle.radius < 0.5;
}

template<rl::signed_integral I>
constexpr rl::point2<I> rl::fix_degeneracy(const rl::point2<I>& point) noexcept
{
    return point;
}

template<rl::signed_integral I>
constexpr rl::segment2<I> rl::fix_degeneracy(const rl::segment2<I>& segment) noexcept
{
    return segment;
}

template<rl::signed_integral I>
constexpr rl::box2<I> rl::fix_degeneracy(const rl::box2<I>& box) noexcept
{
    return
        rl::box2(
            box.x,
            box.y,
            box.width <= 0 ? 1 : box.width,
            box.height <= 0 ? 1 : box.height
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr rl::circle2<I, F> rl::fix_degeneracy(const rl::circle2<I, F>& circle) noexcept
{
    return
        rl::circle2<I, F>(
            circle.x,
            circle.y,
            circle.radius <= 0.5f ? 0.5f : circle.radius
        );
}

