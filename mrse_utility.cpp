#pragma once

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

#include "dictionary.hpp"

namespace mrse{

    void binary_print(auto num){
        std::cout << std::bitset<sizeof(num) * 8>(num) << std::endl;
    }

}
