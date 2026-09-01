#include<iostream>
#include<cstdlib>

int fibonacci_number_rec( int n){
	if( n == 0)
		return 0;
	if( n == 1)
		return 1;
	return fibonacci_number_rec( n-1) + fibonacci_number_rec( n-2);
}

int fibonacci_number(int n){
	if( n==0)
		return 0;
	if( n==1)
		return 1;

	int x, y, z;
	x = 0, y = 1, z;
	int i = 2;
	while( i<=n){
		z = x + y;
		x = y;
		y = z;
		i++;
	}
	return z;
}

int main(int argc, char **argv){
	if( argc < 2)
		return -1;
	int n = std::stoi( argv[1]);
	int fib = fibonacci_number( n);
	std::cout<< "The "<< n<< "th fibonacci number is - "<< fib<< std::endl;
}
