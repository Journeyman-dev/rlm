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
#include <rlm/cellular/do_intersect.hpp>

SCENARIO("It is determined if grid shapes intersect with other grid shapes")
{
    GIVEN("A cell_vector2")
    {
        const rl::cell_vector2 point(1, 1);
        GIVEN("A cell_vector2 that intersects with the cell_vector2")
        {
            const rl::cell_vector2 point_b(1, 1);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(point, point_b));
            }
        }
        GIVEN("A cell_vector2 that does not intersect with the cell_vector2")
        {
            const rl::cell_vector2 point_b(2, 2);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(point, point_b));
            }
        }
        GIVEN("A cell_segment2 that intersects with the cell_vector2")
        {
            const rl::cell_segment2 segment(1, 1, 2, 2);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(point, segment));
                CHECK(rl::do_intersect(segment, point));
            }
        }
        GIVEN("A cell_segment2 that does not intersect with the cell_vector2")
        {
            const rl::cell_segment2 segment(2, 2, 3, 4);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(point, segment));
                CHECK_FALSE(rl::do_intersect(segment, point));
            }
        }
        GIVEN("A cell_box2 that intersects with the cell_vector2")
        {
            const rl::cell_box2 box(1, 1, 2, 2);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(point, box));
                CHECK(rl::do_intersect(box, point));
            }
        }
        GIVEN("A cell_box2 that does not intersect with the cell_vector2")
        {
            const rl::cell_box2 box(2, 2, 3, 4);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(point, box));
                CHECK_FALSE(rl::do_intersect(box, point));
            }
        }
        GIVEN("A cell_circle2 that intersects with the cell_vector2")
        {
            const rl::cell_circle2 circle(1, 1, 2.0f);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(point, circle));
                CHECK(rl::do_intersect(circle, point));
            }
        }
        GIVEN("A cell_circle2 that does not intersect with the cell_vector2")
        {
            const rl::cell_circle2 circle(2, 2, 0.5f);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(point, circle));
                CHECK_FALSE(rl::do_intersect(circle, point));
            }
        }
    }
    GIVEN("A cell_segment2")
    {
        const rl::cell_segment2 segment(2, 2, 3, 3);
        GIVEN("A cell_segment2 that intersects with the cell_segment2")
        {
            const rl::cell_segment2 segment_b(3, 1, 1, 3);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(segment, segment_b));
                CHECK(rl::do_intersect(segment_b, segment));
            }
        }
        GIVEN("A cell_segment2 that does not intersect with the cell_segment2")
        {
            const rl::cell_segment2 segment_b(10, 10, 6, 6);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(segment, segment_b));
                CHECK_FALSE(rl::do_intersect(segment_b, segment));
            }
        }
        GIVEN("A cell_box2 that intersects with the cell_segment2")
        {
            const rl::cell_box2 box(2, 2, 3, 3);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(segment, box));
                CHECK(rl::do_intersect(box, segment));
            }
        }
        GIVEN("A cell_box2 that does not intersect with the cell_segment2")
        {
            const rl::cell_box2 box(10, 10, 6, 6);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(segment, box));
                CHECK_FALSE(rl::do_intersect(box, segment));
            }
        }
        GIVEN("A cell_circle2 that intersects with the cell_segment2")
        {
            const rl::cell_circle2 circle(2, 2, 0.5f);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(segment, circle));
                CHECK(rl::do_intersect(circle, segment));
            }
        }
        GIVEN("A cell_circle2 that does not intersect with the cell_segment2")
        {
            const rl::cell_circle2 circle(10, 10, 2.0f);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(segment, circle));
                CHECK_FALSE(rl::do_intersect(circle, segment));
            }
        }
    }
    GIVEN("A cell_box2")
    {
        const rl::cell_box2 box(1, 1, 2, 2);
        GIVEN("A cell_box2 that intersects with the cell_box2")
        {
            const rl::cell_box2 box_b(2, 2, 3, 3);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(box, box_b));
                CHECK(rl::do_intersect(box_b, box));
            }
        }
        GIVEN("A cell_box2 that does not intersect with the cell_box2")
        {
            const rl::cell_box2 box_b(10, 10, 6, 6);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(box, box_b));
                CHECK_FALSE(rl::do_intersect(box_b, box));
            }
        }
        GIVEN("A cell_circle2 that intersects with the cell_box2")
        {
            const rl::cell_circle2 circle(1, 1, 0.5f);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(box, circle));
                CHECK(rl::do_intersect(circle, box));
            }
        }
        GIVEN("A cell_circle2 that does not intersect with the cell_box2")
        {
            const rl::cell_circle2 circle(10, 10, 2.0f);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(box, circle));
                CHECK_FALSE(rl::do_intersect(circle, box));
            }
        }
    }
    GIVEN("A cell_circle2")
    {
        const rl::cell_circle2 circle(1, 1, 1.0f);
        GIVEN("A cell_circle2 that intersects with the cell_circle2")
        {
            const rl::cell_circle2 circle_b(2, 2, 1.0f);
            THEN("The shapes intersect")
            {
                CHECK(rl::do_intersect(circle, circle_b));
                CHECK(rl::do_intersect(circle_b, circle));
            }
        }
        GIVEN("A cell_circle2 that does not intersect with the cell_circle2")
        {
            const rl::cell_circle2 circle_b(10, 10, 1.0f);
            THEN("The shapes do not intersect")
            {
                CHECK_FALSE(rl::do_intersect(circle, circle_b));
                CHECK_FALSE(rl::do_intersect(circle_b, circle));
            }
        }
    }
}