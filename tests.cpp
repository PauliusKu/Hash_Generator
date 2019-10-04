//
// Created by Paulius on 2019-10-03.
//

#include "tests.h"

#define TEST_FILES "../testFiles/"

void oneSymb(){
    std::string line;
    std::ifstream myfile;

    myfile.open (TEST_FILES "oneSymb1.txt");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();

    myfile.open (TEST_FILES "oneSymb2.txt");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();
}

void bigString(){
    std::string line;
    std::ifstream myfile;

    myfile.open (TEST_FILES "bigString1.txt");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();

    myfile.open (TEST_FILES "bigString2.txt");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();
}

void oneDif(){
    std::string line;
    std::ifstream myfile;

    myfile.open (TEST_FILES "oneDif1.txt");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();

    myfile.open (TEST_FILES "oneDif2.txt");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();
}

void konstitucija(){
    std::string line;
    std::ifstream myfile;
    std::vector <std::string> inputs{};
    double elapsed{};

    myfile.open (TEST_FILES "konstitucija.txt");
    if (myfile.is_open()){
        while (getline(myfile, line))
            inputs.push_back(line);
        myfile.close();
    }
    myfile.close();

    Timer start;
    for(auto& oneLine: inputs)
        oneLine = hashAlgo(oneLine);
    elapsed = start.elapsed();
    start.reset();

    for(auto& oneLine: inputs)
        std::cout << oneLine << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "time: " << elapsed << std::endl;
}

void pairManyDif(){
    std::string first{};
    std::string second{};

    for (unsigned int i = 0; i < 100000; i++){
        first = randomString(5);
        second = randomString(5);
        if (first == second)
            std::cout << "Same strings " << first << " " << second << std::endl;
        else{
            first = hashAlgo(first);
            second = hashAlgo(second);

            if(first == second)
                std::cout << "Very bad " << first << " " << second << std::endl;
        }
    }
    std::cout << "End of test" << std::endl;
}

void pairOneDif(){
    std::string first{};
    std::string second{};

    for (unsigned int i = 0; i < 100000; i++){
        first = randomString(5);
        second = first;
        second[randomNum(0, 4)] = randomString(1)[0];

        if (first != second) {
            first = hashAlgo(first);
            second = hashAlgo(second);

            if (first == second)
                std::cout << "Very bad " << first << " " << second << std::endl;
        } else i++;
    }
    std::cout << "End of test" << std::endl;
}

void pairOneDifStat(){
    std::string first{};
    std::string second{};

    unsigned long numOfItr = 100000;
    unsigned long diff {};
    unsigned long max = 0;
    unsigned long min = 10;
    unsigned long sum = 0;

    for (unsigned int i = 0; i < numOfItr; i++){
        first = randomString(5);
        second = first;
        second[randomNum(0, 4)] = randomString(1)[0];

        if (first != second) {
            first = hashAlgo(first);
            second = hashAlgo(second);

            if (first == second)
                std::cout << "Very bad " << first << " " << second << std::endl;

            diff = 0;
            for(unsigned long j = 0; j < first.size(); j++){
                if (first[j] != second[j])
                    diff++;
            }

            if (diff > max)
                max = diff;
            if (diff < min)
                min = diff;
            sum += diff;
        } else i++;
    }


    std::cout << "Results: " << std::endl;
    std::cout << "Max diff: " << max * 100 / 8 << std::endl;
    std::cout << "Min diff: " << min * 100 / 8 << std::endl;
    std::cout << "Average diff: " << double(sum  * 100 / 8 / numOfItr) << std::endl;
    std::cout << "End of test" << std::endl;
}