/* Cantor representation of a number n, is n = ak*k! + ak-1*(k-1)! + ... a2*2! + a1*1!, where 0<=ai<=i
I discovered that give a number n, its cantor representation can only have AROUND log n / loglog n bits.
So, that is the time complexity of this algorithm.*/

#include<iostream>
#include<cstdlib>
#include<cmath>

long int factorial(int n){
	long int res = 1;
	while(n>1){
		res = res*n;
		--n;
	}
	return res;
}

void cantor_representation(long int n){
	int k = 0;
	long int fact = 1;
	while( fact * (k+1) <= n){	//This loop calculates the value of k such that k!<n and also calcualtes fact = k! which we will decrement and decrease later
		fact = fact * (k+1);
		k++;
	}

	while( k>0){
		int coeff = n / fact;
		std::cout<< coeff<< "  ";
		n = n % fact;
		fact = fact / k;
		--k;
	}
	std::cout<< std::endl;
}

int main(int argc, char **argv){
	if( argc < 2)
		return -1;

	int n = std::stol( argv[1]);
	cantor_representation( n);
}
