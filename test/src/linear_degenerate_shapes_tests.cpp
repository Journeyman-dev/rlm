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
#include <rlm/linear/degenerate_shapes.hpp>
#include <rlm/linear/ostream.hpp>

SCENARIO("It is determined if a rectangle2 is degenerate")
{
    GIVEN("A default constructed rectangle2")
    {
        const rl::rectangle2 rectangle;
        THEN("The rectangle2 is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(rectangle));
        }
    }
    GIVEN("A rectangle2 with a negative width")
    {
        const rl::rectangle2 rectangle(1.0f, 1.0f, -2.0f, 2.0f);
        THEN("The rectangle2 is degenerate")
        {
            CHECK(rl::is_degenerate(rectangle));
        }
    }
    GIVEN("A rectangle2 with a negative height")
    {
        const rl::rectangle2 rectangle(1.0f, 1.0f, 2.0f, -2.0f);
        THEN("The rectangle2 is degenerate")
        {
            CHECK(rl::is_degenerate(rectangle));
        }
    }
    GIVEN("A box2 with positive dimensions")
    {
        const rl::rectangle2 rectangle(1.0f, 1.0f, 2.0f, 2.0f);
        THEN("The box2 is not degenerate")
        {
            CHECK_FALSE(rl::is_degenerate(rectangle));
        }
    }
}

SCENARIO("A rectangle2 is fixed")
{
    GIVEN("A degenerate rectangle2")
    {
        const rl::rectangle2 rectangle(1.0f, 1.0f, -1.0f, -1.0f);
        THEN("The fixed box2 has minimum dimnensions")
        {
            CHECK(rl::fix_degeneracy(rectangle) == rl::rectangle2(1.0f, 1.0f, 0.0f, 0.0f));
        }
    }
    GIVEN("A non-degenerate rectangle2")
    {
        const rl::rectangle2 rectangle(1.0f, 1.0f, 10.0f, 15.0f);
        THEN("THe fixed rectangle2 is the same")
        {
            CHECK(rl::fix_degeneracy(rectangle) == rl::rectangle2(1.0f, 1.0f, 10.0f, 15.0f));
        }
    }
}