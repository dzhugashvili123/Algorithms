#include<iostream>
#include<cstdlib>
#include<cmath>

long int fast_exponentiation(int x, int power){
	long int product = 1;
	if( x == 0 && power != 0) return 0;
	else if( x == 0 && power == 0){
		std::cout<< "0^0 is not mathematically defined"<< std::endl; exit(1);
	}
	else if( power == 0) return 1;

	while( power>0){
		if( power % 2 == 1) product = product * x;
		x = x * x;
		power = power >> 1;
	}
	return product;
}

int main(int argc, char **argv){
	if(argc < 3)
		return -1;

	int a = std::stoi(argv[1]);
	int n = std::stoi(argv[2]);

	std::cout<< "Result of " << a<< "^"<< n<< " is - "<< fast_exponentiation(a, n)<< std::endl;
}
