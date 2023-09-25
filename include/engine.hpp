#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "core/config.hpp"
#include "core/decoder.hpp"
#include "core/encoder.hpp"
#include "core/translator.hpp"
#include "validator.hpp"



namespace mrse{

    extern std::string to_morse(const std::string& text, INPUT_FLAGS flag = INPUT_FLAGS::RAW_INPUT);

    extern std::string to_ascii(const std::string& morse);

    extern std::vector<mrse::d_Type> encode_text(const std::string& input, INPUT_FLAGS flag = INPUT_FLAGS::RAW_INPUT);
    

    std::string decode_binary(std::vector<mrse::d_Type> streams);

}