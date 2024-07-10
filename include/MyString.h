#pragma once
#include <cstring>
#include <iostream>

class MyString
{

    char* m_pStr;

public:

    MyString();
    MyString(const char* str);
    MyString(const MyString& oth);
    MyString(MyString&& oth) noexcept;


    ~MyString();


    const char* GetString() const;


    void SetNewString(const char* str);
    void SetNewString(const MyString& oth);


    MyString& operator=(const MyString& oth);
    MyString& operator=(const char* oth);
    MyString& operator=(MyString&& oth) noexcept;


    MyString operator+(const MyString& oth);
    MyString operator+(const char* str);


    MyString& operator+=(const MyString& oth);
    MyString& operator+=(const char* str);


    friend std::ostream& operator<<(std::ostream& examp, const MyString& str);

    void StrSwap(MyString& oth);

    bool operator==(const MyString& oth);
    bool operator==(const char* oth);

    friend class Pair;

    friend class Base;

};