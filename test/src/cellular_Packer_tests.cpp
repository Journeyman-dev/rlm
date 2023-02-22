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
#include <rlm/cellular/Packer.hpp>
#include <rlm/cellular/pack_box.hpp>
#include <rlm/cellular/do_intersect.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <vector>
#include <span>

bool noBoxIntersect(const std::vector<rl::pack_box<int>>& boxes)
{
  for (std::size_t a_i = 0; a_i < boxes.size(); a_i++)
  {
    auto& box_a = boxes[a_i];
    for (std::size_t b_i = 0; b_i < boxes.size(); b_i++)
    {
      auto& box_b = boxes[b_i];
      if (a_i != b_i && box_a.page == box_b.page)
      {
        if (rl::do_intersect(box_a.box, box_b.box))
        {
          return false;
        }
      }
    }
  }
  return true;
}


SCENARIO("Packer is used to bin pack")
{
  GIVEN("A Packer with max dimensions (512, 512)")
  {
    rl::Packer<int> packer(512, 512);

    GIVEN("A packable vector of pack_box")
    {
      std::vector<rl::pack_box<int>> boxes = {
          rl::pack_box(0, 1, 1),    rl::pack_box(0, 1, 1),     rl::pack_box(0, 1, 1),
          rl::pack_box(0, 1, 1),    rl::pack_box(0, 1, 1),     rl::pack_box(0, 5, 5),
          rl::pack_box(0, 5, 5),    rl::pack_box(0, 5, 5),     rl::pack_box(0, 5, 5),
          rl::pack_box(0, 25, 125), rl::pack_box(0, 125, 52),  rl::pack_box(0, 11, 5),
          rl::pack_box(0, 48, 48),  rl::pack_box(0, 48, 48),   rl::pack_box(0, 48, 48),
          rl::pack_box(0, 48, 48),  rl::pack_box(0, 48, 48),   rl::pack_box(0, 48, 48),
          rl::pack_box(0, 48, 48),  rl::pack_box(0, 48, 48),   rl::pack_box(0, 48, 48),
          rl::pack_box(0, 48, 48),  rl::pack_box(0, 48, 48),   rl::pack_box(0, 48, 48),
          rl::pack_box(0, 48, 48),  rl::pack_box(0, 512, 512), rl::pack_box(0, 512, 1),
          rl::pack_box(0, 1, 512)};

      WHEN("The vector of Rect is packed with the Packer")
      {
        packer.Pack(boxes);

        THEN("No Rect intersect") { CHECK(noBoxIntersect(boxes)); }
      }

      WHEN("The vector of Rect is cut in half and packed online")
      {
        const auto half_way = boxes.size() / 2;
        std::span<rl::pack_box<int>> span_a(&boxes.front(), half_way);
        std::span<rl::pack_box<int>> span_b(&boxes.front() + half_way, boxes.size() - half_way);
        packer.Pack(span_a);
        packer.Pack(span_b);

        THEN("No Rect intersect") { CHECK(noBoxIntersect(boxes)); }
      }
    }

    GIVEN("A vector of Rect where one is larger than the Packer max dimensions")
    {
      std::vector<rl::pack_box<int>> boxes = {rl::pack_box(0, 1, 1), rl::pack_box(0, 1, 1),
                                       rl::pack_box(0, 1, 1), rl::pack_box(0, 1, 1),
                                       rl::pack_box(0, 1, 513)};

      THEN("The Packer throws an exception on packing the Rect vector")
      {
        CHECK_THROWS(packer.Pack(boxes));
      }
    }

    GIVEN("A vector of Rect where one is degenerate")
    {
      std::vector<rl::pack_box<int>> boxes = {rl::pack_box(0, 1, 1), rl::pack_box(0, 1, 1),
                                       rl::pack_box(0, 1, 1), rl::pack_box(0, 1, 1),
                                       rl::pack_box(0, 1, 0)};

      THEN("The Packer throws an exception on packing the Rect vector")
      {
        CHECK_THROWS(packer.Pack(boxes));
      }
    }
  }
}