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
#include <rlm/cellular/shape_conversion.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("A cell_vector2 is converted into a cell_vector2")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point(1, 1);
        WHEN("It is determined if the cell_vector2 is a cell_vector2")
        {
            const auto is_cell_vector2 = rl::is_cell_vector2(point);
            THEN("The cell_vector2 is a cell_vector2")
            {
                CHECK(is_cell_vector2);
            }
        }
        WHEN("The cell_vector2 is converted to a cell_vector2")
        {
            const auto cell_vector2_o = rl::as_cell_vector2(point);
            THEN("The correct cell_vector2 was returned")
            {
                REQUIRE(cell_vector2_o.has_value());
                CHECK(cell_vector2_o.value() == rl::cell_vector2(1, 1));
            }
        }
    }
}

SCENARIO("A cell_segment2 is converted into a cell_vector2")
{
    GIVEN("A cell_segment2 that is a cell_vector2")
    {
        const rl::cell_segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the cell_segment2 is a cell_vector2")
        {
            const auto is_cell_vector2 = rl::is_cell_vector2(segment);
            THEN("The cell_segment2 is a cell_vector2")
            {
                CHECK(is_cell_vector2);
            }
        }
        WHEN("The cell_segment2 is converted to a cell_vector2")
        {
            const auto cell_vector2_o = rl::as_cell_vector2(segment);
            THEN("The correct cell_vector2 was returned")
            {
                REQUIRE(cell_vector2_o.has_value());
                CHECK(cell_vector2_o.value() == rl::cell_vector2(1, 1));
            }
        }
    }
    GIVEN("A cell_segment2 that is not a cell_vector2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("It is determined if the cell_segment2 is a cell_vector2")
        {
            const auto is_cell_vector2 = rl::is_cell_vector2(segment);
            THEN("The cell_segment2 is not a cell_vector2")
            {
                CHECK_FALSE(is_cell_vector2);
            }
        }
        WHEN("The cell_segment2 is converted to a cell_vector2")
        {
            const auto cell_vector2_o = rl::as_cell_vector2(segment);
            THEN("No cell_vector2 was returned")
            {
                CHECK_FALSE(cell_vector2_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_box2 is converted into a cell_vector2")
{
    GIVEN("A cell_box2 that is a cell_vector2")
    {
        const rl::cell_box2 box(1, 1, 1, 1);
        WHEN("It is determined if the cell_box2 is a cell_vector2")
        {
            const auto is_point = rl::is_cell_vector2(box);
            THEN("The box is a cell_vector2")
            {
                CHECK(is_point);
            }
        }
        WHEN("The cell_box2 is converted to a cell_vector2")
        {
            const auto point_o = rl::as_cell_vector2(box);
            THEN("The correct cell_vector2 was returned")
            {
                REQUIRE(point_o.has_value());
                CHECK(point_o.value() == rl::cell_vector2(1, 1));
            }
        }
    }
    GIVEN("A cell_box2 that is not a cell_vector2")
    {
        const rl::cell_box2 box(1, 2, 3, 4);
        WHEN("It is determined if the cell_box2 is a cell_vector2")
        {
            const auto is_point = rl::is_cell_vector2(box);
            THEN("The cell_box2 is not a cell_vector2")
            {
                CHECK_FALSE(is_point);
            }
        }
        WHEN("The cell_box2 is converted to a cell_vector2")
        {
            const auto point_o = rl::as_cell_vector2(box);
            THEN("No cell_vector2 was returned")
            {
                CHECK_FALSE(point_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_circle2 is converted into a cell_vector2")
{
    GIVEN("A cell_circle2 that is a cell_vector2")
    {
        const rl::cell_circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the cell_circle2 is a cell_vector2")
        {
            const auto is_point = rl::is_cell_vector2(circle);
            THEN("The circle is a cell_vector2")
            {
                CHECK(is_point);
            }
        }
        WHEN("The cell_circle2 is converted to a cell_vector2")
        {
            const auto point_o = rl::as_cell_vector2(circle);
            THEN("The correct cell_vector2 was returned")
            {
                REQUIRE(point_o.has_value());
                CHECK(point_o.value() == rl::cell_vector2(1, 1));
            }
        }
    }
    GIVEN("A cell_circle2 that is not a cell_vector2")
    {
        const rl::cell_circle2 circle(1, 2, 3.0f);
        WHEN("It is determined if the cell_circle2 is a cell_vector2")
        {
            const auto is_point = rl::is_cell_vector2(circle);
            THEN("The cell_circle2 is not a cell_vector2")
            {
                CHECK_FALSE(is_point);
            }
        }
        WHEN("The cell_circle2 is converted to a cell_vector2")
        {
            const auto point_o = rl::as_cell_vector2(circle);
            THEN("No cell_vector2 was returned")
            {
                CHECK_FALSE(point_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_vector2 is converted into a cell_segment2")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point(1, 1);
        WHEN("It is determined if the cell_vector2 is a cell_segment2")
        {
            const auto is_segment = rl::is_cell_segment2(point);
            THEN("The point is a cell_segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The cell_vector2 is converted to a cell_segment2")
        {
            const auto segment_o = rl::as_cell_segment2(point);
            THEN("The correct cell_segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::cell_segment2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A cell_segment2 is converted into a cell_segment2")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the cell_segment2 is a cell_segment2")
        {
            const auto is_segment = rl::is_cell_segment2(segment);
            THEN("The segment is a cell_segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The cell_segment2 is converted to a cell_segment2")
        {
            const auto segment_o = rl::as_cell_segment2(segment);
            THEN("The correct cell_segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::cell_segment2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A cell_box2 is converted into a cell_segment2")
{
    GIVEN("A cell_box2 that is a cell_segment2")
    {
        const rl::cell_box2 box(1, 1, 1, 1);
        WHEN("It is determined if the cell_box2 is a cell_segment2")
        {
            const auto is_segment = rl::is_cell_segment2(box);
            THEN("The box is a cell_segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The cell_box2 is converted to a cell_segment2")
        {
            const auto segment_o = rl::as_cell_segment2(box);
            THEN("The correct cell_segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::cell_segment2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A cell_box2 that is not a cell_segment2")
    {
        const rl::cell_box2 box(1, 2, 3, 4);
        WHEN("It is determined if the cell_box2 is a cell_segment2")
        {
            const auto is_segment = rl::is_cell_segment2(box);
            THEN("The cell_box2 is not a cell_segment2")
            {
                CHECK_FALSE(is_segment);
            }
        }
        WHEN("The cell_box2 is converted to a cell_segment2")
        {
            const auto segment_o = rl::as_cell_segment2(box);
            THEN("No cell_segment2 was returned")
            {
                CHECK_FALSE(segment_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_circle2 is converted into a cell_segment2")
{
    GIVEN("A cell_circle2 that is a cell_segment2")
    {
        const rl::cell_circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the cell_circle2 is a cell_segment2")
        {
            const auto is_segment = rl::is_cell_segment2(circle);
            THEN("The circle is a cell_segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The cell_circle2 is converted to a cell_segment2")
        {
            const auto segment_o = rl::as_cell_segment2(circle);
            THEN("The correct cell_segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::cell_segment2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A cell_circle2 that is not a cell_segment2")
    {
        const rl::cell_circle2 circle(1, 1, 2.5f);
        WHEN("It is determined if the cell_circle2 is a cell_segment2")
        {
            const auto is_segment = rl::is_cell_segment2(circle);
            THEN("The cell_circle2 is not a cell_segment2")
            {
                CHECK_FALSE(is_segment);
            }
        }
        WHEN("The cell_circle2 is converted to a cell_segment2")
        {
            const auto segment_o = rl::as_cell_segment2(circle);
            THEN("No cell_segment2 was returned")
            {
                CHECK_FALSE(segment_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_vector2 is converted into a cell_box2")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point(1, 1);
        WHEN("It is determined if the cell_vector2 is a cell_box2")
        {
            const auto is_box = rl::is_cell_box2(point);
            THEN("The point is a cell_box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The cell_vector2 is converted to a cell_box2")
        {
            const auto box_o = rl::as_cell_box2(point);
            THEN("The correct cell_box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::cell_box2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A cell_segment2 is converted into a cell_box2")
{
    GIVEN("A cell_segment2 that is a cell_box2")
    {
        const rl::cell_segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the cell_segment2 is a cell_box2")
        {
            const auto is_box = rl::is_cell_box2(segment);
            THEN("The cell_segment2 is a cell_box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The cell_segment2 is converted to a cell_box2")
        {
            const auto box_o = rl::as_cell_box2(segment);
            THEN("The correct cell_box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::cell_box2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A cell_segment2 that is not a cell_box2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("It is determined if the cell_segment2 is a cell_box2")
        {
            const auto is_box = rl::is_cell_box2(segment);
            THEN("The cell_segment2 is not a cell_box2")
            {
                CHECK_FALSE(is_box);
            }
        }
        WHEN("The cell_segment2 is converted to a cell_box2")
        {
            const auto box_o = rl::as_cell_box2(segment);
            THEN("No cell_box2 was returned")
            {
                CHECK_FALSE(box_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_box2 is converted into a cell_box2")
{
    GIVEN("A cell_box2")
    {
        const rl::cell_box2 box(1, 1, 1, 1);
        WHEN("It is determined if the cell_box2 is a cell_box2")
        {
            const auto is_box = rl::is_cell_box2(box);
            THEN("The box is a cell_box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The cell_box2 is converted to a cell_box2")
        {
            const auto box_o = rl::as_cell_box2(box);
            THEN("The correct cell_box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::cell_box2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A cell_circle2 is converted into a cell_box2")
{
    GIVEN("A cell_circle2 that is a cell_box2")
    {
        const rl::cell_circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the cell_circle2 is a cell_box2")
        {
            const auto is_box = rl::is_cell_box2(circle);
            THEN("The cell_circle2 is a cell_box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The cell_circle2 is converted to a cell_box2")
        {
            const auto box_o = rl::as_cell_box2(circle);
            THEN("The correct cell_box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::cell_box2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A cell_circle2 that is not a cell_box2")
    {
        const rl::cell_circle2 circle(1, 2, 7.0f);
        WHEN("It is determined if the cell_circle2 is a cell_box2")
        {
            const auto is_box = rl::is_cell_box2(circle);
            THEN("The cell_circle2 is not a cell_box2")
            {
                CHECK_FALSE(is_box);
            }
        }
        WHEN("The cell_circle2 is converted to a cell_box2")
        {
            const auto box_o = rl::as_cell_box2(circle);
            THEN("No cell_box2 was returned")
            {
                CHECK_FALSE(box_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_vector2 is converted into a cell_circle2")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point(1, 1);
        WHEN("It is determined if the cell_vector2 is a cell_circle2")
        {
            const auto is_circle = rl::is_cell_circle2(point);
            THEN("The point is a cell_circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The cell_vector2 is converted to a cell_circle2")
        {
            const auto circle_o = rl::as_cell_circle2(point);
            THEN("The correct cell_circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::cell_circle2(1, 1, 0.5f));
            }
        }
    }
}

SCENARIO("A cell_segment2 is converted into a cell_circle2")
{
    GIVEN("A cell_segment2 that is a cell_circle2")
    {
        const rl::cell_segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the cell_segment2 is a cell_circle2")
        {
            const auto is_circle = rl::is_cell_circle2(segment);
            THEN("The cell_segment2 is a cell_circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The cell_segment2 is converted to a cell_circle2")
        {
            const auto circle_o = rl::as_cell_circle2(segment);
            THEN("The correct cell_circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::cell_circle2(1, 1, 0.5f));
            }
        }
    }
    GIVEN("A cell_segment2 that is not a cell_circle2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("It is determined if the cell_segment2 is a cell_circle2")
        {
            const auto is_circle = rl::is_cell_circle2(segment);
            THEN("The cell_segment2 is not a cell_circle2")
            {
                CHECK_FALSE(is_circle);
            }
        }
        WHEN("The cell_segment2 is converted to a cell_circle2")
        {
            const auto circle_o = rl::as_cell_circle2(segment);
            THEN("No cell_circle2 was returned")
            {
                CHECK_FALSE(circle_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_box2 is converted into a cell_circle2")
{
    GIVEN("A cell_box2 that is a cell_circle2")
    {
        const rl::cell_box2 box(1, 1, 1, 1);
        WHEN("It is determined if the cell_box2 is a cell_circle2")
        {
            const auto is_circle = rl::is_cell_circle2(box);
            THEN("The cell_box2 is a cell_circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The cell_box2 is converted to a cell_circle2")
        {
            const auto circle_o = rl::as_cell_circle2(box);
            THEN("The correct cell_circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::cell_circle2(1, 1, 0.5f));
            }
        }
    }
    GIVEN("A cell_box2 that is not a cell_circle2")
    {
        const rl::cell_box2 box(1, 2, 3, 4);
        WHEN("It is determined if the cell_box2 is a cell_circle2")
        {
            const auto is_circle = rl::is_cell_circle2(box);
            THEN("The cell_box2 is not a cell_circle2")
            {
                CHECK_FALSE(is_circle);
            }
        }
        WHEN("The cell_box2 is converted to a cell_circle2")
        {
            const auto circle_o = rl::as_cell_circle2(box);
            THEN("No cell_circle2 was returned")
            {
                CHECK_FALSE(circle_o.has_value());
            }
        }
    }
}

SCENARIO("A cell_circle2 is converted into a cell_circle2")
{
    GIVEN("A cell_circle2")
    {
        const rl::cell_circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the cell_circle2 is a cell_circle2")
        {
            const auto is_circle = rl::is_cell_circle2(circle);
            THEN("The circle is a cell_circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The cell_circle2 is converted to a cell_circle2")
        {
            const auto circle_o = rl::as_cell_circle2(circle);
            THEN("The correct cell_circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::cell_circle2(1, 1, 0.5f));
            }
        }
    }
}