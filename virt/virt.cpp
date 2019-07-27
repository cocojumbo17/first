// virt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Persone
{
public:
	Persone(const std::string& name)
		:m_name(name)
	{
		std::cout << "Persone <" << Name() << ">" << std::endl;
	}
	virtual ~Persone()
	{
		std::cout << "~Persone <" << Name() << ">" << std::endl;
	}
	virtual  std::string Name()
	{
		return m_name;
	}
private:
	std::string m_name;
};

class Teacher : public Persone
{
public:
	Teacher(const std::string& name)
		:Persone(name)
	{
		std::cout << "Teacher <" << Name() << ">" << std::endl;
	}
	virtual ~Teacher()
	{
		std::cout << "~Teacher<" << Name() << ">" << std::endl;
	}
	virtual std::string Name()
	{
		return "teacher " + Persone::Name();
	}
};

class Professor : public Teacher
{
public:
	Professor(const std::string& name)
		:Teacher(name)
	{
		std::cout << "Professor <" << Name() << ">" << std::endl;
	}
	virtual ~Professor()
	{
		std::cout << "~Professor <" << Name() << ">" << std::endl;
	}
	virtual std::string Name()
	{
		return "Prof. " + Persone::Name();
	}
};

int main()
{
	{
		Professor p("Straustrup");
		std::cout << "size of std::string is " << sizeof(std::string) << std::endl;
		std::cout << "size of p is " << sizeof(p) << std::endl;
	}
    return 0;
}

