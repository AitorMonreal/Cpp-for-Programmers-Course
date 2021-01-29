#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>

constexpr int s_Length = 10;

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

std::ostream& operator<<(std::ostream& stream, const std::vector<std::string>& wordVector)
{
	std::vector<std::string>::const_iterator it;
	for (it = wordVector.begin(); it != wordVector.end(); it++)
		stream << *it << ", ";
	//stream << "\n";
	return stream;
}

int main()
{
	//static const int s_Length = 6;
	std::array<std::string, s_Length> wordList{ "blue", "red", "orange", "yellow", "silent", "listen", "arc", "car", "below", "night" };
	std::cout << "List of words:\n";
	for (int i = 0; i < s_Length; i++)
		std::cout << wordList[i] << "\n";

	std::string baseWord;
	std::cout << "\nEnter the word for which you want to search anagrams for in the list:\n";
	std::cin >> baseWord;
	ReorderString(baseWord);

	ReorderList(wordList);
	std::cout << "\nReordered list of words:\n";
	for (int i = 0; i < s_Length; i++)
		std::cout << wordList[i] << "\n";

	//std::map<char, std::string> sortedWordsMap{ std::make_pair(wordList[0][0], wordList[0]) };
	//std::vector<std::string> wordVector({ wordList[0] });
	//std::map<char, std::vector<std::string>> sortedWordsMap{ std::make_pair(wordList[0][0], wordVector) };

	//Create the Map of words
	std::map<char, std::vector<std::string>> sortedWordsMap;
	bool present;
	for (const std::string& word : wordList)  // const auto& is used because you're not modifying word. This also avoid making deep-copies of word - this is generally ok for ints or doubles because making copies is cheap, but this is not the case for strings, for instance.
	{
		present = false;
		for (const auto& element : sortedWordsMap)
		{
			if (element.first == word[0])
			{
				present = true;
				sortedWordsMap[element.first].push_back(word);  //map[key] == element in map for that key
			}
		}
		if (present == false)
			sortedWordsMap.insert(std::pair<char, std::vector<std::string>>(word[0], { word }));
	}
	std::cout << "\nWord Map:\n";
	for (const auto& element : sortedWordsMap)
		//std::cout << std::vector<std::string>(element.second);
		std::cout << element.first << "      " << std::vector<std::string>(element.second) << "\n";

	//Search for the base word in the Map, first finding the letter which it belongs to, and then in those elements
	present = false;
	for (const auto& element : sortedWordsMap)
	{
		if (element.first == baseWord[0]) {
			present = true;
			break;
		}
	}

	if (present == true)
	{
		present = false;
		for (const auto& word : sortedWordsMap[baseWord[0]])
		{
			if (baseWord == word)
			{
				present = true;
				break;
}
		}

	}

	if (present == true)
		std::cout << "\n\nThe word has an anagram in the list.\n\n";

	else
		std::cout << "\n\nNo anagram found in the list.\n\n";

	std::cin.get();
}
