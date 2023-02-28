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
#include <rlm/color/color_channel.hpp>
#include <cstdint>

SCENARIO("A color is casted to another channel type")
{
    GIVEN("A float color channel value")
    {
        const auto channel = 0.5f;
        WHEN("The channel is casted to an uint8_t")
        {
            const auto casted_channel = rl::color_channel_cast<std::uint8_t, float>(channel);
            THEN("The return value is correct")
            {
                CHECK(casted_channel == 127);
            }
        }
        WHEN("The channel is casted to a double")
        {
            const auto casted_channel = rl::color_channel_cast<double, float>(channel);
            THEN("The return value is correct")
            {
                CHECK(casted_channel == 0.5);
            }
        }
    }
    GIVEN("An uint8_t channel")
    {
        const std::uint8_t channel = 255;
        WHEN("The channel is casted to a float")
        {
            const auto casted_channel = rl::color_channel_cast<float, std::uint8_t>(channel);
            THEN("The return value is correct")
            {
                CHECK(casted_channel == 1.0f);
            }
        }
        WHEN("The channel is casted to a uin16_t")
        {
            const auto casted_channel = rl::color_channel_cast<std::uint16_t, std::uint8_t>(channel);
            THEN("The return value is correct")
            {
                CHECK(casted_channel == 65535);
            }
        }
    }
    GIVEN("A uint16_t channel")
    {
        const std::uint16_t channel = 65535;
        WHEN("The channel is casted to a float")
        {
            const auto casted_channel = rl::color_channel_cast<float, std::uint16_t>(channel);
            THEN("The return value is correct")
            {
                CHECK(casted_channel == 1.0f);
            }
        }
        WHEN("The channel is casted to a uint8_t")
        {
            const auto casted_channel = rl::color_channel_cast<std::uint8_t, std::uint16_t>(channel);
            THEN("The return value is correct")
            {
                CHECK(casted_channel == 255);
            }
        }
    }
}

SCENARIO("The max value of a color channel is gotten")
{
    GIVEN("The max value of a float channel")
    {
        const auto max = rl::color_channel_max_value<float>();
        THEN("The value is correct")
        {
            CHECK(max == 1.0f);
        }
    }
    GIVEN("The max value of a uint8_t channel")
    {
        const auto max = rl::color_channel_max_value<std::uint8_t>();
        THEN("The value is correct")
        {
            CHECK(max == 255);
        }
    }
}

SCENARIO("A color channel is clamped within the range of valid values")
{
    GIVEN("A float color channel that is out of range")
    {
        const auto channel = 433.44f;
        WHEN("The float channel is clamped")
        {
            const auto clamped = rl::color_channel_clamp<float>(channel);
            THEN("The clamped value is correct")
            {
                CHECK(clamped == 1.0f);
            }
        }
    }
}