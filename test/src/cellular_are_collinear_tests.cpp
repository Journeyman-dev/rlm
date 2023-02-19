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
    IMPLIED, INCLUDING BUT NOT LIMITE  TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <catch2/catch_all.hpp>
#include <rlm/cellular/are_collinear.hpp>

SCENARIO("Get if grid shapes are collinear")
{
    GIVEN("Three collinear cell_vector2")
    {
        const rl::cell_vector2 point_a(0, 0);
        const rl::cell_vector2 point_b(1, 1);
        const rl::cell_vector2 point_c(2, 2);
        THEN("The cell_vector2 are collinear")
        {
            CHECK(rl::are_collinear(point_a, point_b, point_c));
        }
    }
    GIVEN("Three non-collinear cell_vector2")
    {
        const rl::cell_vector2 point_a(0, 0);
        const rl::cell_vector2 point_b(1, 1);
        const rl::cell_vector2 point_c(2, 3);
        THEN("The cell_vector2 are not collinear")
        {
            CHECK_FALSE(rl::are_collinear(point_a, point_b, point_c));
        }
    }
    GIVEN("A cell_vector2 and a cell_segment2 that are collinear")
    {
        const rl::cell_vector2 point(0, 0);
        const rl::cell_segment2 segment(-5, -5, 15, 15);
        THEN("The shapes are collinear")
        {
            CHECK(rl::are_collinear(point, segment));
            CHECK(rl::are_collinear(segment, point));
        }
    }
    GIVEN("A cell_vector2 and a cell_segment2 that are not collinear")
    {
        const rl::cell_vector2 point(0, 1);
        const rl::cell_segment2 segment(-5, -5, 15, 15);
        THEN("The shapes are not collinear")
        {
            CHECK_FALSE(rl::are_collinear(point, segment));
            CHECK_FALSE(rl::are_collinear(segment, point));
        }
    }
}