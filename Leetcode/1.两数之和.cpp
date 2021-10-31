/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(hash.count(target - nums[i])){
                ans.emplace_back(i);
                ans.emplace_back(hash[target - nums[i]]);
                break;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};
// @lc code=end

