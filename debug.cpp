/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <regex>

#include "LeetCode_Helper_Func.h"

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries)
    {
        int n = s.size();
        vector<int> presum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + (s[i - 1] == '|' ? 1 : 0);
        }
        vector<int> ans;
        for (auto &query: queries) {
            int l = query[0];
            int r = query[1];
            int leftIndex, rightIndex;
            if (s[l] == '|') {
                leftIndex = l;
            } else {
                leftIndex = upper_bound(presum.begin(), presum.end(), presum[l + 1]) - presum.begin();
            }
            if (s[r] == '|') {
                rightIndex = r;
            } else {
                rightIndex =  lower_bound(presum.begin(), presum.end(), presum[r + 1]) - presum.begin();
            }
            if (leftIndex < rightIndex && rightIndex != n + 1 && leftIndex != n + 1) {
                int tmpAns = rightIndex - leftIndex - (presum[rightIndex] - presum[leftIndex]);
                ans.emplace_back(tmpAns);
            } else {
                ans.emplace_back(0);
            }
        }
        return ans;
    }
};

int main()
{
    // string input = "input.txt";
    // ifstream fin(input);
    // vector<vector<int>> vec = to_vvi(fin);
    Solution solution;
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    vector<int> ans = solution.platesBetweenCandles(s, queries);
    return 0;
}
