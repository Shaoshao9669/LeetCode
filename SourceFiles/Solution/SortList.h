#ifndef _SORT_LIST_H_
#define _SORT_LIST_H_

/*
LeetCode 148:
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4, 2, 1, 3]
Output : [1, 2, 3, 4]

Example 2 :
Input : head = [-1, 5, 3, 4, 0]
Output : [-1, 0, 3, 4, 5]

Example 3 :
Input : head = []
Output : []
*/

#include "common.h"

namespace SortList
{
	class Solution
	{
	public:
		static ListNode* sortList(ListNode* head)
		{
			ListNode* res = head;
			ListNode* temp = head;
			vector<int> val;

			if (head == NULL)
			{
				return NULL;
			}
	
			while (res != NULL)
			{
				val.push_back(res->val);
				res = res->next;
			}

			sort(val.begin(), val.end());

			for (int i = 0; i < (int)val.size(); i++)
			{
				temp->val = val[i];
				temp = temp->next;
			}

			return head;
		}

		static void test()
		{
			vector<int> head1 = { 4, 2, 1, 3 };
			vector<int> head2 = { -1, 5, 3, 4, 0 };
			vector<int> head3 = { };

			ListNode* list1 = CreateListNode(head1);
			ListNode* list2 = CreateListNode(head2);
			ListNode* list3 = CreateListNode(head3);

			ListNode* output1; ListNode* output2; ListNode* output3;

			output1 = sortList(list1);
			output2 = sortList(list2);
			output3 = sortList(list3);

			OutputList(output1);
			OutputList(output2);
			OutputList(output3);
		}
	};
}

#endif // _SORT_LIST_H_
