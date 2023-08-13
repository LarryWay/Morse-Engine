#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>
#include <string_view>
#include <numeric>

constexpr const std::array<std::pair<char, std::string_view>, 27> dictionary{{
    {'A',".-"},
    {'B',"-..."},
    {'C',"-.-."},
    {'D',"-.."},
    {'E',"."},
    {'F',"..-."},
    {'G',"--."},
    {'H',"...."},
    {'I',".."},
    {'J',".---"},
    {'K',"-.-"},
    {'L',".-.."},
    {'M',"--"},
    {'N',"-."},
    {'O',"---"},
    {'P',".--."},
    {'Q',"--.-"},
    {'R',".-."},
    {'S',"..."},
    {'T',"-"},
    {'U',"..-"},
    {'V',"...-"},
    {'W',".--"},
    {'X',"-..-"},
    {'Y',"-.--"},
    {'Z',"--.."},
    {' '," "},
}};

[[nodiscard]] std::string translate_letter(char c){
    for(const auto set : dictionary){
        if(set.first == c) return std::string{set.second};
    }

    return "####";   // THROW ERROR
}

// Version 1
std::string translate_phrase(std::string input){    

    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    std::string new_phrase;
    //std::vector<char> new_phrase;

    for(auto c_it = input.begin() ; c_it != input.end() - 1 ; c_it++){
        new_phrase += translate_letter(*c_it) + ' ';  // Try catch?
    }

    new_phrase += translate_letter(*input.end());

    return new_phrase;
}



// Version 2
[[nodiscard]] std::string translate_phrase_v2(std::string input){
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
            std::cout << m << " -> " << set.first << std::endl;
            return set.first;
        } 
    }

    return '#'; // THROW ERROR
}

/*  Morse translator v.1
std::string translate_morse(std::string stream){
    std::string return_string;

    std::array<char, 4> ditdah_buffer;
    int dd_count = 0;

    for(int x = 0 ; x < stream.length() ; x++){

        if(stream.at(x) != ' '){
            ditdah_buffer[dd_count] = stream.at(x);
            dd_count++;
        }else{
            if (dd_count == 0) continue;
            return_string += translate_morse_letter(std::string(ditdah_buffer.begin(), ditdah_buffer.begin() + dd_count));
            std::fill(ditdah_buffer.begin(), ditdah_buffer.end(), NULL);
            dd_count = 0;
        }
    }

    return_string += translate_morse_letter(std::string(ditdah_buffer.begin(), ditdah_buffer.begin() + dd_count));
    return return_string;

}

*/


// Morse translator v.2
[[nodiscard]] std::string translate_morse_v2(std::string input){
    input += ' ';
    std::vector<char> char_vec(input.cbegin(), input.cend());  // Vector of dit-dahs
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



int main(){

}
