#pragma once
class SingletonThreadLess
{
public:
	static SingletonThreadLess* get();
	static SingletonThreadLess* get(const float&);

	SingletonThreadLess(const SingletonThreadLess& other) = delete;

	void operator=(const SingletonThreadLess& other) = delete;

	float pValue() const;
		
private:
	SingletonThreadLess();
	SingletonThreadLess(float value);
	
	static SingletonThreadLess* instance;

	float Value() const;
	float number;
	
};

