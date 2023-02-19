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
#include <rlm/cellular/cell_segment2.hpp>
#include <rlm/cellular/translation.hpp>
#include <rlm/cellular/magnitude.hpp>
#include <cmath>

template<rl::signed_integral I, rl::floating_point F>
constexpr F rl::length(const rl::cell_segment2<I>& segment) noexcept
{
    const auto translation = rl::translation<I>(segment);
    return rl::magnitude<I, F>(translation);
}

template<rl::signed_integral I>
constexpr I rl::cell_length(const rl::cell_segment2<I>& segment) noexcept
{
    return
        rl::max(
            rl::width(segment),
            rl::height(segment)
        );
}

template<rl::signed_integral I>
constexpr I rl::width(const rl::cell_segment2<I>& segment) noexcept
{
    return
        std::abs(
            segment.end_x -
            segment.start_x
        ) + 1;
}

template<rl::signed_integral I>
constexpr I rl::height(const rl::cell_segment2<I>& segment) noexcept
{
    return
        std::abs(
            segment.end_y -
            segment.start_y
        ) + 1;
}

