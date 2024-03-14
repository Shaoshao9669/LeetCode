#ifndef _SWAP_NODES_IN_PAIRS_H_
#define _SWAP_NODES_IN_PAIRS_H_

/*
Given a linked list, swap every two adjacent nodes and return its head.You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1, 2, 3, 4]
Output : [2, 1, 4, 3]

Example 2 :
Input : head = []
Output : []

Example 3 :
Input : head = [1]
Output : [1]
*/

#include "common.h"

namespace SwapNodesInPairs
{
	class Solution
	{
	public:
		static ListNode* swapPairs(ListNode* head)
		{
			if (head == NULL)
			{
				return NULL;
			}
			if (head->next == NULL)
			{
				return head;
			}

			ListNode* cur = head->next;

			if (head->next != NULL)
			{	
				ListNode* temp = cur->next;

				head->next = NULL;
				cur->next = head;

				head->next = swapPairs(temp);
			}

			return cur;
		}

		static void test()
		{
			vector<int> nums1 = { 1, 2, 3, 4};
			vector<int> nums2 = {};
			vector<int> nums3 = {1};

			ListNode* list1 = CreateListNode(nums1);
			ListNode* list2 = CreateListNode(nums2);
			ListNode* list3 = CreateListNode(nums3);

			ListNode* output1; ListNode* output2; ListNode* output3;

			output1 = swapPairs(list1);
			output2 = swapPairs(list2);
			output3 = swapPairs(list3);

			OutputList(output1);
			OutputList(output2);
			OutputList(output3);
		}
	};
}

#endif // _SWAP_NODES_IN_PAIRS_H_
