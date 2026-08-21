//Send the array as command line arguments

#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
}

void selection_sort(int *arr, int n){
        int local_min;
        for(int i=0; i<n-1; i++){
                local_min = i;
                int j = i+1;
                for(; j<n; j++){
                        if(arr[local_min] >= arr[j])
                                local_min = j;
                }
                swap(&arr[i], &arr[local_min]);
        }
}

int main(int argc, char **argv){

        if(argc == 1) return -1;

        int n = argc-1;

        int arr[n];
        for(int i=1; i<argc; i++)
                arr[i-1] = atoi(argv[i]);

        selection_sort(arr, sizeof(arr)/sizeof(int));
        printf("Sorted array - ");
        for(int i=0; i<n; i++)
                printf("%d  ", arr[i]);
}
