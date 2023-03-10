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
#include <rlm/cellular/cell_box2.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <rlm/min.hpp>
#include <rlm/max.hpp>
#include <cassert>
#include <cmath>

template<rl::signed_integral I>
constexpr I rl::left_x(const rl::cell_segment2<I>& segment) noexcept
{
    return rl::min(segment.start_x, segment.end_x);
}

template<rl::signed_integral I>
constexpr I rl::right_x(const rl::cell_segment2<I>& segment) noexcept
{
    return rl::max(segment.start_x, segment.end_x);
}

template<rl::signed_integral I>
constexpr I rl::top_y(const rl::cell_segment2<I>& segment) noexcept
{
    return rl::min(segment.start_y, segment.end_y);
}

template<rl::signed_integral I>
constexpr I rl::bottom_y(const rl::cell_segment2<I>& segment) noexcept
{
    return rl::max(segment.start_y, segment.end_y);
}

template<rl::signed_integral I>
constexpr I rl::left_x(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return fixed_box.x;
}

template<rl::signed_integral I>
constexpr I rl::right_x(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return fixed_box.x + fixed_box.width - 1;
}

template<rl::signed_integral I>
constexpr I rl::top_y(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return fixed_box.y;
}

template<rl::signed_integral I>
constexpr I rl::bottom_y(const rl::cell_box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return fixed_box.y + fixed_box.height - 1;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr I rl::left_x(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return fixed_circle.x - static_cast<I>(std::round(fixed_circle.radius));
}

template<rl::signed_integral I, rl::floating_point F>
constexpr I rl::right_x(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return fixed_circle.x + static_cast<I>(std::round(fixed_circle.radius));
}

template<rl::signed_integral I, rl::floating_point F>
constexpr I rl::top_y(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return fixed_circle.y - static_cast<I>(std::round(fixed_circle.radius));
}

template<rl::signed_integral I, rl::floating_point F>
constexpr I rl::bottom_y(const rl::cell_circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return fixed_circle.y + static_cast<I>(std::round(fixed_circle.radius));
}
