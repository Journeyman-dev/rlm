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

#ifndef RLM_CELLULAR_SUB_SHAPES_INL
#define RLM_CELLULAR_SUB_SHAPES_INL

#include <rlm/concepts.hpp>
#include <rlm/cellular/point2.hpp>
#include <rlm/cellular/segment2.hpp>

template<rl::signed_integral I>
constexpr rl::point2<I> rl::start(const rl::segment2<I>& segment) const noexcept
{
    return
        rl::point2<I>(
            segment.start_x,
            segment.start_y
        );
}

template<rl::signed_integral I = int>
constexpr rl::point2<I> rl::end(const rl::segment2<I>& segment) const noexcept
{
    return
        rl::point2<I>(
            segment.end_x,
            segment.end_y
        );
}

#endif