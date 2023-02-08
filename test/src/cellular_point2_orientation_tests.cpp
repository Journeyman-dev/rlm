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
#include <rlm/cellular/point2_orientation.hpp>

SCENARIO("The orientation is gotten from three point2")
{
    GIVEN("Three collinear point2")
    {
        const rl::point2 point_a(0, 0);
        const rl::point2 point_b(1, 0);
        const rl::point2 point_c(3, 0);
        WHEN("The orientation determinant is gotten from the three point2")
        {
            const auto orientation_determinant = rl::orientation_determinant(point_a, point_b, point_c);
            THEN("The value is correct")
            {
                CHECK(orientation_determinant == 0);
            }
        }
        WHEN("The position orientation is gotten from the three point2")
        {
            const auto position_orientation = rl::position_orientation(point_a, point_b, point_c);
            THEN("The value is correct")
            {
                CHECK(position_orientation == rl::PositionOrientation::Collinear);
            }
        }
    }
    GIVEN("Three clockwise point2")
    {
        const rl::point2 point_a(0, 0);
        const rl::point2 point_b(1, -1);
        const rl::point2 point_c(-1, -1);
        WHEN("The orientation determinant is gotten from the three point2")
        {
            const auto orientation_determinant = rl::orientation_determinant(point_a, point_b, point_c);
            THEN("The value is in the correct range")
            {
                CHECK(orientation_determinant > 0);
            }
        }
        WHEN("The position orientation is gotten from the three point2")
        {
            const auto position_orientation = rl::position_orientation(point_a, point_b, point_c);
            THEN("The value is correct")
            {
                CHECK(position_orientation == rl::PositionOrientation::Clockwise);
            }
        }
    }
    GIVEN("Three counter-clockwise point2")
    {
        const rl::point2 point_a(0, 0);
        const rl::point2 point_b(-1, -1);
        const rl::point2 point_c(1, -1);
        WHEN("The orientation determinant is gotten from the three point2")
        {
            const auto orientation_determinant = rl::orientation_determinant(point_a, point_b, point_c);
            THEN("The value is in the correct range")
            {
                CHECK(orientation_determinant < 0);
            }
        }
        WHEN("The position orientation is gotten from the three point2")
        {
            const auto position_orientation = rl::position_orientation(point_a, point_b, point_c);
            THEN("The value is correct")
            {
                CHECK(position_orientation == rl::PositionOrientation::CounterClockwise);
            }
        }
    }
}

