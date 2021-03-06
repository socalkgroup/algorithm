// twosum_thkim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

namespace
{
	vector<pair<int, int>> Solution(const vector<int>& input, int sum)
	{
		vector<pair<int, int>> result;
		unordered_map<int, int> hashMap;
		
		auto find = [&](int val) -> int
		{
			auto it = hashMap.find(val);
			if (it == hashMap.end())
				return -1;
			return it->second;
		};

		for (auto it = input.begin(); it != input.end(); ++it)
		{
			auto idx = distance(input.begin(), it);
			auto& val = *it;
			hashMap[val] = idx;

			auto candi = sum - val;
			auto idx2 = find(candi);
			if (idx2 >= 0 && idx2 != idx)
			{
				result.emplace_back(make_pair(idx, idx2));
			}
		}

		return result;
	}
}


int main()
{
	vector<int> input = { 1,3,5,6,7,8 };
	auto sum = 10;

	vector<pair<int, int>> result = Solution(input, sum);

	for (auto& r : result)
	{
		cout << "[" << r.first << "," << r.second << "]" << endl;
	}

    return 0;
}

