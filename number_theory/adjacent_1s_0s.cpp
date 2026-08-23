//This program counts the number of adjacent 1s( consequenctly adjacent 0s) in the binary representation of a number
#include<iostream>
#include<cstdlib>

int count_1s(int n){
	//Function borrowed from /number_theory/ones_zeroes_in_binary_rep.cpp
        int count = 0;
        while( n>0){
                ++count;
                n = n & (n-1); //Removes the rightmost 1 in n
        }

        return count;
}

int adjacent_1s(int n){
	
	int n_shr = n >> 1;
	
	int bitstring_denoting_1s = n & n_shr; //number of 1s here gives the number of adjacent 1s in n;
	int count = count_1s( bitstring_denoting_1s);
	return count;
}

int adjacent_0s(int n){
	//Extra careful here as if 13 = (1101), but is represented as (00000000 00001101), so we create a mask to find complement
	int bits_count = 0;
        int temp = n;
	int mask = 0;
        while(temp>0){	//If there are k bits, there will be k 1s in mask
                mask = (mask << 1) + 1;
                temp = temp >> 1;
        }
	int complement_1s = ~n & mask;
	return adjacent_1s(complement_1s);
}

int main(int argc, char **argv){
	if( argc==1 || argc>2) return -1;

	int n = atoi(argv[1]);
	int count_adj_1s = adjacent_1s(n);
	int count_adj_0s = adjacent_0s(n);

	std::cout<< "The number of adjacent 1s are - "<< count_adj_1s<< ", number of adjacent 0s are - "<< count_adj_0s<< std::endl;
}
