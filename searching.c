#include<stdio.h>

int linear_search(int *arr, int n, int x){
	int i = 0;
	while( i<n && arr[i]!=x){
		i++;
	}
	if(i<n) return i;
	else return -1;
}

int binary_search(int *arr, int n, int x){
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

int main(){
	int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int x=7;
	int index = binary_search(arr, (int)(sizeof(arr)/sizeof(int)), x);

	if(index == -1) printf("The element does not exist in the array.");
	else printf("The element %d is present in index %d of the array.", x, index);
}

