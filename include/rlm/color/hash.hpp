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

#include <rlm/color/color_g.hpp>
#include <rlm/color/color_ga.hpp>
#include <rlm/color/color_rgb.hpp>
#include <rlm/color/color_rgba.hpp>
#include <functional>
#include <cstddef>

namespace std
{
    template <rl::color_channel C>
    struct hash<rl::color_g<C>> 
    {
        constexpr std::size_t operator()(const rl::color_g<C> &color) const;
    };

    template <rl::color_channel C>
    struct hash<rl::color_ga<C>> 
    {
        constexpr std::size_t operator()(const rl::color_ga<C> &color) const;
    };

    template <rl::color_channel C>
    struct hash<rl::color_rgb<C>> 
    {
        constexpr std::size_t operator()(const rl::color_rgb<C> &color) const;
    };

    template <rl::color_channel C>
    struct hash<rl::color_rgba<C>> 
    {
        constexpr std::size_t operator()(const rl::color_rgba<C> &color) const;
    };
}

#include <rlm/color/detail/hash.inl>