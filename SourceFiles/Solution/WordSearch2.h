#ifndef _WORD_SEARCH_2_H_
#define _WORD_SEARCH_2_H_

/*
LeetCode 212:
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
*/

#include "common.h"

namespace WordSearch2
{
	class Solution
	{
	public:
		static vector<string> output;

		static bool dfs(vector<vector<char>>& board, int x, int y, int count, string word)
		{
			int m = board.size();
			int n = board[0].size();
			bool ret = false;

			if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '-')
			{
				return ret;
			}
			if (board[x][y] != word[count])
			{
				return ret;
			}
			if (count == word.size() - 1)
			{
				ret = true;
				return ret;
			}

			char temp = board[x][y];
			board[x][y] = '-';
			ret = dfs(board, x + 1, y, count + 1, word) || dfs(board, x - 1, y, count + 1, word) || dfs(board, x, y + 1, count + 1, word)
				|| dfs(board, x , y - 1, count + 1, word);
			board[x][y] = temp;

			return ret;
		}

		static void findWord(vector<vector<char>>& board, string word)
		{
			int m = board.size();
			int n = board[0].size();
			bool ret = false;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (board[i][j] == word[0])
					{
						ret = dfs(board, i, j, 0, word);
						if (ret == true)
						{
							output.push_back(word);
							return;
						}
					}
				}
			}
		}

		static vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
		{
			output.clear();
			
			for (int i = 0; i < (int)words.size(); i++)
			{
				findWord(board, words[i]);
			}

			return output;
		}

		static void test()
		{
			vector<vector<char>> board1 = { {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'} , {'i', 'h', 'k', 'r'},  {'i', 'f', 'l', 'v'} };
			vector<vector<char>> board2 = { {'a', 'b'}, {'c', 'd'} };
			vector<string> word1 = { "eat", "oath" };
			vector<string> word2 = { "abcb" };

			vector<string> output1, output2;

			output1 = findWords(board1, word1);
			output2 = findWords(board2, word2);

			OutputVectorString(output1);
			OutputVectorString(output2);
		}
	};

	vector<string> Solution::output;
}



#endif // _WORD_SEARCH_2_H_
