#include<iostream>
#include<cstdlib>
#include<cmath>

int gcd(int a, int b){
	if( a < 1 || b < 1){
		std::cout<< "Negative numbers in GCD fucntion"<< std::endl; exit(1);
	}
	int rem;
	while( b>0){
		rem = a % b;
		a = b;
		b = rem;
	}

	return a;
}

int prime_checking(int n){
	//returns 1 if prime, 0 else
	if( n == 1) return 0;	//1 is neither prime nor composite
	int sqrt_n = sqrt(n);
	for(int i=2; i <= sqrt_n; i++){
		if( n%i == 0)	return 0;
	}
	return 1;
}

int main(int argc, char **argv){
	if(argc < 3)
		return -1;

	int a = std::stoi(argv[1]);
	int b = std::stoi(argv[2]);

	std::cout<< "GCD of " << a<< ", "<< b<< " is - "<< gcd(a, b)<< std::endl;
}
