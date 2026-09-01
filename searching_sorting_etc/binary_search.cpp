#include<iostream>
#include<cstdlib>

int binary_search(int *arr, int n, int x){
//Returns index if it exists, -1 else
        int i = 0, j = n-1;
        int m;
        while( i<j ){
                m = (i+j)/2;
                if( x > arr[m] ) i = m+1;
                else j = m;
        }
        if( x == arr[i]) return i;
        else return -1;
}

int binary_search_rec(int *arr, int beg, int last, int x){
	int mid = (beg + last)/2;

	if( arr[mid] == x)
		return mid;
	else if( x > arr[mid] && mid < last)
		return binary_search_rec(arr, mid+1, last, x);
	else if( x < arr[mid] && mid > beg)
		return binary_search_rec(arr, beg, mid-1, x);
	return -1;
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

        int result = binary_search_rec(arr, 0, number_of_elements,  element_to_search);
        return result;
}
