#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "core/config.cpp"
#include "../include/validator.hpp"
#include "../include/core/core.hpp"


namespace mrse{

    std::string to_morse(const std::string& text, INPUT_FLAGS flag){
        assert(validate_ascii_phrase(text, flag));
        return core::translate_ascii_phrase(text, flag);
    }

    std::string to_ascii(const std::string& morse){
        assert(validate_morse_phrase(morse));
        return core::translate_morse_phrase(morse);
    }

    std::vector<mrse::d_Type> encode_text(const std::string& input, INPUT_FLAGS flag){
        assert(validate_ascii_phrase(input, flag) == true);
        return core::encode_morse_phrase(core::translate_ascii_phrase(input, flag));
    }

    std::string decode_binary(std::vector<mrse::d_Type> streams){
        auto vec = core::decode_binary_stream(streams);
        return core::translate_morse_phrase({vec.cbegin(), vec.cend()});
    }

}