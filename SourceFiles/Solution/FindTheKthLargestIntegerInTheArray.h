#ifndef _FIND_THE_KTH_LARGEST_INTEGER_IN_THE_ARRAY_H_
#define _FIND_THE_KTH_LARGEST_INTEGER_IN_THE_ARRAY_H_

/*
You are given an array of strings nums and an integer k.Each string in nums represents an integer without leading zeros.
Return the string that represents the kth largest integer in nums.
Note: Duplicate numbers should be counted distinctly.For example, if nums is["1", "2", "2"], "2" is the first largest integer, "2" is the second - largest integer, and "1" is the third - largest integer.

Example 1 :
Input : nums = ["3", "6", "7", "10"], k = 4
Output : "3"
Explanation :
The numbers in nums sorted in non - decreasing order are["3", "6", "7", "10"].
The 4th largest integer in nums is "3".

Example 2 :
Input : nums = ["2", "21", "12", "1"], k = 3
Output : "2"
Explanation :
The numbers in nums sorted in non - decreasing order are["1", "2", "12", "21"].
The 3rd largest integer in nums is "2".

Example 3 :
Input : nums = ["0", "0"], k = 2
Output : "0"
Explanation :
The numbers in nums sorted in non - decreasing order are["0", "0"].
The 2nd largest integer in nums is "0".
*/

#include "common.h"

namespace FindTheKthLargestIntegerInTheArray
{
	class Solution 
	{
	public:
		static int StringToInt(string str)
		{
			int integer = 0;

			for (int i = 0; i < (int)str.size(); i++)
			{
				integer = integer * 10 + (str[i] - '0');
			}

			return integer;
		}

		static string kthLargestNumber(vector<string>& nums, int k)
		{
			priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;

			for (int i = 0; i < (int)nums.size(); i++)
			{
				q.push({ StringToInt(nums[i]), nums[i]});
				if ((int)q.size() > k)
				{
					q.pop();
				}
			}

			return q.top().second;
		}

		static void test()
		{
			vector<string> nums1 = { "3", "6", "7", "10" }; int k1 = 4;
			vector<string> nums2 = { "2", "21", "12", "1" }; int k2 = 3;
			vector<string> nums3 = { "0", "0" }; int k3 = 2;

			string output1 = kthLargestNumber(nums1, k1);
			string output2 = kthLargestNumber(nums2, k2);
			string output3 = kthLargestNumber(nums3, k3);

			OutputString(output1);
			OutputString(output2);
			OutputString(output3);
		}
	};
}




#endif // _FIND_THE_KTH_LARGEST_INTEGER_IN_THE_ARRAY_H_
