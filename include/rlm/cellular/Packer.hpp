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
#include <rlm/cellular/pack_space.hpp>
#include <vector>
#include <span>
#include <cstddef>

namespace rl
{
    template<rl::signed_integral I>
    struct cell_box2;

    template<rl::signed_integral I, typename ID>
    struct pack_box;

    template<rl::signed_integral I>
    struct pack_space;

    template<rl::signed_integral I = int>
    class Packer
    {
        private:
            std::vector<rl::pack_space<I>> spaces = std::vector<rl::pack_space<I>>();
            I top_page_i = 0;
            I width = 0;
            I height = 0;
            I max_bin_width = 0;
            I max_bin_height = 0;
            I top_page_width = 0;
            I top_page_height = 0;

        private:
            constexpr void reserveSpaces(std::size_t box_count);
            constexpr bool tryPlaceSpace(rl::pack_box<I>& box);
            constexpr bool tryPlaceExpandBin(rl::pack_box<I>& box);
            constexpr void createSpacesFromLeftoverPage();
            constexpr void placeNewPage(rl::pack_box<I>& box);

        public:
            constexpr Packer() noexcept = default;
            constexpr Packer(I max_bin_width, I max_bin_height);

            constexpr void Initialize(I max_bin_width, I max_bin_height);
            constexpr bool GetIsInitialized() const noexcept;
            constexpr bool GetIsEmpty() const noexcept;
            constexpr void ReserveSpaces(std::size_t box_count);
            constexpr void TrimToFitSpaces();
            constexpr const std::vector<rl::pack_space<I>>& GetSpaces() const noexcept;
            constexpr I GetPageCount() const noexcept;
            constexpr I GetWidth() const noexcept;
            constexpr I GetHeight() const noexcept;
            constexpr I GetMaxPageWidth() const noexcept;
            constexpr I GetMaxPageHeight() const noexcept;
            constexpr I GetTopPageWidth() const noexcept;
            constexpr I GetTopPageHeight() const noexcept;
            constexpr void Pack(const std::span<rl::pack_box<I>> boxes);
    };
}

#include <rlm/cellular/detail/Packer.inl>