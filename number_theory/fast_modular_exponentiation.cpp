#include<iostream>
#include<cstdlib>
#include<cmath>

int fast_modular_exponentiation(int a, int n, int m){
	//We are calculation a^n mod m
	int rem = 1;
	int a_mod_m = a%m;
	while( n > 0){
		if( n%2 == 1) rem = (rem * a_mod_m) % m;
		a_mod_m = (a_mod_m * a_mod_m) % m;
		n = n >> 1;
	}
	return rem;
}

int main(int argc, char **argv){
	if(argc < 4)
		return -1;

	int a = std::stoi(argv[1]);
	int n = std::stoi(argv[2]);
	int m = std::stoi(argv[3]);

	std::cout<< "Result of " << a<< "^"<< n<< " mod " << m<< " is - "<< fast_modular_exponentiation(a, n, m)<< std::endl;
}
