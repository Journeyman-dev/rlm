# SPDX-FileCopyrightText: 2023 Daniel Aimé Valcour <fosssweeper@gmail.com>
#
# SPDX-License-Identifier: MIT

# Copyright (c) 2023 Daniel Aimé Valcour
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
# the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

target_sources(RlmTest
    PRIVATE
        "cellular_box2_tests.cpp"
        "cellular_circle2_tests.cpp"
        "cellular_edges_tests.cpp"
        "cellular_direction_tests.cpp"
        "cellular_is_degenerate_tests.cpp"
        "cellular_point2_tests.cpp"
        "cellular_reverse_tests.cpp"
        "cellular_segment2_tests.cpp"
        "cellular_shape_points_tests.cpp"
        "clamp_tests.cpp"
        "linear_is_degenerate_tests.cpp"
        "linear_rectangle2_tests.cpp"
        "linear_vector2_tests.cpp"
        "linear_vector3_tests.cpp"
        "linear_vector4_tests.cpp"
        "max_tests.cpp"
        "min_tests.cpp"
        "mirror_tests.cpp"
        "repeat_tests.cpp"
)