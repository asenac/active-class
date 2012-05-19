#include <iostream>
#include <string>
#include "ActiveClass.hpp"

class ExampleClass : public ActiveClass
{
public:

    ASYNC_METHOD(sayHelo, std::string name);
};

ASYNC_METHOD_IMPL(ExampleClass, sayHelo)
{
    std::cout << "Helo " << p.name << "!" << std::endl;
}

int main(int argc, const char *argv[])
{
    ExampleClass ec;

    ec.start();

    for (int i = 0; i < 10; i++) 
    {
        // Advanced initializer lists in C++11
        ec.sayHelo({"John"});
    }

    ec.wait();
    
    return 0;
}
