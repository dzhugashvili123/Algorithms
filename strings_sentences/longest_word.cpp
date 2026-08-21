#include<iostream>
#include<cstring>
using namespace std;

char *longest_word_finder(const char *sentence){
	char *longest_word_beginning = new char[30];
	const char *current_word_beginning = sentence;
	int current_word_length = 0;
	int longest_word_length = 0;

	while(*sentence != '\0'){
		if(*sentence == ' ' || *sentence == ',' || *sentence == ';' || *sentence == '.'){
			if(current_word_length > longest_word_length){
				strncpy(longest_word_beginning, current_word_beginning, current_word_length);
				*(longest_word_beginning + current_word_length) = '\0';
				longest_word_length = current_word_length;
			}
			current_word_length = 0;
			++sentence;
			current_word_beginning = sentence;
			continue;
		}
		++current_word_length;
		++sentence;
	}

	//If the sentence doesn't end with full-stiop, one final check has to be done
	if(current_word_length > longest_word_length){
		strncpy(longest_word_beginning,
		current_word_beginning,
		current_word_length);

		*(longest_word_beginning + current_word_length) = '\0';
	}
	
	return longest_word_beginning;
}

int main(){
	const char *sentence = "The curious programmer solved the difficult problem quickly.";
	char *longest_word = longest_word_finder(sentence);
	cout<< "The longest word in the sentence is - "<< longest_word<< endl;
}
