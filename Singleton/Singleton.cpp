#include <iostream>
#include "singletonthreadless.h"
#include "singletonthreadsafe.h"

void thread1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingletonThreadLess* singleton = SingletonThreadLess::get(1.1);
    std::cout << singleton->pValue() << "\n";
}

void thread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingletonThreadLess* singleton = SingletonThreadLess::get(2.2);
    std::cout << singleton->pValue() << "\n";
}

void sthread1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingletonThreadSafe* singleton = SingletonThreadSafe::get(3.3);
    std::cout << singleton->pValue() << "\n";
}

void sthread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    SingletonThreadSafe* singleton = SingletonThreadSafe::get(4.4);
    std::cout << singleton->pValue() << "\n";
}

int main()
{
    //singleton without thread safety
    //Sometimes Singleton is createt twice
    std::thread t1(&thread1);
    std::thread t2(&thread2);
    t1.join();  
    t2.join();

    //singleton with thread safty
    //create one instance of singleton all the time
    std::thread st1(&sthread1);
    std::thread st2(&sthread2);
    st1.join();
    st2.join();


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