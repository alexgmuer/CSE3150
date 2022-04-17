#include <fstream>
#include <iostream>
#include <string>
// Define data structure inside each node as a class
// Data structure needs to contain the type 



//template <class T>
class Simulator {
    public:
        // Will probably need some sort of Node structure
        class Node {
            friend class Simulator;
            //T data;
            Node* next;
                // Constructor
                Node() {

                }
                
                // Destructor
                // Probably not needed
                //~Node() {
                    
                //}
            
            // Store whether node is generator, buffer, server, dispatcher
            // Store the next node it is connected to
        };
        
    private:
        // Something here

    public:
        // Constructor
        Simulator() {

        }
        
        // Destructor
        ~Simulator() {
            
        }

        // Method to read in specification from text file (examples given as test1.txt and test2.txt)
        void read(const char* filename) {
            // Open file as a stream
            std::fstream filestream;
            filestream.open(filename);

            // Check if file is open
            if (filestream.is_open()) {
                
                std::string line;

                // Read data in from file and put into string 
                while (std::getline(filestream, line)) {
                    std::cout << line << std::endl;
                }

            }

        }

    
};