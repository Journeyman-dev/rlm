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
#include <rlm/lerp.hpp>

SCENARIO("Two primitives are linear interpolated")
{
    GIVEN("Two floats")
    {
        const float a = 1.0f;
        const float b = 10.5f;
        WHEN("The floats are linear interpolated")
        {
            const auto result = rl::lerp(a, b, 0.5f);
            THEN("The result is correct")
            {
                CHECK(result == 5.75f);
            }
        }
    }
    GIVEN("Two ints")
    {
        const int a = 100;
        const int b = 34;
        WHEN("The ints are linear interpolated")
        {
            const auto result = rl::lerp(a, b, 0.5f);
            THEN("The result is correct")
            {
                CHECK(result == 67);
            }
        }
    }
}