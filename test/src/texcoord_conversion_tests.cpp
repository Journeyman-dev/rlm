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
#include <rlm/texcoord/conversion.hpp>
#include <rlm/texcoord/ostream.hpp>

SCENARIO("A pack_box is converted to a stpqp")
{
    GIVEN("A pack_box and bin dimensions")
    {
        rl::pack_box<int> box;
        box.box.x = 0;
        box.box.y = 64;
        box.box.width = 251;
        box.box.height = 65;
        box.page = 2;
        int width = 500;
        int height = 128;
        WHEN("The pack_box is converted to an stpqp")
        {
            const auto stpqp = rl::to_stpqp<float, int>(box, width, height);
            THEN("The stpqp is correct")
            {
                CHECK(stpqp == rl::stpqp<float>(0, 0.5f, 0.5f, 1.0f, 2.0f));
            }
        }
    }
}