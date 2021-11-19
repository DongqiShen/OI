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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            int last = n - 1;
            int target = -nums[i];
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j-1] == nums[j]) {
                    continue;
                }

                while (j < last && nums[j] + nums[last] > target) {
                    last--;
                }
                if (j == last) {
                    break;
                }

                if (nums[j] + nums[last] == target) {
                    ans.push_back({nums[i], nums[j], nums[last]});
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = solution.threeSum(nums);
    return 0;
}
