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

template<rl::signed_integral Ia, rl::signed_integral Ib>
constexpr rl::cell_vector2<Ia> rl::template_cast(const rl::cell_vector2<Ib>& point) noexcept
{
    return
        rl::cell_vector2<Ia>(
            static_cast<Ia>(point.x),
            static_cast<Ia>(point.y)
        );
}

template<rl::signed_integral Ia, rl::signed_integral Ib>
constexpr rl::cell_segment2<Ia> rl::template_cast(const rl::cell_segment2<Ib>& segment) noexcept
{
    return
        rl::cell_segment2<Ia>(
            static_cast<Ia>(segment.start_x),
            static_cast<Ia>(segment.start_y),
            static_cast<Ia>(segment.end_x),
            static_cast<Ia>(segment.end_y)
        );
}

template<rl::signed_integral Ia, rl::signed_integral Ib>
constexpr rl::cell_box2<Ia> rl::template_cast(const rl::cell_box2<Ib>& box) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_box, box);
    return
        rl::cell_box2<Ia>(
            static_cast<Ia>(fixed_box.x),
            static_cast<Ia>(fixed_box.y),
            static_cast<Ia>(fixed_box.width),
            static_cast<Ia>(fixed_box.height)
        );
}

template<rl::signed_integral Ia, rl::floating_point Fa, rl::signed_integral Ib, rl::floating_point Fb>
constexpr rl::cell_circle2<Ia, Fa> rl::template_cast(const rl::cell_circle2<Ib, Fb>& circle) noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_circle, circle);
    return
        rl::cell_circle2<Ia, Fa>(
            static_cast<Ia>(fixed_circle.x),
            static_cast<Ia>(fixed_circle.y),
            static_cast<Fa>(fixed_circle.radius)
        );
}

