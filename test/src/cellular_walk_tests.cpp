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
#include <rlm/cellular/walk.hpp>
#include <rlm/cellular/cell_vector2.hpp>
#include <rlm/cellular/ostream.hpp>
#include <vector>
#include <algorithm>

SCENARIO("A cell_vector2 is walked over")
{
    std::vector<rl::cell_vector2<int>> traversed_points;
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point(1, 1);
        WHEN("The cell_vector2 is walked over")
        {
            rl::walk<int>(point,
                          [&](const rl::cell_vector2<int>& step)
                          {
                              traversed_points.push_back(step);
                          });
            THEN("The walked over points are correct")
            {
                std::vector<rl::cell_vector2<int>> correct_points = {rl::cell_vector2(1, 1)};
                CHECK(std::equal(
                    traversed_points.begin(), traversed_points.end(), correct_points.begin()));
            }
        }
    }
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(1, 1, 4, 2);
        WHEN("The cell_segment2 is walked over")
        {
            rl::walk<int>(segment,
                          [&](const rl::cell_vector2<int>& step)
                          {
                              traversed_points.push_back(step);
                          });
            THEN("The walked over points are correct")
            {
                std::vector<rl::cell_vector2<int>> correct_points = {rl::cell_vector2(1, 1),
                                                                     rl::cell_vector2(2, 1),
                                                                     rl::cell_vector2(3, 2),
                                                                     rl::cell_vector2(4, 2)};
                CHECK(std::equal(
                    traversed_points.begin(), traversed_points.end(), correct_points.begin()));
            }
        }
    }
    GIVEN("A cell_box2")
    {
        const rl::cell_box2 box(1, 1, 3, 3);
        WHEN("The cell_box2 is walked over")
        {
            rl::walk<int>(box,
                          [&](const rl::cell_vector2<int>& step)
                          {
                              traversed_points.push_back(step);
                          });
            THEN("The walked over points are correct")
            {
                std::vector<rl::cell_vector2<int>> correct_points = {rl::cell_vector2(1, 1),
                                                                     rl::cell_vector2(2, 1),
                                                                     rl::cell_vector2(3, 1),
                                                                     rl::cell_vector2(1, 2),
                                                                     rl::cell_vector2(2, 2),
                                                                     rl::cell_vector2(3, 2),
                                                                     rl::cell_vector2(1, 3),
                                                                     rl::cell_vector2(2, 3),
                                                                     rl::cell_vector2(3, 3)};
                CHECK(std::equal(
                    traversed_points.begin(), traversed_points.end(), correct_points.begin()));
            }
        }
    }
    GIVEN("A cell_circle2")
    {
        const rl::cell_circle2 circle(3, 3, 2.0f);
        WHEN("The cell_circle2 is walked over")
        {
            rl::walk<int>(circle,
                          [&](const rl::cell_vector2<int>& step)
                          {
                              traversed_points.push_back(step);
                          });
            THEN("The walked over points are correct")
            {
                std::vector<rl::cell_vector2<int>> correct_points = {rl::cell_vector2(2, 2),
                                                                     rl::cell_vector2(2, 4),
                                                                     rl::cell_vector2(3, 2),
                                                                     rl::cell_vector2(3, 4),
                                                                     rl::cell_vector2(4, 2),
                                                                     rl::cell_vector2(4, 4),
                                                                     rl::cell_vector2(3, 1),
                                                                     rl::cell_vector2(3, 5),
                                                                     rl::cell_vector2(1, 3),
                                                                     rl::cell_vector2(2, 3),
                                                                     rl::cell_vector2(3, 3),
                                                                     rl::cell_vector2(4, 3),
                                                                     rl::cell_vector2(5, 3)};
                CHECK(std::equal(
                    traversed_points.begin(), traversed_points.end(), correct_points.begin()));
            }
        }
    }
}