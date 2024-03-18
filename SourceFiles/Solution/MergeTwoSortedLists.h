#ifndef _MERGE_TWO_SORTED_LISTS_H_
#define _MERGE_TWO_SORTED_LISTS_H_

/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
*/

#include "common.h"

namespace MergeTwoSortedList
{
	class Solution
	{
	public:
		static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
		{
			ListNode* res = new ListNode();

			if (list1 == NULL)
			{
				return list2;
			}

			if (list2 == NULL)
			{
				return list1;
			}

			if (list1 != NULL && list2 != NULL)
			{
				if (list1->val < list2->val)
				{
					res->val = list1->val;
					res->next = mergeTwoLists(list1->next, list2);
				}
				else
				{
					res->val = list2->val;
					res->next = mergeTwoLists(list1, list2->next);
				}
			}

			return res;
		}

		static void test()
		{
			vector<int> nums1_list1 = { 1, 2, 4 };
			vector<int> nums1_list2 = { 1, 3, 4 };
			vector<int> nums2_list1 = { };
			vector<int> nums2_list2 = { };
			vector<int> nums3_list1 = { };
			vector<int> nums3_list2 = { 0 };

			ListNode* list1_1 = CreateListNode(nums1_list1);
			ListNode* list1_2 = CreateListNode(nums1_list2);
			ListNode* list2_1 = CreateListNode(nums2_list1);
			ListNode* list2_2 = CreateListNode(nums2_list2);
			ListNode* list3_1 = CreateListNode(nums3_list1);
			ListNode* list3_2 = CreateListNode(nums3_list2);

			ListNode* output1; ListNode* output2; ListNode* output3;

			output1 = mergeTwoLists(list1_1, list1_2);
			output2 = mergeTwoLists(list2_1, list2_2);
			output3 = mergeTwoLists(list3_1, list3_2);

			OutputList(output1);
			OutputList(output2);
			OutputList(output3);
		}
	};
}

/*
	static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* head = NULL;

		if (list1 == NULL)
		{
			return list2;
		}
		if (list2 == NULL)
		{
			return list1;
		}
		if (list1 == NULL || list2 == NULL)
		{
			return NULL;
		}

		if (list1 != NULL && list2 != NULL)
		{
			if (list1->val < list2->val)
			{
				head = list1;
				head->next = mergeTwoLists(list1->next, list2);
			}
			else
			{
				head = list2;
				head->next = mergeTwoLists(list1, list2->next);
			}
		}

		return head;
	}
*/

#endif // _MERGE_TWO_SORTED_LISTS_H_
