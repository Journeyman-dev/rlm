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
#include <rlm/cellular/does_fit.hpp>
#include <rlm/cellular/ostream.hpp>

SCENARIO("It is determined if a cell_box2 fits in a different cell_box2")
{
    GIVEN("A cell_box2")
    {
        const rl::cell_box2 box(1, 1, 4, 4);
        GIVEN("Another cell_box2 the first box fits into")
        {
            const rl::cell_box2 fitting_box(133, 14, 6, 10);
            THEN("The first cell_box2 fits in the second cell_box2")
            {
                CHECK(rl::does_fit(fitting_box, box));
            }
        }
        GIVEN("Another cell_box2 the first box does not fit into")
        {
            const rl::cell_box2 fitting_box(133, 4, 2, 5);
            THEN("The first cell_box2 does not fit in the second cell_box2")
            {
                CHECK_FALSE(rl::does_fit(fitting_box, box));
            }
        }
    }
}