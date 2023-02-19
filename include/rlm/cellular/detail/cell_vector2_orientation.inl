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
#include <rlm/position_orientation.hpp>
#include <rlm/cellular/cell_vector2.hpp>

template <rl::signed_integral I>
constexpr I rl::orientation_determinant(
    const rl::cell_vector2<I>& point_a,
    const rl::cell_vector2<I>& point_b,
    const rl::cell_vector2<I>& point_c
) noexcept
{
    return
        (point_b.y - point_a.y) *
        (point_c.x - point_b.x) -
        (point_b.x - point_a.x) *
        (point_c.y - point_b.y);
}

template <rl::signed_integral I>
constexpr rl::PositionOrientation rl::position_orientation(
    const rl::cell_vector2<I>& point_a,
    const rl::cell_vector2<I>& point_b,
    const rl::cell_vector2<I>& point_c
) noexcept
{
    const auto determinant = rl::orientation_determinant(point_a, point_b, point_c);
    if (determinant == 0)
    {
        return rl::PositionOrientation::Collinear;
    }
    else if (determinant > 0)
    {
        return rl::PositionOrientation::Clockwise;
    }
    else  // if (determinant < 0)
    {
        return rl::PositionOrientation::CounterClockwise;
    }
}

