//
// Created by Vladas on 2019-05-21.
//

#include "randomNum.h"
#include <random>
#include <chrono>
#include <iomanip>

std::mt19937 randomly_seeded_engine() {

    // create a seed sequence of several reasonably random values
    std::seed_seq seed_seq{(unsigned int) std::random_device{}(),
                           (unsigned int) std::chrono::system_clock::now().time_since_epoch().count(),
                           (unsigned int) std::random_device{}(),
                           (unsigned int) std::chrono::steady_clock::now().time_since_epoch().count(),
                           (unsigned int) std::random_device{}()};

    return std::mt19937(seed_seq); // note: the seed sequence provides a warm up sequence for the rng
}

double randomNum(double &a, double &b) {

    static auto rng = randomly_seeded_engine();
    static std::uniform_real_distribution<double> distribution;

    distribution.param(std::uniform_real_distribution<double>::param_type{a, b});
    return distribution(rng);
}

int randomNum(int a, int b) {

    static auto rng = randomly_seeded_engine();
    static std::uniform_int_distribution<int> distribution;

    distribution.param(std::uniform_int_distribution<int>::param_type{a, b});
    return distribution(rng);
}

double randomNum() {

    static auto rng = randomly_seeded_engine();
    static std::uniform_real_distribution<double> distribution;

    distribution.param(std::uniform_real_distribution<double>::param_type{0, 1});
    return distribution(rng);
}

char randomChar() {
    return randomNum(32, 127);
}

std::string randomString(unsigned int length){
    std::string randStr {};

    for(unsigned int i = 0; i < length; i++){
        randStr += randomChar();
    }
    return randStr;
}
