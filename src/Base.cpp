#include "Base.h"
#include <cstring>

Base::Base() : capacity(1), count(0)
{
    pBase = new Pair[this->capacity];

}

Base::~Base()
{

	delete[] this->pBase;
	this->pBase = nullptr;

}

Base::Base(const Base& bd): pBase(new Pair[bd.capacity]), count(bd.count), capacity(bd.capacity) 
{
	if(bd.count > 0) 
	{
		
	std::copy(bd.pBase, bd.pBase + bd.count, pBase);
		
	}

}

Base::Base(Base&& bd) noexcept 
{

	count = bd.count;
	pBase = bd.pBase;
	capacity = bd.capacity;
	bd.pBase = nullptr;

}

Base& Base::operator=(Base&& bd) noexcept
{
	if (this == &bd) 
	{
		return *this;
	}

	Pair* tmp = pBase;
	count = bd.count;
	capacity = bd.capacity;
	pBase = bd.pBase;
	bd.pBase = tmp;
	bd.pBase = nullptr;
	return *this;
}

Base& Base::operator =(const Base& bd)
{
	if (this == &bd)
	{
		return *this;
	}

	this->capacity = bd.capacity;
	this->count = bd.count;

	for (int i = 0; i < bd.count; i++)
	{
		this->pBase[i] = bd.pBase[i];
	}

	return *this;

}

MyData& Base::operator[](const char* key)

{
	for (int i = 0; i < this->count; i++) 
	{
		if (strcmp(pBase[i].Key.GetString(), key) == 0)
		{
			return pBase[i].data_m;
		}
	}
	if (this->count >= this->capacity)
	{
		this->capacity *= 3;
		Pair* NewArray = new Pair[this->capacity];
		for (int i = 0; i < this->count; i++)
		{
			NewArray[i] = pBase[i];
		}
		delete[] pBase;
		pBase = NewArray;
		NewArray = nullptr;
	}

	pBase[count].Key = key;

	count++;

	return pBase[count - 1].data_m;
}

std::ostream& operator<< (std::ostream& examp, Base& bd)
{
	if (bd.count == 0) 
	{
		std::cout << "Your database is empty!!!\n";
		return examp;
	}

	for (int i = 0; i < bd.count; i++) 
	{

		examp << "№ " << i + 1 << std::endl;
		examp << "Full Name: ";
		examp << bd.pBase[i].ReturnKey() << std::endl;
		examp << "Gender: ";
		examp << bd.pBase[i].Returndata_m().Return_Sex() << std::endl;
		examp << "Age: ";
		examp << bd.pBase[i].Returndata_m().Return_m_age() << std::endl;
		examp << "Job: ";
		examp << bd.pBase[i].Returndata_m().Return_m_job().GetString() << std::endl;
		examp << "Salary: ";
		examp << bd.pBase[i].Returndata_m().Return_m_salary() << std::endl << std::endl;

	}

	return examp;

}

int Base::DeletePair(const char* key) 
{
	bool True_Key = false;

	for (int i = 0; i < this->count; i++) 
	{
		if (strcmp(pBase[i].Key.m_pStr, key) == 0)
		{
			True_Key = true;
			return i;
		}
	}
	if (True_Key == false)
	{

		return -2;
	}

	return 0;

}

bool Base::CheckName(const char* ptr) 
{
	for (size_t i = 0; i < count; i++)
	{
		if (strcmp(pBase[i].Key.m_pStr, ptr) == 0)
		{
			return true;
		}
	}

	return false;

}
