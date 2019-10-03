#include "hashFunction.h"
#include "tests.h"

void readConsole();

int main() {
    int input{};

    while(true){
        std::cin >> input;
        switch (input){
            case 0:
                readConsole();
                break;
            case 1:
                oneSymb();
                break;
            case 2:
                bigString();
                break;
            case 3:
                oneDif();
                break;
            case 4:
                konstitucija();
                break;
            case 5:
                pairManyDif();
                break;
            case 6:
                pairOneDif();
                break;
            case 9:
                return 0;
            default:
                return 0;
        }
    }
}

void readConsole(){
    std::string inpStr{};
    std::getline(std::cin, inpStr);
    std::getline(std::cin, inpStr);
    std::cout << hashAlgo(inpStr) << std::endl;
}