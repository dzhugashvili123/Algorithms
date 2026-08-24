//Send the array as command line arguments

#include<iostream>
#include<cstdlib>

void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
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

int main(int argc, char **argv){

        if(argc == 1) return -1;

        int n = argc-1;

        int arr[n];
        for(int i=1; i<argc; i++)
                arr[i-1] = std::atoi(argv[i]);

        insertion_sort(arr, sizeof(arr)/sizeof(int));
        std::cout<< "Sorted array - ";
        for(int i=0; i<n; i++)
                std::cout<< arr[i]<< "  ";
}
