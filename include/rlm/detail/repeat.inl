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

#ifndef RLM_REPEAT_INL
#define RLM_REPEAT_INL

#include <rlm/concepts.hpp>
#include <rlm/min.hpp>
#include <rlm/max.hpp>
#include <cmath>
#include <type_traits>

template<rl::primitive P>
constexpr P rl::repeat(P value, P a, P b) noexcept
{
    const auto min = rl::min(a, b);
    const auto max = rl::max(a, b);
    const auto denominator = max - min;
    if (denominator == 0)
    {
        return min;
    }
    P mod;
    if (std::is_floating_point_v<P>)
    {
        mod = fmod(value, denominator);
    }
    else // if (!std::is_floating_point_v<P>)
    {
        mod = value % denominator;
    }
    return min + mod;
}

#endif