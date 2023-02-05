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

#ifndef RLM_CELLULAR_STRUCT_CAST_INL
#define RLM_CELLULAR_STRUCT_CAST_INL

#include <rlm/concepts.hpp>
#include <rlm/cellular/point2.hpp>
#include <rlm/cellular/segment2.hpp>
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/circle2.hpp>

template<rl::signed_integral Ia, rl::signed_integral Ib>
constexpr rl::point2<Ia> rl::struct_cast(const rl::point2<Ib>& point)
{
    return
        rl::point2<Ia>(
            static_cast<Ia>(point.x),
            static_cast<Ia>(point.y)
        );
}

template<rl::signed_integral Ia, rl::signed_integral Ib>
constexpr rl::segment2<Ia> rl::struct_cast(const rl::segment2<Ib>& segment)
{
    return
        rl::segment2<1a>(
            static_cast<Ia>(segment.start_x),
            static_cast<Ia>(segment.start_y),
            static_cast<Ia>(segment.end_x),
            static_cast<Ia>(segment.end_y)
        );
}

template<rl::signed_integral Ia, rl::signed_integral Ib>
constexpr rl::box2<Ia> rl::struct_cast(const rl::box2<Ib>& box)
{
    return
        rl::box2<Ia>(
            static_cast<Ia>(box.x),
            static_cast<Ia>(box.y),
            static_cast<Ia>(box.width),
            static_cast<Ia>(box.height)
        );
}

template<rl::signed_integral Ia, rl::floating_point Fa, rl::signed_integral Ib, rl::floating_point Fb>
constexpr rl::circle2<Ia, Fa> rl::struct_cast(const rl::circle2<Ib, Fb>& circle)
{
    return
        rl::circle2<Ia>(
            static_cast<Ia>(circle.x),
            static_cast<Ia>(circle.y),
            static_cast<Fa>(circle.radius)
        );
}

#endif