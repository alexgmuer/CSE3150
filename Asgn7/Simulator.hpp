#include <fstream>
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
// Define data structure inside each node as a class
// Data structure needs to contain the type 

class Component {
    public:
        std::string name;
        // Func is temporarily a string
        std::string func;
        Component* target;
};

class Buffer : public Component
{
    public:

    private:

    public:

};

class Generator : public Component
{
    public:

    private:

    public:

};

class Server : public Component
{
    public:

    private:

    public:

};

class Router : public Component
{
    public:

    private:

    public:

};

//template <class T>
class Simulator {
    public:
        // Node and connection maps TEMPORARILY PUBLIC
        std::map<std::string, std::string> node_lines;
        std::map<std::string, std::string> connection_lines;
        
        std::map<std::string, Component> Network_Nodes;
        
    private:
        void generate_network(std::map<std::string, std::string> node_lines,
                              std::map<std::string, std::string> connection_lines) {
            
            // Function which takes the nodes and connection maps and generates
            // network of Component nodes and their targets

            for (auto it = node_lines.cbegin(); it != node_lines.cend(); ++it) {
                // Iterate through node_lines and add node name and func info
                Component Component_Node;
                Component_Node.name = it->first;
                Component_Node.func = it->second;

                Network_Nodes[it->first] = Component_Node;
            }
            
            for (auto it = connection_lines.cbegin(); it != connection_lines.cend(); ++it) {
                // Iterate through connection_lines and add targets to each node
                Component* Target_Node = &Network_Nodes[it->second];
                Network_Nodes[it->first].target = Target_Node;
            }


        }


    public:
        // Method to read in specification from text file (examples given as test1.txt and test2.txt)
        void read(const char* filename) {
            // Open file as a stream
            std::fstream filestream;
            filestream.open(filename);

            std::string line;
            
            // Need to parse string based around '<-' and '=' characters
            std::vector<std::string> file_lines;

            // Declare delimiters
            const char* equal_delim = "=";
            const char* arrow_delim = "->";
            
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
                
                // If equal substring is in line
                if (equal_found != std::string::npos) {
                    // Temp buffer to hold tokenized parts of line
                    std::vector<std::string> temp_buf;

                    // Make line into stream
                    std::istringstream line_stream(file_lines[i]);

                    // temp string 
                    std::string temp_str;


                    while (std::getline(line_stream, temp_str, '=')) {
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


                    while (std::getline(line_stream, temp_str, '>')) {
                        
                        temp_buf.push_back(temp_str);
                    }
                    
                    temp_buf[0].resize(temp_buf[0].size() - 1);
                    
                    connection_lines[temp_buf[0]] = temp_buf[1];
                }
                
            }

            // Generate network from node and connection maps
            generate_network(node_lines, connection_lines);
        }

};

std::ostream& operator<<(std::ostream& os, const Simulator* s) {
        
    // Temporary printing functionality 
    //for (auto it = s->node_lines.cbegin(); it != s->node_lines.cend(); ++it) {
    //    std::cout << "Node: " << it->first << "\tFunction: " << it->second << std::endl;
    //}
    
    //for (auto it = s->connection_lines.cbegin(); it != s->connection_lines.cend(); ++it) {
    //    std::cout << "Starting Node: " << it->first << "\tEnding Node:" << it->second << std::endl;
    //}


    for (auto it = s->Network_Nodes.cbegin(); it != s->Network_Nodes.cend(); ++it) {

        std::cout << it->first         << " --> " 
                  << it->second.name   << "=" 
                  << it->second.func   << " target=" 
                  << it->second.target->name << std::endl;
    }

    return os;
}