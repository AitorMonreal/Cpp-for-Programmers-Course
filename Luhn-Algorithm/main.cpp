#include <iostream>
#include "mainFunctions.h"

int main()
{
	int* accountNumber = AccountInput();
	bool result = CheckAccount(accountNumber);
	if (result == true)
		std::cout << "Account passed the check.\n";
	else
		std::cout << "Account failed to pass the check.\n";

	std::cin.get();
	return 0;
}
