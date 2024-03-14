#ifndef _SWAPPING_NODES_IN_A_LINKED_LIST_H_
#define _SWAPPING_NODES_IN_A_LINKED_LIST_H_

/*
You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
*/

#include "common.h"

namespace SwappingNodesInALinkedList
{
	class Solution
	{
	public:
		static ListNode* swapNodes(ListNode* head, int k)
		{
			ListNode* begin = head;
			ListNode* end = head;
			ListNode* pre_begin = new ListNode();
			ListNode* pre_end = new ListNode();
			pre_begin->next = begin;
			pre_end->next = end;
			ListNode* next_begin = begin->next;
			ListNode* next_end = end->next;
			ListNode* temp = head;
			int list_len = 0;
			bool is_near = false;

			while (temp != NULL)
			{
				temp = temp->next;
				list_len++;
			}
			int reverse_k = list_len - k;
			if (reverse_k == k)
			{
				is_near = true;
			}

			while (k > 1)
			{
				pre_begin = pre_begin->next;
				begin = begin->next;
				next_begin = next_begin->next;
				k--;
			}

			while (reverse_k > 0)
			{
				pre_end = pre_end->next;
				end = end->next;
				next_end = next_end->next;
				reverse_k--;
			}

			if (!is_near)
			{
				pre_begin->next = end;
				end->next = next_begin;
				pre_end->next = begin;
				begin->next = next_end;
			}
			else
			{
				pre_begin->next = end;
				end->next = begin;
				begin->next = next_end;
			}

			return head;
		}

		static void test()
		{
			vector<int> nums1 = { 1, 2, 3, 4, 5};
			vector<int> nums2 = { 7, 9, 6, 6, 7, 8, 3, 0, 9, 5 };

			int k1 = 2, k2 = 5;

			ListNode* output1; ListNode* output2;

			ListNode* list1 = CreateListNode(nums1);
			ListNode* list2 = CreateListNode(nums2);

			output1 = swapNodes(list1, k1);
			output2 = swapNodes(list2, k2);

			OutputList(output1);
			OutputList(output2);
		}
	};
}

#endif // _SWAPPING_NODES_IN_A_LINKED_LIST_H_
