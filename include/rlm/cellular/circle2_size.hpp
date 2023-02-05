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

#ifndef RLM_CELLULAR_CIRCLE2_SIZE_HPP
#define RLM_CELLULAR_CIRCLE2_SIZE_HPP

#include <rlm/concepts.hpp>

namespace rl
{
    template<rl::signed_integral I, rl::floating_point F>
    struct circle2;

    template<rl::signed_integral I, rl::floating_point F>
    constexpr I tile_radius(const rl::circle2<I, F>& circle) noexcept;

    template<rl::signed_integral I, rl::floating_point F>
    constexpr F diameter(const rl::circle2<I, F>& circle) noexcept;

    template<rl::signed_integral I, rl::floating_point F>
    constexpr I tile_diameter(const rl::circle2<I, F>& circle) noexcept;
}

#include <rlm/cellular/detail/circle2_size.inl>

#endif