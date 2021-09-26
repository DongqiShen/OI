/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <limits.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int target_sum = accumulate(nums.begin(), nums.end(), target);
        if(target_sum < 0 || target_sum & 1){
            return 0;
        }
        target_sum /= 2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target_sum + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            int num = nums[i-1];
            for(int j = 0; j <= target_sum; ++j){
                dp[i][j] = dp[i-1][j];
                if(j >= num){
                    dp[i][j] += dp[i-1][j-num];
                }
            }
        }
        return dp[n][target_sum];
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {100};
    int target = 3;
    int ret = solution.findTargetSumWays(nums, target);
    return 0;
}