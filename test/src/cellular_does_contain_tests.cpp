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
#include <rlm/cellular/does_contain.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("It is determined if a point2 contains other cell shapes")
{
    GIVEN("A point2")
    {
        const rl::point2 point(1, 1);
        GIVEN("A point2 that is within the point2")
        {
            const rl::point2 point_b(1, 1);
            THEN("The point2 is within the point2")
            {
                CHECK(rl::does_contain(point, point_b));
            }
        }
        GIVEN("A point2 that is not within the point2")
        {
            const rl::point2 point_b(4, 5);
            THEN("The point2 is not within the point2")
            {
                CHECK_FALSE(rl::does_contain(point, point_b));
            }
        }
        GIVEN("A segment2 that is within the point2")
        {
            const rl::segment2 segment(1, 1, 1, 1);
            THEN("The segment2 is within the point2")
            {
                CHECK(rl::does_contain(point, segment));
            }
        }
        GIVEN("A segment2 that is not within the point2")
        {
            const rl::segment2 segment(4, 5, 6, 7);
            THEN("The segment2 is not within the point2")
            {
                CHECK_FALSE(rl::does_contain(point, segment));
            }
        }
        GIVEN("A box2 that is within the point2")
        {
            const rl::box2 box(1, 1, 1, 1);
            THEN("The box2 is within the point2")
            {
                CHECK(rl::does_contain(point, box));
            }
        }
        GIVEN("A box2 that is not within the point2")
        {
            const rl::box2 box(4, 5, 6, 7);
            THEN("The box2 is not within the point2")
            {
                CHECK_FALSE(rl::does_contain(point, box));
            }
        }
        GIVEN("A circle2 that is within the point2")
        {
            const rl::circle2 circle(1, 1, 0.5f);
            THEN("The circle2 is within the point2")
            {
                CHECK(rl::does_contain(point, circle));
            }
        }
        GIVEN("A circle2 that is not within the point2")
        {
            const rl::circle2 circle(4, 5, 4.0f);
            THEN("The circle2 is not within the point2")
            {
                CHECK_FALSE(rl::does_contain(point, circle));
            }
        }
    }
}

SCENARIO("It is determined if a segment2 contains other cell shapes")
{
    GIVEN("A segment2")
    {
        const rl::segment2 segment(1, 1, 3, 3);
        GIVEN("A point2 that is within the segment2")
        {
            const rl::point2 point(1, 1);
            THEN("The segment2 is within the segment2")
            {
                CHECK(rl::does_contain(segment, point));
            }
        }
        GIVEN("A point2 that is not within the segment2")
        {
            const rl::point2 point(4, 5);
            THEN("The segment2 is not within the segment2")
            {
                CHECK_FALSE(rl::does_contain(segment, point));
            }
        }
        GIVEN("A segment2 that is within the segment2")
        {
            const rl::segment2 segment_b(1, 1, 1, 1);
            THEN("The segment2 is within the segment2")
            {
                CHECK(rl::does_contain(segment, segment_b));
            }
        }
        GIVEN("A segment2 that is not within the segment2")
        {
            const rl::segment2 segment_b(4, 5, 6, 7);
            THEN("The segment2 is not within the segment2")
            {
                CHECK_FALSE(rl::does_contain(segment, segment_b));
            }
        }
        GIVEN("A box2 that is within the segment2")
        {
            const rl::box2 box(1, 1, 1, 1);
            THEN("The box2 is within the segment2")
            {
                CHECK(rl::does_contain(segment, box));
            }
        }
        GIVEN("A box2 that is not within the segment2")
        {
            const rl::box2 box(4, 5, 6, 7);
            THEN("The box2 is not within the segment2")
            {
                CHECK_FALSE(rl::does_contain(segment, box));
            }
        }
        GIVEN("A circle2 that is within the segment2")
        {
            const rl::circle2 circle(1, 1, 0.5f);
            THEN("The circle2 is within the segment2")
            {
                CHECK(rl::does_contain(segment, circle));
            }
        }
        GIVEN("A circle2 that is not within the segment2")
        {
            const rl::circle2 circle(4, 5, 4.0f);
            THEN("The circle2 is not within the segment2")
            {
                CHECK_FALSE(rl::does_contain(segment, circle));
            }
        }
    }
}

SCENARIO("It is determined if a box2 contains other cell shapes")
{
    GIVEN("A box2")
    {
        const rl::box2 box(1, 1, 3, 3);
        GIVEN("A point2 that is within the box2")
        {
            const rl::point2 point(1, 1);
            THEN("The segment2 is within the box2")
            {
                CHECK(rl::does_contain(box, point));
            }
        }
        GIVEN("A point2 that is not within the box2")
        {
            const rl::point2 point(4, 5);
            THEN("The segment2 is not within the box2")
            {
                CHECK_FALSE(rl::does_contain(box, point));
            }
        }
        GIVEN("A segment2 that is within the box2")
        {
            const rl::segment2 segment(1, 1, 1, 1);
            THEN("The segment2 is within the box2")
            {
                CHECK(rl::does_contain(box, segment));
            }
        }
        GIVEN("A segment2 that is not within the box2")
        {
            const rl::segment2 segment(4, 5, 6, 7);
            THEN("The segment2 is not within the box2")
            {
                CHECK_FALSE(rl::does_contain(box, segment));
            }
        }
        GIVEN("A box2 that is within the box2")
        {
            const rl::box2 box_b(1, 1, 1, 1);
            THEN("The box2 is within the box2")
            {
                CHECK(rl::does_contain(box, box_b));
            }
        }
        GIVEN("A box2 that is not within the box2")
        {
            const rl::box2 box_b(4, 5, 6, 7);
            THEN("The box2 is not within the box2")
            {
                CHECK_FALSE(rl::does_contain(box, box_b));
            }
        }
        GIVEN("A circle2 that is within the box2")
        {
            const rl::circle2 circle(1, 1, 0.5f);
            THEN("The circle2 is within the box2")
            {
                CHECK(rl::does_contain(box, circle));
            }
        }
        GIVEN("A circle2 that is not within the box2")
        {
            const rl::circle2 circle(4, 5, 4.0f);
            THEN("The circle2 is not within the segment2")
            {
                CHECK_FALSE(rl::does_contain(box, circle));
            }
        }
    }
}

SCENARIO("It is determined if a circle2 contains other cell shapes")
{
    GIVEN("A circle2")
    {
        const rl::circle2 circle(1, 1, 2.3f);
        GIVEN("A point2 that is within the circle2")
        {
            const rl::point2 point(1, 1);
            THEN("The segment2 is within the circle2")
            {
                CHECK(rl::does_contain(circle, point));
            }
        }
        GIVEN("A point2 that is not within the circle2")
        {
            const rl::point2 point(4, 5);
            THEN("The segment2 is not within the circle2")
            {
                CHECK_FALSE(rl::does_contain(circle, point));
            }
        }
        GIVEN("A segment2 that is within the circle2")
        {
            const rl::segment2 segment(1, 1, 1, 1);
            THEN("The segment2 is within the circle2")
            {
                CHECK(rl::does_contain(circle, segment));
            }
        }
        GIVEN("A segment2 that is not within the circle2")
        {
            const rl::segment2 segment(4, 5, 6, 7);
            THEN("The segment2 is not within the circle2")
            {
                CHECK_FALSE(rl::does_contain(circle, segment));
            }
        }
        GIVEN("A box2 that is within the circle2")
        {
            const rl::box2 box(1, 1, 1, 1);
            THEN("The box2 is within the box2")
            {
                CHECK(rl::does_contain(circle, box));
            }
        }
        GIVEN("A box2 that is not within the circle2")
        {
            const rl::box2 box(4, 5, 6, 7);
            THEN("The box2 is not within the circle2")
            {
                CHECK_FALSE(rl::does_contain(circle, box));
            }
        }
        GIVEN("A circle2 that is within the circle2")
        {
            const rl::circle2 circle_b(1, 1, 0.5f);
            THEN("The circle2 is within the circle2")
            {
                CHECK(rl::does_contain(circle, circle_b));
            }
        }
        GIVEN("A circle2 that is not within the box2")
        {
            const rl::circle2 circle_b(4, 5, 4.0f);
            THEN("The circle2 is not within the circle2")
            {
                CHECK_FALSE(rl::does_contain(circle, circle_b));
            }
        }
    }
}