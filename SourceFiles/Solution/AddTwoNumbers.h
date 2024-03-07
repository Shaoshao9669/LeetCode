#ifndef _ADD_TWO_NUMBERS_H_
#define _ADD_TWO_NUMBERS_H_

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

#include "common.h"
#include "memory.h"

namespace AddTwoNumbers
{
	class Solution
	{
	public:
		static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			ListNode* head = new ListNode();
			ListNode* res = head;

			int sum = 0;
			int carry = 0;

			while (l1 != NULL && l2 != NULL)
			{
				sum = l1->val + l2->val + carry;
				
				res->val = sum % 10;
				carry = sum / 10;
				if (l1->next != NULL || l2->next != NULL)
				{
					res->next = new ListNode();
					res = res->next;
				}
				l1 = l1->next;
				l2 = l2->next;
			}

			while (l1 != NULL)
			{
				sum = l1->val + carry;

				res->val = sum % 10;
				carry = sum / 10;
				if (l1->next != NULL)
				{
					res->next = new ListNode();
					res = res->next;
				}	
				l1 = l1->next;
			}

			while (l2 != NULL)
			{
				sum = l2->val + carry;

				res->val = sum % 10;
				carry = sum / 10;
				if (l2->next != NULL)
				{
					res->next = new ListNode();
					res = res->next;
				}
				l2 = l2->next;
			}

			if (carry == 1)
			{
				res->next = new ListNode();
				res->next->val = 1;
			}

			return head;
		}

		static void test()
		{
			vector<int> nums1_list1 = { 2, 4, 3 };
			vector<int> nums1_list2 = { 5, 6, 4 };
			vector<int> nums2_list1 = { 0 };
			vector<int> nums2_list2 = { 0 };
			vector<int> nums3_list1 = { 9, 9, 9, 9, 9, 9, 9 };
			vector<int> nums3_list2 = { 9, 9, 9, 9 };

			ListNode* list1_1 = CreateListNode(nums1_list1);
			ListNode* list1_2 = CreateListNode(nums1_list2);
			ListNode* list2_1 = CreateListNode(nums2_list1);
			ListNode* list2_2 = CreateListNode(nums2_list2);
			ListNode* list3_1 = CreateListNode(nums3_list1);
			ListNode* list3_2 = CreateListNode(nums3_list2);

			ListNode* output1; ListNode* output2; ListNode* output3;

			output1 = addTwoNumbers(list1_1, list1_2);
			output2 = addTwoNumbers(list2_1, list2_2);
			output3 = addTwoNumbers(list3_1, list3_2);

			OutputList(output1);
			OutputList(output2);
			OutputList(output3);
		}
	};
}


#endif // _ADD_TWO_NUMBERS_H_
