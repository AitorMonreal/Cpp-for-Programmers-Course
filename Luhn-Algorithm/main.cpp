#include <iostream>
constexpr int numberLength = 10;

int* AccountInput()
{
	int accountNumber[numberLength];
	for (int i = 0; i < numberLength; i++)
	{
		std::cout << "Enter the next number for the account\n";
		std::cin >> accountNumber[i];
	}
	return accountNumber;
}

void CheckAccount(int* accountNumber)
{
	DoubleValue(int* accountNumber);
	SumElements(int* accountNumber);
	FindModulo(int* accountNumber);
}

void DoubleValue(int* accountNumber)
{
	
}

int main()
{
	int* accountNumber = AccountInput();
	CheckAccount(accountNumber);
	std::cin.get();
	return 0;
}
