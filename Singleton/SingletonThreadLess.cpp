#include "SingletonThreadLess.h"
#include <iostream>

SingletonThreadLess* SingletonThreadLess::instance = nullptr;

SingletonThreadLess* SingletonThreadLess::get()
{
	if(instance == nullptr)
	{
		 instance = new SingletonThreadLess();
	}
	return instance;
}

SingletonThreadLess* SingletonThreadLess::get(const float& value)
{
	if (instance == nullptr)
	{
		instance = new SingletonThreadLess((float)value);
	}
	return instance;
}

float SingletonThreadLess::pValue() const
{
	return number;
}

SingletonThreadLess::SingletonThreadLess()
{
	number = 0.5;
}

SingletonThreadLess::SingletonThreadLess(float value)
	:number(value)
{}

float SingletonThreadLess::Value() const
{
	return number;
}
