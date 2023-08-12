#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <array>


struct Parcel{

    bool prev;
    bool curr;
    bool next;

    Parcel(bool p, bool c, bool n) : prev(p), curr(c), next(n) { }

    char get_char(){
        if(prev || next && !curr) return NULL;
        if(curr && next) return '-';
        if(!(prev || next) && curr) return '.';
        if(!prev && !curr && !next) return ' ';
        else return 'X';
    }

};

std::vector<char> decode(uint32_t stream){
    uint32_t indexer = 0b10000000'00000000'00000000'00000000;
    bool cache = 0;

    while(indexer != 0){
        if(indexer & stream){
            break;
        }
        indexer = indexer >> 1;
    }

    std::vector<char> symbols;

    while(indexer != 0){
        Parcel parcel(((indexer << 1) & stream), (indexer & stream), ((indexer >> 1) & stream));
        if(parcel.prev && parcel.curr){
            indexer = indexer >> 1;
            continue;
        }

        symbols.push_back(parcel.get_char());

        indexer = indexer >> 1;
    }

    return symbols;
}

uint32_t encode(std::string input){
    uint32_t stream = 0b00000000'00000000'00000000'00000000;

    for(char c : input){
        if(c == '.'){
            stream = (stream | 0b1) << 2;
        }else if(c == '-'){
            stream = ((stream << 1) | 0b11) << 2;
        }else if(c == ' '){
            stream = stream << 2;
        }
    }

    return stream;
}

int main(){

    /*
    uint32_t stream = 0b00000000'00000000'00000000'00000000;

    std::string input = ". -.. -.";

    for(char c : input){
        if(c == '.'){
            stream = (stream | 0b1) << 2;
        }else if(c == '-'){
            stream = ((stream << 1) | 0b11) << 2;
        }else if(c == ' '){
            stream = stream << 2;
        }
    }

    uint32_t indexer = 0b10000000'00000000'00000000'00000000;
    bool cache = 0;

    while(indexer != 0){
        if(indexer & stream){
            std::cout << std::bitset<32>(indexer) << '\n';
            break;
        }
        indexer = indexer >> 1;
    }
    std::cout << std::bitset<32>(stream) << std::endl;


    std::vector<char> symbols;

    while(indexer != 0){
        Parcel parcel(((indexer << 1) & stream), (indexer & stream), ((indexer >> 1) & stream));
        if(parcel.prev && parcel.curr){
            indexer = indexer >> 1;
            continue;
        }

        symbols.push_back(parcel.get_char());

        indexer = indexer >> 1;
    }

    for(char c : symbols){
        std::cout << c;
    }
    */
   uint32_t data = encode(std::string{". -. .- --"});
   std::cout << std::bitset<32>(data) << '\n';

   for(char c : decode(data)){
    std::cout << c;
   }


}