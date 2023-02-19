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
#include <rlm/cellular/cell_segment2.hpp>

SCENARIO("A cell_segment2 is constructed")
{
    GIVEN("A cell_segment2 constructed with its default constructor")
    {
        const rl::cell_segment2 segment;
        THEN("The property values are default")
        {
            CHECK(segment.start_x == 0);
            CHECK(segment.start_y == 0);
            CHECK(segment.end_x == 0);
            CHECK(segment.end_y == 0);
        }
    }
    GIVEN("A cell_segment2 constructed with its overloaded constructor")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        THEN("The property values are correct")
        {
            CHECK(segment.start_x == 1);
            CHECK(segment.start_y == 2);
            CHECK(segment.end_x == 3);
            CHECK(segment.end_y == 4);
        }
    }
}

SCENARIO("Two cell_segment2 are compared")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment_a(1, 2, 3, 4);
        GIVEN("A cell_segment2 that is the same")
        {
            const rl::cell_segment2 segment_b(1, 2, 3, 4);
            THEN("The cell_segment2 are equal")
            {
                CHECK(segment_a == segment_b);
                CHECK_FALSE(segment_a != segment_b);
            }
        }
        GIVEN("A cell_segment2 that is different")
        {
            const rl::cell_segment2 segment_b(5, 6, 7, 8);
            THEN("The cell_segment2 are not equal")
            {
                CHECK_FALSE(segment_a == segment_b);
                CHECK(segment_a != segment_b);
            }
        }
    }
}