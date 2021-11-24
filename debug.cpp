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
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
        dp[0][1][1] = -prices[0];
        dp[0][2][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][1][0] = max(dp[i-1][1][1] + prices[i], dp[i-1][1][0]);
            dp[i][1][1] = max(-prices[i], dp[i-1][1][1]);
            dp[i][2][0] = max(dp[i-1][2][1] + prices[i], dp[i-1][2][0]);
            dp[i][2][1] = max(dp[i-1][1][0] - prices[i], dp[i-1][2][1]);
        }
        return dp[n-1][2][0];
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {7, 5, 6, 4};
    return 0;
}
