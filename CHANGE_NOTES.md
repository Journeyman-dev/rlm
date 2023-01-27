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
