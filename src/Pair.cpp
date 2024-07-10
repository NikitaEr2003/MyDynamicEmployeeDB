#include "Pair.h"

Pair::Pair(const char* k, const MyData& d)

{
    size_t num = strlen(k);

	this->Key.m_pStr = new char[num+1];

    for ( size_t i =0; i < num; i++)
	{
        this->Key.m_pStr[i] =k[i];
    }

    this->Key.m_pStr[num] = '\0';

	this->data_m.sex = d.sex;
	this->data_m.m_age = d.m_age;
	this->data_m.m_job = d.m_job;
	this->data_m.m_salary = d.m_salary;
	
}

Pair::Pair(Pair&& other) noexcept
{

    this->data_m = std::move(other.data_m);
    this->Key = std::move(other.Key);

}

Pair& Pair::operator = (Pair&& other) noexcept

{
    this->Key = std::move(other.Key);
    this->data_m.sex = other.data_m.sex;
    this->data_m.m_salary = other.data_m.m_salary;
    this->data_m.m_job = std::move(other.data_m.m_job);
    this->data_m.m_age = other.data_m.m_age;

    return *this;

}

Pair& Pair::operator = (const Pair& other) 

{
	this->Key = other.Key;
	this->data_m.sex = other.data_m.sex;
	this->data_m.m_salary = other.data_m.m_salary;
	this->data_m.m_job = other.data_m.m_job;
	this->data_m.m_age = other.data_m.m_age;

	return *this;

}

bool Pair::operator==(const char* key)

{

	if (this->Key == key) 

	{

		return true;

	}

	return false;

}

MyData& Pair::Returndata_m()

{
    return data_m;

}

MyString & Pair::ReturnKey()

{
    return Key;

}
