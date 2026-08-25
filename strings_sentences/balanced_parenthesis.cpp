//From the input (not command line) check if the expression is balanced or not

#include<iostream>
#include<stack>
#include<cstring>

int balanced_parenthesis_check(char *str, int len){
	//Return 1 if balanced, 0 else

	std::stack<char> parenthesis_stack;
	
	for(int i=0; i<len; i++){
		if( str[i] == '(' || str[i] == '{' || str[i] == '[')
			parenthesis_stack.push( str[i]);
		else if( str[i] == ')' || str[i] == '}' || str[i] == ']'){
			if( parenthesis_stack.empty())
				return 0;

			if( (str[i] == ')' && parenthesis_stack.top() == '(') || (str[i] == '}' && parenthesis_stack.top() == '{') || (str[i] == ']' && parenthesis_stack.top() == '['))
				parenthesis_stack.pop();
			else
				return 0;
		}
		
	}

	if( parenthesis_stack.empty())
		return 1;
	return 0;
}

int main(){
	char exp[150];
	std::cout<< "Enter your string - ";
	std::cin.getline(exp, 149);

	int balanced_flag = balanced_parenthesis_check(exp, std::strlen(exp));
	if( balanced_flag)
		std::cout<< "The expression is balanced."<< std::endl;
	else
		std::cout<< "The expression is not balanced."<< std::endl;
}
