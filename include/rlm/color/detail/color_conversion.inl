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
#include <rlm/color/grayscale_conversion.hpp>
#include <rlm/color/color_g.hpp>
#include <rlm/color/color_ga.hpp>
#include <rlm/color/color_rgb.hpp>
#include <rlm/color/color_rgba.hpp>
#include <type_traits>
#include <limits>
#include <cstdint>

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_g<Ca> rl::to_color_g(rl::color_g<Cb> color) noexcept
{
    return
        rl::color_g<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(
                    color.g
                )
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_g<Ca> rl::to_color_g(rl::color_ga<Cb> color) noexcept
{
    return
        rl::color_g<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_g<Ca> rl::to_color_g(rl::color_rgb<Cb> color) noexcept
{
    return
        rl::color_g<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::rgb_to_grayscale_libpng<Cb>(
                    color.r,
                    color.g,
                    color.b
                )
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_g<Ca> rl::to_color_g(rl::color_rgba<Cb> color) noexcept
{
    return
        rl::color_g<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::rgb_to_grayscale_libpng<Cb>(
                    color.r,
                    color.g,
                    color.b
                )
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_ga<Ca> rl::to_color_ga(rl::color_g<Cb> color) noexcept
{
    return
        rl::color_ga<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_max_value<Ca>()
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_ga<Ca> rl::to_color_ga(rl::color_ga<Cb> color) noexcept
{
    return
        rl::color_ga<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.a)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_ga<Ca> rl::to_color_ga(rl::color_rgb<Cb> color) noexcept
{
    return
        rl::color_ga<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::rgb_to_grayscale_libpng<Cb>(
                    color.r,
                    color.g,
                    color.b
                )
            ),
            rl::color_channel_max_value<Ca>()
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_ga<Ca> rl::to_color_ga(rl::color_rgba<Cb> color) noexcept
{
    return
        rl::color_ga<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::rgb_to_grayscale_libpng<Cb>(
                    color.r,
                    color.g,
                    color.b
                )
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.a)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgb<Ca> rl::to_color_rgb(rl::color_g<Cb> color) noexcept
{
    return
        rl::color_rgb<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgb<Ca> rl::to_color_rgb(rl::color_ga<Cb> color) noexcept
{
    return
        rl::color_rgb<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgb<Ca> rl::to_color_rgb(rl::color_rgb<Cb> color) noexcept
{
    return
        rl::color_rgb<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.r)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.b)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgb<Ca> rl::to_color_rgb(rl::color_rgba<Cb> color) noexcept
{
    return
        rl::color_rgb<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.r)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.b)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgba<Ca> rl::to_color_rgba(rl::color_g<Cb> color) noexcept
{
    return
        rl::color_rgba<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_max_value<Ca>()
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgba<Ca> rl::to_color_rgba(rl::color_ga<Cb> color) noexcept
{
    return
        rl::color_rgba<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.a)
            )
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgba<Ca> rl::to_color_rgba(rl::color_rgb<Cb> color) noexcept
{
    return
        rl::color_rgba<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.r)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.b)
            ),
            rl::color_channel_max_value<Ca>()
        );
}

template<rl::color_channel Ca, rl::color_channel Cb>
constexpr rl::color_rgba<Ca> rl::to_color_rgba(rl::color_rgba<Cb> color) noexcept
{
    return
        rl::color_rgba<Ca>(
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.r)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.g)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.b)
            ),
            rl::color_channel_cast<Ca, Cb>(
                rl::color_channel_clamp<Cb>(color.a)
            )
        );
}