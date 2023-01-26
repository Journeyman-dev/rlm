
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
#include <rlm/cellular/box2.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("A box2 is constructed")
{
    GIVEN("A box2 constructed with its default constructor")
    {
        const rl::box2 box;
        THEN("The property values are default")
        {
            CHECK(box.x == 0);
            CHECK(box.y == 0);
            CHECK(box.width == 0);
            CHECK(box.height == 0);
        }
    }
    GIVEN("A box2 constructed with its overloaded constructor")
    {
        const rl::box2 box(1, 2, 3, 4);
        THEN("The property values are correct")
        {
            CHECK(box.x == 1);
            CHECK(box.y == 2);
            CHECK(box.width == 3);
            CHECK(box.height == 4);
        }
    }
}