//
// Created by Paulius on 2019-09-14.
//

#include <iostream>
#include "hashFunction.h"

#define SIZE 10

std::vector<unsigned int> convertStringToInt(std::string& pInp){
    std::vector<unsigned int> IntArr{};

    for(auto& value: pInp){
        IntArr.push_back((int)value);
    }
    return IntArr;
}

std::vector<std::vector<unsigned int>> makeBlocks(std::vector<unsigned int>& pInp){
    std::vector<std::vector<unsigned int>> Blocks{};
    std::vector<unsigned int> EmptyBlock (SIZE, 0);
    std::vector<unsigned int> Block = EmptyBlock;

    int counter = 0;

    for(unsigned int i : pInp){
        Block[counter] = i;
        if (counter == SIZE - 1){
            Blocks.push_back(Block);
            Block = EmptyBlock;
            counter = -1;
        }
        counter++;
    }
    if (counter == 0)
        return Blocks;

    const int numOfFilled = counter;
    while(counter < SIZE - 1){
        Block[counter] = Block[counter - numOfFilled];
        counter++;
    }
    Blocks.push_back(Block);

    return Blocks;
}

std::vector<unsigned int> hashAlgo(std::vector<std::vector<unsigned int>>& pInpBlocks){
    std::vector<unsigned int> Seed {125, 11, 78, 15, 36, 2, 189, 201};

    std::cout << "Start" << std::endl;
    for(auto& value: pInpBlocks){
        Seed = hashFunc(value, Seed);
    }
    return Seed;
}

std::vector<unsigned int> hashFunc(std::vector<unsigned int>& pInp1, std::vector<unsigned int>& pInp2){
    std::vector<unsigned int> Result{};
    unsigned int rez {};

    for(unsigned int i = 0; i < SIZE; i++){
        rez = (pInp1[i] + pInp2[i])%SIZE;
        Result.push_back(rez);
        std::cout << rez << " " << pInp1[i] << " " << pInp2[i] << std::endl;
    }
    return Result;
}
//a: 8 0 9 9 2 3 2 0 1 0
//b: 8 0 9 9 2 3 8 4 9 0
