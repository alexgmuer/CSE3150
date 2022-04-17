#include <iostream>
#include <iomanip>
#include "Simulator.hpp"

int main(int argc,char* argv[]) {
   Simulator* s = new Simulator;
   s->read(argv[1]);
   // std::cout << s << std::endl;
   
   

   delete s;
   return 0;
}