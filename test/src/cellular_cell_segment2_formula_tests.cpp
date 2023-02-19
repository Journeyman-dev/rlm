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
#include <rlm/cellular/cell_segment2_formula.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("The slope is gotten from a cell_segment2")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("The slope is gotten from the cell_segment2")
        {
            const auto slope = rl::slope(segment);
            THEN("The value is correct")
            {
                CHECK(slope == 1.0f);
            }
        }
    }
}

SCENARIO("The rise is gotten from a cell_segment2")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("The rise is gotten from the cell_segment2")
        {
            const auto rise = rl::rise(segment);
            THEN("The value is correct")
            {
                CHECK(rise == 1);
            }
        }
    }
}

SCENARIO("The run is gotten from a cell_segment2")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("The run is gotten from the cell_segment2")
        {
            const auto run = rl::run(segment);
            THEN("The value is correct")
            {
                CHECK(run == 1);
            }
        }
    }
}

SCENARIO("The y intercept is gotten from a cell_segment2")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("The y intercept is gotten from the cell_segment2")
        {
            const auto y_intercept = rl::y_intercept(segment);
            THEN("The value is correct")
            {
                CHECK(y_intercept == 1);
            }
        }
    }
}

SCENARIO("The x intercept is gotten from a cell_segment2")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(1, 2, 3, 4);
        WHEN("The x intercept is gotten from the cell_segment2")
        {
            const auto x_intercept = rl::x_intercept(segment);
            THEN("The value is correct")
            {
                CHECK(x_intercept == -1);
            }
        }
    }
}