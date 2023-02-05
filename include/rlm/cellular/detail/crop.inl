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

#ifndef RLM_CELLULAR_CROP_INL
#define RLM_CELLULAR_CROP_INL

#include <rlm/concepts.hpp>
#include <rlm/cellular/concepts.hpp>
#include <rlm/cellular/point2.hpp>
#include <rlm/cellular/segment2.hpp>
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/circle2.hpp>
#include <rlm/cellular/is_containing.hpp>
#include <rlm/cellular/shape_conversion.hpp>
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/edges.hpp>
#include <rlm/cellular/box2_between.hpp>
#include <rlm/cellular/direction.hpp>
#include <rlm/min.hpp>
#include <rlm/max.hpp>
#include <optional>

template<rl::signed_integral I>
constexpr std::optional<rl::box2<I>> rl::crop(const rl::point2<I>& point, const rl::box2<I>& crop_box) noexcept
{
    if (!std::is_containing(crop_box, point))
    {
        return std::nullopt;
    }
    return rl::as_box2(point);
}

template<rl::signed_integral I>
constexpr std::optional<rl::segment2<I>> rl::crop(const rl::segment2<I>& segment, const rl::box2<I>& crop_box) noexcept
{
    if (!std::is_containing(crop_box, segment))
    {
        return std::nullopt;
    }
    auto result =
        rl::segment2<I>(
            rl::max(rl::left_x(segment), rl::left_x(crop_box)),
            rl::max(rl::top_y(segment), rl::top_y(crop_box)),
            rl::min(rl::right_x(segment), rl::right_x(crop_box)),
            rl::min(rl::bottom_y(segment), rl::bottom_y(crop_box))
        );
    if (
        rl::goes_left(segment) != rl::goes_left(result) ||
        rl::goes_up(segment) != rl::goes_up(result)
    )
    {
        result = rl::reverse(result);
    }
    return result;
}

template<rl::signed_integral I = int>
constexpr std::optional<rl::box2<I>> rl::crop(const rl::box2<I>& box, const rl::box2<I>& crop_box) noexcept
{
    if (!is_containing(crop_box, box))
    {
        return std::nullopt;
    }
    return
        rl::box2_between<I>(
            rl::max(rl::left_x(box), rl::left_x(crop_box)),
            rl::max(rl::top_y(box), rl::top_y(crop_box)),
            rl::min(rl::right_x(box), rl::right_x(crop_box)),
            rl::min(rl::bottom_y(box), rl::bottom_y(crop_box))
        );
}

#endif