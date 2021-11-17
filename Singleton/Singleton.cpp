#include <iostream>
#include "singletonthreadless.h"
//#include "singletonthreadsafe.h"

int main()
{

    SingletonThreadLess* n = SingletonThreadLess::get(0.05);
    std::cout << n->Value() << std::endl;

}
