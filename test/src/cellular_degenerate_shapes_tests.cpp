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
#include <rlm/cellular/degenerate_shapes.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("It is determined if a cell_vector2 is degenerate")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point;
        THEN("The cell_vector2 is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(point));
        }
    }
}

SCENARIO("A cell_vector2 is fixed")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point;
        THEN("The fixed cell_vector2 is the same")
        {
            CHECK(rl::fix_degeneracy(point) == rl::cell_vector2());
        }
    }
}

SCENARIO("It is determined if a cell_segment2 is degenerate")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment;
        THEN("The cell_segment2 is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(segment));
        }
    }
}

SCENARIO("A cell_segment2 is fixed")
{
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment;
        THEN("The fixed cell_segment2 is the same")
        {
            CHECK(rl::fix_degeneracy(segment) == rl::cell_segment2());
        }
    }
}

SCENARIO("It is determined if a cell_box2 is degenerate")
{
    GIVEN("A default constructed cell_box2")
    {
        const rl::cell_box2 box;
        THEN("The cell_box2 is degenerate")
        {
            CHECK(rl::is_degenerate(box));
        }
    }
    GIVEN("A cell_box2 with a negative width")
    {
        const rl::cell_box2 box(1, 1, -2, 2);
        THEN("The cell_box2 is degenerate")
        {
            CHECK(rl::is_degenerate(box));
        }
    }
    GIVEN("A cell_box2 with a negative height")
    {
        const rl::cell_box2 box(1, 1, 2, -2);
        THEN("The cell_box2 is degenerate")
        {
            CHECK(rl::is_degenerate(box));
        }
    }
    GIVEN("A cell_box2 with positive dimensions")
    {
        const rl::cell_box2 box(1, 1, 2, 2);
        THEN("The cell_box2 is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(box));
        }
    }
}

SCENARIO("A cell_box2 is fixed")
{
    GIVEN("A degenerate cell_box2")
    {
        const rl::cell_box2 box(1, 1, -1, -1);
        THEN("The fixed cell_box2 has minimum dimnensions")
        {
            CHECK(rl::fix_degeneracy(box) == rl::cell_box2(1, 1, 1, 1));
        }
    }
    GIVEN("A non-degenerate cell_box2")
    {
        const rl::cell_box2 box(1, 1, 10, 15);
        THEN("THe fixed cell_box2 is the same")
        {
            CHECK(rl::fix_degeneracy(box) == rl::cell_box2(1, 1, 10, 15));
        }
    }
}

SCENARIO("It is determined if a cell_circle2 is degenerate")
{
    GIVEN("A default constructed cell_circle2")
    {
        const rl::cell_circle2 circle;
        THEN("The cell_circle2 is degenerate")
        {
            CHECK(rl::is_degenerate(circle));
        }
    }
    GIVEN("A cell_circle2 with a negative radius")
    {
        const rl::cell_circle2 circle(1, 1, -1.0f);
        THEN("The cell_circle2 is degenerate")
        {
            CHECK(rl::is_degenerate(circle));
        }
    }
    GIVEN("A cell_circle2 with a radius of 0.49f")
    {
        const rl::cell_circle2 circle(1, 1, 0.49f);
        THEN("The circle is degenerate")
        {
            CHECK(rl::is_degenerate(circle));
        }
    }
    GIVEN("A circle with a radius of 10.0f")
    {
        const rl::cell_circle2 circle(1, 1, 10.0f);
        THEN("The circle is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(circle));
        }
    }
}

SCENARIO("A cell_circle2 is fixed")
{
    GIVEN("A degenerate cell_circle2")
    {
        const rl::cell_circle2 circle(1, 1, -0.5f);
        THEN("The fixed cell_circle2 has minimum radius")
        {
            CHECK(rl::fix_degeneracy(circle) == rl::cell_circle2(1, 1, 0.5f));
        }
    }
    GIVEN("A non-degenerate cell_circle2")
    {
        const rl::cell_circle2 circle(1, 1, 10.0f);
        THEN("THe fixed cell_circle2 is the same")
        {
            CHECK(rl::fix_degeneracy(circle) == rl::cell_circle2(1, 1, 10.0f));
        }
    }
}