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

#include <ostream>
#include <type_traits>
#include <rlm/color/concepts.hpp>
#include <rlm/color/color_g.hpp>
#include <rlm/color/color_ga.hpp>
#include <rlm/color/color_rgb.hpp>
#include <rlm/color/color_rgba.hpp>

namespace rl
{
    template<rl::color_channel C>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::color_g<C>& color)
    {
        if constexpr (std::is_same<C, unsigned char>::value || std::is_same<C, wchar_t>::value)
        {
            os << "(" << static_cast<unsigned int>(color.g) << ")";
        }
        else
        {
            os << "(" << color.g << ")";
        }
        return os;
    }

    template<rl::color_channel C>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::color_ga<C>& color)
    {
        if constexpr (std::is_same<C, unsigned char>::value || std::is_same<C, wchar_t>::value)
        {
            os << "(" << static_cast<unsigned int>(color.g) << ", " << static_cast<unsigned int>(color.a) << ")";
        }
        else
        {
            os << "(" << color.g << ", " << color.a << ")";
        }
        return os;
    }

    template<rl::color_channel C>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::color_rgb<C>& color)
    {
        if constexpr (std::is_same<C, unsigned char>::value || std::is_same<C, wchar_t>::value)
        {
            os << "(" << static_cast<unsigned int>(color.r) << ", " << static_cast<unsigned int>(color.g) << ", " << static_cast<unsigned int>(color.b) << ")";
        }
        else
        {
            os << "(" << color.r << ", " << color.g << ", " << color.b << ")";
        }
        return os;
    }

    template<rl::color_channel C>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::color_rgba<C>& color)
    {
        if constexpr (std::is_same<C, unsigned char>::value || std::is_same<C, wchar_t>::value)
        {
            os << "(" << static_cast<unsigned int>(color.r) << ", " << static_cast<unsigned int>(color.g) << ", " << static_cast<unsigned int>(color.b) << ", " << static_cast<unsigned int>(color.a) << ")";
        }
        else
        {
            os << "(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
        }
        return os;
    }
}    // namespace rl