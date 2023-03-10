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

namespace rl
{
    template<rl::signed_integral I>
    struct cell_vector2;
    template<rl::signed_integral I>
    struct cell_segment2;
    template<rl::signed_integral I>
    struct cell_box2;
    template<rl::signed_integral I, rl::floating_point F>
    struct cell_circle2;

    template<rl::signed_integral I = int, rl::floating_point F = float>
    constexpr rl::cell_box2<I> bounding_cell_box2(const rl::cell_vector2<I>& point) noexcept;

    template<rl::signed_integral I = int, rl::floating_point F = float>
    constexpr rl::cell_box2<I> bounding_cell_box2(const rl::cell_segment2<I>& segment) noexcept;

    template<rl::signed_integral I = int, rl::floating_point F = float>
    constexpr rl::cell_box2<I> bounding_cell_box2(const rl::cell_box2<I>& box) noexcept;

    template<rl::signed_integral I = int, rl::floating_point F = float>
    constexpr rl::cell_box2<I> bounding_cell_box2(const rl::cell_circle2<I, F>& circle) noexcept;

    template<typename I = int,
             typename F = float,
             rl::cellular_shape<I, F> S,
             rl::cellular_shape<I, F>... Ss>
    constexpr rl::cell_box2<I> bounding_cell_box2(const S& shape_a, const Ss&... shape_n) noexcept;
}    // namespace rl

#include <rlm/cellular/detail/bounding_cell_box2.inl>
