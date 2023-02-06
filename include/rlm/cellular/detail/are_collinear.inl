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
#include <rlm/cellular/point2_orientation.hpp>
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/segment2_between.hpp>

template <rl::signed_integral I>
constexpr bool rl::are_collinear(const rl::point2<I>& point_a, const rl::point2<I>& point_b, const rl::point2<I>& point_c) noexcept
{
    return
        rl::orientation_determinant<I>(point_a, point_b, point_c) == 0;
}

template <rl::signed_integral I>
constexpr bool rl::are_collinear(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept
{
    return
        rl::are_collinear<I>(
            segment_a,
            rl::start<I>(segment_b)
        ) &&
        rl::are_collinear<I>(
            segment_a,
            rl::end<I>(segment_b)
        );
}

template <rl::signed_integral I>
constexpr bool rl::are_collinear(const rl::segment2<I>& segment, const rl::point2<I>& point) noexcept
{
    return
        rl::are_collinear<I>(
            point,
            segment
        );
}

template <rl::signed_integral I>
constexpr bool rl::are_collinear(const rl::point2<I>& point, const rl::segment2<I>& segment) noexcept
{
    return
        rl::are_collinear<I>(
            point,
            rl::start<I>(segment),
            rl::end<I>(segment)
        );
}

template <typename I, rl::point2_or_segment2<I> ... Ss>
constexpr bool rl::are_collinear(const rl::point2<I>& point_a, const rl::point2<I>& point_b, const rl::point2<I>& point_c, const Ss&... shape_n) noexcept
{
    return
        rl::are_collinear<I>(
            point_a,
            point_b,
            point_c
        ) &&
        rl::are_collinear(
            rl::segment2_between<I>(
                point_b,
                point_c
            ),
            shape_n...
        );
}

template <typename I, rl::point2_or_segment2<I> ... Ss>
constexpr bool rl::are_collinear(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b, const Ss&... shape_n ) noexcept
{
    return
        rl::are_collinear<I>(
            segment_a,
            segment_b
        ) &&
        rl::are_collinear<I>(
            segment_b,
            shape_n...
        );
}

template <typename I, rl::point2_or_segment2<I> ... Ss>
constexpr bool rl::are_collinear(const rl::point2<I>& point, const rl::segment2<I>& segment, const Ss&... shape_n) noexcept
{
    return
        rl::are_collinear<I>(
            point,
            segment
        ) &&
        rl::are_collinear(
            segment,
            shape_n...
        );
}

template <typename I, rl::point2_or_segment2<I> ... Ss>
constexpr bool rl::are_collinear(const rl::segment2<I>& segment, const rl::point2<I>& point, const Ss&... shape_n) noexcept
{
    return
        rl::are_collinear<I>(
            segment,
            point
        ) &&
        rl::are_collinear<I>(
            point,
            shape_n...
        );
}