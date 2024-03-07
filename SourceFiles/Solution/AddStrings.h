#ifndef _ADD_STRINGS_H_
#define _ADD_STRINGS_H_

/*
Given two non - negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built - in library for handling large integers(such as BigInteger).You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
*/

#include "common.h"

namespace AddStrings
{
	class Solution
	{
	public:
		static string addStrings(string num1, string num2) 
		{
			string str;

			reverse(num1.begin(), num1.end());
			reverse(num2.begin(), num2.end());
			
			int num1_size = num1.size();
			int num2_size = num2.size();
			int i = 0;
			int sum = 0, carry = 0, res;

			while (num1_size > 0 && num2_size > 0)
			{
				sum = (num1[i] - '0') + (num2[i] - '0') + carry;

				res = sum % 10;
				carry = sum / 10;
				str.push_back('0' + res);

				num1_size--;
				num2_size--;
				i++;
			}

			while (num1_size > 0)
			{
				sum = (num1[i] - '0') + carry;

				res = sum % 10;
				carry = sum / 10;

				str.push_back('0' + res);
				num1_size--;
				i++;
			}

			while (num2_size > 0)
			{
				sum = (num2[i] - '0') + carry;

				res = sum % 10;
				carry = sum / 10;

				str.push_back('0' + res);
				num2_size--;
				i++;
			}

			if (carry == 1)
			{
				str.push_back('1');
			}

			reverse(str.begin(), str.end());

			return str;
		}

		static void test()
		{
			string example1_num1 = "11", example1_num2 = "123";
			string example2_num1 = "456", example2_num2 = "77";
			string example3_num1 = "0", example3_num2 = "0";

			string output1, output2, output3;

			output1 = addStrings(example1_num1, example1_num2);
			output2 = addStrings(example2_num1, example2_num2);
			output3 = addStrings(example3_num1, example3_num2);

			OutputString(output1);
			OutputString(output2);
			OutputString(output3);
		}
	};
}

#endif // _ADD_STRINGS_H_
