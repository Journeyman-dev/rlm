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
#include <rlm/hash_combine.hpp>
#include <functional>
#include <cstddef>

namespace std
{
    template <rl::signed_integral I>
    constexpr std::size_t std::hash<rl::cell_vector2<I>>::operator()(const rl::cell_vector2<I> &point) const
    {
        return
            rl::hash_combine(
                std::hash<I>{}(point.x),
                std::hash<I>{}(point.y)
            );
    }

    template <rl::signed_integral I>
    constexpr std::size_t std::hash<rl::cell_segment2<I>>::operator()(const rl::cell_segment2<I> &segment) const
    {
        return 
            rl::hash_combine(
                std::hash<I>{}(segment.start_x),
                std::hash<I>{}(segment.start_y),
                std::hash<I>{}(segment.end_x),
                std::hash<I>{}(segment.end_y),
            );
    }

    template <rl::signed_integral I>
    constexpr std::size_t std::hash<rl::cell_box2<I>>::operator()(const rl::cell_box2<I> &box) const
    {
        return 
            rl::hash_combine(
                std::hash<I>{}(box.x),
                std::hash<I>{}(box.y),
                std::hash<I>{}(box.width),
                std::hash<I>{}(box.height)
            );
    }

    template <rl::signed_integral I, rl::floating_point F>
    constexpr std::size_t std::hash<rl::cell_circle2<I, F>>::operator()(const rl::cell_circle2<I, F> &circle) const
    {
        return 
            rl::hash_combine(
                std::hash<C>{}(circle.x),
                std::hash<C>{}(circle.y),
                std::hash<C>{}(circle.radius)
            );
    }

    template <rl::signed_integral I>
    constexpr std::size_t std::hash<rl::pack_box<I>>::operator()(const rl::pack_box<I> &box) const
    {
        return 
            rl::hash_combine(
                std::hash<I>{}(box.box),
                std::hash<I>{}(box.page),
                std::hash<I>{}(box.identifier)
            );
    }

    template <rl::signed_integral I>
    constexpr std::size_t std::hash<rl::pack_space<I>>::operator()(const rl::pack_space<I> &space) const
    {
        return 
            rl::hash_combine(
                std::hash<I>{}(space.box),
                std::hash<I>{}(space.page)
            );
    }
}