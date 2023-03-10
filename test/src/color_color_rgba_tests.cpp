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
#include <rlm/color/color_rgba.hpp>
#include <rlm/color/ostream.hpp>
#include <cstdint>

SCENARIO("A color_rgba is constructed")
{
    GIVEN("A color_rgba constructed with its default constructor")
    {
        rl::color_rgba<std::uint8_t> color;
        THEN("All properties are correct")
        {
            CHECK(color.r == 0);
            CHECK(color.g == 0);
            CHECK(color.b == 0);
            CHECK(color.a == 0);
        }
    }
    GIVEN("A color_rgb constructed with its overloaded constructor")
    {
        rl::color_rgba<std::uint8_t> color(1, 2, 3, 4);
        THEN("All properties are correct")
        {
            CHECK(color.r == 1);
            CHECK(color.g == 2);
            CHECK(color.b == 3);
            CHECK(color.a == 4);
        }
    }
}

SCENARIO("Two color_rgba are compared")
{
    GIVEN("A color_rgba")
    {
        const rl::color_rgba<std::uint8_t> color_a(24, 44, 100, 244);
        GIVEN("Another color_rgba that is equal")
        {
            const rl::color_rgba<std::uint8_t> color_b(24, 44, 100, 244);
            THEN("The color_rgba are equal")
            {
                CHECK(color_a == color_b);
            }
        }
        GIVEN("Another color_rgba that is not equal")
        {
            const rl::color_rgba<std::uint8_t> color_b(55, 128, 200, 255);
            THEN("The color_rgba are not equal")
            {
                CHECK(color_a != color_b);
            }
        }
    }
}