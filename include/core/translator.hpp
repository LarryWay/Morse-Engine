#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <utility>
#include <span>
#include <ranges>

#include "config.hpp"


namespace mrse{

    namespace core{

        namespace helpers{

            const char translate_morse_letter(const std::span<char>& span);

        }

        [[nodiscard]] std::string translate_ascii_letter(char c) noexcept;

        char translate_morse_letter(const std::string& m);

        [[nodiscard]] std::string translate_ascii_phrase(const std::string& input, INPUT_FLAGS flag = INPUT_FLAGS::RAW_INPUT);

        [[nodiscard]] std::string translate_morse_phrase(const std::string& input);

    }

}