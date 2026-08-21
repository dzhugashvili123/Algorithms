//Send the array as command line arguments

#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
}

void bubble_sort(int *arr, int n){
        for(int i=0; i<n-1; i++){
                for(int j=0; j<n-i-1; j++){
                        if( arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
                }
        }
}

int main(int argc, char **argv){

        if(argc == 1) return -1;

        int n = argc-1;

        int arr[n];
        for(int i=1; i<argc; i++)
                arr[i-1] = atoi(argv[i]);

	bubble_sort(arr, sizeof(arr)/sizeof(int));
	printf("Sorted array - ");
	for(int i=0; i<n; i++)
		printf("%d  ", arr[i]);
}
