//
// Created by Paulius on 2019-09-14.
//

#ifndef HASH_GENERATOR_HASHFUNCTION_H
#define HASH_GENERATOR_HASHFUNCTION_H

#include <string>
#include <vector>

std::vector<unsigned int> convertStringToInt(std::string& pInp);
std::vector<std::vector<unsigned int>> makeBlocks(std::vector<unsigned int>& pInp);
std::vector<unsigned int> hashFunc(std::vector<unsigned int>& pInp1, std::vector<unsigned int>& pInp2);
std::vector<unsigned int> hashAlgo(std::vector<std::vector<unsigned int>>& pInpBlocks);

#endif //HASH_GENERATOR_HASHFUNCTION_H
