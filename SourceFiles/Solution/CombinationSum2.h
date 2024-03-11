#ifndef _COMBINATION_SUM_2_H_
#define _COMBINATION_SUM_2_H_

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
*/

#include "common.h"

namespace CombinationSum2
{
	class Solution {
	public:
		static vector<vector<int>> path_sum;
		static vector<int> path;

		static void dfs(vector<int>& candidates, int k, int sum, int target)
		{
			if (sum == target)
			{
				vector<int> temp;
				temp = path;
				sort(temp.begin(), temp.end());
				for (int j = 0; j < (int)path_sum.size(); j++)
				{
					if (temp == path_sum[j])
					{
						return;
					}
				}
				path_sum.push_back(temp);
			}

			if (sum > target)
			{
				return;
			}

			for (int i = k; i < (int)candidates.size(); i++)
			{
				sum += candidates[i];
				path.push_back(candidates[i]);
				dfs(candidates, i + 1, sum, target);
				path.pop_back();
				sum -= candidates[i];
			}
		}

		static vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
		{
			path_sum.clear();
			path.clear();
			dfs(candidates, 0, 0, target);
			return path_sum;
		}

		static void test()
		{
			vector<int> candidates1 = { 10, 1, 2, 7, 6, 1, 5 };
			int target1 = 8;
			vector<int> candidates2 = { 2, 5, 2, 1, 2 };
			int target2 = 5;

			vector<vector<int>> output1, output2;

			output1 = combinationSum2(candidates1, target1);
			output2 = combinationSum2(candidates2, target2);

			OutputDoubleVector(output1);
			OutputDoubleVector(output2);
		}
	};

	vector<vector<int>> Solution::path_sum;
	vector<int> Solution::path;
}


#endif // _COMBINATION_SUM_2_H_
