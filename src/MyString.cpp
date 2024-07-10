#include <string>
#include "MyString.h"
#pragma warning(disable : 4996)
using namespace std;

MyString::MyString() :m_pStr(nullptr){}

MyString::MyString(const char* str)
{
    if(str)
    {
    size_t size = strlen(str);
    m_pStr = new char[size + 1];

    for (int i = 0; i < size; i++)
    {
        m_pStr[i] = str[i];
    }

    m_pStr[size] = '\0';}
    else
    {
    m_pStr = nullptr;
    }
}

MyString::MyString(const MyString& oth)
{
    if(oth.m_pStr)
    {
    size_t size = strlen(oth.m_pStr);
    m_pStr = new char[size + 1];

    for (int i = 0; i < size; i++)
    {
        m_pStr[i] = oth.m_pStr[i];
    }

    m_pStr[size] = '\0';
    }
    else
    {
    m_pStr = nullptr;
    }

}

MyString::MyString(MyString && oth) noexcept
{
        m_pStr = oth.m_pStr;

        oth.m_pStr = nullptr;
}

MyString::~MyString()
{
    delete[] m_pStr;

    m_pStr = nullptr;
}

const char* MyString::GetString() const
{
    return  this->m_pStr;
}

void MyString::SetNewString(const char* str)
{
    if (str)
    {
    size_t size = strlen(str);
    char* NewStr = new char[size + 1];

    for (int i = 0; i < size; i++)
    {
        NewStr[i] = str[i];
    }

    NewStr[size] = '\0';

    delete[] m_pStr;

    m_pStr = NewStr;
    }
    else
    {
       if(m_pStr)
       {
            delete [] m_pStr;
            m_pStr = nullptr;
        }
    }

}

void MyString::SetNewString(const MyString& oth)
{
    if (oth.m_pStr)
    {
        size_t size = strlen(oth.m_pStr);
        char* NewStr = new char[size + 1];

        for (int i = 0; i < size; i++)
        {
            NewStr[i] = oth.m_pStr[i];
        }

        NewStr[size] = '\0';

            delete[] m_pStr;
        m_pStr = NewStr;
    }
    else
    {
        if(m_pStr)
        {
            delete [] m_pStr;
            m_pStr = nullptr;
        }
    }
}

MyString& MyString::operator=(const MyString& oth)
{
    if (this == &oth)
    {
        return *this;

    }

        delete[] m_pStr;

    if (oth.m_pStr)
    {
        size_t size = std::strlen(oth.m_pStr);

        m_pStr = new char[size + 1];

        std::strcpy(m_pStr, oth.m_pStr);
    }
    else
    {

        m_pStr = nullptr;
    }

    return *this;
}

MyString& MyString::operator =(const char* oth)
{
    if (oth == nullptr)
    {
        delete[] this->m_pStr;
        m_pStr = nullptr;
        return *this;

    }

    delete[] m_pStr;
    this->m_pStr = new char[std::strlen(oth) + 1];
    std::strcpy(this->m_pStr, oth);
    return *this;
}
MyString& MyString::operator =(MyString&& oth) noexcept
{
    if (this != &oth)

    {
        delete[] m_pStr;
        m_pStr = oth.m_pStr;
        oth.m_pStr = nullptr;
    }

    return *this;
}


MyString MyString::operator +(const MyString& oth)
{
    if (!m_pStr && !oth.m_pStr)

    {
        return MyString{};
    }

    else if (!m_pStr)

    {
        return MyString{oth.m_pStr};
    }
    else if (!oth.m_pStr)
    {
        return MyString{m_pStr};
    }

    size_t len1 = strlen(m_pStr);
    size_t len2 = strlen(oth.m_pStr) ;
    size_t totallen = len1 + len2;

    char* NewStr = new char[totallen + 1];

    std::copy(m_pStr, m_pStr + len1, NewStr);

    std::copy(oth.m_pStr, oth.m_pStr + len2, NewStr + len1);

    NewStr[totallen] = '\0';

    MyString New(NewStr);
    delete[] NewStr;

    return New;
}

MyString MyString::operator +(const char* str)
{
    if (!m_pStr && ! str)

    {
        return MyString{};
    }

    else if (!m_pStr)

    {
        return MyString{str};
    }
    else if (!str)
    {
        return MyString{m_pStr};
    }

    size_t len1 = strlen(m_pStr);
    size_t len2 = strlen(str) ;
    size_t totallen = len1 + len2;

    char* NewStr = new char[totallen + 1];

    std::copy(m_pStr, m_pStr + len1, NewStr);

    std::copy(str, str + len2, NewStr + len1);

    NewStr[totallen] = '\0';

    MyString New(NewStr);
    delete[] NewStr;

    return New;
}

MyString& MyString::operator +=(const MyString& oth)
{
    size_t len1 = m_pStr ? strlen(m_pStr) : 0;
    size_t len2 = oth.m_pStr ? strlen(oth.m_pStr) : 0;
    size_t totallen = len1 + len2;
    char* NewStr = new char[totallen + 1];

    if (m_pStr)
        std::copy(m_pStr, m_pStr + len1, NewStr);

    if (oth.m_pStr)
        std::copy(oth.m_pStr, oth.m_pStr + len2, NewStr + len1);

    NewStr[totallen] = '\0';
    delete[] this->m_pStr;
    this->m_pStr = NewStr;

    return *this;
}

MyString& MyString::operator +=(const char* str)
{
    size_t len1 = m_pStr ? strlen(m_pStr) : 0;
    size_t len2 = str ? strlen(str) : 0;
    size_t totallen = len1 + len2;
    char* NewStr = new char[totallen + 1];

    if (m_pStr)
        std::copy(m_pStr, m_pStr + len1, NewStr);

    if (str)
        std::copy(str, str + len2, NewStr + len1);

    NewStr[totallen] = '\0';
    delete[] this->m_pStr;
    this->m_pStr = NewStr;

    return *this;
}

bool MyString::operator ==(const MyString& oth)
{
    if(oth.m_pStr == nullptr)
    {
    return m_pStr == nullptr;
    }

    if(m_pStr == nullptr)
    {
        return false;
    }

    return strcmp(this->m_pStr, oth.m_pStr) == 0;

}

bool MyString::operator ==(const char* oth)
{
    if (oth == nullptr)
    {
    return m_pStr == nullptr;
    }

    if (m_pStr == nullptr)
    {
        return false;

    }
    return std::strcmp(m_pStr, oth) == 0;
}

std::ostream& operator<<(std::ostream& examp, const MyString& str)
{
    examp << str.GetString();
    return examp;
}

void MyString::StrSwap(MyString& oth)
{
 char * Temp = m_pStr;
 m_pStr = oth.m_pStr;
 oth.m_pStr = Temp;
}