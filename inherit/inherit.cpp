// inherit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct ClassA
{
	void Test(int val)
	{
		std::cout << "ClassA::Test(int " << val << ")" << std::endl;
	}
	void Test(double val)
	{
		std::cout << "ClassA::Test(double " << val << ")" << std::endl;
	}
};

struct ClassB:ClassA
{
	using ClassA::Test;
	void Test(const char* val)
	{
		std::cout << "ClassA::Test(char* " << val << ")" << std::endl;
	}
};

int main()
{
	ClassA a;
	ClassB b;
	a.Test(1);
	a.Test(3.14);
	b.Test("Hello");
	b.Test(2);
}

