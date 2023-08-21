#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <iostream>
#include <utility>

#include "dictionary.hpp"



namespace mrse{

    using d_Type = uint64_t;

    int _required_bits_to_translate(const std::string& input){  // TODO: FIX THIS FUNCTION TO RETURN ACCURATE NUMBERS
        int counter = 0;
        for(const char c : input){
            switch(c){
                case '.': counter++; break;     // counts bits required for a '.' (1)
                case '-': counter += 2; break;  // counts bits required for a '-' (2)
                case ' ': counter += 2; break;  // counts bits required for a ' ' (2)
                case '/': counter += 3; break;  // counts bits required for a '/' (3)
            }
            counter += 2;  // counts bits for space between characters (1) 
        }

        return (counter);  //  -1 to ignore last "space between characters", not needed
    }



    int _num_of_dtypes_needed(float _required_bits){  // calculates number of d_Types needed to contain encoded message 
        float bits_per_dtype = (_required_bits / (sizeof(d_Type) * 8));
        
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
            }else if(c == '/'){  // *** CAUTION: assumes a ' ' follows the '/' ***  SHOULD MAKE MORE RESILIANT
                stream = ((stream << 2) | 0b111) << 2;  // marks a '/' as a "111" in binary
            }
        }
        stream = stream >> 1;
    }



    std::vector<d_Type> encode_morse(const std::string& input){
        std::vector<d_Type> return_vec(_num_of_dtypes_needed(_required_bits_to_translate(input)));  // Increment by one to guarentee space
        std::fill(return_vec.begin(), return_vec.end(), 0);

        const auto i_size = input.size();
        const auto rv_size = return_vec.size();
        const auto block_size = floor(i_size / rv_size);
        const auto block_remainder = i_size % rv_size;
        
        std::vector<std::pair<int, int>> split_locs(rv_size);
        const auto sp_size = split_locs.size();
        for(int x = 0 ; x < sp_size - 1 ; x++){
            split_locs.at(x) = { block_size * x  ,  block_size * (x + 1)};
        }
        split_locs.at(sp_size - 1) = { block_size * (sp_size - 1)  , block_size * sp_size + block_remainder};

        /*  
        USE FOR DEBUG
        for(auto p : split_locs){
            std::cout << std::string{input.begin() + p.first, input.begin() + p.second} << '\t' << "(" << p.first << "," << p.second << ")" << '\n';
        }
        */

        for(int x = 0 ; x < rv_size ; x++){
            _encode_by_bitshift(return_vec.at(x), {input.begin() + split_locs.at(x).first, input.begin() + split_locs.at(x).second});
        }

        return return_vec;
    }



}




/*

NOTES
    uint64_t indexer = 1;
    indexer = indexer << ((sizeof(d_Type) * 8) - 1);    USE FOR DECODER FILE

*/