#pragma once

#include <array>
#include <utility>
#include <string_view>
#include <unordered_map>
#include <string>


namespace mrse{
    
    using d_Type = uint64_t;

    enum INPUT_FLAGS{

        RAW_INPUT,
        CAPITALIZED_INPUT

    };

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

    inline static const std::unordered_map<char, std::string> morse_dictionary_map = 
    {
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
    };



    struct dd_struct{
        char symb;
        int size;
        d_Type notation;
    };


    inline static constexpr const std::array<dd_struct, 4> ditdah_dictionary{{
        {'.', 1, 0b1}, {'-', 2, 0b11}, {' ', 1, 0b00}, {'/', 3, 0b111}
    }};
}

