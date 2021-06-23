#include "header.h"


std::pair<int,int> twosum(const std::vector<int> &array, int sum){

	std::unordered_map<int,int> u_map;
	for(size_t idx = 0;idx < array.size(); ++idx){
		int sub = sum - u_map[idx];
		if(u_map.find(sub) != u_map.end()){
			return std::make_pair(u_map[sub],idx);
		}else{
			u_map[sub] = idx;
		}
	}

	return std::make_pair(0,0);
}