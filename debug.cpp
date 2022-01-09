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
#include <sstream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression)
    {
        int n = expression.size();
        vector<char> ops;
        vector<int> nums;
        string str = "";
        for (int i = 0; i < n; ++i) {
            char ch = expression[i];
            if (isdigit(ch)) {
                str += ch;
            } else {
                nums.emplace_back(stoi(str));
                ops.emplace_back(ch);
                str.clear();
            }
        }
        nums.emplace_back(stoi(str));
        n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i].emplace_back(nums[i]);
        }
        for (int l = 1; l <= n; ++l) { // 区间长度
            for (int i = 0; i + l - 1 < n; ++i) { // i：区间起点
                int j = i + l - 1; // j：区间终点
                for (int k = i; k < j; ++k) { // k：区间中点
                    for (auto &left: dp[i][k]) { // left: 左区间可能的值
                        for (auto &right: dp[k+1][j]) { // right: 右区间可能的值
                            int result = 0;
                            if (ops[k] == '+') {
                                result = left + right;
                            } else if (ops[k] == '-') {
                                result = left - right;
                            } else if (ops[k] == '*') {
                                result = left * right;
                            }
                            dp[i][j].emplace_back(result);
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    Solution solution;
    string expression = "2-1-1";
    vector<int> ans = solution.diffWaysToCompute(expression);
    return 0;
}