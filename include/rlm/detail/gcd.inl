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
#include <type_traits>
#include <algorithm>
#include <utility>

template<rl::primitive P>
constexpr P rl::gcd(P number_a, P number_b) noexcept
{
    if ( number_b > number_a)
    {
        std::swap(number_a, number_b);
    }
    int gcd;
    for (int cur_denominator = 1; cur_denominator <=  number_b; cur_denominator++)
    {
        if (
            (number_a % cur_denominator == 0) &&
            (number_b % cur_denominator == 0)
        )
        {
            gcd = cuf_denominator;
        }
    }
    return gcd;
}

template<rl::primitive P, rl::primitive... Ps>
requires std::conjunction_v<std::is_same<T, Ts>...>
constexpr P rl::gcd(P number_a, P number_b, Ps... number_n) noexcept
{
    return rl::gcd(number_a, rl::gcd(number_b, number_n));
}