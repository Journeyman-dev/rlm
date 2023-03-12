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
#include <rlm/cellular/pack_box.hpp>

SCENARIO("A pack_box is constructed")
{
    GIVEN("A default constructed pack_box")
    {
        const rl::pack_box box;
        THEN("The properties are correct")
        {
            CHECK(box.identifier == 0);
            CHECK(box.page == 0);
            CHECK(box.box == rl::cell_box2());
        }
    }
    GIVEN("An overload constructed pack_box")
    {
        const rl::pack_box box(1, 2, 3);
        THEN("The properties are correct")
        {
            CHECK(box.identifier == 1);
            CHECK(box.box == rl::cell_box2(0, 0, 2, 3));
        }
    }
}

SCENARIO("Two pack_box are compared")
{
    GIVEN("A pack_box")
    {
        const rl::pack_box<int> box_a(1, 2, 3);
        GIVEN("A pack_box that is the same")
        {
            const rl::pack_box<int> box_b(1, 2, 3);
            THEN("The pack_box are equal")
            {
                CHECK(box_a == box_b);
                CHECK_FALSE(box_a != box_b);
            }
        }
        GIVEN("A pack_box that is different")
        {
            const rl::pack_box<int> box_b(3, 4, 5);
            THEN("The pack_box are not equal")
            {
                CHECK_FALSE(box_a == box_b);
                CHECK(box_a != box_b);
            }
        }
    }
}
