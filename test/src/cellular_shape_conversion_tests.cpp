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

SCENARIO("A point2 is converted into a point2")
{
    GIVEN("A point2")
    {
        const rl::point2 point(1, 1);
        WHEN("It is determined if the point2 is a point2")
        {
            const auto is_point2 = rl::is_point2(point);
            THEN("The point2 is a point2")
            {
                CHECK(is_point2);
            }
        }
        WHEN("The point2 is converted to a point2")
        {
            const auto point2_o = rl::as_point2(point);
            THEN("The correct point2 was returned")
            {
                REQUIRE(point2_o.has_value());
                CHECK(point2_o.value() == rl::point2(1, 1));
            }
        }
    }
}

SCENARIO("A segment2 is converted into a point2")
{
    GIVEN("A segment2 that is a point2")
    {
        const rl::segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the segment2 is a point2")
        {
            const auto is_point2 = rl::is_point2(segment);
            THEN("The segment2 is a point2")
            {
                CHECK(is_point2);
            }
        }
        WHEN("The segment2 is converted to a point2")
        {
            const auto point2_o = rl::as_point2(segment);
            THEN("The correct point2 was returned")
            {
                REQUIRE(point2_o.has_value());
                CHECK(point2_o.value() == rl::point2(1, 1));
            }
        }
    }
    GIVEN("A segment2 that is not a point2")
    {
        const rl::segment2 segment(1, 2, 3, 4);
        WHEN("It is determined if the segment2 is a point2")
        {
            const auto is_point2 = rl::is_point2(segment);
            THEN("The segment2 is not a point2")
            {
                CHECK_FALSE(is_point2);
            }
        }
        WHEN("The segment2 is converted to a point2")
        {
            const auto point2_o = rl::as_point2(segment);
            THEN("No point2 was returned")
            {
                CHECK_FALSE(point2_o.has_value());
            }
        }
    }
}

SCENARIO("A box2 is converted into a point2")
{
    GIVEN("A box2 that is a point2")
    {
        const rl::box2 box(1, 1, 1, 1);
        WHEN("It is determined if the box2 is a point2")
        {
            const auto is_point = rl::is_point2(box);
            THEN("The box is a point2")
            {
                CHECK(is_point);
            }
        }
        WHEN("The box2 is converted to a point2")
        {
            const auto point_o = rl::as_point2(box);
            THEN("The correct point2 was returned")
            {
                REQUIRE(point_o.has_value());
                CHECK(point_o.value() == rl::point2(1, 1));
            }
        }
    }
    GIVEN("A box2 that is not a point2")
    {
        const rl::box2 box(1, 2, 3, 4);
        WHEN("It is determined if the box2 is a point2")
        {
            const auto is_point = rl::is_point2(box);
            THEN("The box2 is not a point2")
            {
                CHECK_FALSE(is_point);
            }
        }
        WHEN("The box2 is converted to a point2")
        {
            const auto point_o = rl::as_point2(box);
            THEN("No point2 was returned")
            {
                CHECK_FALSE(point_o.has_value());
            }
        }
    }
}

SCENARIO("A circle2 is converted into a point2")
{
    GIVEN("A circle2 that is a point2")
    {
        const rl::circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the circle2 is a point2")
        {
            const auto is_point = rl::is_point2(circle);
            THEN("The circle is a point2")
            {
                CHECK(is_point);
            }
        }
        WHEN("The circle2 is converted to a point2")
        {
            const auto point_o = rl::as_point2(circle);
            THEN("The correct point2 was returned")
            {
                REQUIRE(point_o.has_value());
                CHECK(point_o.value() == rl::point2(1, 1));
            }
        }
    }
    GIVEN("A circle2 that is not a point2")
    {
        const rl::circle2 circle(1, 2, 3.0f);
        WHEN("It is determined if the circle2 is a point2")
        {
            const auto is_point = rl::is_point2(circle);
            THEN("The circle2 is not a point2")
            {
                CHECK_FALSE(is_point);
            }
        }
        WHEN("The circle2 is converted to a point2")
        {
            const auto point_o = rl::as_point2(circle);
            THEN("No point2 was returned")
            {
                CHECK_FALSE(point_o.has_value());
            }
        }
    }
}

SCENARIO("A point2 is converted into a segment2")
{
    GIVEN("A point2")
    {
        const rl::point2 point(1, 1);
        WHEN("It is determined if the point2 is a segment2")
        {
            const auto is_segment = rl::is_segment2(point);
            THEN("The point is a segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The point2 is converted to a segment2")
        {
            const auto segment_o = rl::as_segment2(point);
            THEN("The correct segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::segment2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A segment2 is converted into a segment2")
{
    GIVEN("A segment2")
    {
        const rl::segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the segment2 is a segment2")
        {
            const auto is_segment = rl::is_segment2(segment);
            THEN("The segment is a segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The segment2 is converted to a segment2")
        {
            const auto segment_o = rl::as_segment2(segment);
            THEN("The correct segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::segment2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A box2 is converted into a segment2")
{
    GIVEN("A box2 that is a segment2")
    {
        const rl::box2 box(1, 1, 1, 1);
        WHEN("It is determined if the box2 is a segment2")
        {
            const auto is_segment = rl::is_segment2(box);
            THEN("The box is a segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The box2 is converted to a segment2")
        {
            const auto segment_o = rl::as_segment2(box);
            THEN("The correct segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::segment2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A box2 that is not a segment2")
    {
        const rl::box2 box(1, 2, 3, 4);
        WHEN("It is determined if the box2 is a segment2")
        {
            const auto is_segment = rl::is_segment2(box);
            THEN("The box2 is not a segment2")
            {
                CHECK_FALSE(is_segment);
            }
        }
        WHEN("The box2 is converted to a segment2")
        {
            const auto segment_o = rl::as_segment2(box);
            THEN("No segment2 was returned")
            {
                CHECK_FALSE(segment_o.has_value());
            }
        }
    }
}

SCENARIO("A circle2 is converted into a segment2")
{
    GIVEN("A circle2 that is a segment2")
    {
        const rl::circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the circle2 is a segment2")
        {
            const auto is_segment = rl::is_segment2(circle);
            THEN("The circle is a segment2")
            {
                CHECK(is_segment);
            }
        }
        WHEN("The circle2 is converted to a segment2")
        {
            const auto segment_o = rl::as_segment2(circle);
            THEN("The correct segment2 was returned")
            {
                REQUIRE(segment_o.has_value());
                CHECK(segment_o.value() == rl::segment2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A circle2 that is not a segment2")
    {
        const rl::circle2 circle(1, 1, 2.5f);
        WHEN("It is determined if the circle2 is a segment2")
        {
            const auto is_segment = rl::is_segment2(circle);
            THEN("The circle2 is not a segment2")
            {
                CHECK_FALSE(is_segment);
            }
        }
        WHEN("The circle2 is converted to a segment2")
        {
            const auto segment_o = rl::as_segment2(circle);
            THEN("No segment2 was returned")
            {
                CHECK_FALSE(segment_o.has_value());
            }
        }
    }
}

SCENARIO("A point2 is converted into a box2")
{
    GIVEN("A point2")
    {
        const rl::point2 point(1, 1);
        WHEN("It is determined if the point2 is a box2")
        {
            const auto is_box = rl::is_box2(point);
            THEN("The point is a box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The point2 is converted to a box2")
        {
            const auto box_o = rl::as_box2(point);
            THEN("The correct box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::box2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A segment2 is converted into a box2")
{
    GIVEN("A segment2 that is a box2")
    {
        const rl::segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the segment2 is a box2")
        {
            const auto is_box = rl::is_box2(segment);
            THEN("The segment2 is a box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The segment2 is converted to a box2")
        {
            const auto box_o = rl::as_box2(segment);
            THEN("The correct box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::box2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A segment2 that is not a box2")
    {
        const rl::segment2 segment(1, 2, 3, 4);
        WHEN("It is determined if the segment2 is a box2")
        {
            const auto is_box = rl::is_box2(segment);
            THEN("The segment2 is not a box2")
            {
                CHECK_FALSE(is_box);
            }
        }
        WHEN("The segment2 is converted to a box2")
        {
            const auto box_o = rl::as_box2(segment);
            THEN("No box2 was returned")
            {
                CHECK_FALSE(box_o.has_value());
            }
        }
    }
}

SCENARIO("A box2 is converted into a box2")
{
    GIVEN("A box2")
    {
        const rl::box2 box(1, 1, 1, 1);
        WHEN("It is determined if the box2 is a box2")
        {
            const auto is_box = rl::is_box2(box);
            THEN("The box is a box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The box2 is converted to a box2")
        {
            const auto box_o = rl::as_box2(box);
            THEN("The correct box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::box2(1, 1, 1, 1));
            }
        }
    }
}

SCENARIO("A circle2 is converted into a box2")
{
    GIVEN("A circle2 that is a box2")
    {
        const rl::circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the circle2 is a box2")
        {
            const auto is_box = rl::is_box2(circle);
            THEN("The circle2 is a box2")
            {
                CHECK(is_box);
            }
        }
        WHEN("The circle2 is converted to a box2")
        {
            const auto box_o = rl::as_box2(circle);
            THEN("The correct box2 was returned")
            {
                REQUIRE(box_o.has_value());
                CHECK(box_o.value() == rl::box2(1, 1, 1, 1));
            }
        }
    }
    GIVEN("A circle2 that is not a box2")
    {
        const rl::circle2 circle(1, 2, 7.0f);
        WHEN("It is determined if the circle2 is a box2")
        {
            const auto is_box = rl::is_box2(circle);
            THEN("The circle2 is not a box2")
            {
                CHECK_FALSE(is_box);
            }
        }
        WHEN("The circle2 is converted to a box2")
        {
            const auto box_o = rl::as_box2(circle);
            THEN("No box2 was returned")
            {
                CHECK_FALSE(box_o.has_value());
            }
        }
    }
}

SCENARIO("A point2 is converted into a circle2")
{
    GIVEN("A point2")
    {
        const rl::point2 point(1, 1);
        WHEN("It is determined if the point2 is a circle2")
        {
            const auto is_circle = rl::is_circle2(point);
            THEN("The point is a circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The point2 is converted to a circle2")
        {
            const auto circle_o = rl::as_circle2(point);
            THEN("The correct circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::circle2(1, 1, 0.5f));
            }
        }
    }
}

SCENARIO("A segment2 is converted into a circle2")
{
    GIVEN("A segment2 that is a circle2")
    {
        const rl::segment2 segment(1, 1, 1, 1);
        WHEN("It is determined if the segment2 is a circle2")
        {
            const auto is_circle = rl::is_circle2(segment);
            THEN("The segment2 is a circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The segment2 is converted to a circle2")
        {
            const auto circle_o = rl::as_circle2(segment);
            THEN("The correct circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::circle2(1, 1, 0.5f));
            }
        }
    }
    GIVEN("A segment2 that is not a circle2")
    {
        const rl::segment2 segment(1, 2, 3, 4);
        WHEN("It is determined if the segment2 is a circle2")
        {
            const auto is_circle = rl::is_circle2(segment);
            THEN("The segment2 is not a circle2")
            {
                CHECK_FALSE(is_circle);
            }
        }
        WHEN("The segment2 is converted to a circle2")
        {
            const auto circle_o = rl::as_circle2(segment);
            THEN("No circle2 was returned")
            {
                CHECK_FALSE(circle_o.has_value());
            }
        }
    }
}

SCENARIO("A box2 is converted into a circle2")
{
    GIVEN("A box2 that is a circle2")
    {
        const rl::box2 box(1, 1, 1, 1);
        WHEN("It is determined if the box2 is a circle2")
        {
            const auto is_circle = rl::is_circle2(box);
            THEN("The box2 is a circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The box2 is converted to a circle2")
        {
            const auto circle_o = rl::as_circle2(box);
            THEN("The correct circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::circle2(1, 1, 0.5f));
            }
        }
    }
    GIVEN("A box2 that is not a circle2")
    {
        const rl::box2 box(1, 2, 3, 4);
        WHEN("It is determined if the box2 is a circle2")
        {
            const auto is_circle = rl::is_circle2(box);
            THEN("The box2 is not a circle2")
            {
                CHECK_FALSE(is_circle);
            }
        }
        WHEN("The box2 is converted to a circle2")
        {
            const auto circle_o = rl::as_circle2(box);
            THEN("No circle2 was returned")
            {
                CHECK_FALSE(circle_o.has_value());
            }
        }
    }
}

SCENARIO("A circle2 is converted into a circle2")
{
    GIVEN("A circle2")
    {
        const rl::circle2 circle(1, 1, 0.5f);
        WHEN("It is determined if the circle2 is a circle2")
        {
            const auto is_circle = rl::is_circle2(circle);
            THEN("The circle is a circle2")
            {
                CHECK(is_circle);
            }
        }
        WHEN("The circle2 is converted to a circle2")
        {
            const auto circle_o = rl::as_circle2(circle);
            THEN("The correct circle2 was returned")
            {
                REQUIRE(circle_o.has_value());
                CHECK(circle_o.value() == rl::circle2(1, 1, 0.5f));
            }
        }
    }
}