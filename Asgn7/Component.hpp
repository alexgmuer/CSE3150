#include <iostream>
#include <memory>


// General Component Class
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
                std::shared_ptr<Component> temp_target = target;

                std::cout << name << " --> " 
                << func << "(" << "target=" << temp_target->name << ")" 
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
                std::shared_ptr<Component> temp_target = target;

                std::cout << name << " --> " 
                << func << "(" << func_args << ",target=" << temp_target->name << ")" 
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
                std::shared_ptr<Component> temp_target = target;

                std::cout << name << " --> " 
                << func << "(" << func_args << ",target=" << temp_target->name << ")" 
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
        
        class Exit : public Server
        {
            public:

            private:

            public:
                Exit() {
                    target = nullptr;
                }

        };

    class Router : public Component
    {
        public:

        private:

        public:
            void print(void) {
                std::shared_ptr<Component> temp_target = target;

                std::cout << name << " --> " 
                << func << "(" << func_args << ",target=" << temp_target->name << ")" 
                << std::endl;
            }

    };

        class Dispatch : public Router
        {
            public:

            private:

            public:
                Dispatch() {
                    target = nullptr;
                }

        };
