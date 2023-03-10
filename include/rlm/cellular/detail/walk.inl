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
#include <rlm/cellular/cell_segment2_size.hpp>
#include <rlm/cellular/lerp.hpp>
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/cellular/cell_circle2_size.hpp>
#include <rlm/configuration.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <rlm/cellular/shape_points.hpp>
#include <functional>
#include <cmath>

template<rl::signed_integral I, rl::floating_point F>
constexpr void rl::walk(const rl::cell_vector2<I>& point, const rl::walk_predicate<I>& predicate)
{
    predicate(point);
}

template<rl::signed_integral I, rl::floating_point F>
constexpr void rl::walk(const rl::cell_segment2<I>& segment, const rl::walk_predicate<I>& predicate)
{
    if (rl::cell_length<I>(segment) == 1)
    {
        predicate(rl::start<I>(segment));
        return;
    }
    for (I cell_i = 0; cell_i < rl::cell_length<I>(segment); cell_i++)
    {
        const F percent = static_cast<F>(cell_i) / static_cast<F>(rl::cell_length<I>(segment) - 1);
        predicate(rl::lerp<I, F>(segment, percent));
    }
}

template<rl::signed_integral I, rl::floating_point F>
constexpr void rl::walk(const rl::cell_box2<I>& box, const rl::walk_predicate<I>& predicate)
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    for (I cell_y = rl::top_y(fixed_box); cell_y <= rl::bottom_y(fixed_box); cell_y++)
    {
        for (I cell_x = rl::left_x(fixed_box); cell_x <= rl::right_x(fixed_box); cell_x++)
        {
            predicate(rl::cell_vector2<I>(cell_x, cell_y));
        }
    }
}

template<rl::signed_integral I, rl::floating_point F>
constexpr void rl::walk(const rl::cell_circle2<I, F>& circle,
                        const rl::walk_predicate<I>& predicate)
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    for (I offset_y = 1; offset_y <= rl::tile_radius(fixed_circle); offset_y++)
    {
        const I offset_x = static_cast<I>(
            std::floor(std::sqrt(fixed_circle.radius * fixed_circle.radius - offset_y * offset_y)));
        for (I cell_x = fixed_circle.x - offset_x; cell_x <= fixed_circle.x + offset_x; cell_x++)
        {
            predicate(rl::cell_vector2<I>(cell_x, fixed_circle.y - offset_y));
            predicate(rl::cell_vector2<I>(cell_x, fixed_circle.y + offset_y));
        }
    }
    for (I cell_x = rl::left_x<I, F>(fixed_circle); cell_x <= rl::right_x<I, F>(fixed_circle);
         cell_x++)
    {
        predicate(rl::cell_vector2<I>(cell_x, fixed_circle.y));
    }
}