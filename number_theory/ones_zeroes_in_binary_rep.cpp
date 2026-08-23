//This program counts the number of 1s( consequently 0s) in the binary representation of a number
#include<iostream>
#include<cstdlib>

int count_1s(int n){
	int count = 0;
	while( n>0){
		++count;
		n = n & (n-1); //Removes the rightmost 1 in n
			      //If n=(m100000), then n-1=(m011111), the rightmost 1 becomes 0 and all 0s to its left will be 1, this is so when we AND, the rightmost 0s (which become 1s) are preserved as 0s(1 AND 0), while the in m the right most 1 will become 0 in n-1, and its AND will be 0, the remoining m-LSBs are same
	}

	return count;
}

int count_0s(int n){
	//We use the above function, but we complement n
	int no_bits = 0;
	int temp = n;
	while(temp>0){
		++no_bits;
		temp = temp >> 1;
	}

	int no_1s = count_1s(n);
	return no_bits - no_1s;
}

int main(int argc, char **argv){
	if(argc == 1 || argc > 2) return -1;
	
	int n = atoi(argv[1]);
	int count_of_1s = count_1s(n);
	int count_of_0s = count_0s(n);

	std::cout<< "The number of 0s is - "<< count_of_0s<< ", while the number of 1s is - "<< count_of_1s<< std::endl;
}
