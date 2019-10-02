#include <iostream>
#include <vector>

#include "hashFunction.h"

int main() {
    std::string startData = "dsfgfgfgfgdgfggdfgfgfghyergesagaeryryhg";
    std::cin >> startData;
    std::vector<unsigned int> IntArr = convertStringToInt(startData);

//    for(auto& i: IntArr){
//        std::cout << i;
//        std::cout << std::endl;
//    }
    std::vector<std::vector<unsigned int>> pOut = makeBlocks(IntArr);

    for(auto& i: pOut){
        for(auto& j: i){
            std::cout << j;
        }
        std::cout << std::endl;
    }

    std::vector<unsigned int> rez = hashAlgo(pOut);

    for(auto& i: rez){
        std::cout << i << " ";
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}