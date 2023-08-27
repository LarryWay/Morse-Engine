#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <optional>

#include "dictionary.hpp"
#include "mrse_utility.cpp"




namespace mrse{

    namespace helpers{

        template <typename T>
        int find_first_bit_pos(const T s){
            std::make_unsigned_t<T> indexer = 1;
            int cnt = 0;
            indexer <<= ((sizeof(T) * 8) - 1);
            while(indexer){
                if(indexer & s){
                    break;
                }
                indexer >>= 1;
                cnt++;
            }
            return ((sizeof(T) * 8) - cnt);
        }


        template <typename T>
        std::optional<char> decode_with_anchor(const int anchor, const int shifter, const T stream){  // assume stream is unsigned
            T s = stream;
            s <<= ((sizeof(T) * 8) - anchor);
            s >>= ((sizeof(T) * 8) - (anchor - shifter + 1));

            for(const auto& dd : ditdah_dictionary){
                if(dd.notation == s){
                    if (dd.symb == ' ' && (anchor - shifter) < dd.size){
                        return {};               
                    }
                    return dd.symb;
                } 
            }
            return {};
        }


    }




    std::vector<char> decode_stream(const std::vector<mrse::d_Type>& streams){
        std::vector<char> return_vec;

        for(const auto s : streams){
            int anchor = helpers::find_first_bit_pos(s) - 1;  //inclusive
            int shifter = anchor;   // inclusive
            bool prev_bit = false;
            for(mrse::d_Type indexer = (static_cast<mrse::d_Type>(1) << anchor - 2) ; indexer != 0 ; indexer >>= 1){
                if(prev_bit != static_cast<bool>(indexer & s)){   
                    auto op = helpers::decode_with_anchor(anchor, shifter, s);
                    if(op.has_value()) return_vec.push_back(op.value());
                    anchor = shifter - 1;
                }
                shifter--;
                prev_bit = indexer & s;
            }
            auto op = helpers::decode_with_anchor(anchor, shifter, s);
            if(op.has_value()) return_vec.push_back(op.value());

        }

        return return_vec;
    }

}
