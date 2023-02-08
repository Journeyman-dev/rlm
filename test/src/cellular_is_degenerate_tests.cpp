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
#include <rlm/cellular/is_degenerate.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("It is determined if a box2 is degenerate")
{
    GIVEN("A default constructed box2")
    {
        const rl::box2 box;
        THEN("The box2 is degenerate")
        {
            CHECK(rl::is_degenerate(box));
        }
    }
    GIVEN("A box2 with a negative width")
    {
        const rl::box2 box(1, 1, -2, 2);
        THEN("The box2 is degenerate")
        {
            CHECK(rl::is_degenerate(box));
        }
    }
    GIVEN("A box2 with a negative height")
    {
        const rl::box2 box(1, 1, 2, -2);
        THEN("The box2 is degenerate")
        {
            CHECK(rl::is_degenerate(box));
        }
    }
    GIVEN("A box2 with positive dimensions")
    {
        const rl::box2 box(1, 1, 2, 2);
        THEN("The box2 is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(box));
        }
    }
}

SCENARIO("It is determined if a circle2 is degenerate")
{
    GIVEN("A default constructed circle2")
    {
        const rl::circle2 circle;
        THEN("The circle2 is degenerate")
        {
            CHECK(rl::is_degenerate(circle));
        }
    }
    GIVEN("A circle2 with a negative radius")
    {
        const rl::circle2 circle(1, 1, -1.0f);
        THEN("The circle2 is degenerate")
        {
            CHECK(rl::is_degenerate(circle));
        }
    }
    GIVEN("A circle2 with a radius of 0.49f")
    {
        const rl::circle2 circle(1, 1, 0.49f);
        THEN("The circle is degenerate")
        {
            CHECK(rl::is_degenerate(circle));
        }
    }
    GIVEN("A circle with a radius of 10.0f")
    {
        const rl::circle2 circle(1, 1, 10.0f);
        THEN("The circle is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(circle));
        }
    }
}