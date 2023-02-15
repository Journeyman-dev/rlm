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

#include <concepts>
#include <type_traits>

namespace rl
{
    template<typename T>
    concept primitive = std::floating_point<T> || std::integral<T>;

    template<typename T>
    concept signed_primitive = std::floating_point<T> || std::signed_integral<T>;

    template<typename T>
    concept unsigned_primitive = std::unsigned_integral<T>;

    template<typename T>
    concept floating_point = std::floating_point<T>;

    template<typename T>
    concept integral = std::integral<T>;

    template<typename T>
    concept signed_integral = std::signed_integral<T>;

    template<typename T>
    concept unsigned_integral = std::unsigned_integral<T>;

    template<typename T>
    concept totally_ordered = std::totally_ordered<T>;

    template<typename T>
    concept equality_comparable = std::equality_comparable<T>;

    template<typename T, typename... Ts>
    concept is_any_of = (std::same_as<T, Ts> || ...);
}    // namespace rl
