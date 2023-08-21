#pragma once

#include <array>
#include <utility>
#include <string_view>

namespace mrse{
    constexpr const std::array<std::pair<char, std::string_view>, 37> morse_dictionary{{
        {'A',".-"}, {'B',"-..."}, {'C',"-.-."},
        {'D',"-.."}, {'E',"."}, {'F',"..-."},
        {'G',"--."}, {'H',"...."}, {'I',".."},
        {'J',".---"}, {'K',"-.-"}, {'L',".-.."},
        {'M',"--"}, {'N',"-."}, {'O',"---"},
        {'P',".--."}, {'Q',"--.-"}, {'R',".-."},
        {'S',"..."}, {'T',"-"}, {'U',"..-"},
        {'V',"...-"}, {'W',".--"}, {'X',"-..-"},
        {'Y',"-.--"}, {'Z',"--.."}, {' ',"/"},
        {'1',".----"}, {'2',"..---"}, {'3',"...--"},
        {'4',"....-"}, {'5',"....."}, {'6',"-...."},
        {'7',"--..."}, {'8',"---.."}, {'9',"----."},
        {'0',"-----"} 
    }};

    constexpr const std::array<std::pair<char, int>, 3> ditdah_dictionary{{  // TODO: MAKE USE OF THIS DICTIONARY
        {'.', 1}, {'-', 2}, {' ', 2}
    }};
}

