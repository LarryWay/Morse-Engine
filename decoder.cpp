#include <iostream>
#include <vector>
#include <string>

#include "dictionary.hpp"
#include "utility.cpp"




namespace mrse{


    void _locate_start_of_stream(auto& i, const auto s){
        while(i){
            if(i & s){
                i >>= 2;
                break;
            }
            i >>= 1;
        }
    }


    std::vector<char> decode(const std::vector<mrse::d_Type>& streams){
        std::vector<char> return_vec;

        for(const auto s : streams){
            mrse::d_Type indexer = 1;
            indexer <<= ((sizeof(d_Type) * 8) - 1); 
            _locate_start_of_stream(indexer, s);


            // TODO: DECODE USING BINARY TREE


        }

        return return_vec;
    }

}
