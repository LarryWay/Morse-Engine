#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <optional>

#include "config.hpp"

namespace mrse{

    namespace core{

        namespace helpers{

            template <typename T>
            int find_first_bit_pos(const T s) noexcept;

            template <typename T>
            std::optional<char> decode_with_anchor(const int anchor, const int shifter, const T stream) noexcept;

        }


        std::vector<char> decode_binary_stream(const std::vector<mrse::d_Type>& streams);

    }
}