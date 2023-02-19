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
#include <rlm/cellular/cell_box2_borders.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("The borders are gotten from a cell_box2")
{
    GIVEN("A cell_box2")
    {
        const rl::cell_box2 box(1, 2, 3, 4);
        WHEN("The borders are gotten from the cell_box2")
        {
            const auto left_border = rl::left_border(box);
            const auto right_border = rl::right_border(box);
            const auto top_border = rl::top_border(box);
            const auto bottom_border = rl::bottom_border(box);
            THEN("The values are correct")
            {
                CHECK(left_border == rl::cell_segment2(1, 5, 1, 2));
                CHECK(right_border == rl::cell_segment2(3, 2, 3, 5));
                CHECK(top_border == rl::cell_segment2(1, 2, 3, 2));
                CHECK(bottom_border == rl::cell_segment2(3, 5, 1, 5));
            }
        }
    }
}

SCENARIO("The borders are gotten from a cell_box2 with trimmed corners")
{
    GIVEN("A cell_box2 with a width and height greater than one")
    {
        const rl::cell_box2 box(1, 2, 3, 4);
        WHEN("The left border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(1, 4, 1, 2));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(1, 5, 1, 3));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(1, 5, 1, 2));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(1, 4, 1, 3));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(1, 4, 1, 2));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(1, 4, 1, 2));
            }
        }
        WHEN("The left border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner_o =
                rl::left_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(1, 2, 1, 4));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(1, 3, 1, 5));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(1, 2, 1, 5));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(1, 3, 1, 4));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(1, 2, 1, 4));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(1, 2, 1, 4));
            }
        }
        WHEN("The right border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(3, 3, 3, 5));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(3, 2, 3, 4));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(3, 3, 3, 4));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(3, 2, 3, 5));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(3, 2, 3, 4));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(3, 2, 3, 4));
            }
        }
        WHEN("The right border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner_o =
                rl::right_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(3, 5, 3, 3));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(3, 4, 3, 2));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(3, 4, 3, 3));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(3, 5, 3, 2));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(3, 4, 3, 2));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(3, 4, 3, 2));
            }
        }
        WHEN("The top border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(2, 2, 3, 2));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(1, 2, 2, 2));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(1, 2, 2, 2));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(2, 2, 3, 2));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(1, 2, 3, 2));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(1, 2, 3, 2));
            }
        }
        WHEN("The top border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner_o =
                rl::top_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(3, 2, 2, 2));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(2, 2, 1 ,2));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(2, 2, 1, 2));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(3, 2, 2, 2));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(3, 2, 1, 2));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(3, 2, 1, 2));
            }
        }
        WHEN("The bottom border is gotten from the box in clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto counter_clockwise_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::Clockwise
                );
            const auto left_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::Clockwise
                );
            const auto right_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::Clockwise
                );
            const auto top_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            const auto bottom_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::Clockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(2, 5, 1, 5));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(3, 5, 2, 5));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(2, 5, 1, 5));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(3, 5, 2, 5));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(2, 5, 2, 5));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(2, 5, 2, 5));
            }
        }
        WHEN("The bottom border is gotten from the box in counter clockwise direction")
        {
            const auto clockwise_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Clockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto counter_clockwise_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::CounterClockwise,
                    rl::RotationMotion::CounterClockwise
                );
            const auto left_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Left,
                    rl::RotationMotion::CounterClockwise
                );
            const auto right_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Right,
                    rl::RotationMotion::CounterClockwise
                );
            const auto top_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            const auto bottom_corner_o =
                rl::bottom_border_trimmed(
                    box,
                    rl::BorderCorners::Top,
                    rl::RotationMotion::CounterClockwise
                );
            THEN("The clockwise cornered border is correct")
            {
                REQUIRE(clockwise_corner_o.has_value());
                CHECK(clockwise_corner_o.value() == rl::cell_segment2(1, 5, 2, 5));
            }
            THEN("The counter clockwise cornered border is correct")
            {
                REQUIRE(counter_clockwise_corner_o.has_value());
                CHECK(counter_clockwise_corner_o.value() == rl::cell_segment2(2, 5, 3, 5));
            }
            THEN("The left cornered border is correct")
            {
                REQUIRE(left_corner_o.has_value());
                CHECK(left_corner_o.value() == rl::cell_segment2(1, 5, 2, 5));
            }
            THEN("The right cornered border is correct")
            {
                REQUIRE(right_corner_o.has_value());
                CHECK(right_corner_o.value() == rl::cell_segment2(2, 5, 3, 5));
            }
            THEN("The top cornered border is correct")
            {
                REQUIRE(top_corner_o.has_value());
                CHECK(top_corner_o.value() == rl::cell_segment2(2, 5, 2, 5));
            }
            THEN("The bottom cornered border is correct")
            {
                REQUIRE(bottom_corner_o.has_value());
                CHECK(bottom_corner_o.value() == rl::cell_segment2(2, 5, 2, 5));
            }
        }
    }
    GIVEN("A cell_box2 with a width equal to one and a height greater than one")
    {
        const rl::cell_box2 box(0, 0, 1, 4);
        WHEN("The borders are gotten from the cell_box2 with no corners")
        {
            const auto left = rl::left_border_trimmed(box, rl::BorderCorners::None);
            const auto right = rl::right_border_trimmed(box, rl::BorderCorners::None);
            const auto top = rl::top_border_trimmed(box, rl::BorderCorners::None);
            const auto bottom = rl::bottom_border_trimmed(box, rl::BorderCorners::None);
            THEN("There only horizontal borders")
            {
                CHECK(left.has_value());
                CHECK(right.has_value());
                CHECK_FALSE(top.has_value());
                CHECK_FALSE(bottom.has_value());
            }
        }
    }
    GIVEN("A cell_box2 with a width greater than one and a height equal to one")
    {
        const rl::cell_box2 box(0, 0, 4, 1);
        WHEN("The borders are gotten from the cell_box2 with no corners")
        {
            const auto left = rl::left_border_trimmed(box, rl::BorderCorners::None);
            const auto right = rl::right_border_trimmed(box, rl::BorderCorners::None);
            const auto top = rl::top_border_trimmed(box, rl::BorderCorners::None);
            const auto bottom = rl::bottom_border_trimmed(box, rl::BorderCorners::None);
            THEN("There only vertical borders")
            {
                CHECK_FALSE(left.has_value());
                CHECK_FALSE(right.has_value());
                CHECK(top.has_value());
                CHECK(bottom.has_value());
            }
        }
    }
}