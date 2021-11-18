#include "SingletonThreadSafe.h"

SingletonThreadSafe* SingletonThreadSafe::instance = nullptr;
std::mutex SingletonThreadSafe::s_mutex;

SingletonThreadSafe* SingletonThreadSafe::get()
{
	std::lock_guard<std::mutex> lock(s_mutex);
	if (instance == nullptr)
	{
		instance = new SingletonThreadSafe();
	}
	return instance;
}

SingletonThreadSafe* SingletonThreadSafe::get(const float& value)
{
	std::lock_guard<std::mutex> lock(s_mutex);
	if (instance == nullptr)
	{
		instance = new SingletonThreadSafe((float)value);
	}
	return instance;
}

float SingletonThreadSafe::pValue() const
{
	return number;
}

SingletonThreadSafe::SingletonThreadSafe()
{
	number = 0.5;
}

SingletonThreadSafe::SingletonThreadSafe(float value)
	:number(value)
{}

float SingletonThreadSafe::Value() const
{
	return number;
}
