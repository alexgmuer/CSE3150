#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <vector>
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

            std::string line;
            
            // Need to parse string based around '<-' and '=' characters
            std::vector<std::string> file_lines;

            // Declare delimiters
            std::string equal_delim = "=";
            std::string arrow_delim = "->";
            
            // Check if file is open
            if (filestream.is_open()) {
                // Read data in from file and put into string 
                while (std::getline(filestream, line)) {
                    file_lines.push_back(line);
                }
            }
            
            // Iterate through file_lines vector and parse each file line
            for (int i=0;i<file_lines.size();i++) {
                //std::cout << file_lines[i] << std::endl;
                
                // Check if there is a '=' substring or a '->' substring in the line
                size_t equal_found = file_lines[i].find(equal_delim);
                size_t arrow_found = file_lines[i].find(arrow_delim);
                
                std::map<std::string, std::string> node_lines;
                std::map<std::string, std::string> connection_lines;
                // If equal substring is in line
                if (equal_found != std::string::npos) {
                    // Temp buffer to hold tokenized parts of line
                    std::vector<std::string> temp_buf;

                    // Make line into stream
                    std::istringstream line_stream(file_lines[i]);

                    // temp string 
                    std::string temp_str;


                    while (std::getline(line_stream, temp_str, equal_delim)) {
                        temp_buf.push_back(temp_str);
                    }

                    node_lines[temp_buf[0]] = temp_buf[1];
                }
                
                // If arrow substring is in line, add to connection_lines map
                // Key in each map element is the source, value is destination
                if (arrow_found != std::string::npos) {
                    // Temp buffer to hold tokenized parts of line
                    std::vector<std::string> temp_buf;

                    // Make line into stream
                    std::istringstream line_stream(file_lines[i]);

                    // temp string 
                    std::string temp_str;


                    while (std::getline(line_stream, temp_str, equal_delim)) {
                        temp_buf.push_back(temp_str);
                    }

                    connection_lines[temp_buf[0]] = temp_buf[1];
                }
                
                
            }

        }

    
};