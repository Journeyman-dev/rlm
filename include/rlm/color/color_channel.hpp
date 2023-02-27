#pragma once

#include <rlm/color/concepts.hpp>

namespace rl
{
    template<rl::color_channel Ca, rl::color_channel Cb>
    constexpr Ca color_channel_cast(Cb channel) noexcept;

    template<rl::color_channel C>
    constexpr C color_channel_max_value();

    template<rl::color_channel C>
    constexpr C color_channel_clamp(C channel);
}

#include <rlm/color/detail/color_channel.inl>