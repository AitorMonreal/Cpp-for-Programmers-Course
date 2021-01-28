#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>

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
	
	//std::map<char, std::string> sortedWordsMap{ std::make_pair(wordList[0][0], wordList[0]) };
	std::vector<std::string> vectorWord = { wordList[0] };
	std::map<char, std::vector<std::string>> sortedWordsMap{ std::make_pair(wordList[0][0], vectorWord) };

	for (const std::string& word : wordList)  // const auto& is used because you're not modifying word. This also avoid making deep-copies of word - this is generally ok for ints or doubles because making copies is cheap, but this is not the case for strings, for instance.
	{
		bool present = false;
		for (const auto& element : sortedWordsMap)
		{
			if (element.first == word[0])
				present = true;
		}
		if (present == false)
			sortedWordsMap.insert(std::pair<char, std::vector<std::string>>(word[0], { word }));
	}
	std::cout << "MAP:\n\n";
	for (const auto& element : sortedWordsMap)
		std::cout << element.first << "      " << element.second[0] << "\n";

	std::cin.get();
}
