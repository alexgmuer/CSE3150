

class Simulator {
    public:
        // Will probably need some sort of Node structure
        class Node {
            friend class Simulator;
                // Constructor
                Node() {

                }
                
                // Destructor
                ~Node() {
                    
                }
            
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


        }

    
};