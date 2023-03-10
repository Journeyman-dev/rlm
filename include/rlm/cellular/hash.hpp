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
#include <rlm/cellular/cell_vector2.hpp>
#include <rlm/cellular/cell_segment2.hpp>
#include <rlm/cellular/cell_box2.hpp>
#include <rlm/cellular/cell_circle2.hpp>
#include <rlm/cellular/pack_box.hpp>
#include <rlm/cellular/pack_space.hpp>
#include <functional>

namespace std
{
    template <rl::signed_integral I>
    struct hash<rl::cell_vector2<I>> 
    {
        constexpr std::size_t operator()(const rl::cell_vector2<I> &point) const;
    };

    template <rl::signed_integral I>
    struct hash<rl::cell_segment2<I>> 
    {
        constexpr std::size_t operator()(const rl::cell_segment2<I> &segment) const;
    };

    template <rl::signed_integral I>
    struct hash<rl::cell_box2<I>> 
    {
        constexpr std::size_t operator()(const rl::cell_box2<I> &box) const;
    };

    template <rl::signed_integral I, rl::floating_point F>
    struct hash<rl::cell_circle2<I, F>> 
    {
        constexpr std::size_t operator()(const rl::cell_circle2<I, F> &circle) const;
    };

    template <rl::signed_integral I>
    struct hash<rl::pack_box<I>> 
    {
        constexpr std::size_t operator()(const rl::pack_box<I> &box) const;
    };

    template <rl::signed_integral I>
    struct hash<rl::pack_space<I>> 
    {
        constexpr std::size_t operator()(const rl::pack_space<I> &space) const;
    };
}

#include <rlm/cellular/detail/hash.inl>