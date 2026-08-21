#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

float mean_finder(vector<int> &list){
	float sum = 0;
	for( auto num : list){
		sum += num;
	}
	return sum/(float)(list.size());
}

float median_finder(vector<int> &original_list){
	vector<int> list = original_list;
	sort(list.begin(), list.end());
	int n = list.size();
	float median;
	if( n % 2 == 0){	//Even elements
		int n_by_2 = list.at(n/2 - 1);
		int n_by_2_plus_1 = list.at(n/2);
		median = ((float)(n_by_2 + n_by_2_plus_1))/2;
	}
	else{	//Odd elements
		median = list.at(n/2);
	}
	return median;
}

int mode_finder(vector<int> &list){
	//REturn a single mode
	map<int, int> number_frequency;
	for( auto num: list){
		if(number_frequency.find(num) == number_frequency.end())	//Check if element is there in list, if not, then initialise with 1 because it is seen now
			number_frequency[num] = 1;
		else	++(number_frequency[num]);
	}

	int mode_freq = 0, mode = 0;
	for( auto num_freq: number_frequency){
		if(num_freq.second > mode_freq){
			mode = num_freq.first;
			mode_freq = num_freq.second;
		}
	}
	return mode;
}

int main(){
	vector<int> list = {37, 12, 45, 23, 37, 8, 71, 45, 16, 37, 56, 23, 89, 45, 12};
	float mean = mean_finder(list);
	float median = median_finder(list);
	int mode = mode_finder(list);
	cout<< "Mean of the list is - "<< mean<< endl;
	cout<< "Meadian of the list is - "<< median<< endl;
	cout<< "Mode of the list is - "<< mode<< endl;
}

