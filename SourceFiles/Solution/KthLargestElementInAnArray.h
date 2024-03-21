#ifndef _KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H_
#define _KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H_

/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting ?

Example 1 :
Input : nums = [3, 2, 1, 5, 6, 4], k = 2
Output : 5

Example 2 :
Input : nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output : 4
*/

#include "common.h"

namespace KthLargestElementInAnArray
{
	class Solution
	{
	public:
		static int findKthLargest(vector<int>& nums, int k)
		{
			priority_queue<int, vector<int>, greater<int>> q;

			for (int i = 0; i < (int)nums.size(); i++)
			{
				q.push(nums[i]);
				if ((int)q.size() > k)
				{
					q.pop();
				}
			}

			return q.top();
		}

		static void test()
		{
			vector<int> nums1 = { 3, 2, 1, 5, 6, 4 }; int k1 = 2;
			vector<int> nums2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 }; int k2 = 4;

			int output1 = findKthLargest(nums1, k1);
			int output2 = findKthLargest(nums2, k2);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
		}
	};
}


#endif // _KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H_
