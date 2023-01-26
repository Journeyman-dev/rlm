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
#include <rlm/cellular/ostream.hpp>
#include <rlm/cellular/point2.hpp>

SCENARIO("A point2 is constructed")
{
    GIVEN("A point2 constructed with its default constructor")
    {
        const rl::point2 point;
        THEN("The property values are default")
        {
            CHECK(point.x == 0);
            CHECK(point.y == 0);
        }
    }
    GIVEN("A point2 constructed with its overloaded constructor")
    {
        const rl::point2 point(1, 2);
        THEN("The property values are correct")
        {
            CHECK(point.x == 1);
            CHECK(point.y == 2);
        }
    }
}

SCENARIO("Two point2 are compared")
{
    GIVEN("A point2")
    {
        const rl::point2 point_a(1, 2);
        GIVEN("A point2 that is the same")
        {
            const rl::point2 point_b(1, 2);
            THEN("The point2 are equal")
            {
                CHECK(point_a == point_b);
                CHECK_FALSE(point_a != point_b);
            }
        }
        GIVEN("A point2 that is different")
        {
            const rl::point2 point_b(3, 4);
            THEN("The point2 are not equal")
            {
                CHECK_FALSE(point_a == point_b);
                CHECK(point_a != point_b);
            }
        }
    }
}

SCENARIO("Two point2 are combined with math operators")
{
    GIVEN("Two point2")
    {
        const rl::point2 point_a(1, 2);
        const rl::point2 point_b(3, 4);
        THEN("The sum of the points is correct")
        {
            CHECK(point_a + point_b == rl::point2(4, 6));
        }
        THEN("The difference of ths points is correct")
        {
            CHECK(point_a - point_b == rl::point2(-2, -2));
        }
        THEN("The product of the points is correct")
        {
            CHECK(point_a * point_b == rl::point2(3, 8));
        }
        THEN("The quotient of the points is correct")
        {
            CHECK(point_a / point_b == rl::point2(0, 0));
        }
    }
}

SCENARIO("A point2 is combined with a scalar using math operators")
{
    GIVEN("A point2 and a scalar")
    {
        const rl::point2 point(1, 6);
        const int scalar = 2;
        THEN("The sum of the point and the scalar is correct")
        {
            CHECK(point + scalar == rl::point2(3, 8));
        }
        THEN("The difference of the point and the scalar is correct")
        {
            CHECK(point - scalar == rl::point2(-1, 4));
        }
        THEN("The product of the point and the scalar is correct")
        {
            CHECK(point * scalar == rl::point2(2, 12));
        }
        THEN("The quotient of the point and the scalar is correct")
        {
            CHECK(point / scalar == rl::point2(0, 3));
        }
    }
}