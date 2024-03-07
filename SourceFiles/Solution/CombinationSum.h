#ifndef _COMBINATION_SUM_H_
#define _COMBINATION_SUM_H

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []
*/

#include "common.h"

namespace CombinationSum
{
	class Solution {
	public:
		static vector<int> path;
		static vector<vector<int>> path_sum;

		static void dfs(vector<int>& candidates, int k, int sum, int target)
		{
			if (sum == target)
			{
				path_sum.push_back(path);
				return;
			}
			if (sum > target)
			{
				return;
			}

			for (int i = k; i < (int)candidates.size(); i++)
			{
				sum = sum + candidates[i];
				path.push_back(candidates[i]);
				dfs(candidates, i, sum, target);
				path.pop_back();
				sum = sum - candidates[i];
			}
		}

		static vector<vector<int>> combinationSum(vector<int>& candidates, int target)
		{
			path.clear();
			path_sum.clear();
			dfs(candidates, 0, 0, target);
			return path_sum;
		}

		static void test()
		{
			vector<int> candidates1 = { 2, 3, 6, 7 };
			int target1 = 7;
			vector<int> candidates2 = { 2, 3, 5 };
			int target2 = 8;
			vector<int> candidates3 = { 2 };
			int target3 = 1;

			vector<vector<int>> output1, output2, output3;

			output1 = combinationSum(candidates1, target1);
			output2 = combinationSum(candidates2, target2);
			output3 = combinationSum(candidates3, target3);

			OutputDoubleVector(output1);
			OutputDoubleVector(output2);
			OutputDoubleVector(output3);
		}
	};

	vector<int> Solution::path;
	vector<vector<int>> Solution::path_sum;
}

#endif // _COMBINATION_SUM_H_
