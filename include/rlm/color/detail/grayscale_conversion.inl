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
#include <rlm/color/color_channel.hpp>
#include <cstdint>
#include <type_traits>

template<rl::color_channel C>
constexpr C rl::rgb_to_grayscale_libpng(C r, C g, C b) noexcept
{
    if constexpr (std::is_floating_point<C>::value)
    {
        return 
            static_cast<C>(0.21268) *
            rl::color_channel_clamp<C>(r) +
            static_cast<C>(0.7151) *
            rl::color_channel_clamp<C>(g) +
            static_cast<C>(0.07217) *
            rl::color_channel_clamp<C>(b);
    }
    else // if constexpr (std::is_unsigned<C>::value)
    {
        static_assert(
            !std::is_same<C, std::uintmax_t>::value,
            "color channel type unconvertable to grayscale"
        );
        return 
            (
                static_cast<std::uintmax_t>(6969) *
                static_cast<std::uintmax_t>(r) +
                static_cast<std::uintmax_t>(23434) *
                static_cast<std::uintmax_t>(g) +
                static_cast<std::uintmax_t>(2365) *
                static_cast<std::uintmax_t>(b)
            ) /
            static_cast<std::uintmax_t>(32768);
    }
}