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

## Version 0.1.0

TODO write description.

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