#include <iostream>
#include <random>



int main() {

    std::cout << "\e[32m---ENTERING MAIN---\e[0m" << std::endl;

    std::random_device rand_dev;

    std::default_random_engine e1(rand_dev());

    std::uniform_real_distribution<float> uniform_dist(0, 2*3.14);

    float mean = uniform_dist(e1);

    std::cout << "Random mean is " << mean << std::endl;
    
    
    std::cout << "\e[32m---EXITING MAIN---\e[0m" << std::endl;
    return 0;
}