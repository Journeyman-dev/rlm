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
#include <rlm/linear/box2.hpp>
#include <rlm/linear/vector2.hpp>
#include <rlm/linear/vector3.hpp>
#include <rlm/linear/vector4.hpp>
#include <rlm/hash_combine.hpp>
#include <cstddef>
#include <functional>

namespace std
{
    template<rl::floating_point F>
    constexpr std::size_t hash<rl::box2<F>>::operator()(const rl::box2<F> &box) const
    {
        return
            rl::hash_combine(
                std::hash<F>{}(box.x),
                std::hash<F>{}(box.y),
                std::hash<F>{}(box.width),
                std::hash<F>{}(box.height)
            );
    }

    constexpr std::size_t hash<rl::vector2<F>>::operator()(const rl::vector2<F> &vector) const
    {
        return
            rl::hash_combine(
                std::hash<F>{}(vector.x),
                std::hash<F>{}(vector.y)
            );
    }

    constexpr std::size_t hash<rl::vector3<F>>::operator()(const rl::vector3<F> &vector) const
    {
        return
            rl::hash_combine(
                std::hash<F>{}(vector.x),
                std::hash<F>{}(vector.y),
                std::hash<F>{}(vector.z)
            );
    }

    constexpr std::size_t hash<rl::vector4<F>>::operator()(const rl::vector4<F> &vector) const
    {
        return
            rl::hash_combine(
                std::hash<F>{}(vector.x),
                std::hash<F>{}(vector.y),
                std::hash<F>{}(vector.z),
                std::hash<F>{}(vector.w)
            );
    }
}