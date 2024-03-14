#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

#include "common.h"

namespace BinarySearch
{
	class Solution
	{
	public:
		static int search(vector<int>& nums, int target)
		{
			int left = 0, right = nums.size() - 1;
			int middle;

			while (left != right)
			{
				middle = (left + right) / 2;
				if (nums[middle] > target)
				{
					right = middle - 1;
				}
				else if (nums[middle] < target)
				{
					left = middle + 1;
				}
				else
				{
					return middle;
				}
			}

			return -1;
		}

		static void test()
		{
			vector<int> nums1 = { -1,0,3,5,9,12 };
			int target1 = 9;
			vector<int> nums2 = { -1,0,3,5,9,12 };
			int target2 = 2;

			int output1, output2;

			output1 = search(nums1, target1);
			output2 = search(nums2, target2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}

#endif // _BINARY_SEARCH_H_
