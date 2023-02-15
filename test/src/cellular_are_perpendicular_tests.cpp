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
#include <rlm/cellular/are_perpendicular.hpp>

SCENARIO("Get if two segment2 are perpendicular")
{
    GIVEN("A segment2")
    {
        const rl::segment2 segment(0, 0, 3, 3);
        GIVEN("A perpendicular segment2")
        {
            const rl::segment2 segment_b(3, 0, 0, 3);
            THEN("The segments are perpendicular")
            {
                CHECK(rl::are_perpendicular(segment, segment_b));
            }
        }
        GIVEN("A non-perpendicular segment2")
        {
            const rl::segment2 segment_b(-1, 0, 3, 4);
            THEN("The segments are not perpendicular")
            {
                CHECK_FALSE(rl::are_perpendicular(segment, segment_b));
            }
        }
    }
}