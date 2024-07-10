
#include "Menu.h"

void Menu::Menu_m()
{
	size_t Num;

	std::cout << "\t\tDatabase Menu\n";
	std::cout << "Print database -> 1\n";
	std::cout << "Add a new employee -> 2\n";
	std::cout << "Delete an employee -> 3\n";
	std::cout << "Delete all employees -> 4\n";
	std::cout << "Find an employee by Name -> 5\n";
	std::cout << "Exit the program -> 6\n";
	std::cout << "Number of employees: " << this->Data.count << std::endl;
	std::cout << "Reserved: " << this->Data.capacity - this->Data.count << std::endl;

	std::cin >> Num;

	switch (Num)
	{
	case 1: std::cout << this->Data; std::cout << std::endl; Backtomenu(); break;

	case 2: AddNewCrew(); break;

	case 3: DeleteForKey(); std::cout << "Returning to the menu...\n"; Custom_sleep(); std::cout << "\033[2J\033[1;1H"; Menu_m(); break;

	case 4: DeleteEveryone(); std::cout << "Returning to the menu...\n"; Custom_sleep(); std::cout << "\033[2J\033[1;1H"; Menu_m(); break;

	case 5: FindKeYAndPrint(); break;

	case 6: std::cout << "The program has finished\n"; return ;

	default: std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cout << "Error, returning to the menu\n"; Custom_sleep(); std::cout << "\033[2J\033[1;1H"; Menu_m(); break;

	}

}

void Menu::Backtomenu()
{
	std::string answer;

	std::cout << "Return to the menu? Press any key\n";

	std::cin >> answer;

	std::cout << "Returning to the menu...\n";

	Custom_sleep();

	std::cout << "\033[2J\033[1;1H";

	Menu_m();

}

void Menu::AddNewCrew()

{
	bool Addnew = true;
	while (Addnew) {
		char Name[100];
		std::cout << "Specify the key (full name)\n";
		std::cin.ignore();
		std::cin.getline(Name, 100);
		std::string Sex_str;
		MyData::Sex Sex;
		std::cout << "Specify the gender M or F\n";
		std::cin >> Sex_str;
		if (Sex_str == "M" || Sex_str == "m" || Sex_str == "M" || Sex_str == "m")
		{
			Sex = MyData::Sex::MALE;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		else if (Sex_str == "ж" || Sex_str == "Ж" || Sex_str == "F" || Sex_str == "f")
		{
			Sex = MyData::Sex::FEMALE;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Sex = MyData::Sex::FEMALE;
		}
		std::cout << "Specify the position at work\n";
		char Job[100];
		std::cin.getline(Job, 100);
		std::cout << "Enter your age\n";
		size_t Age;
		bool AgeTrue = false;
		while (!AgeTrue)
		{
			std::cin >> Age;

			if (std::cin.fail())
			{
				std::cout << "Input error\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			else
			{
				AgeTrue = true;
			}

		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter salary\n";
		float Salary;
		bool SalaryTrue = false;
		do
		{
			std::cin >> Salary;

			if (std::cin.fail())
			{
				std::cout << "Input error\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			else
			{
				SalaryTrue = true;
			}

		} while (!SalaryTrue);

		this->Data[Name] = MyData(Sex, Age, Job, Salary);
		std::cout << "Should I add more? ->(1)\n";
		size_t Num;
		std::cin >> Num;
		if (Num != 1) {
			Addnew = false;
			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Returning to menu...\n";

			Custom_sleep();

			std::cout << "\033[2J\033[1;1H";

			Menu_m();
		}
		
		
	}

	
}

void Menu::DeleteForKey()

{
	std::cout << "Enter the key:\n";
	char Name[100];
	std::cin.ignore();
	std::cin.getline(Name, 100);

	if (this->Data.CheckName(Name))

	{
		int Num = this->Data.DeletePair(Name);

		this->Data.count--;

		for (int i = Num; i < Data.count; i++)

		{
			Data.pBase[i] = Data.pBase[i + 1];

		}

		std::cout << "Deleting an employee from the database...\n";

	}

	else 

	{
		std::cout << "Employee not found\n";
	}

}

void Menu::DeleteEveryone() 

{
	if (this->Data.count != 0)

	{

		this->Data.count = 0;
		this->Data.capacity = 1;

	}

	else
	{

		std::cout << "Your database is empty\n";

	}

}

void Menu::FindKeYAndPrint() 

{

	char key[100];
	std::cout << "Enter the key: \n";
	std::cin.ignore();
	std::cin.getline(key, 100);
	if (this->Data.CheckName(key))

	{

		for (size_t i = 0; i < this->Data.count; i++) 

		{
			if (this->Data.pBase[i].Key == key)

			{
				std::cout << "№ " << i + 1 << std::endl;
				std::cout << "Name: \n";
				std::cout << this->Data.pBase[i].Key << std::endl;
				std::cout << "Gender: \n";
				std::cout << this->Data.pBase[i].data_m.Return_Sex() << std::endl;
				std::cout << "Age: \n";
				std::cout << this->Data.pBase[i].data_m.Return_m_age() << std::endl;
				std::cout << "Job Title: \n";
				std::cout << this->Data.pBase[i].data_m.Return_m_job() << std::endl;
				std::cout << "Salary: \n";
				std::cout << this->Data.pBase[i].data_m.Return_m_salary() << std::endl;

			}
		}


		Backtomenu();

	}

	else 

	{
		std::cout << "No such employee in the database\n";
		std::cout << "Returning to the menu...\n";
		Custom_sleep();
		std::cout << "\033[2J\033[1;1H";
		Menu_m();
	}

}
