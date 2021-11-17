#pragma once
class SingletonThreadLess
{
public:
	static SingletonThreadLess* get();
	static SingletonThreadLess* get(const float&);

	SingletonThreadLess(const SingletonThreadLess& other) = delete;

	void operator=(const SingletonThreadLess& other) = delete;

	float pValue() const;

	void something();

	//static float value() { return getInstance().pValue(); }
		
private:
	SingletonThreadLess();
	SingletonThreadLess(float value);
	
	static SingletonThreadLess* instance;

	float Value() const;
	float number;
	
};

//SingletonThreadLess *SingletonThreadLess::instance;