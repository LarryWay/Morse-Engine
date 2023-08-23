#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

#include "dictionary.hpp"
#include "mrse_utility.cpp"




namespace mrse{

    namespace helpers{
        int longest_binary_notation(){
            const auto dd_not = (*std::max_element(ditdah_dictionary.begin(), ditdah_dictionary.end(), [](const dd_struct& a, const dd_struct& b){
                std::cout << a.notation << " " << b.notation << '\n';  // REMOVe WHEN DONE
                return a.notation < b.notation;
            })).notation;



        }


        d_Type locate_start_of_stream(const d_Type s){  // MAYBE UNUSED? (pun)
            d_Type indexer = 1;
            indexer <<= ((sizeof(d_Type) * 8) - 1);
            while(indexer){
                if(indexer & s){
                    indexer >>= 2;
                    break;
                }
                indexer >>= 1;
            }
            return indexer;
        }


        template <typename T>
        T first_active_bit_pos(const T s){
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



    }



    std::vector<char> decode(const std::vector<mrse::d_Type>& streams){
        std::vector<char> return_vec;

        for(const auto s : streams){

            // TODO: DECODE USING BINARY TREE
            //       IMPLEMENT THE HELPLER NAMESPACE IN ENCODER.CPP


        }

        return return_vec;
    }

}
