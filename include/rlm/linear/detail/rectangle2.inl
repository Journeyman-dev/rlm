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

template<rl::floating_point F>
constexpr rl::rectangle2<F>::rectangle2(F x, F y, F width, F height) noexcept
    : x(x)
    , y(y)
    , width(width)
    , height(height)
{
}

template<rl::floating_point F>
constexpr bool rl::rectangle2<F>::operator==(const rl::rectangle2<F>& that) const noexcept
{
    return
        this->x == that.x &&
        this->y == that.y &&
        this->width == that.width &&
        this->height == that.height;
}

template<rl::floating_point F>
constexpr bool rl::rectangle2<F>::operator!=(const rl::rectangle2<F>& that) const noexcept
{
    return
        this->x != that.x ||
        this->y != that.y ||
        this->width != that.width ||
        this->height != that.height;
}