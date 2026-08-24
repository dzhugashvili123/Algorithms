#include<iostream>
#include<cstdlib>
#include<stack>

void char_to_precedence(char *op){
	switch(*op){
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		default: return -1;
	}
}

void infix_to_postfix(char **str, int n){
	std::stack<char> stack;
	for(int i = 0; i<n; i++){
		if( std::isdigit( *(str[i]))){
			std::cout<< str[i]<< "  ";
			i++;
			continue;
		}
		/////////
		
	}
}

int main(int argc, char **argv){
	if(argc == 1)
		return 0;

	infix_to_postfix(argv+1, argc-1);
}
