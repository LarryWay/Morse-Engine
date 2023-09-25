#pragma clang diagnostic ignored "-Wpragma-once-outside-header"
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <utility>
#include <span>
#include <ranges>

#include "config.cpp"

namespace mrse{

    namespace core{


        namespace helpers{

            
            // Copy of translate_morse_letter, but uses span instead
            const char translate_morse_letter(const std::span<char>& span){
                for(const auto& set : mrse::morse_dictionary){
                    if(std::equal(set.second.cbegin(), set.second.cend(), span.begin(), span.end())){
                        return set.first;
                    } 
                }
                std::cerr << "Morse does not have a proper translation: \"" << std::string{span.begin(), span.end()} << "\"" << std::endl;
                std::cerr << "\t- Function called: mrse::helpers::translate_morse_letter" << std::endl;
                std::exit(EXIT_FAILURE);
            }
            


        }




        // Version 2.0
        [[nodiscard]] std::string translate_ascii_letter(char c) noexcept{
            for(const auto& set : mrse::morse_dictionary){
                if(set.first == c) return std::string{set.second};
            }
            std::cerr << "Letter does not have a proper translation: '" << c << "'" << std::endl;
            std::exit(EXIT_FAILURE);
        }


        char translate_morse_letter(const std::string& m){
            for(const auto& set : mrse::morse_dictionary){
                if(set.second == m){
                    return set.first;
                } 
            }
            std::cerr << "Morse does not have a proper translation: \"" << m << "\"" << std::endl;
            std::exit(EXIT_FAILURE);
        }



        // Version 3.1 - INPUT_FLAGS optimization
        [[nodiscard]] std::string translate_ascii_phrase(const std::string& input, INPUT_FLAGS flag = INPUT_FLAGS::RAW_INPUT){
            std::vector<char> capital_letters(input.size());
            std::span<const char> characters;
            std::vector<std::string> translation_list(input.size());
            
            if(flag == INPUT_FLAGS::RAW_INPUT){
                std::transform(input.cbegin(), input.cend(), capital_letters.begin(), ::toupper);
                characters = {capital_letters.begin(), capital_letters.end()};
                
            }else if(flag == INPUT_FLAGS::CAPITALIZED_INPUT){
                characters = {input.begin(), input.end()};
            }


            std::transform(characters.begin(), 
                        characters.end(), 
                        translation_list.begin(), 
                        [](char c){ return translate_ascii_letter(c);});


            std::string return_string{std::move(*translation_list.begin())};
            for(auto it = translation_list.begin() + 1 ; it != translation_list.end() ; it++){
                return_string += ' ' + std::move(*it);
            }

            return return_string;
        }



        
        // Version 3.0 - implemented use of span to prevent unecessary string copies
        // Note: Assumes the last character of input is not ' '
        [[nodiscard]] std::string translate_morse_phrase(const std::string& input){
            std::string appended_input = input + ' ';
            std::vector<char> translated_vec;
            int pivot = 0;
            for(size_t x = 0 ; x < appended_input.size() ; x++){
                if(appended_input.at(x) == ' '){
                    char translated_char = helpers::translate_morse_letter(std::span<char>{appended_input.begin() + pivot, appended_input.begin() + x}); 
                    translated_vec.push_back(translated_char);
                    pivot = x + 1;
                }
            }

            return std::string{translated_vec.cbegin(), translated_vec.cend()};
        }
    
    }

}
