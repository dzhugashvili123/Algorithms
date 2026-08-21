#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int anagram_checker(const char *word1, const char *word2){
	//Returns 1 if anagram, 0 else
	map<char, int> word1char_map, word2char_map;
	const char *word1_p = word1, *word2_p = word2;

	if(strlen(word1) != strlen(word2))
		return 0;

	int len = strlen(word1);
	for(int i=0; i<len; i++){
		if(word1char_map.find(*word1_p) == word1char_map.end()){
			word1char_map.insert({ *word1_p, 1});
			++word1_p;
			continue;
		}
		++word1char_map.at(*word1_p);
		++word1_p;
	}

	for(int i=0; i<len; i++){
		if(word2char_map.find(*word2_p) == word2char_map.end()){
			word2char_map.insert({ *word2_p, 1});
			++word2_p;
			continue;
		}
		++word2char_map.at(*word2_p);
		++word2_p;
	}

	for( auto element : word1char_map){
		if(word2char_map.find(element.first) == word2char_map.end())	//The char is not there in second word
			return 0;
		if(element.second != word2char_map.at(element.first))	//There different frequencies of a character
			return 0;
	}

	return 1;

}

int main(){
	const char *word1 = "listen";
	const char *word2 = "silento";
	int is_anagram = anagram_checker(word1, word2);
	if( is_anagram == 1)
		cout<< "The words are anagrams"<< endl;
	else
		cout<< "The words are not anagrams."<< endl;
}
