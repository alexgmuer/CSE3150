
// IDEA: Use dynamic_cast<> to cast Component object down to more 
// specific Buffer, Generator, Server class
class Component {
    public:
        std::string name;
        // Func is temporarily a string
        std::string func;
        std::string func_args;
        Component* target;
};

    class Buffer : public Component
    {
        public:

        private:

        public:

    };

        class FIFO : public Buffer
        {
            public:

            private:

            public:
                void print(void) {
                    
                }

        };

    class Generator : public Component
    {
        public:

        private:

        public:

    };
    
        class Poisson : public Generator
        {
            public:

            private:

            public:
                void print(void) {
                    
                }

        };

    class Server : public Component
    {
        public:

        private:

        public:

    };
    
        class ServerCst : public Server
        {
            public:

            private:

            public:
                void print(void) {
                    
                }

        };
        
        class ServerNormal : public Server
        {
            public:

            private:

            public:
                void print(void) {
                    
                }

        };
        
        class ServerExp : public Server
        {
            public:

            private:

            public:
                void print(void) {
                    
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
                    
                }

        };

    class Exit : public Component
    {
        public:

        private:

        public:
            void print(void) {
                
            }

    };