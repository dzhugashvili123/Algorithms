#include<iostream>
#include<cstdlib>
#include<cstring>

int naive_stringmatcher(char *str, char *substr){
	int n = std::strlen(str);
	int m = std::strlen(substr);
	int index = 0;
	int substr_found = 0;
	for(; index<n-m+1; index++){
		for(int j=0; j<m; j++){
			if( str[index+j] != substr[j])
				break;
			else if( str[index+j] == substr[j] && j==(m-1))
				substr_found = 1;
		}
		if(substr_found == 1)
			return index;
	}
	return -1;
}

int main(int argc, char **argv){
	if(argc < 3)
		exit(1);

	char *str = argv[1];
	char *substr = argv[2];
	int index_substr = naive_stringmatcher(str, substr);
	if( index_substr == -1)
		std::cout<< "String not matched"<< std::endl;
	else
		std::cout<< "String matched from the index - "<< index_substr<< std::endl;
}
