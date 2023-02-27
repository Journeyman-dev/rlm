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
#include <rlm/clamp.hpp>
#include <type_traits>

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr Ca rl::color_channel_cast(Cb channel) noexcept
{
   if constexpr (
        std::is_floating_point<Ca>::value &&
        std::is_unsigned<Cb>::value
    )
    {
        return
            static_cast<Ca>(
                rl::clamp<Cb>(
                    channel *
                    static_cast<Ca>(
                        rl::color_channel_max_value<Cb>()
                    ),
                    static_cast<Cb>(0),
                    static_cast<Cb>(
                        rl::color_channel_max_value<Cb>()
                    )
                )
            );
    }
    else if constexpr (
        std::is_unsigned<Ca>::value &&
        std::is_floating_point<Cb>::value
    )
    {
        return
            static_cast<Ca>(1) /
            static_cast<Ca>(rl::color_channel_max_value<Cb>()) *
            static_cast<Ca>(channel);
    }
    else if constexpr (
        std::is_unsigned<Ca>::value &&
        std::is_unsigned<Cb>::value
    )
    {
        using LargestType = std::conditional_v<
            sizeof(Ca) > sizeof(Cb),
            Ca,
            Cb
        >;
        return
            static_cast<Ca>(
                static_cast<LargestType>(std::numeric_limits<Ca>::max()) /
                static_cast<LargestType>(std::numeric_limits<Cb>::max()) *
                static_cast<LargestType>(channel)
            );
    }
    else if constexpr (
        std::is_floating_point<Ca>::value &&
        std::is_floating_point<Cb>::value  
    )
    {
        return static_cast<Ca>(channel);
    }
    static_assert("invalid color channel type");
    return channel;
}

template<rl::color_channel C>
constexpr C rl::color_channel_max_value()
{
    if constexpr (std::is_floating_point<C>::value)
    {
        return static_cast<C>(1);
    }
    else //if constexpr (std::is_unsigned<C>::value)
    {
        return std::numeric_limits<C>::max();
    }
    static_assert(true, "invalid color channel type");
    return 0;
}

template<rl::color_channel C>
constexpr C rl::color_channel_clamp(C channel)
{
    if constexpr (std::is_floating_point<C>::value)
    {
        return
            rl::clamp<C>(
                channel,
                static_cast<C>(0),
                rl::color_channel_max_value<C>()
            );
    }
    return channel;
}