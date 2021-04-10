#include<iostream>
#include<unordered_map>

std::pair<int,int> twosum(const std::std::vector<int> &array, int sum){

	std::unordered_map<int,int> u_map;
	for(unsigned long idx = 0;idx < array.size();++i){
		int sub = sum - u_map[idx];
		if(u_map.find(sub) != array.end()){
			return make_pair(u_map[sub],idx);
		}else{
			u_map[sub] = idx;
		}
	}

	return make_pair(0,0);
}