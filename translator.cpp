#include <iostream>
#include <string>
#include <string_view>

#include <vector>
#include <array>

#include <utility>
#include <numeric>


constexpr const std::array<std::pair<char, std::string_view>, 37> dictionary{{
    {'A',".-"}, {'B',"-..."}, {'C',"-.-."},
    {'D',"-.."}, {'E',"."}, {'F',"..-."},
    {'G',"--."}, {'H',"...."}, {'I',".."},
    {'J',".---"}, {'K',"-.-"}, {'L',".-.."},
    {'M',"--"}, {'N',"-."}, {'O',"---"},
    {'P',".--."}, {'Q',"--.-"}, {'R',".-."},
    {'S',"..."}, {'T',"-"}, {'U',"..-"},
    {'V',"...-"}, {'W',".--"}, {'X',"-..-"},
    {'Y',"-.--"}, {'Z',"--.."}, {' ',"/"},
    {'1',".----"}, {'2',"..---"}, {'3',"...--"},
    {'4',"....-"}, {'5',"....."}, {'6',"-...."},
    {'7',"--..."}, {'8',"---.."}, {'9',"----."},
    {'0',"-----"} 
}};


// Version 2.0
[[nodiscard]] std::string translate_letter(char c){
    for(const auto set : dictionary){
        if(set.first == c) return std::string{set.second};
    }

    throw std::domain_error("Used a character that does not have a proper translation");
}



// Version 2.0
[[nodiscard]] std::string translate_phrase(std::string input){
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    std::vector<std::string> translation_list(input.length());

    std::transform(input.cbegin(), 
                   input.cend(), 
                   translation_list.begin(), 
                   [](const char c){
                        try{
                            return translate_letter(c);
                        }catch(std::domain_error& e){
                            std::cout << e.what() << std::endl;
                            std::exit(EXIT_FAILURE);
                        }
                    });
    
    std::string return_string = std::accumulate(std::next(translation_list.begin()), 
                                                translation_list.end(), 
                                                *translation_list.begin(),
                                                [](std::string a, std::string b){
                                                    return std::move(a) + ' ' + b;
                                                });

    return return_string;
}



const char translate_morse_letter(std::string m){
    for(const auto set : dictionary){
        if(set.second == m){
            return set.first;
        } 
    }

    throw std::domain_error("Used a morse character that does not have a proper translation");
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
            try{
                translated_char = translate_morse_letter(std::string{char_vec.begin() + pivot, char_vec.begin() + x}); 
            }catch(std::domain_error& e){
                std::cout << e.what() << std::endl;
                std::exit(EXIT_FAILURE);
            }
            translated_vec.push_back(translated_char);
            pivot = x + 1;
        }
    }

    return std::string{translated_vec.begin(), translated_vec.end()};
}
