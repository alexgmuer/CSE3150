
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