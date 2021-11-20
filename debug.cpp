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
    int findLHS(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int begin = 0;
        int maxLen = 0;
        int n = nums.size();
        for (int end = 0; end < n; ++end) {
            while (nums[end] - nums[begin] > 1) {
                begin++;
            }
            if (nums[end] - nums[begin] == 1){
                maxLen = max(maxLen, end - begin + 1);
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    return 0;
}
