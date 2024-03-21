#ifndef _REVERSE_LINKED_LIST_2_H_
#define _REVERSE_LINKED_LIST_2_H_

/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/

#include "common.h"

namespace ReversedLinkedList2
{
	class Solution
	{
	public:
		static ListNode* ReverseList(ListNode* head)
		{
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

		static ListNode* reverseBetween(ListNode* head, int left, int right)
		{
			if (left == right)
			{
				return head;
			}

			ListNode* left_front = new ListNode();
			left_front->next = head;
			ListNode* left_node = head;
			ListNode* left_back = head->next;
			ListNode* right_front = new ListNode();
			right_front->next = head;
			ListNode* right_node = head;
			ListNode* right_back = head->next;

			int left_count = 0, right_count = 0;

			while (left_count != left - 1)
			{
				left_front = left_front->next;
				left_node = left_node->next;
				left_back = left_back->next;

				left_count++;
			}

			while (right_count != right - 1)
			{
				right_front = right_front->next;
				right_node = right_node->next;
				right_back = right_back->next;

				right_count++;
			}

			right_node->next = NULL;

			ListNode* reversehead = ReverseList(left_node);

			left_front->next = reversehead;
			
			while (reversehead->next != NULL)
			{
				reversehead = reversehead->next;
			}
			reversehead->next = right_back;

			return head;
		}

		static void test()
		{
			vector<int> nums1 = { 1, 2, 3, 4, 5}; int left1 = 2; int right1 = 4;
			vector<int> nums2 = { 5 }; int left2 = 1; int right2 = 1;

			ListNode* list1 = CreateListNode(nums1);
			ListNode* list2 = CreateListNode(nums2);

			ListNode* output1; ListNode* output2;

			output1 = reverseBetween(list1, left1, right1);
			output2 = reverseBetween(list2, left2, right2);

			OutputList(output1);
			OutputList(output2);
		}
	};
};

#endif // _REVERSE_LINKED_LIST_2_H_
