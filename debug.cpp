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
    int smallestDistancePair(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n-1] - nums[0];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int count = 0;
            int l = 0;
            for (int r = 0; r < n; ++r) {
                while (nums[r] - nums[l] > mid) {
                    l++;
                }
                count += r - l;
            }
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{   
    Solution solution;
    return 0;
}