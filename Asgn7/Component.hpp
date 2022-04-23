#include <iostream>

// IDEA: Use dynamic_cast<> to cast Component object down to more 
// specific Buffer, Generator, Server class
class Component {
    public:
        std::string name;
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
            void print(void) {
                std::cout << name << " --> " 
                << func << "(" << ",target=" << target->name << ")" 
                << std::endl;
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
            void print(void) {
                std::cout << name << " --> " 
                << func << "(" << func_args << ",target=" << target->name << ")" 
                << std::endl;
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
                std::cout << name << " --> " 
                << func << "(" << func_args << ",target=" << target->name << ")" 
                << std::endl;
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

    class Router : public Component
    {
        public:

        private:

        public:
            void print(void) {
                std::cout << name << " --> " 
                << func << "(" << func_args << ",target=" << target->name << ")" 
                << std::endl;
            }

    };

        class Dispatch : public Router
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
                << func << std::endl;
            }

    };