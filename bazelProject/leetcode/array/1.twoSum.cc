#include "header.h"


std::vector<int> twoSum(const std::vector<int> &array, int sum){

	std::unordered_map<int,int> u_map;
	for(int idx = 0;idx < array.size(); ++idx){
		int sub = sum - array[idx];
		if(u_map.find(sub) != u_map.end()){
			return {u_map[sub], idx};
		}else{
			u_map[array[idx]] = idx;
		}
	}

	return {};
}