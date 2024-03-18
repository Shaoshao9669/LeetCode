#ifndef _TEXT_JUSTIFICATION_H_
#define _TEXT_JUSTIFICATION_H_

/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:
A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.

Example 1:
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.

Example 3:
Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

#include "common.h"

namespace TextJustification
{
	class Solution
	{
	public:
		static vector<string> fullJustify(vector<string>& words, int maxWidth)
		{
			vector<string> res_vec;
			map<int, queue<string>> words_queue;
			vector<int> word_len;
			int row = 0;
			int len_in_row = 0;

			// split words in row
			for (int i = 0; i < (int)words.size(); i++)
			{
				if (len_in_row + (int)words[i].size() <= maxWidth)
				{
					len_in_row += words[i].size() + 1;
					words_queue[row].push(words[i]);
				}
				else
				{
					if (words_queue[row].size() == 1)
					{
						len_in_row = len_in_row - 1;
					}
					else
					{
						len_in_row = len_in_row - words_queue[row].size();
					}					
					word_len.push_back(len_in_row);
					row = row + 1;
					len_in_row = 0;
					words_queue[row].push(words[i]);
					len_in_row += words[i].size() + 1;
				}
			}
			if (words_queue[row].size() == 1)
			{
				len_in_row = len_in_row - 1;
			}
			else
			{
				len_in_row = len_in_row - words_queue[row].size();
			}
			word_len.push_back(len_in_row);

			// calculate blank grid
			for (int i = 0; i < (int)words_queue.size(); i++)
			{
				int blank_grid_count;

				if ((i == (int)words_queue.size() - 1) || words_queue[i].size() == 1)
				{
					blank_grid_count = words_queue[i].size();
				}
				else
				{
					blank_grid_count = words_queue[i].size() - 1;
				}

				vector<int> blank_grid(blank_grid_count, 0);
				
				if (i == (int)words_queue.size() - 1)
				{
					for (int j = 0; j < blank_grid_count - 1; j++)
					{
						blank_grid[j] = 1;
					}
					blank_grid[blank_grid_count - 1] = maxWidth - word_len[i] - words_queue[i].size() + 1;
				}
				else
				{
					for (int j = 0; j < blank_grid_count; j++)
					{
						int numerator;
						int remainder = 1;
						int denominator = blank_grid_count;
						if (j > 0 && remainder != 0)
						{
							numerator = maxWidth - word_len[i] - j;
						}
						else if (j == 0)
						{
							numerator = maxWidth - word_len[i];
						}

						int res = numerator / denominator;
						remainder = numerator % denominator;

						if (remainder != 0)
						{
							blank_grid[j] = res + 1;
						}
						else
						{
							blank_grid[j] = res;
						}
					}
				}
				
				string res_str;
				int blank_count = 0;

				while (words_queue[i].empty() == false)
				{	
					res_str.append(words_queue[i].front());
					
					if (blank_count < blank_grid_count)
					{
						for (int j = 0; j < blank_grid[blank_count]; j++)
						{
							res_str.append(" ");
						}
					}

					blank_count++;
					words_queue[i].pop();
				}
				
				res_vec.push_back(res_str);
			}

			return res_vec;
		}

		static void test()
		{
			vector<string> words1 = { "This", "is", "an", "example", "of", "text", "justification." };
			vector<string> words2 = { "What", "must", "be", "acknowledgment", "shall", "be" };
			vector<string> words3 = { "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do" };

			int maxWidth1 = 16; int maxWidth2 = 16; int maxWidth3 = 20;

			vector<string> output1 = fullJustify(words1, maxWidth1);
			vector<string> output2 = fullJustify(words2, maxWidth2);
			vector<string> output3 = fullJustify(words3, maxWidth3);

			OutputVectorString(output1);
			OutputVectorString(output2);
			OutputVectorString(output3);
		}
	};
}

#endif // _TEXT_JUSTIFICATION_H_
