#pragma once
template<typename T>
class IncrementFunctor
{
	T value;
public:
	IncrementFunctor(T num) : value(num) {};
	T operator() (T x)
	{
		return x + value;
	}

};


