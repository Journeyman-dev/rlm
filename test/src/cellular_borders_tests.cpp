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

#include <catch2/catch_all.hpp>
#include <rlm/cellular/borders.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("The borders are gotten from a box2")
{
    GIVEN("A box2")
    {
        const rl::box2 box(1, 2, 3, 4);
        WHEN("The left border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(1, 4, 1, 2));
                CHECK(counter_clockwise_corner == rl::segment2(1, 5, 1, 3));
                CHECK(left_corner == rl::segment2(1, 5, 1, 2));
                CHECK(right_corner == rl::segment2(1, 4, 1, 3));
                CHECK(top_corner == rl::segment2(1, 4, 1, 2));
                CHECK(bottom_corner == rl::segment2(1, 4, 1, 2));
            }
        }
        WHEN("The left border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner =
                rl::left_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(1, 2, 1, 4));
                CHECK(counter_clockwise_corner == rl::segment2(1, 3, 1, 5));
                CHECK(left_corner == rl::segment2(1, 2, 1, 5));
                CHECK(right_corner == rl::segment2(1, 3, 1, 4));
                CHECK(top_corner == rl::segment2(1, 2, 1, 4));
                CHECK(bottom_corner == rl::segment2(1, 2, 1, 4));
            }
        }
        WHEN("The right border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(3, 3, 3, 5));
                CHECK(counter_clockwise_corner == rl::segment2(3, 2, 3, 4));
                CHECK(left_corner == rl::segment2(3, 3, 3, 4));
                CHECK(right_corner == rl::segment2(3, 2, 3, 5));
                CHECK(top_corner == rl::segment2(3, 2, 3, 4));
                CHECK(bottom_corner == rl::segment2(3, 2, 3, 4));
            }
        }
        WHEN("The right border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner =
                rl::right_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(3, 5, 3, 3));
                CHECK(counter_clockwise_corner == rl::segment2(3, 4, 3, 2));
                CHECK(left_corner == rl::segment2(3, 4, 3, 3));
                CHECK(right_corner == rl::segment2(3, 5, 3, 2));
                CHECK(top_corner == rl::segment2(3, 4, 3, 2));
                CHECK(bottom_corner == rl::segment2(3, 4, 3, 2));
            }
        }
        WHEN("The top border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(2, 2, 2, 2));
                CHECK(counter_clockwise_corner == rl::segment2(1, 2, 3, 2));
                CHECK(left_corner == rl::segment2(1, 2, 3, 2));
                CHECK(right_corner == rl::segment2(2, 2, 2, 2));
                CHECK(top_corner == rl::segment2(1, 2, 2, 2));
                CHECK(bottom_corner == rl::segment2(1, 2, 2, 2));
            }
        }
        WHEN("The top border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner =
                rl::top_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(2, 2, 2, 2));
                CHECK(counter_clockwise_corner == rl::segment2(3, 2, 1 ,2));
                CHECK(left_corner == rl::segment2(3, 2, 1, 2));
                CHECK(right_corner == rl::segment2(2, 2, 2, 2));
                CHECK(top_corner == rl::segment2(2, 2, 1, 2));
                CHECK(bottom_corner == rl::segment2(2, 2, 1, 2));
            }
        }
        WHEN("The bottom border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(3, 5, 2, 5));
                CHECK(counter_clockwise_corner == rl::segment2(2, 5, 1, 5));
                CHECK(left_corner == rl::segment2(3, 5, 2, 5));
                CHECK(right_corner == rl::segment2(2, 5, 1, 5));
                CHECK(top_corner == rl::segment2(3, 5, 1, 5));
                CHECK(bottom_corner == rl::segment2(3, 5, 1, 5));
            }
        }
        WHEN("The bottom border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner =
                rl::bottom_border(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The borders are correct")
            {
                CHECK(clockwise_corner == rl::segment2(2, 5, 3, 5));
                CHECK(counter_clockwise_corner == rl::segment2(1, 5, 2, 5));
                CHECK(left_corner == rl::segment2(2, 5, 3, 5));
                CHECK(right_corner == rl::segment2(1, 5, 2, 5));
                CHECK(top_corner == rl::segment2(1, 5, 3, 5));
                CHECK(bottom_corner == rl::segment2(1, 5, 3, 5));
            }
        }
    }
}