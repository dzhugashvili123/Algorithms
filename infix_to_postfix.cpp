//Try running with ./a.out 8 '+' 3 '*' '(' 2 '-' 5 ')' '/' 3

#include<iostream>
#include<cstdlib>
#include<stack>

int char_to_precedence(char op){
	switch(op){
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
			continue;
		}
		if( *(str[i]) == '(')
			stack.push('(');
		else if( *str[i] == ')'){
			while( stack.top() != '('){
				std::cout<< stack.top()<< "  ";
				stack.pop();
			}
			stack.pop();
		}
		else{
			int n = char_to_precedence( *(str[i]));
			if(n<=0)
				continue;
			if( stack.empty() || n > char_to_precedence(stack.top())) // cuurent precedene >= stack top precedence, = is for right associativity
				stack.push( *(str[i]));
			else {
				std::cout<< stack.top()<< "  ";
				stack.pop();
				stack.push( *(str[i]));	
			}
		}
	}

	while( !stack.empty()){
		std::cout<< stack.top()<< "  ";
		stack.pop();
	}
}

int main(int argc, char **argv){
	if(argc == 1)
		return 0;

	infix_to_postfix(argv+1, argc-1);
}
