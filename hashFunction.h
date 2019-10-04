//
// Created by Paulius on 2019-09-14.
//

#ifndef HASH_GENERATOR_HASHFUNCTION_H
#define HASH_GENERATOR_HASHFUNCTION_H

#include <string>
#include <vector>

std::string hexToString(unsigned int n);
std::string hashFunc(std::string& pBlock1, std::string& pBlock2);
std::vector<std::string> makeBlocks(const std::string& pInp1);
std::string hashAlgo(const std::string& pInp1);

#endif //HASH_GENERATOR_HASHFUNCTION_H
