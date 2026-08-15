#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
	if( a < 1 || b < 1){
		printf("Negative numbers in GCD fucntion"); exit(1);
	}
	int rem;
	while( b>0){
		rem = a % b;
		a = b;
		b = rem;
	}

	return a;
}

long int fast_exponentiation(int x, int power){
	long int product = 1;
	if( x == 0 && power != 0) return 0;
	else if( x == 0 && power == 0){
		printf("0^0 is not mathematically defined"); exit(1);
	}
	else if( power == 0) return 1;

	while( power>0){
		if( power % 2 == 1) product = product * x;
		x = x * x;
		power = power >> 1;
	}
	return product;
}

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

int main(){
	printf("%d", fast_modular_exponentiation(7, 11, 5));
}
