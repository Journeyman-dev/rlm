// SPDX-FileCopyrightText: 2022-2023 Daniel Aimé Valcour <fosssweeper@gmail.com>
//
// SPDX-License-Identifier: MIT

/*
    Copyright (c) 2022-2023 Daniel Aimé Valcour
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
#include <rlm/min.hpp>
#include <type_traits>

SCENARIO("Determine the lowest of float values")
{
    GIVEN("Two float values")
    {
        const float a = 3.5334f;
        const float b = 4.2525f;
        WHEN("The lowest value is determined")
        {
            const auto min = rl::min(a, b);
            THEN("The min is a float")
            {
                CHECK(std::is_same_v<decltype(min), const float>);
            }
            THEN("The lowest value is correct")
            {
                CHECK(min == a);
            }
        }
    }
    GIVEN("Five float values")
    {
        const float a = 3.52325f;
        const float b = 35.353f;
        const float c = 2.3f;
        const float d = -356.55f;
        const float e = 149.6f;
        WHEN("The lowest value is determined")
        {
            const auto min = rl::min(a, b, c, d, e);
            THEN("The min is a float")
            {
                CHECK(std::is_same_v<decltype(min), const float>);
            }
            THEN("The lowest value is correct")
            {
                CHECK(min == d);
            }
        }
    }
}

SCENARIO("Determine the lowest of int values")
{
    GIVEN("Two int values")
    {
        const int a = 3;
        const int b = 4;
        WHEN("The lowest value is determined")
        {
            const auto min = rl::min(a, b);
            THEN("The min is a int")
            {
                CHECK(std::is_same_v<decltype(min), const int>);
            }
            THEN("The lowest value is correct")
            {
                CHECK(min == a);
            }
        }
    }
    GIVEN("Five int values")
    {
        const int a = 3;
        const int b = 35;
        const int c = 2;
        const int d = -356;
        const int e = 149;
        WHEN("The lowest value is determined")
        {
            const auto min = rl::min(a, b, c, d, e);
            THEN("The min is a int")
            {
                CHECK(std::is_same_v<decltype(min), const int>);
            }
            THEN("The lowest value is correct")
            {
                CHECK(min == d);
            }
        }
    }
}