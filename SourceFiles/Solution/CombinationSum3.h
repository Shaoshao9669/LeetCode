#ifndef _COMBINATION_SUM_3_H_
#define _COMBINATION_SUM_3_H

/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations.The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output : [[1, 2, 4]]
Explanation :
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2 :
Input : k = 3, n = 9
Output : [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
Explanation :
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3 :
Input : k = 4, n = 1
Output : []
Explanation : There are no valid combinations.
Using 4 different numbers in the range[1, 9], the smallest sum we can get is 1 + 2 + 3 + 4 = 10 and since 10 > 1, there are no valid combination.
*/

#include "common.h"

namespace CombinationSum3
{
    class Solution {
    public:
		static vector<int> path;
		static vector<vector<int>> path_sum;
		
		static void dfs(int k, int start_index, int target, int sum)
		{
			if (target == sum && path.size() == k)
			{
				path_sum.push_back(path);
				return;
			}
			if (sum > target)
			{
				return;
			}

			for (int i = start_index; i < target; i++)
			{
				sum += i;
				path.push_back(i);
				dfs(k, i + 1, target, sum);
				path.pop_back();
				sum -= i;
			}
		}

		static vector<vector<int>> combinationSum3(int k, int n)
		{
			path.clear();
			path_sum.clear();
			dfs(k, 1, n, 0);
			return path_sum;
		}

		static void test()
		{
			int example1_k = 3, example1_n = 7;
			int example2_k = 3, example2_n = 9;
			int example3_k = 4, example3_n = 1;

			vector<vector<int>> output1, output2, output3;

			output1 = combinationSum3(example1_k, example1_n);
			output2 = combinationSum3(example2_k, example2_n);
			output3 = combinationSum3(example3_k, example3_n);

			OutputDoubleVector(output1);
			OutputDoubleVector(output2);
			OutputDoubleVector(output3);
		}
    };

	vector<int> Solution::path;
	vector<vector<int>> Solution::path_sum;
}

#endif // _COMBINATION_SUM_3_H_
