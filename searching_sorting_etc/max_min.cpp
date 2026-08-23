#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;

pair<int, int> max_min(vector<int> &list){
	int max = list.at(0); int min = list.at(0);
	for(int i = 1; i<list.size(); i++){
		int x = list.at(i);
		if(x >= max) max = x;
		if(x <= min) min = x;
	}
	return pair<int, int>(max, min);
}

int second_max(vector<int> &list){
	if( list.size() == 1) return list.at(0);
	int max = list.at(0);
	int next_max = INT_MIN;

	for(int i=1; i<list.size(); i++){
		if(list.at(i) > max){
			next_max = max;
			max = list.at(i);
		}
		if(list.at(i) < max && list.at(i) > next_max)
			next_max = list.at(i);
	}
	return next_max;
}

int main(){
	vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int next_max = second_max(list);
	return next_max;
/*	pair<int, int> max_min_result = max_min(list);
	std::cout<< "Maximum of the list - "<< max_min_result.first<<endl;
	std::cout<< "Minimum of the list - "<< max_min_result.second<<endl;
*/}
