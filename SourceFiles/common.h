#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void AddNode(ListNode* head, int val)
{
	ListNode* newNode = new ListNode(val);

	if (head == NULL)
	{
		head = newNode;
		return;
	}
	ListNode* temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

ListNode* CreateListNode(vector<int> nums)
{
	if (nums.size() == 0)
	{
		return NULL;
	}

	ListNode* head = new ListNode(nums[0]);

	for (int i = 1; i < (int)nums.size(); i++)
	{
		AddNode(head, nums[i]);
	}

	return head;
}

ListNode* CreateCycleListNode(vector<int> nums, int node_num)
{
	if (nums.size() == 0)
	{
		return NULL;
	}

	ListNode* head = new ListNode(nums[0]);

	for (int i = 1; i < (int)nums.size(); i++)
	{
		AddNode(head, nums[i]);
	}

	ListNode* cycle_node = head;
	ListNode* temp = head;

	while (node_num > 0)
	{
		cycle_node = cycle_node->next;
		node_num = node_num - 1;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = cycle_node;

	return head;
}

string ReverseString(string str)
{
	string res;

	const char* str_c = str.c_str();
	char* str_rev = new char[str.size()];
	strcpy(str_rev, str_c);
	char* ret = str_rev;
	char* p = str_rev + str.size() - 1;

	while (p > str_rev)
	{
		char t = *str_rev;
		*str_rev++ = *p;
		*p-- = t;
	}
	res = ret;

	return res;
}

void OutputVector(vector<int> nums)
{
	cout << "[";
	for (int i = 0; i < (int)nums.size(); i++)
	{
		cout << nums[i];

		if (i < (int)nums.size() - 1)
		{
			cout << ",";
		}
	}
	cout << "]" << endl;
}

void OutputString(string str)
{
	cout << "\"" << str << "\"" << endl;
}

void OutputDoubleVector(vector<vector<int>> nums)
{
	cout << "[";
	for (int i = 0; i < (int)nums.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < (int)nums[i].size(); j++)
		{
			cout << nums[i][j];

			if (j < (int)nums[i].size() - 1)
			{
				cout << ",";
			}
			else
			{
				cout << "]";
			}
		}
		if (i < (int)nums.size() - 1)
		{
			cout << ",";
		}
	}
	cout << "]" << endl;
}

void OutputList(ListNode* head)
{
	cout << "[";
	while (head != NULL)
	{
		printf("%d", head->val);
		if (head->next != NULL)
		{
			printf(" ");
		}
		head = head->next;
	}
	cout << "]" << endl;
}

void OutputVectorChar(vector<vector<char>>& board)
{
	cout << "[";
	for (int i = 0; i < (int)board.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < (int)board[i].size(); j++)
		{
			cout << "\"" << board[i][j] << "\"";

			if (j < (int)board[i].size() - 1)
			{
				cout << ",";
			}
			else
			{
				cout << "]";
			}
		}
		if (i < (int)board.size() - 1)
		{
			cout << ",";
		}
	}
	cout << "]" << endl;
}

void OutputSingleNumber(int num)
{
	cout << num << endl;
}

void OutputVectorString(vector<string> strs)
{
	cout << "[";
	for (int i = 0; i < (int)strs.size(); i++)
	{
		cout << "\"" << strs[i] << "\"";

		if (i < (int)strs.size() - 1)
		{
			cout << "," << endl << " ";
		}
	}
	cout << "]" << endl;
}

#endif // _COMMON_H_
