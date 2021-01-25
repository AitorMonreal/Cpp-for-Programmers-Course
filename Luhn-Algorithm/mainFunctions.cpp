#include <iostream>
#include "mainFunctions.h"
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

bool CheckAccount(int* accountNumber)
{
	DoubleValue(accountNumber);
	return FindModulo(accountNumber);
}

void DoubleValue(int* accountNumber)
{
	for (int i = numberLength - 1; i >= 0; i--)
	{
		if ((i % 2) != 0) {
			accountNumber[i] = 2 * accountNumber[i];
			if (accountNumber[i] > 10)
				accountNumber[i] -= 9;
		}
	}
}

bool FindModulo(int* accountNumber)
{
	bool result = false;
	int elementSum = 0;
	for (int i = 0; i < numberLength; i++)
		elementSum += accountNumber[i];

	if (elementSum % 10 == 0)
		result = true;

	return result;
}