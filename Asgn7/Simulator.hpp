#include <fstream>
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <memory>

// Component class and related children classes in Component.hpp
#include "Component.hpp"


// Simulator class
class Simulator {
    public:
        // Node and connection maps TEMPORARILY PUBLIC
        std::map<std::string, std::string> node_lines;
        std::map<std::string, std::string> connection_lines;
        
        std::map<std::string, std::shared_ptr<Component>> Network_Nodes;
        
    private:
        // Function to parse out the arguments and function name from RHS of string
        std::pair<std::string,std::string> extract_args(const std::string& func_and_args) {
            auto last = func_and_args.find_last_of(')');
            if (last == std::string::npos) return {};

            auto args_ind = func_and_args.find_first_of('(');
            if (args_ind == std::string::npos) return {};

            std::string func = func_and_args.substr(0,args_ind);
            std::string args = func_and_args.substr(args_ind+1);
            args.pop_back();

            return {func, args};
        }

        void generate_network(std::map<std::string, std::string> node_lines,
                              std::map<std::string, std::string> connection_lines) {
            
            // Function which takes the nodes and connection maps and generates
            // network of Component nodes and their targets
            
            std::pair<std::string,std::string> cur;

            for (auto it_node = node_lines.cbegin(); it_node != node_lines.cend(); ++it_node) {
                // Iterate through node_lines and add node name and func info
                
                cur = *it_node;

                std::string temp_func;
                std::string temp_args;
                if (cur.second == "Exit") {
                    temp_func = "Exit";
                    temp_args = " ";
                } else {
                    auto pair = extract_args(cur.second);
                    temp_func = pair.first;
                    temp_args = pair.second;
                }

                // Determine based on func name how to add to Network_Nodes
                if (temp_func == "FIFO") {
                    
                    std::shared_ptr<Component> Component_Node;
                    Component_Node = std::shared_ptr<Component>(new FIFO);

                    
                    Component_Node->name = cur.first;
                    Component_Node->func = temp_func;
                    Component_Node->func_args_str = temp_args;

                    Network_Nodes.insert(std::make_pair(cur.first, Component_Node));
                }
                if (temp_func == "ServerExp") {
                    
                    std::shared_ptr<Component> Component_Node;
                    Component_Node = std::shared_ptr<Component>(new ServerExp);

                    
                    Component_Node->name = cur.first;
                    Component_Node->func = temp_func;
                    Component_Node->func_args_str = temp_args;

                    Network_Nodes.insert(std::make_pair(cur.first, Component_Node));
                }
                if (temp_func == "ServerNormal") {
                    
                    std::shared_ptr<Component> Component_Node;
                    Component_Node = std::shared_ptr<Component>(new ServerNormal);

                    
                    Component_Node->name = cur.first;
                    Component_Node->func = temp_func;
                    Component_Node->func_args_str = temp_args;

                    Network_Nodes[cur.first] = Component_Node;
                    Network_Nodes.insert(std::make_pair(cur.first, Component_Node));
                }
                if (temp_func == "ServerCst") {
                    
                    std::shared_ptr<Component> Component_Node;
                    Component_Node = std::shared_ptr<Component>(new ServerCst);
                    
                    Component_Node->name = cur.first;
                    Component_Node->func = temp_func;
                    Component_Node->func_args_str = temp_args;

                    Network_Nodes.insert(std::make_pair(cur.first, Component_Node));
                }
                if (temp_func == "Poisson") {
                    
                    std::shared_ptr<Component> Component_Node;
                    Component_Node = std::shared_ptr<Component>(new Poisson);

                    
                    Component_Node->name = cur.first;
                    Component_Node->func = temp_func;
                    Component_Node->func_args_str = temp_args;

                    Network_Nodes.insert(std::make_pair(cur.first, Component_Node));
                }
                if (temp_func == "Exit") {
                    
                    std::shared_ptr<Component> Component_Node;
                    Component_Node = std::shared_ptr<Component>(new Exit);

                    
                    Component_Node->name = cur.first;
                    Component_Node->func = temp_func;
                    Component_Node->func_args_str = temp_args;

                    Network_Nodes.insert(std::make_pair(cur.first, Component_Node));
                }
                if (temp_func == "Dispatch") {

                    std::shared_ptr<Component> Component_Node;
                    Component_Node = std::shared_ptr<Component>(new Dispatch);

                    
                    Component_Node->name = cur.first;
                    Component_Node->func = temp_func;
                    Component_Node->func_args_str = temp_args;

                    Network_Nodes.insert(std::make_pair(cur.first, Component_Node));
                }

                
            }
            
            std::pair<std::string,std::string> temp;
            std::shared_ptr<Component> Target_Node;
            for (auto it_con = connection_lines.cbegin(); it_con != connection_lines.cend(); ++it_con) {
                // Iterate through connection_lines and add targets to each node
                
                temp = *it_con;

                Target_Node = Network_Nodes[temp.second];

                Network_Nodes[temp.first]->target = Target_Node;
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

// Use template type for specific component type.
// All component specific types have a print() method
std::ostream& operator<<(std::ostream& os, const Simulator* s) {
    // Iterate through Network_Nodes map
    std::pair<std::string,std::shared_ptr<Component>> temp;
    for (auto it = s->Network_Nodes.cbegin(); it != s->Network_Nodes.cend(); ++it) {
        // Call print functions of subcomponent classes
        temp = *it;
        temp.second->print();
    }
    return os;
}