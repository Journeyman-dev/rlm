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
#include <rlm/cellular/bounds.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("Get the bounding box2 of cell shapes")
{
    GIVEN("A point2")
    {
        const rl::point2 point(1, 1);
        THEN("The bounding box2 is correct")
        {
            CHECK(rl::bounding_box2(point) == rl::box2(1, 1, 1, 1));
        }
    }
    GIVEN("A segment2")
    {
        const rl::segment2 segment(1, 2, 3, 4);
        THEN("The bounding box2 is correct")
        {
            CHECK(rl::bounding_box2(segment) == rl::box2(1, 2, 3, 3));
        }
    }
    GIVEN("A box2")
    {
        const rl::box2 box(1, 2, 3, 4);
        THEN("The bounding box2 is correct")
        {
            CHECK(rl::bounding_box2(box) == rl::box2(1, 2, 3, 4));
        }
    }
    GIVEN("A circle2")
    {
        const rl::circle2 circle(1, 2, 3.0f);
        THEN("The bounding box2 is correct")
        {
            CHECK(rl::bounding_box2(circle) == rl::box2(-2, -1, 6, 6));
        }
    }
    GIVEN("A point2, segment2, box2, and circle2")
    {
        const rl::point2 point(0, 50);
        const rl::segment2 segment(0, -50, 0, -43);
        const rl::box2 box(50, 0, 5, 5);
        const rl::circle2 circle(-50, 0, 3.0f);
        THEN("The bounding box2 is correct")
        {
            CHECK(rl::bounding_box2(point, segment, box, circle) == rl::box2(-53, 54, 108, 116));
        }
    }
}