#ifndef _LINKED_LIST_CYCLE_H_
#define _LINKED_LIST_CYCLE_H_

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
*/

#include "common.h"

namespace LinkedListCycle
{
	class Solution
	{
	public:
		static int hasCycle(ListNode* head)
		{
			ListNode* slow = head;
			ListNode* fast = head;
			bool hasCycle = false;

			while (slow != NULL && fast != NULL && fast->next != NULL)
			{
				slow = slow->next;
				fast = fast->next->next;

				if (slow == fast)
				{
					hasCycle = true;
				}

				if (hasCycle == true)
				{
					ListNode* temp = head;
					int pos = 0;

					while (temp != slow)
					{
						slow = slow->next;
						temp = temp->next;

						pos = pos + 1;
					}

					return pos;
				}
			}

			return -1;
		}

		static void test()
		{
			vector<int> nums1 = { 3, 2, 0, -4 };
			vector<int> nums2 = { 1, 2 };
			vector<int> nums3 = { 1 };

			ListNode* list1 = CreateCycleListNode(nums1, 1);
			ListNode* list2 = CreateCycleListNode(nums2, 0);
			ListNode* list3 = CreateListNode(nums3);

			int output1; int output2; int output3;

			output1 = hasCycle(list1);
			output2 = hasCycle(list2);
			output3 = hasCycle(list3);

			OutputSingleNumber(output1);
			OutputSingleNumber(output2);
			OutputSingleNumber(output3);
		}
	};
};






#endif // _LINKED_LIST_CYCLE_H_
