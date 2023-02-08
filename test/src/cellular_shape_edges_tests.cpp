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
#include <rlm/cellular/segment2.hpp>
#include <rlm/cellular/shape_edges.hpp>

SCENARIO("The edge coordinates are gotten from a segment2")
{
    GIVEN("A segment2")
    {
        const rl::segment2 segment(1, 2, 3, 4);
        THEN("The edge coodinates are correct")
        {
            CHECK(rl::left_x(segment) == 1);
            CHECK(rl::right_x(segment) == 3);
            CHECK(rl::top_y(segment) == 2);
            CHECK(rl::bottom_y(segment) == 4);
        }
    }
}

SCENARIO("The edge coordinates are gotten from a box2")
{
    GIVEN("A box2")
    {
        const rl::box2 box(1, 2, 3, 4);
        THEN("The edge coordinates are correct")
        {
            CHECK(rl::left_x(box) == 1);
            CHECK(rl::right_x(box) == 3);
            CHECK(rl::top_y(box) == 2);
            CHECK(rl::bottom_y(box) == 5);
        }
    }
}

SCENARIO("The edge coordinates are gotten from a cirlce2")
{
    GIVEN("A cirlce2")
    {
        const rl::circle2 circle(1, 2, 0.5f);
        THEN("The edge coordinates are correct")
        {
            CHECK(rl::left_x(circle) == 1);
            CHECK(rl::right_x(circle) == 1);
            CHECK(rl::top_y(circle) == 2);
            CHECK(rl::bottom_y(circle) == 2);
        }
    }
}