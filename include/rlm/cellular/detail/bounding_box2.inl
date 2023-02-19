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
#include <rlm/cellular/concepts.hpp>
#include <rlm/cellular/point2.hpp>
#include <rlm/cellular/segment2.hpp>
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/circle2.hpp>
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/min.hpp>
#include <rlm/max.hpp>
#include <rlm/configuration.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <cmath>
#include <cassert>

template<rl::signed_integral I, rl::floating_point F>
constexpr rl::box2<I> rl::bounding_box2(const rl::point2<I>& point) noexcept
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
constexpr rl::box2<I> rl::bounding_box2(const rl::segment2<I>& segment) noexcept
{
    const auto min_x = rl::min(segment.start_x, segment.end_x);
    const auto max_x = rl::max(segment.start_x, segment.end_x);
    const auto min_y = rl::min(segment.start_y, segment.end_y);
    const auto max_y = rl::max(segment.start_y, segment.end_y);
    return
        rl::box2<I>(
            min_x,
            min_y,
            (max_x - min_x) + 1,
            (max_y - min_y) + 1
        );
}

template<rl::signed_integral I, rl::floating_point F>
constexpr rl::box2<I> rl::bounding_box2(const rl::box2<I>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return fixed_box;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr rl::box2<I> rl::bounding_box2(const rl::circle2<I, F>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    const auto tile_diameter = static_cast<I>(std::round(fixed_circle.radius)) * 2;
    return rl::box2<I>(
        rl::left_x(fixed_circle),
        rl::top_y(fixed_circle),
        tile_diameter,
        tile_diameter
    );
}

namespace rl::inl
{
    template<rl::signed_integral I>
    constexpr rl::box2<I> bounding_pair_box2(const rl::box2<I>& box_a, const rl::box2<I>& box_b) noexcept
    {
        RLM_HANDLE_DEGENERACY(fixed_box_a, box_a);
        RLM_HANDLE_DEGENERACY(fixed_box_b, box_b);
        const auto left_x = rl::min(rl::left_x(fixed_box_a), rl::left_x(box_b));
        const auto right_x = rl::max(rl::right_x(fixed_box_a), rl::right_x(box_b));
        const auto top_y = rl::min(rl::top_y(fixed_box_a), rl::top_y(box_b));
        const auto bottom_y = rl::max(rl::bottom_y(fixed_box_a), rl::bottom_y(box_b));
        const auto width = (right_x - left_x) + 1;
        const auto height = (bottom_y - top_y) + 1;
        return
            rl::box2<I>(
                left_x,
                right_x,
                width,
                height
            );
    }
}

template<
    typename I,
    typename F,
    rl::cellular_shape<I, F> S,
    rl::cellular_shape<I, F>... Ss
>
constexpr rl::box2<I> rl::bounding_box2(const S& shape_a, const Ss&... shape_n) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_shape_a, shape_a);
    return rl::inl::bounding_pair_box2<I>(rl::bounding_box2<I, F>(fixed_shape_a), rl::bounding_box2<I, F>(shape_n...));
}