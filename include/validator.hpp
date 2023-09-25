#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <span>

#include "core/config.hpp"


namespace mrse{

    bool validate_ascii_letter(const char c);

    bool validate_ascii_phrase(const std::string& phrase, INPUT_FLAGS flag = INPUT_FLAGS::RAW_INPUT);

    bool validate_morse_phrase(const std::string& phrase);



}