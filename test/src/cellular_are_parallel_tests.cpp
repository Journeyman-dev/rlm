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
#include <rlm/cellular/are_parallel.hpp>

SCENARIO("Test if segment2 are parallel")
{
    GIVEN("A segment2")
    {
        const rl::segment2 segment(0, 0, 1, 1);
        GIVEN("A parallel segment2")
        {
            const rl::segment2 segment_b(1, 1, 2, 2);
            THEN("The segments are parallel")
            {
                CHECK(rl::are_parallel(segment, segment_b));
            }
        }
        GIVEN("A non-parallel segment2")
        {
            const rl::segment2 segment_b(2, 0, 1, 0);
            THEN("The segments are not parallel")
            {
                CHECK_FALSE(rl::are_parallel(segment, segment_b));
            }
        }
        GIVEN("Four parallel segment2")
        {
            const rl::segment2 segment_b(1, 1, 0, 0);
            const rl::segment2 segment_c (15, 15, 89, 89);
            const rl::segment2 segment_d(-245, -245, 55, 55);
            const rl::segment2 segment_e(5, 5, 10, 10);
            THEN("The segments are parallel")
            {
                CHECK(
                    rl::are_parallel(
                        segment,
                        segment_b,
                        segment_c,
                        segment_d,
                        segment_e
                    )
                );
            }
        }
        GIVEN("Three parallel and one non-parallel segment2")
        {
            const rl::segment2 segment_b(1, 1, 0, 0);
            const rl::segment2 segment_c (15, 15, 89, 89);
            const rl::segment2 segment_d(-245, -245, 55, 55);
            const rl::segment2 segment_e(5, 5, 10, 11);
            THEN("The segments are not parallel")
            {
                CHECK_FALSE(
                    rl::are_parallel(
                        segment,
                        segment_b,
                        segment_c,
                        segment_d,
                        segment_e
                    )
                );
            }
        }
    }
}