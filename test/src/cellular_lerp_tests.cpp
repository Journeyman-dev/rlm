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
#include <rlm/cellular/lerp.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("Two point2 are linear interpolated")
{
    GIVEN("Two point2")
    {
        const rl::point2 a(1, 1);
        const rl::point2 b(5, 10);
        WHEN("The point2 are linear interpolated")
        {
            const auto result = rl::lerp(a, b, 0.65f);
            THEN("The result is correct")
            {
                CHECK(result == rl::point2(4, 7));
            }
        }
    }
}

SCENARIO("A segment2 is linear interpolated")
{
    GIVEN("A segment2")
    {
        const rl::segment2 segment(1, 2, 3, 4);
        WHEN("The segment2 is linear interpolated")
        {
            const auto result = rl::lerp(segment, 0.83f);
            THEN("The result is correct")
            {
                CHECK(result == rl::point2(3, 4));
            }
        }
    }
}