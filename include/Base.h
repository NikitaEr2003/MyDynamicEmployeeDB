
#include <ostream>
#include "Pair.h"
#include "MyData.h"
#include "Custom_sleep.h"
class Base 
{

	Pair* pBase;

	size_t count;

	size_t capacity;

public:

	Base();

	~Base();

	Base(const Base& bd);

	Base& operator =(const Base& bd);

	Base(Base&& bd) noexcept;

	Base& operator=(Base&& bd) noexcept;

	MyData& operator[](const char* key);

	int DeletePair(const char* key);

	friend std::ostream& operator<< (std::ostream& examp, Base& bd);

	bool CheckName(const char* ptr);

	friend class Menu;
};