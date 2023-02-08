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
#include <rlm/cellular/translation.hpp>
#include <rlm/cellular/distance_between.hpp>

template <rl::signed_integral I>
constexpr I rl::dot(const rl::point2<I>& a, const point2<I>& b) noexcept
{
    return
        (a.x * b.x) +
        (a.y * b.y);
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::unit_dot(const rl::point2<I>& a, const point2<I>& b) noexcept
{
    if (a == b)
    {
        return static_cast<F>(0);
    }
    return
        static_cast<F>(rl::dot<I>(a, b)) /
        (distance * distance);
}

template <rl::signed_integral I>
constexpr I rl::dot(const rl::point2<I>& a, const segment2<I>& b) noexcept
{
    return
        (
            (a.x - b.start_x) *
            (b.end_x - b.start_x)
        ) +
        (
            (a.y - b.start_y) *
            (b.end_y - b.start_y)
        );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr F rl::unit_dot(const rl::point2<I>& a, const segment2<I>& b) noexcept
{
    if (a == b)
    {
        return static_cast<F>(0);
    }
    return
        static_cast<F>(rl::dot(a, b)) /
        (distance * distance);
}

template <rl::signed_integral I>
constexpr auto rl::dot(const rl::segment2<I>& a, const point2<I>& b) noexcept
{
    return rl::dot<I>(b, a);
}

template <rl::signed_integral I = int, rl::floating_point F>
constexpr auto rl::unit_dot(const rl::segment2<I>& a, const point2<I>& b) noexcept
{
    return rl::unit_dot<I, F>(b, a);
}

template <rl::signed_integral I>
constexpr auto rl::dot(const rl::segment2<I>& a, const segment2<I>& b) noexcept
{
    return rl::dot<I>(
        rl::translation(a),
        rl::translation(b)
    );
}

template <rl::signed_integral I, rl::floating_point F>
constexpr auto rl::unit_dot(const rl::segment2<I>& a, const rl::segment2<I>& b) noexcept
{
    return rl::unit_dot<I, F>(
        rl::translation(a),
        rl::translation(b)
    );
}

