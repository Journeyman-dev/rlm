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
#include <rlm/cellular/distance_between.hpp>

SCENARIO("The distance between two cell shapes is determined")
{
    GIVEN("A point2")
    {
        const rl::point2 point(1, 0);
        GIVEN("A point2")
        {
            const rl::point2 other_point(2, 0);
            THEN("The distance between the two point2 is correct.")
            {
                CHECK(rl::distance_between(point, other_point) == 1);
            }
        }
        GIVEN("A segment2")
        {
            const rl::segment2 segment(2, 0, 3, 0);
            THEN("The distance between the point2 and the segment2 is correct")
            {
                CHECK(rl::distance_between(point, segment) == 1);
                CHECK(rl::distance_between(segment, point) == 1);
            }
        }
        GIVEN("A box2")
        {
            const rl::box2 box(2, 0, 2, 2);
            THEN("The distance between the point2 and the box2 is correct")
            {
                CHECK(rl::distance_between(point, box) == 1);
                CHECK(rl::distance_between(box, point) == 1);
            }
        }
        GIVEN("A circle2")
        {
            const rl::circle2 circle(2, 0, 0.5f);
            THEN("The distance between the point2 and the circle2 is correct")
            {
                CHECK(rl::distance_between(point, circle) == 0.5f);
                CHECK(rl::distance_between(circle, point) == 0.5f);
            }
        }
    }
    GIVEN("A segment2")
    {
        const rl::segment2 segment(-1, 0, 1, 0);
        GIVEN("A segment2")
        {
            const rl::segment2 other_segment(2, 0, 3, 0);
            THEN("The distance between the two segment2 is correct.")
            {
                CHECK(rl::distance_between(segment, other_segment) == 3.0f);
            }
        }
        GIVEN("A box2")
        {
            const rl::box2 box(2, 0, 2, 2);
            THEN("The distance between the segment2 and the box2 is correct")
            {
                CHECK(rl::distance_between(segment, box) == 1.0f);
                CHECK(rl::distance_between(box, segment) == 1.0f);
            }
        }
        GIVEN("A circle2")
        {
            const rl::circle2 circle(2, 0, 0.5f);
            THEN("The distance between the segment2 and the circle2 is correct")
            {
                CHECK(rl::distance_between(segment, circle) == 8.5f);
                CHECK(rl::distance_between(circle, segment) == 8.5f);
            }
        }
    }
    GIVEN("A box2")
    {
        const rl::box2 box(-1, 0, 1, 1);
        GIVEN("A box2")
        {
            const rl::box2 other_box(2, 0, 2, 2);
            THEN("The distance between the two box2 is correct.")
            {
                CHECK(rl::distance_between(box, other_box) == 2.0f);
            }
        }
        GIVEN("A circle2")
        {
            const rl::circle2 circle(2, 0, 0.5f);
            THEN("The distance between the segment2 and the circle2 is correct")
            {
                CHECK(rl::distance_between(box, circle) == 2.5f);
                CHECK(rl::distance_between(circle, box) == 2.5f);
            }
        }
    }
    GIVEN("A circle2")
    {
        const rl::circle2 circle(1, 0, 0.5f);
        GIVEN("A box2")
        {
            const rl::circle2 other_circle(3, 0, 0.5f);
            THEN("The distance between the two circle2 is correct.")
            {
                CHECK(rl::distance_between(circle, other_circle) == 1.0f);
            }
        }
    }
}