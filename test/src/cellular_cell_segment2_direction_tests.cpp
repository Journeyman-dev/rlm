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
#include <rlm/cellular/cell_segment2.hpp>
#include <rlm/cellular/cell_segment2_direction.hpp>

SCENARIO("The direction is gotten from a cell_segment2")
{
    GIVEN("A cell_segment2 that goes left")
    {
        const rl::cell_segment2 segment(0, 0, 3, 0);
        WHEN("It is determined if the cell_segment2 goes in different directions")
        {
            const auto left = rl::goes_left(segment);
            const auto right = rl::goes_right(segment);
            const auto up = rl::goes_up(segment);
            const auto down = rl::goes_down(segment);
            THEN("The segment only goes left")
            {
                CHECK(left == true);
                CHECK(right == false);
                CHECK(up == false);
                CHECK(down == false);
            }
        }
    }
    GIVEN("A cell_segment2 that goes right")
    {
        const rl::cell_segment2 segment(0, 0, -3, 0);
        WHEN("It is determined if the cell_segment2 goes in different directions")
        {
            const auto left = rl::goes_left(segment);
            const auto right = rl::goes_right(segment);
            const auto up = rl::goes_up(segment);
            const auto down = rl::goes_down(segment);
            THEN("The segment only goes right")
            {
                CHECK(left == false);
                CHECK(right == true);
                CHECK(up == false);
                CHECK(down == false);
            }
        }
    }
    GIVEN("A cell_segment2 that goes up")
    {
        const rl::cell_segment2 segment(0, 0, 0, -3);
        WHEN("It is determined if the cell_segment2 goes in different directions")
        {
            const auto left = rl::goes_left(segment);
            const auto right = rl::goes_right(segment);
            const auto up = rl::goes_up(segment);
            const auto down = rl::goes_down(segment);
            THEN("The segment only goes left")
            {
                CHECK(left == false);
                CHECK(right == false);
                CHECK(up == true);
                CHECK(down == false);
            }
        }
    }
    GIVEN("A cell_segment2 that goes down")
    {
        const rl::cell_segment2 segment(0, 0, 0, 3);
        WHEN("It is determined if the cell_segment2 goes in different directions")
        {
            const auto left = rl::goes_left(segment);
            const auto right = rl::goes_right(segment);
            const auto up = rl::goes_up(segment);
            const auto down = rl::goes_down(segment);
            THEN("The segment only goes down")
            {
                CHECK(left == false);
                CHECK(right == false);
                CHECK(up == false);
                CHECK(down == true);
            }
        }
    }
}
