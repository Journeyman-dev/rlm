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

template<rl::unsigned_integral H>
constexpr H rl::hash_combine(H hash_a, H hash_b) noexcept
{
    return 
        hash_a ^
        (
            hash_b + 
            0x9e3779b9 + 
            (hash_b << 6) + 
            (hash_b >> 2)
        );
}

template<rl::unsigned_integral H, rl::unsigned_integral... Hs>
    requires std::conjunction_v<std::is_same<H, Hs>...>
constexpr H hash_combine(const H hash_a, const H hash_b, const Hs... hash_n) noexcept
{
    return
        rl::hash_combine(
            rl::hash_combine(hash_a, hash_b),
            hash_n...
        );
}