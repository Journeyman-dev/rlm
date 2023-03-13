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
        "cellular_shape_conversion_tests.cpp"
        "cellular_are_collinear_tests.cpp"
        "cellular_do_intersect_tests.cpp"
        "cellular_are_parallel_tests.cpp"
        "cellular_are_perpendicular_tests.cpp"
        "cellular_bounding_cell_box2_tests.cpp"
        "cellular_cell_box2_between_tests.cpp"
        "cellular_cell_box2_borders_tests.cpp"
        "cellular_center_tests.cpp"
        "cellular_cell_circle2_size_tests.cpp"
        "cellular_cell_circle2_tests.cpp"
        "cellular_crop_tests.cpp"
        "cellular_cross_tests.cpp"
        "cellular_degenerate_shapes_tests.cpp"
        "cellular_distance_between_tests.cpp"
        "cellular_dot_tests.cpp"
        "cellular_shape_edges_tests.cpp"
        "cellular_does_contain_tests.cpp"
        "cellular_does_fit_tests.cpp"
        "cellular_lerp_tests.cpp"
        "cellular_magnitude_tests.cpp"
        "cellular_pack_box_tests.cpp"
        "cellular_pack_space_tests.cpp"
        "cellular_Packer_tests.cpp"
        "cellular_cell_vector2_orientation_tests.cpp"
        "cellular_cell_vector2_tests.cpp"
        "cellular_reverse_tests.cpp"
        "cellular_cell_segment2_direction_tests.cpp"
        "cellular_cell_segment2_formula_tests.cpp"
        "cellular_cell_segment2_size_tests.cpp"
        "cellular_cell_segment2_tests.cpp"
        "cellular_shape_points_tests.cpp"
        "cellular_translation_tests.cpp"
        "cellular_walk_tests.cpp"
        "color_color_channel_tests.cpp"
        "color_color_conversion_tests.cpp"
        "color_color_g_tests.cpp"
        "color_color_ga_tests.cpp"
        "color_color_rgb_tests.cpp"
        "color_color_rgba_tests.cpp"
        "color_grayscale_conversion_tests.cpp"
        "clamp_tests.cpp"
        "gcf_tests.cpp"
        "hash_combine_tests.cpp"
        "lerp_tests.cpp"
        "linear_degenerate_shapes_tests.cpp"
        "linear_box2_tests.cpp"
        "linear_vector2_tests.cpp"
        "linear_vector3_tests.cpp"
        "linear_vector4_tests.cpp"
        "max_tests.cpp"
        "min_tests.cpp"
        "mirror_tests.cpp"
        "repeat_tests.cpp"
        "texcoord_conversion_tests.cpp"
)