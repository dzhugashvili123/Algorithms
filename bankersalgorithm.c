#include<stdio.h>
#include<stdlib.h>

int main(){
	int n_proc, n_resources;

	while(n_proc<1){
		printf("Enter number of processes(>=1) - "); scanf("%d\n", &n_proc);
	}
	while(n_resources<1){
		printf("Enter number of different types of resources(>=1) - "); scanf("%d\n", &n_resources);
	}
	int available[n_resources];
	printf("Enter the total number of instances of resources - ");
	for(int i=0; i<n_resources; i++)
		scanf("%d", &available[i]);
	printf("\n");

	int ALLOC[n_proc][n_resources], MAX[n_proc][n_resources], NEED[n_proc][n_resources];
	printf("Enter the allocation matrix - \n");
	for(int i=0; i<n_proc; i++)
		for(int j=0; j<n_resources; j++)
			scanf("%d", &ALLOC[i][j]);
	
	printf("\nEnter the maximum need matrix - \n");
	for(int i=0; i<n_proc; i++)
		for(int j=0; j<n_resources; j++)
			scanf("%d", &MAX[i][j]);

	//Calculate the need matrix
	for(int i=0; i<n_proc; i++)
		for(int j=0; j<n_resources; j++)
			NEED[i][j] = MAX[i][j] - ALLOC[i][j];

	//Calculating the acutal number of available resources
	for(int i=0; i<n_resources; i++){
		int sum_of_resource = 0;
		for(int j=0; j<n_proc; j++)
			sum_of_resource += NEED[j][i];
		available[i] = sum_of_resource;
	}

	int process_finished[n_proc];	//1 for finished, 0 for unfinished
	for(int i=0; i<n_proc; i++)
		process_finished[i] = 0;

}
