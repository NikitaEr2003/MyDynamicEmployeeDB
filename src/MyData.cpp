#include "MyData.h"

MyData::MyData()

{

	this->sex = UNDEF;
	this->m_age = 0;
	this->m_job = "unknown";
	this->m_salary = 0;
	
}

MyData::MyData(Sex Sex_m, size_t Age, const char* Job, float Salary)
    : sex(Sex_m),
    m_age(Age),
    m_job(Job),
    m_salary(Salary) 
{}

MyData::MyData(const MyData& d) 

{

	this->sex = d.sex;
	this->m_salary = d.m_salary;
	this->m_job = d.m_job;
	this->m_age = d.m_age;
	
}

MyData:: MyData(MyData&& d) noexcept

{
    this->sex = d.sex;
    this->m_salary = d.m_salary;
    this->m_job = std::move(d.m_job);
    this->m_age = d.m_age;

}

MyData& MyData::operator =(const MyData& d)

{

	this->sex = d.sex;
	this->m_salary = d.m_salary;
	this->m_job = d.m_job;
	this->m_age = d.m_age;
	return *this;

}

MyData& MyData::operator =(MyData&& d) noexcept

{
    this->sex = d.sex;
    this->m_salary = d.m_salary;
    this->m_job = std::move(d.m_job);
    this->m_age = d.m_age;
    return *this;

}

std::string MyData::Return_Sex()

{
    if (this->sex == MALE)
    {
        return "Male";

    }
    else if (this->sex == FEMALE)

    {

        return "FEMale";

    }
    else 
    {

        return "Undef";

    }

}

size_t MyData::Return_m_age ()

{

    return m_age;

}

MyString MyData::Return_m_job()

{
    return m_job;

}

float MyData::Return_m_salary()

{
   
    return m_salary;

}

std::ostream& operator << (std::ostream &os, const MyData& d)

{
    os << "Sex: ";
    os << d.sex << std::endl;
    os << "Age : ";
    os << d.m_age << std::endl;
    os << "Job :";
    os << d.m_job <<std::endl;
    os << "Salary :";
    os << d.m_salary <<std::endl;

    return os;

}

