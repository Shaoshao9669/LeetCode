#ifndef _REVERSE_LINKED_LIST_H_
#define _REVERSE_LINKED_LIST_H_

/*
LeetCode 206:
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1, 2, 3, 4, 5]
Output : [5, 4, 3, 2, 1]

Example 2 :
Input : head = [1, 2]
Output : [2, 1]

Example 3 :
Input : head = []
Output : []
*/

#include "common.h"

namespace ReversedLinkedList
{
	class Solution
	{
	public:
		static ListNode* reverseList(ListNode* head)
		{
			if (head == NULL)
			{
				return NULL;
			}

			ListNode* pre = head;
			ListNode* cur = head->next;

			pre->next = NULL;
			while (cur != NULL)
			{
				ListNode* next = cur->next;

				cur->next = pre;
				pre = cur;
				cur = next;
			}

			return pre;
		}

		static void test()
		{
			vector<int> nums1 = { 1, 2, 3, 4, 5 };
			vector<int> nums2 = { 1, 2 };
			vector<int> nums3 = {};

			ListNode* list1 = CreateListNode(nums1);
			ListNode* list2 = CreateListNode(nums2);
			ListNode* list3 = CreateListNode(nums3);

			ListNode* output1; ListNode* output2; ListNode* output3;

			output1 = reverseList(list1);
			output2 = reverseList(list2);
			output3 = reverseList(list3);

			OutputList(output1);
			OutputList(output2);
			OutputList(output3);
		}
	};
};

#endif // _REVERSE_LINKED_LIST_H_

/*
	if (head == NULL)
	{
		return head;
	}

	ListNode* pre = head;
	ListNode* cur = head->next;

	head->next = NULL;

	while (cur != NULL)
	{
		ListNode* next = cur->next;

		cur->next = pre;
		pre = cur;
		cur = next;
	}

	return pre;
*/
