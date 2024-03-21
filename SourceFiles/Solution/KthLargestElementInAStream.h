#ifndef _KTH_LARGEST_ELEMENT_IN_A_STREAM_H_
#define _KTH_LARGEST_ELEMENT_IN_A_STREAM_H_

/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
Implement KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

Example 1:
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
*/

#include "common.h"

namespace KthLargestElementInAStream
{
	class Solution
	{
	public:
		class KthLargest
		{
		public:
			KthLargest(int k, vector<int>& nums) 
			{
				for (const auto& c : nums) 
				{
					q.push(c);
					if ((int)q.size() > k)
					{
						q.pop();
					}
				}
				index = k;
			}

			int add(int val) 
			{
				q.push(val);
				if ((int)q.size() > index)
				{
					q.pop();
				}
				return q.top();
			}
		private:
			int index;
			priority_queue<int, vector<int>, greater<int>> q; 
		};

		static void test()
		{
			vector<int> nums = { 4, 5, 8, 2 };
			KthLargest* kthLargest = new KthLargest(3, nums);

			int para1 = kthLargest->add(3);   // return 4
			int para2 = kthLargest->add(5);   // return 5
			int para3 = kthLargest->add(10);  // return 5
			int para4 = kthLargest->add(9);   // return 8
			int para5 = kthLargest->add(4);   // return 8

			OutputSingleNumber(para1);
			OutputSingleNumber(para2);
			OutputSingleNumber(para3);
			OutputSingleNumber(para4);
			OutputSingleNumber(para5);
		}
	};
}

#endif // _KTH_LARGEST_ELEMENT_IN_A_STREAM_H_
