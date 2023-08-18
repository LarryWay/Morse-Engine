#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <iostream>

#include "dictionary.hpp"



namespace mrse{

    using d_Type = uint64_t;

    int _required_bits_to_translate(const std::string& input){
        int counter = 0;
        for(const char c : input){
            switch(c){
                case '.': counter++; break;     // counts bits required for a '.' (1)
                case '-': counter += 2; break;  // counts bits required for a '-' (2)
                case ' ': counter += 2; break;  // counts bits required for a ' ' (2)
            }
            counter++;  // counts bits for space between characters (1) 
        }

        return (counter - 1);  //  -1 to ignore last "space between characters", not needed
    }



    int _num_of_dtypes_needed(float _required_bits){  // calculates number of d_Types needed to contain encoded message 
        float bits_per_dtype = _required_bits / (sizeof(d_Type) * 8);
        if(bits_per_dtype == floor(bits_per_dtype)){
            return bits_per_dtype;
        }
        return (floor(bits_per_dtype) + 1);
    }



    void _encode_by_bitshift(d_Type& stream, const std::string& str){  // endcoding algorithm to convert dit-dahs to binary
        for(char c : str){
            if(c == '.'){
                stream = (stream | 0b1) << 2;  // marks a '.' as a "1" in binary
            }else if(c == '-'){
                stream = ((stream << 1) | 0b11) << 2;  // marks a '-' as a "11" in binary
            }else if(c == ' '){
                stream = stream << 2;  // marks a ' ' as a "00" in binary
            }
        }
    }



    std::vector<d_Type> encode_morse(const std::string& input){
        std::vector<d_Type> return_vec(_num_of_dtypes_needed(_required_bits_to_translate(input)));
        std::fill(return_vec.begin(), return_vec.end(), 0);

        // TODO: Find a way to split the input into small enough chunks to fit in a d_type

        return return_vec;
    }



}




/*

NOTES
    uint64_t indexer = 1;
    indexer = indexer << ((sizeof(d_Type) * 8) - 1);    USE FOR DECODER FILE

*/