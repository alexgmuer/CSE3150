#include <iostream>
#include <memory>


// General Component Class
class Component {
    public:
        /*const*/ std::string name;
        std::string func;
        std::string func_args;
        std::shared_ptr<Component> target;

        virtual void print() = 0;
};

    class Buffer : public Component
    {
        public:

        private:

        public:
            // Add error checking so that if invalid input file is made, 
            // code outputs error message instead of crashing/segfaulting
            void print(void) {
                std::shared_ptr<Component> temp_target = target;

/*                 if (temp_target == nullptr) {

                    std::cout << func << " " << name << " has no target. Exiting" << std::endl;
                    exit(0);
                }
                else { */
                    std::cout << name << " --> " 
                    << func << "(" << "target=" << temp_target->name << ")" 
                    << std::endl;
                //}
            }

    };

        class FIFO : public Buffer
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
            // Add error checking so that if invalid input file is made, 
            // code outputs error message instead of crashing/segfaulting
            void print(void) {
                std::shared_ptr<Component> temp_target = target;
                
/*                 if (temp_target == nullptr) {
                    std::cout << func << " " << name << " has no target. Exiting" << std::endl;
                    exit(1);
                }
                else { */
                    std::cout << name << " --> " 
                    << func << "(" << func_args << ",target=" << temp_target->name << ")" 
                    << std::endl;
                //}

            }

    };
    
        class Poisson : public Generator
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
            void print(void) {
                std::shared_ptr<Component> temp_target = target;

/*                 if (temp_target == nullptr) {

                    std::cout << "Server " << name << " has no target. Exiting" << std::endl;
                    exit(1);
                }
                else { */
                    std::cout << name << " --> " 
                    << func << "(" << func_args << ",target=" << temp_target->name << ")" 
                    << std::endl;
                //}

            }

    };
    
        class ServerCst : public Server
        {
            public:

            private:

            public:

        };
        
        class ServerNormal : public Server
        {
            public:

            private:

            public:

        };
        
        class ServerExp : public Server
        {
            public:

            private:

            public:

        };
        
    class Exit : public Component
    {
        public:

        private:

        public:
            void print(void) {

                std::cout << name << " --> " 
                << "ServerExit" << "()" 
                << std::endl;
            }

    };

    class Router : public Component
    {
        public:

        private:

        public:

    };

        class Dispatch : public Router
        {
            public:

            private:

            public:
                void print(void) {

                    std::cout << name << " --> " 
                    << func << "(" << func_args << ")" 
                    << std::endl;
                }

        };
