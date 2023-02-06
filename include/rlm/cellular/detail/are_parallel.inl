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
#include <rlm/cellular/cross.hpp>
#include <rlm/cellular/segment2.hpp>

template <rl::signed_integral I>
constexpr bool rl::are_parallel(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b) noexcept
{
    return rl::cross_z<I>(segment_a, segment_b) == 0;
}

template <typename I, rl::is_any_of<rl::segment2<I>>... SGs>
constexpr bool rl::are_parallel(const rl::segment2<I>& segment_a, const rl::segment2<I>& segment_b, const SGs&... segment_n) noexcept
{
    return
        rl::are_parallel<I>(
            segment_a,
            segment_b
        ) &&
        rl::are_parallel<I>(
            segment_b,
            segment_n...
        );
}

