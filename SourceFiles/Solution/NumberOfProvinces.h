#ifndef _NUMBER_OF_PROVINCES_
#define _NUMBER_OF_PROVINCES_

/*
Leetcode 547:
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/

#include "common.h"

namespace NumberOfProvinces
{
    class Solution 
    {
    public:
        static void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int k, int circle_num)
        {
            int n = isConnected.size();

            for (int i = 0; i < n; i++)
            {
                if (visited[i] > 0 || isConnected[k][i] == 0)
                {
                    continue;
                }

                visited[i] = circle_num;
                dfs(isConnected, visited, i, circle_num);
            }
        }

        static int findCircleNum(vector<vector<int>>& isConnected)
        {
            int circle_num = 0;
            int n = isConnected.size();
            vector<int> visited(n, 0);

            for (int i = 0; i < n; i++)
            {
                if (visited[i] > 0)
                {
                    continue;
                }
                circle_num++;
                dfs(isConnected, visited, i, circle_num);
            }

            return circle_num;
        }

        static void test()
        {
            vector<vector<int>> isConnected1 = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
            vector<vector<int>> isConnected2 = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

            int output1 = findCircleNum(isConnected1);
            int output2 = findCircleNum(isConnected2);

            OutputSingleNumber(output1);
            OutputSingleNumber(output2);
        }
    };
}

#endif // _NUMBER_OF_PROVINCES_
