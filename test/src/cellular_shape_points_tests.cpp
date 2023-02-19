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
#include <rlm/cellular/shape_points.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("Get the start and end cell_vector2 of a cell_segment2")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(-49, 55, 32, -2);
        WHEN("The start and end cell_vector2 are gotten from the cell_segment2")
        {
            const auto start = rl::start(segment);
            const auto end = rl::end(segment);
            THEN("The values are correct")
            {
                CHECK(start.x == -49);
                CHECK(start.y == 55);
                CHECK(end.x == 32);
                CHECK(end.y == -2);
            }
        }
    }
}

SCENARIO("Get the corners of a cell_box2")
{
    GIVEN("A cell_box2")
    {
        const rl::cell_box2 box(1, 2, 3, 4);
        WHEN("The corners are gotten from the cell_box2")
        {
            const auto top_left = rl::top_left(box);
            const auto top_right = rl::top_right(box);
            const auto bottom_left = rl::bottom_left(box);
            const auto bottom_right = rl::bottom_right(box);
            THEN("The values are correct")
            {
                CHECK(top_left == rl::cell_vector2(1, 2));
                CHECK(top_right == rl::cell_vector2(3, 2));
                CHECK(bottom_left == rl::cell_vector2(1, 5));
                CHECK(bottom_right == rl::cell_vector2(3, 5));
            }
        }
    }
}