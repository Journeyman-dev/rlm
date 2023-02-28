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
#include <rlm/color/color_conversion.hpp>
#include <rlm/color/ostream.hpp>
#include <cstdint>

SCENARIO("A color struct is converted")
{
    GIVEN("A rl::color_g<std::uint8_t>")
    {
        const rl::color_g<std::uint8_t> color(127);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32639));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 255));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32639, 65535));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.a == 1.0)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32639, 32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 255));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32639, 32639, 32639, 65535));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        converted.a == 1.0
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_g<std::uint16_t>")
    {
        const rl::color_g<std::uint16_t> color(32767);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(128));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32767));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(128, 255));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32767, 65535));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.a == 1.0)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(128, 128, 128));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(128, 128, 128, 255));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 65535));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        (converted.a == 1.0)
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_g<double>")
    {
        const rl::color_g<double> color(0.5);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32767));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 255));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32767, 65535));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 255));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 65535));
            }
        }
    }
    GIVEN("A rl::color_ga<std::uint8_t>")
    {
        const rl::color_ga<std::uint8_t> color(127, 127);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32639));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 127));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.a > 0.49 && converted.a < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32639, 32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32639, 32639, 32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        (converted.a > 0.49 && converted.a < 0.51)
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_ga<std::uint16_t>")
    {
        const rl::color_ga<std::uint16_t> color(32767, 32767);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(128));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32767));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(128, 128));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.4999 && converted.g < 0.51) &&
                         (converted.a > 0.4999 && converted.a < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(128, 128, 128));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(128, 128, 128, 128));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        (converted.a > 0.49 && converted.a < 0.51)
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_ga<double>")
    {
        const rl::color_ga<double> color(0.5, 0.5);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32767));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 127));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 32767));
            }
        }
    }
    GIVEN("A rl::color_rgb<std::uint8_t>")
    {
        const rl::color_rgb<std::uint8_t> color(127, 127, 127);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32639));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 255));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32639, 65535));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.a == 1.0)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32639, 32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 255));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32639, 32639, 32639, 65535));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        converted.a == 1.0
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_rgb<std::uint16_t>")
    {
        const rl::color_rgb<std::uint16_t> color(32767, 32767, 32767);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(128));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32767));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(128, 255));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32767, 65535));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.a == 1.0)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(128, 128, 128));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(128, 128, 128, 255));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 65535));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        (converted.a == 1.0)
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_rgb<double>")
    {
        const rl::color_rgb<double> color(0.5, 0.5, 0.5);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32765));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 255));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32765, 65535));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 255));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 65535));
            }
        }
    }
    GIVEN("A rl::color_rgba<std::uint8_t>")
    {
        const rl::color_rgba<std::uint8_t> color(127, 127, 127, 127);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32639));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 127));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.a > 0.49 && converted.a < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32639, 32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint8_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32639, 32639, 32639, 32639));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint8_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        (converted.a > 0.49 && converted.a < 0.51)
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_rgba<std::uint16_t>")
    {
        const rl::color_rgba<std::uint16_t> color(32767, 32767, 32767, 32767);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(128));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint16_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32767));
            }
        }
        WHEN("The color is converted to rl::color_g<double>")
        {
            const auto converted = rl::to_color_g<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.49 && converted.g < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(128, 128));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_ga<double>")
        {
            const auto converted = rl::to_color_ga<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.g > 0.4999 && converted.g < 0.51) &&
                         (converted.a > 0.4999 && converted.a < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(128, 128, 128));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgb<double>")
        {
            const auto converted = rl::to_color_rgb<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51)
                    )
                );
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(128, 128, 128, 128));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, std::uint16_t>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgba<double>")
        {
            const auto converted = rl::to_color_rgba<double, std::uint16_t>(color);
            THEN("The converted color value is correct")
            {
               CHECK(
                    (
                        (converted.r > 0.49 && converted.r < 0.51) &&
                        (converted.g > 0.49 && converted.g < 0.51) &&
                        (converted.b > 0.49 && converted.b < 0.51) &&
                        (converted.a > 0.49 && converted.a < 0.51)
                    )
                );
            }
        }
    }
    GIVEN("A rl::color_rgba<double>")
    {
        const rl::color_rgba<double> color(0.5, 0.5, 0.5, 0.5);
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint8_t>(127));
            }
        }
        WHEN("The color is converted to rl::color_g<std::uint8_t>")
        {
            const auto converted = rl::to_color_g<std::uint16_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_g<std::uint16_t>(32765));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint8_t>")
        {
            const auto converted = rl::to_color_ga<std::uint8_t, double>(color);
            THEN("The converted color value is correct")
            {
                CHECK(converted == rl::color_ga<std::uint8_t>(127, 127));
            }
        }
        WHEN("The color is converted to rl::color_ga<std::uint16_t>")
        {
            const auto converted = rl::to_color_ga<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_ga<std::uint16_t>(32765, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint8_t>(127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgb<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgb<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgb<std::uint16_t>(32767, 32767, 32767));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint8_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint8_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint8_t>(127, 127, 127, 127));
            }
        }
        WHEN("The color is converted to rl::color_rgba<std::uint16_t>")
        {
            const auto converted = rl::to_color_rgba<std::uint16_t, double>(color);
            THEN("The converted color is correct")
            {
                CHECK(converted == rl::color_rgba<std::uint16_t>(32767, 32767, 32767, 32767));
            }
        }
    }
}