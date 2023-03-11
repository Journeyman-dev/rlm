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

#include <rlm/color/concepts.hpp>
#include <rlm/color/color_g.hpp>
#include <rlm/color/color_ga.hpp>
#include <rlm/hash_combine.hpp>
#include <functional>
#include <cstddef>

namespace std
{
    template <rl::color_channel C>
    constexpr std::size_t hash<rl::color_g<C>>::operator()(const rl::color_g<C> &color) const
    {
        return std::hash<C>{}(color.g);
    }

    template <rl::color_channel C>
    constexpr std::size_t hash<rl::color_ga<C>>::operator()(const rl::color_g<C> &color) const
    {
        return 
            rl::hash_combine(
                std::hash<C>{}(color.g),
                std::hash<C>{}(color.a)
            );
    }

    template <rl::color_channel C>
    constexpr std::size_t hash<rl::color_rgb<C>>::operator()(const rl::color_rgb<C> &color) const
    {
        return 
            rl::hash_combine(
                std::hash<C>{}(color.r),
                std::hash<C>{}(color.g),
                std::hash<C>{}(color.b)
            );
    }

    template <rl::color_channel C>
    constexpr std::size_t hash<rl::color_rgba<C>>::operator()(const rl::color_rgba<C> &color) const
    {
        return 
            rl::hash_combine(
                std::hash<C>{}(color.r),
                std::hash<C>{}(color.g),
                std::hash<C>{}(color.b),
                std::hash<C>{}(color.a)
            );
    }
}