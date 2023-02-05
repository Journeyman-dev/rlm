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

#ifndef RLM_LINEAR_OSTREAM_HPP
#define RLM_LINEAR_OSTREAM_HPP

#include <ostream>
#include <rlm/concepts.hpp>

namespace rl
{
    template<rl::floating_point F>
    struct vector2;
    template<rl::floating_point F>
    struct vector3;
    template<rl::floating_point F>
    struct vector4;
    template<rl::floating_point F>
    struct rectangle2;

    template<rl::signed_integral F = float>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::vector2<F>& vector);

    template<rl::floating_point F = float>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::vector3<F>& vector);

    template<rl::floating_point F = float = float>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::vector4<F>& vector);

    template<rl::floating_point F = float>
    constexpr std::ostream& operator<<(std::ostream& os, const rl::rectangle2<F>& rectangle);
}    // namespace rl

#include <rlm/linear/detail/ostream.inl>

#endif