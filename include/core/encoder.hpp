#include <vector>
#include <cmath>
#include <utility>
#include <assert.h>

#include "config.hpp"

namespace mrse{

    namespace core{

        namespace helpers{
            
            int required_bits_to_translate(const std::string& input) noexcept;

            int num_of_dtypes_needed(float _required_bits) noexcept;

            void encode_by_bitshift(d_Type& stream, const std::string& str) noexcept;

        }

        std::vector<d_Type> encode_morse_phrase(const std::string& input);


    }


}