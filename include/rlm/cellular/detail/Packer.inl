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

#pragma once

#include <rlm/concepts.hpp>
#include <rlm/cellular/does_fit.hpp>
#include <rlm/cellular/shape_edges.hpp>
#include <rlm/cellular/degenerate_shapes.hpp>
#include <rlm/max.hpp>
#include <stdexcept>
#include <cassert>

template<rl::signed_integral I>
constexpr rl::Packer<I>::Packer(I max_bin_width, I max_bin_height)
{
    this->Initialize(max_bin_width, max_bin_height);
}

template<rl::signed_integral I>
constexpr void rl::Packer<I>::Initialize(I max_bin_width, I max_bin_height)
{
    if (
        max_bin_width <= 0 ||
        max_bin_height <= 0
    )
    {
        throw std::runtime_error("invalid Packer max page dimensions");
    }
    this->spaces.clear();
    this->top_page_i = 0;
    this->width = 0;
    this->height = 0;
    this->max_bin_width = max_bin_width;
    this->max_bin_height = max_bin_height;
    this->top_page_width = 0;
    this->top_page_height = 0;
}

template<rl::signed_integral I>
constexpr bool rl::Packer<I>::GetIsInitialized() const noexcept
{
    return this->max_bin_width > 0;
}

template<rl::signed_integral I>
constexpr bool rl::Packer<I>::GetIsEmpty() const noexcept
{
    return this->width == 0; 
}

template<rl::signed_integral I>
constexpr void rl::Packer<I>::ReserveSpaces(std::size_t box_count)
{
    const auto highest_new_space_count = box_count * 2;
    const auto new_space_capacity = this->spaces.size() + highest_new_space_count;
    this->spaces.reserve(new_space_capacity);
}


template<rl::signed_integral I>
constexpr void rl::Packer<I>::TrimToFitSpaces()
{
    this->spaces.trim_to_fit();
}

template<rl::signed_integral I>
constexpr const std::vector<rl::pack_space<I>>& rl::Packer<I>::GetSpaces() const noexcept
{
    return this->spaces;
}

template<rl::signed_integral I>
constexpr I rl::Packer<I>::GetPageCount() const noexcept
{
    return this->top_page_i + 1;
}

template<rl::signed_integral I>
constexpr I rl::Packer<I>::GetWidth() const noexcept
{
    return this->width;
}

template<rl::signed_integral I>
constexpr I rl::Packer<I>::GetHeight() const noexcept
{
    return this->height;
}

template<rl::signed_integral I>
constexpr I rl::Packer<I>::GetMaxPageWidth() const noexcept
{
    return this->max_bin_width;
}

template<rl::signed_integral I>
constexpr I rl::Packer<I>::GetMaxPageHeight() const noexcept
{
    return this->max_bin_height;
}

template<rl::signed_integral I>
constexpr I rl::Packer<I>::GetTopPageWidth() const noexcept
{
    return this->top_page_width;
}

template<rl::signed_integral I>
constexpr I rl::Packer<I>::GetTopPageHeight() const noexcept
{
    return this->top_page_height;
}

template<rl::signed_integral I>
constexpr bool rl::Packer<I>::tryPlaceSpace(rl::pack_box<I>& box)
{
    for (std::size_t space_i = 0; space_i < this->spaces.size(); space_i++)
    {
        auto& space = this->spaces[space_i];
        if (!rl::does_fit<I>(space.box, box.box)) continue;
        box.box.x = rl::left_x<I>(space.box);
        box.box.y = rl::top_y<I>(space.box);
        box.page = space.page;
        // If the extra space to the right of the rect is greater than the extra space bellow...
        if (space.box.width - box.box.width > space.box.height - box.box.height)
        {
            // If there is leftover space to the right of the rect within the containing space...
            if (box.box.width < space.box.width)
            {
                // Place a space to the right that reaches down to the bottom of the rect.
                this->spaces.emplace_back(
                    rl::right_x<I>(box.box) + 1,
                    rl::top_y<I>(box.box),
                    space.box.width - box.box.width,
                    box.box.height,
                    space.page
                );
            }
            // If there is leftover space bellow the rect within the containing space...
            if (box.box.height < space.box.height)
            {
                // Place a space bellow that reaches to the right of the containing space.
                this->spaces.emplace_back(
                    rl::left_x<I>(box.box),
                    rl::bottom_y<I>(box.box) + 1,
                    space.box.width,
                    space.box.height - box.box.height,
                    space.page
                );
            }
        }
        // If the space above and bellow are the same size, or the bottom gap is bigger than the
        // right gap.
        else  // if (cur_space.width - cur_rect->width <= cur_space.height - cur_rect->height)
        {
            // If there is leftover space to the right of the rect within the containing space...
            if (box.box.width < space.box.width)
            {
                // Place a space to the right of the rect that reaches down to the bottom of the
                // containing space.
                this->spaces.emplace_back(
                    rl::right_x<I>(box.box) + 1,
                    rl::top_y<I>(box.box),
                    space.box.width - box.box.width,
                    space.box.height,
                    space.page

                );
            }
            // If there is leftover space bellow the rect within the containing space...
            if (box.box.height < space.box.height)
            {
                // Place a space bellow the rect that reaches only to the width of the rect.
                this->spaces.emplace_back(
                    rl::left_x<I>(box.box),
                    rl::bottom_y<I>(box.box) + 1,
                    box.box.width,
                    space.box.height - box.box.height,
                    space.page
                );
            }
        }
        this->spaces[space_i] = this->spaces.back();
        this->spaces.pop_back();
        std::sort(
            this->spaces.begin(),
            this->spaces.end(),
            [](rl::pack_space<I> a, rl::pack_space<I> b)
            {
                return rl::max(a.box.width, a.box.height) > rl::max(b.box.width, b.box.height);
            }
        );
        return true;
    }
    return false;
}

template<rl::signed_integral I>
constexpr bool rl::Packer<I>::tryPlaceExpandBin(rl::pack_box<I>& box)
{
    auto place_box_right = [&]()
    {
        box.box.x = this->top_page_width;
        box.box.y = 0;
        box.page = this->top_page_i;
        this->top_page_width += box.box.width;
        if (box.box.height < this->top_page_height)
        {
            spaces.emplace_back(
                rl::left_x<I>(box.box),
                box.box.height,
                box.box.width,
                this->top_page_height - box.box.height,
                this->top_page_i
            );
        }
        if (this->top_page_i == 0)
        {
            this->width = this->top_page_width;
        }
    };
    auto place_box_bellow = [&]()
    {
        box.box.x = 0;
        box.box.y = this->top_page_height;
        box.page = this->top_page_i;
        this->top_page_height += box.box.height;
        if (box.box.width < this->top_page_width)
        {
            spaces.emplace_back(
                box.box.width,
                rl::top_y<I>(box.box),
                box.box.height,
                this->top_page_width - box.box.width,
                this->top_page_i
            );
        }
        if (this->top_page_i == 0)
        {
            this->height = this->top_page_height;
        }
    };
    const auto fits_right = this->top_page_width + box.box.width <= this->max_bin_width;
    const auto fits_bellow = this->top_page_height + box.box.height <= this->max_bin_height;
    /*
        Weight the placement choice based on the placed bin has a larger width or height.
    */
    if (fits_bellow && this->top_page_height <= this->top_page_width)
    {
        place_box_bellow();
        return true;
    }
    else if (fits_right && this->top_page_width <= this->top_page_height)
    {
        place_box_right();
        return true;
    }
    /*
        If the weigted conditions don't pass, try them again without the weights.
    */
    else if (fits_bellow)
    {
        place_box_bellow();
        return true;
    }
    else if (fits_right)
    {
        place_box_right();
        return true;
    }
    return false;
}

template<rl::signed_integral I>
constexpr void rl::Packer<I>::createSpacesFromLeftoverPage()
{
    if (this->top_page_width < this->max_bin_width)
    {
        this->spaces.emplace_back(
            this->top_page_width,
            0,
            this->max_bin_width - this->top_page_width,
            this->top_page_height,
            this->top_page_i
        );
    }
    if (this->top_page_height < this->max_bin_height)
    {
        this->spaces.emplace_back(
            0,
            this->top_page_height,
            this->max_bin_width,
            this->max_bin_height - this->top_page_height,
            this->top_page_i
        );
    }
}

template<rl::signed_integral I>
constexpr void rl::Packer<I>::placeNewPage(rl::pack_box<I>& box)
{
    if (!this->GetIsEmpty())
    {
        this->top_page_i++;
    }
    box.box.x = 0;
    box.box.y = 0;
    box.page = this->top_page_i;
    if (this->top_page_i == 0)
    {
        this->width = box.box.width;
        this->height = box.box.height;
    }
    else
    {
        this->width = this->max_bin_width;
        this->height = this->max_bin_height;
    }
    this->top_page_width = box.box.width;
    this->top_page_height = box.box.height;
}

template<rl::signed_integral I>
constexpr void rl::Packer<I>::Pack(const std::span<rl::pack_box<I>> boxes)
{
    if (!this->GetIsInitialized())
    {
        throw std::runtime_error("Packer not initialized");
    }
    if (boxes.size() == 0) return;

    for (auto& box : boxes)
    {
        if (rl::is_degenerate(box.box))
        {
            throw std::runtime_error("degenerate pack_box in Packer pack");
        }
    }
    std::sort(
        boxes.begin(),
        boxes.end(),
        [](rl::pack_box<I> a, rl::pack_box<I> b)
        {
            return rl::max(a.box.width, a.box.height) > rl::max(b.box.width, b.box.height);
        }
    );
    std::size_t box_i = 0;
    auto box = boxes.data() + box_i++;
    if (box->box.width > this->max_bin_width || box->box.height > this->max_bin_height)
    {
        throw std::runtime_error("one or more boxes do not fit in bin");
    }
    this->ReserveSpaces(boxes.size());
    this->placeNewPage(*box);
    auto next_box = [&]() { box = boxes.data() + box_i++; };
    for (; box_i <= boxes.size(); next_box())
    {
        if (this->tryPlaceSpace(*box)) continue;
        if (this->tryPlaceExpandBin(*box)) continue;
        this->createSpacesFromLeftoverPage();
        this->placeNewPage(*box);
    }
}