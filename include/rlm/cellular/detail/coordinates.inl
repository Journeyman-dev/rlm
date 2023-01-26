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

#ifndef RLM_CELLULAR_COORDINATES_INL
#define RLM_CELLULAR_COORDINATES_INL

#include <rlm/concepts.hpp>
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/is_degenerate.hpp>
#include <cassert>

template<rl::signed_integral I>
constexpr I rl::far_x(const rl::box2<I>& box) noexcept
{
    assert(!rl::is_degenerate(box) && "getting far_x of degenerate box2");
    return box.x + box.width - 1;
}

template<rl::signed_integral I>
constexpr I rl::far_y(const rl::box2<I>& box) noexcept
{
    assert(!rl::is_degenerate(box) && "getting far_y of degenerate box2");
    return box.y + box.height - 1;
}

#endif