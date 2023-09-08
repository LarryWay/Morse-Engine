#pragma once

#include <array>
#include <utility>
#include <string_view>


namespace mrse{
    
    using d_Type = uint64_t;


    inline static constexpr const std::array<std::pair<char, std::string_view>, 37> morse_dictionary{{
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

// Should use a dictionary instead



    struct dd_struct{
        char symb;
        int size;
        d_Type notation;
    };


    inline static constexpr const std::array<dd_struct, 4> ditdah_dictionary{{
        {'.', 1, 0b1}, {'-', 2, 0b11}, {' ', 1, 0b00}, {'/', 3, 0b111}
    }};
}

