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
#include <rlm/cellular/cross.hpp>

SCENARIO("A cross product is determined")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point(1, 1);
        GIVEN("A cell_vector2")
        {
            const rl::cell_vector2 other_point(2, 2);
            THEN("The z component of the cross product of the points is correct")
            {
                CHECK(rl::cross_z(point, other_point) == 0);
            }
        }
        GIVEN("A cell_segment2")
        {
            const rl::cell_segment2 segment(1, 2, 3, 4);
            THEN("THe z component of the cross product of the point and the segment is correct")
            {
                CHECK(rl::cross_z(point, segment) == 0);
                CHECK(rl::cross_z(segment, point) == 0);
            }
        }
    }
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(2, 1, 4, 3);
        GIVEN("A cell_segment2")
        {
            const rl::cell_segment2 other_segment(1, 2, 3, 4);
            THEN("The z component of the cross product of the segments is correct")
            {
                CHECK(rl::cross_z(segment, other_segment) == 0);
            }
        }
    }
}