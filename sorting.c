#include<stdio.h>

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

void insertion_sort(int *arr, int n){
	for(int i=1; i<n; i++){
		int j=0;
		while(j<i && arr[j]<arr[i]) j++;
		int temp = arr[i];
		for(int k=j; k<=i; k++){
			swap(&temp, &arr[k]);
		}
	}
}

int main(){
	int arr[] = {5, 12, 17, 21, 42, 50, 63, 76, 89, 94};
	insertion_sort( arr, sizeof(arr)/sizeof(int));
	
	printf("Sorted array - ");
	//Printing elements
	for(int i=0; i<(sizeof(arr)/sizeof(int)); i++)
		printf("%d  ", arr[i]);
	
}
