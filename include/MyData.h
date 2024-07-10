#pragma once
#include "MyString.h"
class MyData
{
public:

	enum Sex

	{
		UNDEF, MALE, FEMALE 

	};

private:

	Sex sex;

	size_t m_age;

	MyString m_job;

	float m_salary;

public:

	MyData();

	MyData(Sex Sex_m, size_t Age, const char* Job, float Salary);

	~MyData() = default;

	MyData(const MyData& d);

	MyData& operator =(const MyData& d);

	MyData(MyData&& d) noexcept;

	MyData& operator =(MyData&& d) noexcept;

	friend std::ostream& operator << (std::ostream &os, const MyData& d);

	friend class Pair;

    std::string Return_Sex();

    size_t Return_m_age();

    MyString Return_m_job();

    float Return_m_salary();

};
