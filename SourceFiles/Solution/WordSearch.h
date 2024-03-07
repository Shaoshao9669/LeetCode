#ifndef _WORD_SEARCH_H_
#define _WORD_SEARCH_H_

/*
LeetCode 79:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/

#include "common.h"

namespace WordSearch
{
	class Solution
	{
	public:
		static bool dfs(vector<vector<char>>& board, int x, int y, int word_index, string word)
		{
			int m = board.size();
			int n = board[0].size();
			bool ret = false;

			if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '-')
			{
				return false;
			}
			if (board[x][y] != word[word_index])
			{
				return false;
			}
			if (word_index == word.size() - 1)
			{
				return true;
			}

			char temp = board[x][y];
			board[x][y] = '-';
			ret = dfs(board, x + 1, y, word_index + 1, word) || dfs(board, x - 1, y, word_index + 1, word) || dfs(board, x, y + 1, word_index + 1, word) \
			|| dfs(board, x, y - 1, word_index + 1, word);
			board[x][y] = temp;

			return ret;
		}

		static bool exist(vector<vector<char>>& board, string word) 
		{
			int m = board.size();
			int n = board[0].size();
			queue<pair<int, int>> board_queue;
			bool isExisted = false;
			
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (word[0] == board[i][j])
					{
						board_queue.push({ i, j });
					}
				}
			}

			while (board_queue.empty() == false)
			{
				int x = board_queue.front().first;
				int y = board_queue.front().second;

				isExisted = isExisted || dfs(board, x, y, 0, word);
				board_queue.pop();
			}

			return isExisted;
		}

		static void test()
		{
			vector<vector<char>> board1 = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'} , {'A', 'D', 'E', 'E'} };
			vector<vector<char>> board2 = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'} , {'A', 'D', 'E', 'E'} };
			vector<vector<char>> board3 = { {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'} , {'A', 'D', 'E', 'E'} };
			string word1 = "ABCCED";
			string word2 = "SEE";
			string word3 = "ABCB";

			bool output1 = exist(board1, word1);
			bool output2 = exist(board2, word2);
			bool output3 = exist(board3, word3);

			OutputBoolean(output1);
			OutputBoolean(output2);
			OutputBoolean(output3);
		}
	};
}

#endif // _WORD_SEARCH_H_
