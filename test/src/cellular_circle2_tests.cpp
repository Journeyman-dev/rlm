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
#include <rlm/cellular/circle2.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("A circle2 is constructed")
{
    GIVEN("A circle2 constructed with its default constructor")
    {
        const rl::circle2 circle;
        THEN("The property values are default")
        {
            CHECK(circle.x == 0);
            CHECK(circle.y == 0);
            CHECK(circle.radius == 0.0f);
        }
    }
    GIVEN("A circle2 constructed with its overloaded constructor")
    {
        const rl::circle2 circle(1, 2, 3.0f);
        THEN("The property values are correct")
        {
            CHECK(circle.x == 1);
            CHECK(circle.y == 2);
            CHECK(circle.radius == 3.0f);
        }
    }
}