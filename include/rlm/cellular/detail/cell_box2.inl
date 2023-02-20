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

#include <rlm/configuration.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>

template<rl::signed_integral I>
constexpr rl::cell_box2<I>::cell_box2(I x, I y, I width, I height) noexcept
    : x(x)
    , y(y)
    , width(width)
    , height(height)
{
}

template<rl::signed_integral I>
constexpr bool rl::cell_box2<I>::operator==(const rl::cell_box2<I>& that) const noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_this, *this);
    RLM_HANDLE_DEGENERACY(fixed_that, that);
    return
        fixed_this.x == fixed_that.x &&
        fixed_this.y == fixed_that.y &&
        fixed_this.width == fixed_that.width &&
        fixed_this.height == fixed_that.height;
}

template<rl::signed_integral I>
constexpr bool rl::cell_box2<I>::operator!=(const rl::cell_box2<I>& that) const noexcept
{
    RLM_HANDLE_DEGENERACY(fixed_this, *this);
    RLM_HANDLE_DEGENERACY(fixed_that, that);
    return
        fixed_this.x != fixed_that.x ||
        fixed_this.y != fixed_that.y ||
        fixed_this.width != fixed_that.width ||
        fixed_this.height != fixed_that.height;
}
