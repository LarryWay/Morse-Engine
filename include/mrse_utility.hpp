#pragma once

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

#include "core/config.hpp"

namespace mrse{

    void binary_print(auto num){
        std::cout << std::bitset<sizeof(num) * 8>(num) << std::endl;
    }

    void print_encoded_stream(std::vector<mrse::d_Type> vector);


}