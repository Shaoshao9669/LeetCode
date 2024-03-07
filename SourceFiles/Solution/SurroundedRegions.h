#ifndef _SURROUNDED_REGIONS_H_
#define _SURROUNDED_REGIONS_H_

/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4 - directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:
Input: board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]]
Output : [["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "O", "X", "X"]]

Explanation : Notice that an 'O' should not be flipped if :
	-It is on the border, or
	-It is adjacent to an 'O' that should not be flipped.
	The bottom 'O' is on the border, so it is not flipped.
	The other three 'O' form a surrounded region, so they are flipped.

Example 2 :
Input : board = [["X"]]
Output : [["X"]]
*/

#include "common.h"

namespace SurroundedRegions
{
	class Solution
	{
	public:
		static void dfs(vector<vector<char>>& board, int x, int y)
		{
			int m = board.size();
			int n = board[0].size();

			if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == 'X')
			{
				return;
			}

			board[x][y] = 'a';
			dfs(board, x + 1, y);
			dfs(board, x - 1, y);
			dfs(board, x, y - 1);
			dfs(board, x, y + 1);
		}

		static void solve(vector<vector<char>>& board)
		{
			int m = board.size();
			int n = board[0].size();

			for (int i = 0; i < m; i++)
			{
				dfs(board, i, 0);
				dfs(board, i, n - 1);
			}
			for (int i = 0; i < n; i++)
			{
				dfs(board, 0, i);
				dfs(board, m - 1, i);
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (board[i][j] == 'O')
					{
						board[i][j] = 'X';
					}
					else if (board[i][j] == 'a')
					{
						board[i][j] = 'O';
					}
				}
			}
		}

		static void test()
		{
			vector<vector<char>> board1 = { {'X', 'X', 'X', 'X'},  {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'} };
			vector<vector<char>> board2 = { {'X', 'X', 'X'},  {'X', 'O', 'X'}, {'X', 'O', 'X'}};
			vector<vector<char>> board3 = { {'X'}};

			solve(board1);
			solve(board2);
			solve(board3);

			OutputVectorChar(board1);
			OutputVectorChar(board2);
			OutputVectorChar(board3);
		}
	};
}

#endif // _SURROUNDED_REGIONS_H_
