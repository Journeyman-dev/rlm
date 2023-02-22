<!--
SPDX-FileCopyrightText: 2023 Daniel Aimé Valcour <fosssweeper@gmail.com>

SPDX-License-Identifier: MIT
-->

<!--
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
-->

# Change Notes

All changes made in each version of RLM are tracked here.

## Version 0.3.0

This is the largest update yet. It includes a massive additions to the cellular math portion of the library.

### Features:
 - Add rl::gcf function to get the greatest common factor of two or more primatives.
 - Add functions to fix degenerate shape dimensions by changing them to have the minimum valid value.
 - Add CMake options to configure if degenerate shapes are fixed automatically (RLM_FIX_DEGENERACY) and to configure if asserts are called for degenerate shapes in debug builds (RLM_ASSERT_DEGENERACY).
 - Port bin packing algorithm from [mpbp](https://github.com/Journeyman-dev/mpbp), which is now archived.
 - Rename structs to be more consistent:
    - point2 -> cell_vector2
    - segment2 -> cell_segment2
    - box2 -> cell_box2
    - circle2 -> cell_circle2
    - rectangle2 -> box2
 - Add rl::walk function to iterate over every cell of a cell shape.
 - Add rl::are_collinear function to determine if cell_vector2 and/or cell_segment2 are collinear.
 - Add rl::are_parallel function to determine if cell_segment2 are parallel.
 - Add rl::are_perpendicular function to determine if cell_segment2 are perpendicular.
 - Add rl::bounding_box2 function to get the bounding cell_box2 of one or more cell shapes.
 - Add rl::box2_between function to get the cell_box2 between four coordinate edges.
 - Add functions to get the size of a cell_circle2.
 - Add rl::cell_segment2_between function to get the cell_segment2 between two cell_vector2.
 - Add functions to get the direction of a cell_segment2.
 - Add functions to get the size of a cell_segment2.
 - Add rl::orientation_determinant function to get the orientation determinant of three cell_vector2.
 - Add rl::position_orientation to get the orientation of three cell_vector2, returned as the new enum rl::PositionOrientation.
 - Add rl::center function to get the center of cell shapes.
 - Add rl::crop function to crop cell shapes within a cell_box2.
 - Add rl::cross_z function to get the z component of the cross product of cell shapes.
 - Add rl::distance_between functions to get the distance between any two cell shapes.
 - Add rl::do_intersect function to determine if any two cell shapes share at least one cell.
 - Add rl::does_contain function to determine if one cell shape is made up of tiles that are entirely within another.
 - Add rl::does_fit function to determine if a cell shape can contain another if it was moved. Only overloaded for cell_box2 in this release.
 - Add rl::dot function to calculate the dot product between cell shapes.
 - Add rl::unit_dot function to calculate the unit dot product between two cell shapes.
 - Add rl::magnitude function to get the magnitude of a cell_vector2.
 - Add functions to convert cell shapes to other cell shapes if possible.
 - Add functions to determine if a cell shape is convertable into a different cell shape type.
 - Add rl::template_cast to cast a struct into the same struct type with different template arguments, casting the property values.
 - Add rl::translation to get the translation of a cell_segment2.

## Version 0.2.0

This version includes a lot of new math functions. Most of these are in the cellular algebra portion of the library.

### Features:
 - Add segment2 reverse function, which takes a segment2 as an argument and returns one with swapped start and end points.
 - Add segment2 direction functions to determine if a segment2 goes up, down, left, or right.
 - Add operators to point2, segment2, box2, and circle2.
    - Add equality comparison operators to all of the above shapes.
    - Add arithmetic operators to point2, including overloads with scalar values.
 - Add functions to get the start and end points of a segment2.
 - Add functions to get the edge x and y coordinates of all cell shapes.
 - Add functions to get the corner points of a box2.
 - Add functions to wrap primitives between two other values.
    - Add clamp to clamp the value between the two other values.
    - Add mirror to mirror the value between the two other values when it goes out of range.
    - Add repeat to repeat the value between the two other values when it goes out of range.
- Add functions to get the border segments of box2 shapes. These functions have arguments allowing to specify the direction that the border segments should go (clockwise or counter clockwise), and to specify which corners of the box2 to trim from the segment.
- Add functions to get the bounding box2 of all cell shapes.
    - Add an overloaded version of this function which uses recursive templates to accept an arbitrary number of shapes to get the box2 that surrounds all of them.

## Version 0.1.0

This version is mostly a polish release, though it includes the addition of two new math functions.

### Features:
 - Add min and max functions, to get the highest and lowest values from all arguments.
    - Added recursive overloads that work for two or more arguments.

### Tooling:
- Fixed unit test continuous integration so that it works.

## Version 0.0.0

This version is the minimum viable product, and is supposed to be a starting point to build off from.

### Features:
- Add several cell shape structs:
    - point2 - A single cell.
    - segment2 - A line segment of cells between two cells.
    - box2 - An axis aligned box of cells.
    - circle2 - A circle of cells.
- Add several linear algebra structs:
    - rectangle2 - A floating point axis aligned box.
    - vector2 - A 2d vector.
    - vector3 - A 3d vector.
    - vector4 - A 4d vector.
- Add is_degenerate function for bot cellular and linear structs to determine if they have invalid property values.
