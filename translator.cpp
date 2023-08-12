#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <array>
#include <string_view>


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

std::string translate_letter(char c){
    for(const auto set : dictionary){
        if(set.first == c) return std::string{set.second};
    }

    return "####";   // THROW ERROR
}

std::string translate_phrase(std::string input){    

    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    std::string new_phrase;

    for(char c : input){
        new_phrase += translate_letter(c) + ' ';  // Try catch?
    }

    return std::string(new_phrase.begin(), new_phrase.end() - 1);
}

const char translate_morse_letter(std::string m){
    for(const auto set : dictionary){
        if(set.second == m) return set.first;
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


/*
 - rework morse translator
    - make it not space dependent / space dependent 
 - rework phrase translator
    - make more efficient with appending elements to string
    - perhaps use vector?

*/


int main(){
    
    std::string phrase = "hello this is larry";


}