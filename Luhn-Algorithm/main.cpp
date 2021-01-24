#include <iostream>

int* accountInput()
{
	int numberLength = 10;
	for (int i = 0; i < numberLength; i++)
	{
		std::cin >> "Enter the next number\n";

	}
}

int main()
{
	int* accountNumber = accountInput();
	std::cin.get();
	return 0;
}
