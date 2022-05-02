#include <iostream>
#include "wiki.hpp"


int main() {

    std::cout << "\e[32m---ENTERING MAIN---\e[0m" << std::endl;

    std::string Wikiname;
    std::cin >> Wikiname;

    Wiki *Final_Notes = new Wiki(Wikiname);

    std::cout << Final_Notes << std::endl;
    
    std::cout << "\e[32m---EXITING MAIN---\e[0m" << std::endl;
    return 0;
}