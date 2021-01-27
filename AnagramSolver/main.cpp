#include <iostream>
#include <string>
#include <array>

void ReorderString(std::string& word)
{
	int wordLength = 0;
	int i, j;
	char temp;
	//std::sort(word.begin(), word.end());
	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
	{
		//std::cout << *it << "\n";
		wordLength += 1;
	}

	i = 1;
	while (i < wordLength)
	{
		j = i;
		while ((j > 0) && (word[j - 1] > word[j]))
		{
			temp = word[j - 1];
			word[j - 1] = word[j];
			word[j] = temp;
			j -= 1;
		}
		i += 1;
	}
	std::cout << word;
}

int main()
{
	static const int s_Length = 6;
	std::array<std::string, s_Length> colour{ "blue", "red", "orange", "yellow", "silent", "listen"};
	std::string baseWord;
	std::cout << "Enter the word for which you find to search anagrams for in the list:\n";
	std::cin >> baseWord;
	ReorderString(baseWord);
	std::cin.get();
}
