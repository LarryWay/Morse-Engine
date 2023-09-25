#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

#include "../include/mrse_utility.hpp"
#include "core/config.cpp"

namespace mrse{
    
    void print_encoded_stream(std::vector<d_Type> vector){
        for(auto binary : vector){
            binary_print(binary);
        }
    }

}
