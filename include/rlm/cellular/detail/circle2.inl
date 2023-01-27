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

#ifndef RLM_CELLULAR_CIRCLE2_INL
#define RLM_CELLULAR_CIRCLE2_INL

template<rl::signed_integral I, rl::floating_point F>
constexpr rl::circle2<I, F>::circle2(I x, I y, F radius) noexcept
    : x(x)
    , y(y)
    , radius(radius)
{
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::circle2<I, F>::operator==(const rl::circle2<I, F>& that) const noexcept
{
    return
        this->x == that.x &&
        this->y == that.y &&
        this->radius == that.radius;
}

template<rl::signed_integral I, rl::floating_point F>
constexpr bool rl::circle2<I, F>::operator!=(const rl::circle2<I, F>& that) const noexcept
{
    return
        this->x != that.x ||
        this->y != that.y ||
        this->radius != that.radius;
}

#endif