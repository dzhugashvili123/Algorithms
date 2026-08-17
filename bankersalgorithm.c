#include<stdio.h>

int less_than_all_resources(int *procNeed, int *available, int n_resources){
	//arg1 is need of 1 process, i.e. NEED[i]. arg2 is number of resources
	//returns 1 if all of needs of process i are less than available, else 0

	for(int i=0; i<n_resources; i++){
		if(procNeed[i] > available[i]) return 0;
	}
	return 1;
}

int main(){
	int n_proc = -1, n_resources = -1;

	while( n_proc<1){
		printf("Enter number of processes(>=1) - "); scanf("%d", &n_proc);
	}
	while( n_resources<1){
		printf("Enter number of different types of resources(>=1) - "); scanf("%d", &n_resources);
	}
	int available[n_resources];
	printf("Enter the total number of instances of resources - ");
	for( int i=0; i<n_resources; i++)
		scanf("%d", &available[i]);
	printf("\n");

	int ALLOC[n_proc][n_resources], MAX[n_proc][n_resources], NEED[n_proc][n_resources];
	printf("Enter the allocation matrix - \n");
	for( int i=0; i<n_proc; i++)
		for(int j=0; j<n_resources; j++)
			scanf("%d", &ALLOC[i][j]);
	
	printf("\nEnter the maximum need matrix - \n");
	for( int i=0; i<n_proc; i++)
		for(int j=0; j<n_resources; j++)
			scanf("%d", &MAX[i][j]);

	//Calculate the need matrix
	for( int i=0; i<n_proc; i++)
		for(int j=0; j<n_resources; j++)
			NEED[i][j] = MAX[i][j] - ALLOC[i][j];

	//Calculating the acutal number of available resources
	for( int i=0; i<n_resources; i++){
		int sum_of_resource = 0;
		for(int j=0; j<n_proc; j++)
			sum_of_resource += ALLOC[j][i];
		available[i] -= sum_of_resource;
	}

	int process_finished[n_proc];	//1 for finished, 0 for unfinished
	int order_of_finish[n_proc];
	int order_counter = 0;
	for( int i=0; i<n_proc; i++)	//Setting the process_finished flag to 0 for all processes
		process_finished[i] = 0;

	for( int try=0; try<n_proc; try++){	//Upperbound on the number of tries
		for( int i=0; i<n_proc; i++){
			if( process_finished[i]) continue;
			if( less_than_all_resources( NEED[i], available, n_resources)){	//NEED < available
				process_finished[i] = 1;
				order_of_finish[order_counter] = i;
				++order_counter;
				//Reclaim the resources from ALLOC[i] to available
				for( int k=0; k<n_resources; k++)
					available[k] += ALLOC[i][k];
			}
		}
	}
	
	//Checking if all are finished. If order_counter < n_proc, then not all processes have been finished.
	if( order_counter != n_proc){
		printf("Deadlock occurence detected");
		return 1;
	}

	printf("One possible safe sequence -");
	for( int i=0; i<n_proc-1; i++) //Last printf should not end with ->, this is why the loop is till n_proc-1 not n_proc
		printf(" P%d -> ", order_of_finish[i]);
	printf(" P%d", order_of_finish[n_proc-1]);
}
