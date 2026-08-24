//Find out there exists a triplet with sum of two elements of array is also in array
//We first push all values of ai to set S which taks O(n). Then we loop thorough all values of ai, aj to find if their sum is in set S, this takes O(n^2)*O(1)

#include<iostream>
#include<set>
#include<cstdlib>

int main(int argc, char **argv){
	//1 for triplet exists, 0 if it doesnt, -1 for error
	if(argc < 4)
		return -1;

	std::set<int> element_lookup;
	int n = argc - 1;
	int arr[n];
	for(int i = 1; i<argc; i++){
		arr[i-1] = atoi( argv[i]);
		element_lookup.insert( arr[i-1]);
	}

	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			int sum = arr[i] + arr[j];
			if(element_lookup.find( sum) != element_lookup.end())
				return 1;
		}
	}
	return 0;
}
