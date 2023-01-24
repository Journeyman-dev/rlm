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
#include <rlm/cellular/segment2.hpp>

SCENARIO("A segment2 is constructed")
{
    GIVEN("A segment2 constructed with its default constructor")
    {
        const rl::segment2 segment;
        THEN("The property values are default")
        {
            CHECK(segment.start_x == 0);
            CHECK(segment.start_y == 0);
            CHECK(segment.end_x == 0);
            CHECK(segment.end_y == 0);
        }
    }
    GIVEN("A segment2 constructed with its overloaded constructor")
    {
        const rl::segment2 segment(1, 2, 3, 4);
        THEN("The property values are correct")
        {
            CHECK(segment.start_x == 1);
            CHECK(segment.start_y == 2);
            CHECK(segment.end_x == 3);
            CHECK(segment.end_y == 4);
        }
    }
}