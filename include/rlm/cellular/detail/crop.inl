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
#include <rlm/cellular/cell_vector2.hpp>
#include <rlm/cellular/cell_segment2.hpp>
#include <rlm/cellular/cell_box2.hpp>
#include <rlm/cellular/cell_circle2.hpp>
#include <rlm/cellular/does_contain.hpp>
#include <rlm/cellular/shape_conversion.hpp>
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/cellular/cell_box2_between.hpp>
#include <rlm/cellular/cell_segment2_direction.hpp>
#include <rlm/min.hpp>
#include <rlm/max.hpp>
#include <rlm/configuration.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <optional>

template<rl::signed_integral I>
constexpr std::optional<rl::cell_vector2<I>> rl::crop(const rl::cell_vector2<I>& point,
                                                      const rl::cell_box2<I>& crop_box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_crop_box, crop_box);
    if (!rl::does_contain<I>(fixed_crop_box, point)) { return std::nullopt; }
    return point;
}

template<rl::signed_integral I>
constexpr std::optional<rl::cell_segment2<I>> rl::crop(const rl::cell_segment2<I>& segment,
                                                       const rl::cell_box2<I>& crop_box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_crop_box, crop_box);
    if (!rl::do_intersect<I>(fixed_crop_box, segment)) { return std::nullopt; }
    auto result =
        rl::cell_segment2<I>(rl::max<I>(rl::left_x<I>(segment), rl::left_x<I>(fixed_crop_box)),
                             rl::max<I>(rl::top_y<I>(segment), rl::top_y<I>(fixed_crop_box)),
                             rl::min<I>(rl::right_x<I>(segment), rl::right_x<I>(fixed_crop_box)),
                             rl::min<I>(rl::bottom_y<I>(segment), rl::bottom_y<I>(fixed_crop_box)));
    if (rl::goes_left<I>(segment) != rl::goes_left<I>(result) ||
        rl::goes_up<I>(segment) != rl::goes_up<I>(result))
    {
        result = rl::reverse<I>(result);
    }
    return result;
}

template<rl::signed_integral I>
constexpr std::optional<rl::cell_box2<I>> rl::crop(const rl::cell_box2<I>& box,
                                                   const rl::cell_box2<I>& crop_box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    RLM_HANDLE_DEGENERACY(fixed_crop_box, crop_box);
    if (!rl::do_intersect<I>(fixed_crop_box, fixed_box)) { return std::nullopt; }
    return rl::cell_box2_between<I>(
        rl::max<I>(rl::left_x<I>(fixed_box), rl::left_x<I>(fixed_crop_box)),
        rl::max<I>(rl::top_y<I>(fixed_box), rl::top_y<I>(fixed_crop_box)),
        rl::min<I>(rl::right_x<I>(fixed_box), rl::right_x<I>(fixed_crop_box)),
        rl::min<I>(rl::bottom_y<I>(fixed_box), rl::bottom_y<I>(fixed_crop_box)));
}
