#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <utility>

#include "dictionary.hpp"

namespace mrse{


    // Version 2.0
    [[nodiscard]] std::string translate_letter(char c) noexcept{
        for(const auto set : mrse::morse_dictionary){
            if(set.first == c) return std::string{set.second};
        }
        std::exit(EXIT_FAILURE);
    }

    const char translate_morse_letter(const std::string& m){
        for(const auto set : mrse::morse_dictionary){
            if(set.second == m){
                return set.first;
            } 
        }
        std::exit(EXIT_FAILURE);
    }



    // Version 2.0
    [[nodiscard]] std::string translate_phrase(const std::string& input){
        std::string uppercase_input;
        std::transform(input.cbegin(), input.cend(), uppercase_input.begin(), ::toupper);
        std::vector<std::string> translation_list(uppercase_input.length());

        std::transform(uppercase_input.cbegin(), 
                    uppercase_input.cend(), 
                    translation_list.begin(), 
                    [](const char c){ return translate_letter(c);});
        
        std::string return_string = std::accumulate(std::next(translation_list.begin()), 
                                                    translation_list.end(), 
                                                    *translation_list.begin(),
                                                    [](std::string a, std::string b){
                                                        return std::move(a) + ' ' + b;
                                                    });

        return return_string;
    }







    // Version 2.1
    [[nodiscard]] std::string translate_morse(std::string input){
        input += ' ';
        std::vector<char> char_vec(input.cbegin(), input.cend());  
        std::vector<char> translated_vec;
        int pivot = 0;

        for(int x = 0 ; x < char_vec.size() ; x++){
            if(char_vec.at(x) == ' '){
                char translated_char;
                    translated_char = translate_morse_letter(std::string{char_vec.begin() + pivot, char_vec.begin() + x}); 
                translated_vec.push_back(translated_char);
                pivot = x + 1;
            }
        }

        return std::string{translated_vec.begin(), translated_vec.end()};
    }



}

// TODO: Optimize functions that take a string as an arguement