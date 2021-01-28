#include <iostream>
#include <string>
#include <array>

constexpr int s_Length = 6;

void ReorderString(std::string& word);
void InsertionSort(std::string& word, int* ptrLength);

void ReorderList(std::array<std::string, s_Length>& list)
{
	for (int i = 0; i < s_Length; i++) {
		ReorderString(list[i]);
	}
}

void ReorderString(std::string& word)
{
	int wordLength = 0;
	int* ptrWordLength = &wordLength;
	//std::sort(word.begin(), word.end());
	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
	{
		//std::cout << *it << "\n";
		wordLength += 1;
	}
	InsertionSort(word, ptrWordLength);
}

void InsertionSort(std::string& word, int* ptrLength) {
	int i, j;
	char temp;
	i = 1;
	while (i < *ptrLength)
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
	//std::cout << word;
}

int main()
{
	//static const int s_Length = 6;
	std::array<std::string, s_Length> wordList{ "blue", "red", "orange", "yellow", "silent", "listen"};
	std::string baseWord;
	std::cout << "Enter the word for which you want to search anagrams for in the list:\n";
	std::cin >> baseWord;
	ReorderString(baseWord);

	ReorderList(wordList);
	for (int i = 0; i < s_Length; i++) {
		std::cout << wordList[i] << "\n";
	}
	std::cin.get();
}
