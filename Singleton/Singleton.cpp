#include <iostream>
#include "singletonthreadless.h"
#include "singletonthreadsafe.h"

int main()
{

    float n = 2.5;
    SingletonThreadSafe* singleton = SingletonThreadSafe::get(n);
    //SingletonThreadLess* singleton = SingletonThreadLess::get();
    std::cout << singleton->pValue() << std::endl;
}

//Another impementation of Singleton class without pointer instance
// //////////////////////////////////////////////////////////////////
//class Singleton
//{
//public:
//    Singleton(Singleton& other) = delete;
//    static Singleton& get()
//    {
//        return sInstance;
//    }
//
//    static Singleton& get(const int& n)
//    {
//        return sInstance;
//    }
//
//    static int Function() { return get().iFunction(); }
//    //static int Function() { return get().number; } // another way to do this
//private:
//    Singleton() {}
//    Singleton(const int& n) :number(n) {}
//
//    static Singleton sInstance;
//
//    int iFunction() { return number; }
//    int number = 10;
//};
//
//Singleton Singleton::sInstance;
//
//int main()
//{
//
//    Singleton& instance = Singleton::get(5);
//    std::cout << instance.Function() << std::endl;
//}