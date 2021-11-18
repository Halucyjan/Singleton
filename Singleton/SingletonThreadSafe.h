#pragma once
#include <mutex>

class SingletonThreadSafe
{
public:
	static SingletonThreadSafe* get();
	static SingletonThreadSafe* get(const float&);

	SingletonThreadSafe(const SingletonThreadSafe& other) = delete;

	void operator=(const SingletonThreadSafe& other) = delete;

	float pValue() const;

private:
	SingletonThreadSafe();
	SingletonThreadSafe(float value);

	static SingletonThreadSafe* instance;
	static std::mutex s_mutex;

	float Value() const;
	float number;

};
