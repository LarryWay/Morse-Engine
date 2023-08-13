#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <string_view>
#include <numeric>

constexpr const std::array<std::pair<char, std::string_view>, 27> dictionary{{
    {'A',".-"}, {'B',"-..."}, {'C',"-.-."},
    {'D',"-.."}, {'E',"."}, {'F',"..-."},
    {'G',"--."}, {'H',"...."}, {'I',".."},
    {'J',".---"}, {'K',"-.-"}, {'L',".-.."},
    {'M',"--"}, {'N',"-."}, {'O',"---"},
    {'P',".--."}, {'Q',"--.-"}, {'R',".-."},
    {'S',"..."}, {'T',"-"}, {'U',"..-"},
    {'V',"...-"}, {'W',".--"}, {'X',"-..-"},
    {'Y',"-.--"}, {'Z',"--.."}, {' ',"/"},
}};

[[nodiscard]] std::string translate_letter(char c){
    for(const auto set : dictionary){
        if(set.first == c) return std::string{set.second};
    }

    return "####";   // THROW ERROR
}



[[nodiscard]] std::string translate_phrase(std::string input){
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    std::vector<std::string> translation_list(input.length());

    std::transform(input.cbegin(), 
                   input.cend(), 
                   translation_list.begin(), 
                   [](const char c){
                        return translate_letter(c);
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

    return '#'; // THROW ERROR
}


// Version 2.0
[[nodiscard]] std::string translate_morse(std::string input){
    input += ' ';
    std::vector<char> char_vec(input.cbegin(), input.cend());  
    std::vector<char> translated_vec;
    int pivot = 0;

    for(int x = 0 ; x < char_vec.size() ; x++){
        if(char_vec.at(x) == ' '){
            translated_vec.push_back(translate_morse_letter(std::string{char_vec.begin() + pivot, char_vec.begin() + x}));
            if (x > char_vec.size() - 2) break;
            if(char_vec.at(x + 1) == ' '){
                translated_vec.push_back(' ');
                x += 2;
                pivot = x + 1;
                continue;
            }
            pivot = x + 1;
        }
    }

    return std::string{translated_vec.begin(), translated_vec.end()};
}

//Version 2.1
[[nodiscard]] std::string translate_morse_v21(std::string input){
    input += ' ';
    std::vector<char> char_vec(input.cbegin(), input.cend());  
    std::vector<char> translated_vec;
    int pivot = 0;

    for(int x = 0 ; x < char_vec.size() ; x++){
        if(char_vec.at(x) == ' '){
            translated_vec.push_back(translate_morse_letter(std::string{char_vec.begin() + pivot, char_vec.begin() + x}));
            pivot = x + 1;
        }
    }

    return std::string{translated_vec.begin(), translated_vec.end()};
}


/*
TODO:
 - add error handling support to the translate_letter function
   and the translate_morse_letter function

*/
