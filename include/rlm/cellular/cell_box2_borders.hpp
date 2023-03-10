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
#include <rlm/cellular/border_corners.hpp>
#include <rlm/rotation_motion.hpp>
#include <optional>

namespace rl
{
    template<rl::signed_integral I>
    struct cell_segment2;
    template<rl::signed_integral I>
    struct cell_box2;

    template<rl::signed_integral I = int>
    constexpr rl::cell_segment2<I>
    left_border(const rl::cell_box2<I>& box,
                rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;

    template<rl::signed_integral I = int>
    constexpr rl::cell_segment2<I>
    right_border(const rl::cell_box2<I>& box,
                 rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;

    template<rl::signed_integral I = int>
    constexpr rl::cell_segment2<I>
    top_border(const rl::cell_box2<I>& box,
               rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;

    template<rl::signed_integral I = int>
    constexpr rl::cell_segment2<I>
    bottom_border(const rl::cell_box2<I>& box,
                  rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;

    template<rl::signed_integral I = int>
    constexpr std::optional<rl::cell_segment2<I>> right_border_trimmed(
        const rl::cell_box2<I>& box,
        rl::BorderCorners border_corners = rl::BorderCorners::None,
        rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;

    template<rl::signed_integral I = int>
    constexpr std::optional<rl::cell_segment2<I>>
    top_border_trimmed(const rl::cell_box2<I>& box,
                       rl::BorderCorners border_corners = rl::BorderCorners::None,
                       rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;

    template<rl::signed_integral I = int>
    constexpr std::optional<rl::cell_segment2<I>> bottom_border_trimmed(
        const rl::cell_box2<I>& box,
        rl::BorderCorners border_corners = rl::BorderCorners::None,
        rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;

    template<rl::signed_integral I = int>
    constexpr std::optional<rl::cell_segment2<I>> left_border_trimmed(
        const rl::cell_box2<I>& box,
        rl::BorderCorners border_corners = rl::BorderCorners::None,
        rl::RotationMotion rotation_motion = rl::RotationMotion::Clockwise) noexcept;
}    // namespace rl

#include <rlm/cellular/detail/cell_box2_borders.inl>
