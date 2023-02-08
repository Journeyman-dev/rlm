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
#include <rlm/cellular/dot.hpp>

SCENARIO("The dot product is gotten between two point2")
{
    GIVEN("Two point2")
    {
        const rl::point2 point_a(1, 2);
        const rl::point2 point_b(2, 4);
        WHEN("The dot product of the two point2 is gotten")
        {
            const auto dot = rl::dot(point_a, point_b);
            THEN("The value is correct")
            {
                CHECK(dot == 10);
            }
        }
    }
}

SCENARIO("The unit dot product is gotten between two point2")
{
    GIVEN("Two point2")
    {
        const rl::point2 point_a(1, 2);
        const rl::point2 point_b(2, 4);
        WHEN("The unit dot product of the two point2 is gotten")
        {
            const auto unit_dot = rl::unit_dot(point_a, point_b);
            THEN("The value is correct")
            {
                CHECK(unit_dot == 2.0f);
            }
        }
    }
}

SCENARIO("The dot product is gotten between a point2 and a segment2")
{
    GIVEN("A point2 and a segment2")
    {
        const rl::point2 point(1, 2);
        const rl::segment2 segment(2, 4, 5, 6);
        WHEN("The dot product of the shapes is gotten")
        {
            const auto dot = rl::dot(point, segment);
            const auto dot_alt = rl::dot(segment, point);
            THEN("The value is correct")
            {
                CHECK(dot == -7);
            }
            THEN("A call with the reverse argument order gives the same result")
            {
                CHECK(dot == dot_alt);
            }
        }
    }
}

SCENARIO("The unit dot product is gotten between a point2 and a segment2")
{
    GIVEN("A point2 and a segment2")
    {
        const rl::point2 point(1, 2);
        const rl::segment2 segment(2, 4, 5, 6);
        WHEN("The unit dot product of the shapes is gotten")
        {
            const auto unit_dot = rl::unit_dot(point, segment);
            const auto unit_dot_alt = rl::unit_dot(segment, point);
            THEN("The value is correct")
            {
                CHECK(unit_dot == -1.4f);
            }
            THEN("A call with the reverse argument order gives the same result")
            {
                CHECK(unit_dot == unit_dot_alt);
            }
        }
    }
}

SCENARIO("The dot product is gotten between two segment2")
{
    GIVEN("Two segment2")
    {
        const rl::segment2 segment_a(1, 2, 3, 4);
        const rl::segment2 segment_b(2, 4, 5, 6);
        WHEN("The dot product of the two segment2 is gotten")
        {
            const auto dot = rl::dot(segment_a, segment_b);
            THEN("The value is correct")
            {
                CHECK(dot == 10);
            }
        }
    }
}

SCENARIO("The unit dot product is gotten between two segment2")
{
    GIVEN("Two segment2")
    {
        const rl::segment2 segment_a(1, 2, 3, 4);
        const rl::segment2 segment_b(2, 4, 5, 6);
        WHEN("The unit dot product of the two segment2 is gotten")
        {
            const auto unit_dot = rl::unit_dot(segment_a, segment_b);
            THEN("The value is correct")
            {
                CHECK(unit_dot == 10.0f);
            }
        }
    }
}