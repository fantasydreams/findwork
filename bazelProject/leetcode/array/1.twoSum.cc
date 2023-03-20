#include "header.h"


std::vector<int> twoSum(const std::vector<int> &array, int sum) {

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

std::vector<int> twoSum1(const std::vector<int>& nums, int target) {
	std::unordered_map<int, int> hashMap; //nums[idx] to idx;
	for(decltype(nums.size()) i = 0; i < nums.size(); ++i) {
		auto pIter = hashMap.find(target - nums[i]);
		if(pIter != hashMap.end()) {
			return {pIter->second, static_cast<int>(i)};
		}
		hashMap[nums[i]] = i;
	}

	return {};
}