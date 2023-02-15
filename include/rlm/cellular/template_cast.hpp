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

namespace rl
{
    template<rl::signed_integral I>
    struct point2;
    template<rl::signed_integral I>
    struct segment2;
    template<rl::signed_integral I>
    struct box2;
    template<rl::signed_integral I, rl::floating_point F>
    struct circle2;

    template<rl::signed_integral Ia, rl::signed_integral Ib>
    constexpr rl::point2<Ia> template_cast(const rl::point2<Ib>& point) noexcept;

    template<rl::signed_integral Ia, rl::signed_integral Ib>
    constexpr rl::segment2<Ia> template_cast(const rl::segment2<Ib>& segment) noexcept;

    template<rl::signed_integral Ia, rl::signed_integral Ib>
    constexpr rl::box2<Ia> template_cast(const rl::box2<Ib>& box) noexcept;

    template<rl::signed_integral Ia,
             rl::floating_point Fa,
             rl::signed_integral Ib,
             rl::floating_point Fb>
    constexpr rl::circle2<Ia, Fa> template_cast(const rl::circle2<Ib, Fb>& circle) noexcept;
}    // namespace rl

#include <rlm/cellular/detail/template_cast.inl>
