#include<iostream>
#include<cstdlib>

int linear_search(int *arr, int n, int x){
//Returns the index if it exists, -1 else
        int i = 0;
        while( i<n && arr[i]!=x){
                i++;
        }
        if(i<n) return i;
        else return -1;
}

int linear_search_rec(int *arr, int beg, int last, int x){
	if( arr[beg] == x)
		return beg;
	if( beg == last)
		return -1;
	return linear_search_rec( arr, beg+1, last, x);
}

int main(int argc, char **argv){
	//Last argument is the number to be searched
	//Returns index if it exists, -1 else

	if(argc == 1 || argc == 2) return -1;

	int number_of_elements = argc-2;
	int element_to_search = std::atoi(argv[argc - 1]);

	int arr[number_of_elements];
	for(int i=1; i<argc-1; i++)
		arr[i-1] = std::atoi(argv[i]);

	int result = linear_search_rec(arr, 0, number_of_elements,  element_to_search);
	return result;
}
