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
            void reserveSpaces(std::size_t box_count);
            bool tryPlaceSpace(rl::pack_box<I>& box);
            bool tryPlaceExpandBin(rl::pack_box<I>& box);
            void createSpacesFromLeftoverPage();
            void placeNewPage(rl::pack_box<I>&& box);

        public:
            constexpr Packer() noexcept = default;
            Packer(I max_bin_width, I max_bin_height);

            void Initialize(I max_bin_width, I max_bin_height);
            bool GetIsInitialized() const noexcept;
            bool GetIsEmpty() const noexcept;
            void ReserveSpaces(std::size_t box_count);
            void TrimToFitSpaces();
            const std::vector<rl::pack_space<I>>& GetSpaces() const noexcept;
            I GetPageCount() const noexcept;
            I GetWidth() const noexcept;
            I GetHeight() const noexcept;
            I GetMaxPageWidth() const noexcept;
            I GetMaxPageHeight() const noexcept;
            I GetTopPageWidth() const noexcept;
            I GetTopPageHeight() const noexcept;
            void Pack(std::span<rl::pack_box2<I>>& boxes);
    };
}

#include <rlm/cellular/detail/Packer.inl>