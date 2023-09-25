#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <span>

#include "core/config.cpp"

namespace mrse{


    bool validate_ascii_letter(const char c){
        try{
            std::string morse = morse_dictionary_map.at(c);
        }catch(std::out_of_range e){
            std::cerr << "ERROR: Unknown translation for ASCII letter \"" << c << "\"" << std::endl;
            return false;
        }
        return true;
    }


    // Version 1.0
    // Note: Very rough version, should condense
    // Purpose: checks if phrase only consists of characters defined in dictionary
    //          Heavy check: translator will NOT throw an error if this returns true
    bool validate_ascii_phrase(const std::string& phrase, INPUT_FLAGS flag){

        if(flag == INPUT_FLAGS::RAW_INPUT){
            std::vector<char> capital_letters(phrase.size());
            std::transform(phrase.cbegin(), phrase.cend(), capital_letters.begin(), ::toupper);
            for(const auto c : capital_letters){
                if(!validate_ascii_letter(c)) return false;
            }
            return true;
        }else if(flag == INPUT_FLAGS::CAPITALIZED_INPUT){
            for(const auto c : phrase){
                if(!validate_ascii_letter(c)) return false;
            }
            return true;
        }else{
            std::cerr << "ERROR: Improper flag in argument" << std::endl;
            return false;
        }

    }



    // Version 1.0
    // Purpose: Checks if phrase is only consisted of '.', '/', or '-' as defined in ditdah_dictionary
    //          DOES NOT check if sequences in the morse phrase are valid
    //          Light Check: translator MAY throw an error if this returns true
    bool validate_morse_phrase(const std::string& phrase){
        for(const char c : phrase){
            bool matched_char = false;
            for(const dd_struct& d : ditdah_dictionary){
                if(c == d.symb) matched_char = true;
            }
            if(!matched_char) {
                std::cerr << "ERROR: character \"" << c << "\" is not a morse character" << std::endl;
                return false;
            }
        }
        return true;
    }


}