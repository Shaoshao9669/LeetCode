#ifndef _TWO_SUM_H_
#define _TWO_SUM_H_

/*
LeetCode 1:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2, 7, 11, 15], target = 9
Output : [0, 1]
Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].

Example 2 :
Input : nums = [3, 2, 4], target = 6
Output : [1, 2]

Example 3 :
Input : nums = [3, 3], target = 6
Output : [0, 1]
*/

#include "common.h"

namespace TwoSum
{
	class Solution
	{
	public:
		static vector<int> twoSum(vector<int>& nums, int target)
		{
			map<int, int> num_map;
			vector<int> res;

			for (int i = 0; i < (int)nums.size(); i++)
			{
				if (num_map.count(target - nums[i]) == 0)
				{
					num_map[nums[i]] = i;
				}
				else
				{
					res.push_back(num_map[target - nums[i]]);
					res.push_back(i);
				}
			}

			return res;
		}

		static void test()
		{
			vector<int> nums1 = { 2, 7, 11, 15 };
			int target1 = 9;
			vector<int> nums2 = { 3, 2, 4 };
			int target2 = 6;
			vector<int>	nums3 = { 3, 3 };
			int target3 = 6;

			vector<int> output1, output2, output3;

			output1 = twoSum(nums1, target1);
			output2 = twoSum(nums2, target2);
			output3 = twoSum(nums3, target3);

			OutputVector(output1);
			OutputVector(output2);
			OutputVector(output3);
		}
	};
}

#endif // _TWO_SUM_H_
