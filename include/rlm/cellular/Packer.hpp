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

namespace rl
{
    template<rl::signed_integral I = int>
    struct cell_box2;

    template<rl::signed_integral I = int, typename ID = unsigned int>
    struct pack_box2;

    template<rl::signed_integral I = int>
    class Packer
    {
        private:
            std::vector<rl::cell_box2<I>> spaces = std::vector<rl::cell_box2<I>>();
            I page_count = 0;
            I width = 0;
            I height = 0;
            I max_page_width = 0;
            I max_page_height = 0;
            I top_page_width = 0;
            I top_page_height = 0;

        public:
            constexpr Packer() noexcept = default;
            Packer(I max_page_width, I max_page_height) noexcept;

            void Initialize(I max_page_width, I max_page_height);
            bool GetIsInitialized() const noexcept;
            bool GetIsEmpty() const noexcept;
            const std::vector<rl::cell_box2<I>>& GetSpaces() const noexcept;
            I GetPageCount() const noexcept;
            I GetWidth() const noexcept;
            I GetHeight() const noexcept;
            I GetMaxPageWidth() const noexcept;
            I GetMaxPageHeight() const noexcept;
            I GetTopPageWidth() const noexcept;
            I GetTopPageHeight() const noexcept;
            void Pack(const std::span<rl::pack_box2<I>>& pack_boxes);
    };
}

#include <rlm/cellular/detail/Packer.inl>