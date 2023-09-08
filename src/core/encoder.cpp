#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <assert.h>

#include "config.cpp"

namespace mrse{

    namespace core{

        namespace helpers{


            int required_bits_to_translate(const std::string& input) noexcept{  
                int counter = 0;
                for(const char c : input){
                    switch(c){  
                        case ditdah_dictionary[0].symb : counter += ditdah_dictionary[0].size ; break;  // counts bits required for a '.' (1)
                        case ditdah_dictionary[1].symb : counter += ditdah_dictionary[1].size ; break;  // counts bits required for a '-' (2)
                        case ditdah_dictionary[2].symb : counter += ditdah_dictionary[2].size ; break;  // counts bits required for a ' ' (2)
                        case ditdah_dictionary[3].symb : counter += ditdah_dictionary[3].size ; break;  // counts bits required for a '/' (3)
                        default:
                            std::cerr << "unexpected symbol: \"" << c << "\" in \"required_bits_to_translate\" function"<< std::endl;  
                            std::exit(EXIT_FAILURE);
                    }
                    counter++;  // counts bits for space between characters (1) 
                }
                counter += 2;  // include starting bits
                return (counter - 1);  //  -1 to ignore last "space between characters", not needed
            }


            int num_of_dtypes_needed(float _required_bits) noexcept{  // calculates number of d_Types needed to contain encoded message 
                float bits_per_dtype = (_required_bits / (sizeof(d_Type) * 8));

                if(bits_per_dtype == floor(bits_per_dtype)){
                    return bits_per_dtype;
                }
                return (floor(bits_per_dtype) + 1);
            }   


            void encode_by_bitshift(d_Type& stream, const std::string& str) noexcept{  // endcoding algorithm to convert dit-dahs to binary
                stream = (stream | 0b1);  // starting bit indicator
                for(const char c : str){
                    for(const auto& s : ditdah_dictionary){
                        if(c == s.symb) stream = ((stream << (s.size + 1)) | s.notation);
                    }
                }
            }

    

        }



        std::vector<d_Type> encode_morse_phrase(const std::string& input){
            
            std::vector<d_Type> return_vec(helpers::num_of_dtypes_needed(helpers::required_bits_to_translate(input)));
            std::fill(return_vec.begin(), return_vec.end(), 0);

            const auto i_size = input.size();
            const auto rv_size = return_vec.size();
            const auto block_size = floor(i_size / rv_size);
            const auto block_remainder = i_size % rv_size;
            auto cnt = block_remainder;
            
            std::vector<std::pair<int, int>> split_locs(rv_size);
            const size_t sp_size = split_locs.size();
            for(size_t x = 0 ; x < sp_size ; x++){
                if(cnt){
                    split_locs.at(x) = { (block_size + 1) * x  ,  (block_size + 1) * (x + 1)};
                    cnt--;
                }else{
                    split_locs.at(x) = { block_size * x + block_remainder  ,  block_size * (x + 1) + block_remainder};
                }
                
            }

            for(size_t x = 0 ; x < rv_size ; x++){
                helpers::encode_by_bitshift(return_vec.at(x), {input.begin() + split_locs.at(x).first, input.begin() + split_locs.at(x).second});
            }

            return return_vec;
        }

    }

}
