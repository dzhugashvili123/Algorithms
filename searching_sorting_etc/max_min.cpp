#include<iostream>
#include<vector>
#include<utility>
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

int main(){
	vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	pair<int, int> max_min_result = max_min(list);
	std::cout<< "Maximum of the list - "<< max_min_result.first<<endl;
	std::cout<< "Minimum of the list - "<< max_min_result.second<<endl;
}
