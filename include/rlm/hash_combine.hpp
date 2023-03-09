// SPDX-FileCopyrightText: 2005-2014 Daniel James
//
// SPDX-License-Identifier: BSL-1.0

/*
    The following functions are based on the Boost C++ Libraries.
    
    https://www.boost.org/
*/

#pragma once

#include <rlm/concepts.hpp>
#include <concepts>
#include <type_traits>

namespace rl
{
    template<rl::unsigned_integral H>
    constexpr H hash_combine(H hash_a, H hash_b) noexcept;

    template<rl::unsigned_integral H, rl::unsigned_integral... Hs>
        requires std::conjunction_v<std::is_same<H, Hs>...>
    constexpr H hash_combine(const H hash_a, const H hash_b, const Hs... hash_n) noexcept;
}

#include <rlm/detail/hash_combine.inl>