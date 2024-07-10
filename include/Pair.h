#pragma once
#include "MyString.h"
#include "MyData.h"
#include <iostream>
#include <limits>

class Pair 

{
	MyString Key;

	MyData data_m;

	Pair()=default;

	~Pair() = default;

	Pair(const char* k, const MyData & d);

	Pair(Pair&& other) noexcept;

	Pair& operator = (Pair&& other) noexcept;

	bool operator==(const char* key) ;

	friend class Base;

    friend class Menu;

public:

	Pair& operator = (const Pair& other);

    MyString & ReturnKey();

    MyData & Returndata_m();

};