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
#include <rlm/cellular/crop.hpp>

SCENARIO("A shape is cropped by a box2")
{
    GIVEN("A box2")
    {
        const rl::box2 crop_box(1, 1, 5, 5);
        GIVEN("A point2 that is intersects the box2")
        {
            const rl::point2 point(2, 2);
            WHEN("The point2 is cropped in the box2")
            {
                const auto cropped_point_o = rl::crop(point, crop_box);
                THEN("The cropped point is correct")
                {
                    REQUIRE(cropped_point_o.has_value());
                    CHECK(cropped_point_o.value() == rl::point2(2, 2));
                }
            }
        }
        GIVEN("A point2 that does not intersect the box2")
        {
            const rl::point2 point(0, 0);
            WHEN("The points is cropped in the box2")
            {
                const auto cropped_point_o = rl::crop(point, crop_box);
                THEN("The cropped point is nullopt")
                {
                    CHECK_FALSE(cropped_point_o.has_value());
                }
            }
        }
        GIVEN("A segment2 that intersects the box2")
        {
            const rl::segment2 segment(0, 0, 2, 2);
            WHEN("The point2 is cropped in the box2")
            {
                const auto cropped_segment_o = rl::crop(segment, crop_box);
                THEN("The cropped segment2 is correct")
                {
                    REQUIRE(cropped_segment_o.has_value());
                    CHECK(cropped_segment_o.value() == rl::segment2(1, 1, 2, 2));
                }
            }
        }
        GIVEN("A segment2 that does not intersect of the box2")
        {
            const rl::segment2 segment(0, 0, -4, -4);
            WHEN("The points is cropped in the box2")
            {
                const auto cropped_segment_o = rl::crop(segment, crop_box);
                THEN("The cropped point is nullopt")
                {
                    CHECK_FALSE(cropped_segment_o.has_value());
                }
            }
        }
    }

}