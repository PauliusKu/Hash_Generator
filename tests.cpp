//
// Created by Paulius on 2019-10-03.
//

#include "tests.h"

void oneSymb(){
    std::string line;
    std::ifstream myfile;

    myfile.open (R"(C:\Users\Paulius\CLionProjects\Hash_Generator\testFiles\oneSymb1.txt)");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();

    myfile.open (R"(C:\Users\Paulius\CLionProjects\Hash_Generator\testFiles\oneSymb2.txt)");
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

    myfile.open (R"(C:\Users\Paulius\CLionProjects\Hash_Generator\testFiles\bigString1.txt)");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();

    myfile.open (R"(C:\Users\Paulius\CLionProjects\Hash_Generator\testFiles\bigString2.txt)");
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

    myfile.open (R"(C:\Users\Paulius\CLionProjects\Hash_Generator\testFiles\oneDif1.txt)");
    if (myfile.is_open()){
        while (getline(myfile, line))
            std::cout << hashAlgo(line) << std::endl;
        myfile.close();
    }
    myfile.close();

    myfile.open (R"(C:\Users\Paulius\CLionProjects\Hash_Generator\testFiles\oneDif2.txt)");
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

    myfile.open (R"(C:\Users\Paulius\CLionProjects\Hash_Generator\testFiles\konstitucija.txt)");
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