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
#include <rlm/cellular/center.hpp>

SCENARIO("The center of a cell shape is determined")
{
    GIVEN("A segment2")
    {
        const rl::segment2 segment(1, 1, 3, 3);
        THEN("The center is correct")
        {
            CHECK(rl::center(segment) == rl::segment2(2, 2, 2, 2));
        }
    }
    GIVEN("A box2")
    {
        const rl::box2 box(0, 0, 4, 4);
        THEN("The center is correct")
        {
            CHECK(rl::center(box) == rl::box2(2, 2, 1, 1));
        }
    }
    GIVEN("A circle2")
    {
        const rl::circle2 circle(4, 4, 3.5f);
        THEN("The center is correct")
        {
            CHECK(rl::center(circle) == rl::point2(4, 4));
        }
    }
}