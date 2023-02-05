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
#include <optional>

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

    template<rl::signed_integral I>
    constexpr bool is_point2(const rl::segment2<I>& segment) noexcept;

    template<rl::signed_integral I>
    constexpr bool is_point2(const rl::box2<I>& box) noexcept;

    template<rl::signed_integral I, rl::floating_point>
    constexpr bool is_point2(const rl::circle2<I, F>& circle) noexcept;

    template<rl::signed_integral I>
    constexpr std::optional<rl::point2<I>> as_point2(const rl::segment2<I>& segment) noexcept;

    template<rl::signed_integral I>
    constexpr std::optional<rl::point2<I>> as_point2(const rl::box2<I>& box) noexcept;

    template<rl::signed_integral I, rl::floating_point>
    constexpr std::optional<rl::point2<I>> as_point2(const rl::circle2<I, F>& circle) noexcept;

    template<rl::signed_integral I>
    constexpr bool is_segment2(const rl::box2<I>& box) noexcept;

    template<rl::signed_integral I, rl::floating_point>
    constexpr bool is_segment2(const rl::circle2<I, F>& circle) noexcept;

    template<rl::signed_integral I>
    constexpr rl::segment2<I> as_segment2(const rl::point2<I>& point) noexcept;

    template<rl::signed_integral I>
    constexpr std::optional<rl::segment2<I>> as_segment2(const rl::box2<I>& box) noexcept;

    template<rl::signed_integral I, rl::floating_point>
    constexpr std::optional<rl::segment2<I>> as_segment2(const rl::circle2<I, F>& circle) noexcept;

    template<rl::signed_integral I>
    constexpr bool is_box2(const rl::segment2<I>& segment) noexcept;

    template<rl::signed_integral I, rl::floating_point>
    constexpr bool is_box2(const rl::circle2<I, F>& circle) noexcept;

    template<rl::signed_integral I>
    constexpr std::optional<rl::box2<I>> as_box2(const rl::point2<I>& point) noexcept;

    template<rl::signed_integral I>
    constexpr std::optional<rl::box2<I>> as_box2(const rl::segment2<I>& segment) noexcept;

    template<rl::signed_integral I, rl::floating_point>
    constexpr std::optional<rl::box2<I>> as_box2(const rl::circle2<I, F>& circle) noexcept;
}

#include <rlm/cellular/detail/shape_conversion.inl>

