//Assume a valid postfix expression is given
//Try running with 8 3 2 '*' '+' 4 '-' as arguments, note that operatos will have to be inside '' as, shell will interpret * as wildcard operator

#include<iostream>
#include<stack>
#include<cctype>
#include<cstdlib>

int is_operator(char *c){
	//1 for operator, 0 otherwise
	if(*c == '+' || *c == '-' || *c == '*' || *c == '/')
		return 1;
	return 0;
}

int compute(int a, int b, char *c){
	switch(*c){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
	}
}

int main(int argc, char **argv){
	if(argc == 1){
		printf("No arguments"); exit(1);
	}

	int n = argc-1;
	std::stack<int> operand_stack;
	int i=1;
	while( i<argc){
		try{	//Cheking for number, it not a number will got to catch block
			int num = std::stoi(argv[i]);
			operand_stack.push( num);
		}
		catch( const std::invalid_argument&){
			if( is_operator(argv[i])){
				int b = operand_stack.top();	operand_stack.pop();
				int a = operand_stack.top(); operand_stack.pop();
				operand_stack.push(compute(a, b, argv[i]));
			}
		}
		i++;
	}

	if(operand_stack.size() == 1)
		return operand_stack.top();
	else exit(1);

}
