# Class Access Specifiers
## Public
    Public data members are accessible to anyone, inside or outside of the class.
## Protected
    Protected data members are accessible only to derived/subclasses of a class.
## Private
    Private data members are only accessible within a class.


# Inheritance
    Inheritance is when a class can inherit the data members of another class. 
    This can be done via public, protected, or private inheritance, however public 
    inheritance allows for runtime polymorphism and is thus preferred as the compiler 
    can optimize code generation.


# Encapsulation
    Encapsulation is a design rule that groups similar data together either within  
    classes or as a general rule.

# Polymorphism
    When the same entity behaves differently in different scenarios. For example, C++ 
    allows for operators to be overloaded to act differently for different classes  
    and objects.

## Runtime Polymorphism
    In runtime polymorphism, the function call is resolved at runtime, and the   
    compiler deduces the object at runtime then decides which function call to bind 
    to it.

# Virtual Keyword
    The virtual keyword when used in a class method definition tells the compiler 
    to use late (runtime) binding. For example, an object defined as a pointer to a 
    parent class could be reassigned to be a child class derived of that parent class, 
    and if the child class has the same function as the parent's virtual function the 
    child's function will override the parent's. This is possible because the compiler 
    utilizes runtime polymorphism to not resolve the virtual function for the parent
    class until runtime, and thus the class object pointer can be reassigned.

    Example:
    ```cpp
    #include<iostream>
    using namespace std;
    
    class base {
    public:
        virtual void print()
        {
            cout << "print base class\n";
        }
    
        void show()
        {
            cout << "show base class\n";
        }
    };
    
    class derived : public base {
    public:
        void print()
        {
            cout << "print derived class\n";
        }
    
        void show()
        {
            cout << "show derived class\n";
        }
    };
    
    int main()
    {
        base *bptr;
        derived d;
        bptr = &d;
    
        // Virtual function, binded at runtime
        bptr->print();
    
        // Non-virtual function, binded at compile time
        bptr->show();
    
        return 0;
    }
    ```