#include <iostream>
#include "wiki.hpp"


int main() {

    std::cout << "\e[32m---ENTERING MAIN---\e[0m" << std::endl;

    std::string Wikiname = "personal_notes";
    //std::cin >> Wikiname;

    Wiki *Final_Notes = new Wiki(Wikiname);
    Final_Notes->read("personal_notes.md");


    std::cout << Final_Notes << std::endl;
    
    std::cout << "\e[32m---EXITING MAIN---\e[0m" << std::endl;
    return 0;
}