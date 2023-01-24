
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
#include <rlm/linear/rectangle2.hpp>
#include <rlm/linear/ostream.hpp>

SCENARIO("A rectangle2 is constructed")
{
    GIVEN("A rectangle2 constructed with its default constructor")
    {
        const rl::rectangle2 rectangle;
        THEN("The property values are default")
        {
            CHECK(rectangle.x == 0.0f);
            CHECK(rectangle.y == 0.0f);
            CHECK(rectangle.width == 0.0f);
            CHECK(rectangle.height == 0.0f);
        }
    }
    GIVEN("A rectangle2 constructed with its overloaded constructor")
    {
        const rl::rectangle2 rectangle(1.0f, 2.0f, 3.0f, 4.0f);
        THEN("The property values are correct")
        {
            CHECK(rectangle.x == 1.0f);
            CHECK(rectangle.y == 2.0f);
            CHECK(rectangle.width == 3.0f);
            CHECK(rectangle.height == 4.0f);
        }
    }
}