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
#include <rlm/cellular/cell_vector2.hpp>

SCENARIO("A cell_vector2 is constructed")
{
    GIVEN("A cell_vector2 constructed with its default constructor")
    {
        const rl::cell_vector2 point;
        THEN("The property values are default")
        {
            CHECK(point.x == 0);
            CHECK(point.y == 0);
        }
    }
    GIVEN("A cell_vector2 constructed with its overloaded constructor")
    {
        const rl::cell_vector2 point(1, 2);
        THEN("The property values are correct")
        {
            CHECK(point.x == 1);
            CHECK(point.y == 2);
        }
    }
}

SCENARIO("Two cell_vector2 are compared")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point_a(1, 2);
        GIVEN("A cell_vector2 that is the same")
        {
            const rl::cell_vector2 point_b(1, 2);
            THEN("The cell_vector2 are equal")
            {
                CHECK(point_a == point_b);
                CHECK_FALSE(point_a != point_b);
            }
        }
        GIVEN("A cell_vector2 that is different")
        {
            const rl::cell_vector2 point_b(3, 4);
            THEN("The cell_vector2 are not equal")
            {
                CHECK_FALSE(point_a == point_b);
                CHECK(point_a != point_b);
            }
        }
    }
}

SCENARIO("Two cell_vector2 are combined with math operators")
{
    GIVEN("Two cell_vector2")
    {
        const rl::cell_vector2 point_a(1, 2);
        const rl::cell_vector2 point_b(3, 4);
        THEN("The sum of the points is correct")
        {
            CHECK(point_a + point_b == rl::cell_vector2(4, 6));
        }
        THEN("The difference of ths points is correct")
        {
            CHECK(point_a - point_b == rl::cell_vector2(-2, -2));
        }
        THEN("The product of the points is correct")
        {
            CHECK(point_a * point_b == rl::cell_vector2(3, 8));
        }
        THEN("The quotient of the points is correct")
        {
            CHECK(point_a / point_b == rl::cell_vector2(0, 0));
        }
    }
}

SCENARIO("A cell_vector2 is combined with a scalar using math operators")
{
    GIVEN("A cell_vector2 and a scalar")
    {
        const rl::cell_vector2 point(1, 6);
        const int scalar = 2;
        THEN("The sum of the point and the scalar is correct")
        {
            CHECK(point + scalar == rl::cell_vector2(3, 8));
        }
        THEN("The difference of the point and the scalar is correct")
        {
            CHECK(point - scalar == rl::cell_vector2(-1, 4));
        }
        THEN("The product of the point and the scalar is correct")
        {
            CHECK(point * scalar == rl::cell_vector2(2, 12));
        }
        THEN("The quotient of the point and the scalar is correct")
        {
            CHECK(point / scalar == rl::cell_vector2(0, 3));
        }
    }
}