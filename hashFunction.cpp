//
// Created by Paulius on 2019-09-14.
//

#include <iostream>
#include "hashFunction.h"

std::string hashAlgo(const std::string& pInp1){
    std::vector<std::string> blocks = makeBlocks(pInp1);
    std::string seed = "FCB469D2";

    for(auto& value: blocks){
        seed = hashFunc(value, seed);
    }
    return seed;
}

std::vector<std::string> makeBlocks(const std::string& pInp1){
    std::vector<std::string> blocks;
    for(unsigned long i = 0; i < pInp1.size(); i++)
        blocks.push_back(pInp1.substr(i, 8));
    return blocks;
}

std::string hashFunc(std::string& pBlock1, const std::string& pBlock2){
    unsigned int hash = 0xAAAAAAAA;
    unsigned long i = 0;

    pBlock1 += pBlock2;

    for (i = 0; i < pBlock1.size(); ++pBlock1[i], ++i){
        if ((i & 1u) == 0)
            hash ^= hash << 7u ^ (pBlock1[i]) * (hash >> 3u);
        else hash ^= ~((hash << 11u) + ((pBlock1[i] + 0u) ^ (hash >> 5u)));
    }

    return hexToString(hash);
}

std::string hexToString(unsigned int hex){
    std::string str {"00000000"};
    int itr = 0;

    do{
        str[itr] = "0123456789ABCDEF"[hex % 16];
        hex >>= 4u;
        itr++;
    } while(hex);

    return str;
}