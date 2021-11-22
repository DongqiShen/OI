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

class BIT {
private:
    int n;
    vector<int> tree;
public:
    static int lowbit(int x) {
        return x & (-x);
    }

    BIT(int _n) : n(_n), tree(_n + 1) {}

    int query(int x) {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }

    void update(int x) {
        while (x <= n) {
            tree[x] += 1;
            x += lowbit(x);
        }
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        for (int &num : nums) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {7, 5, 6, 4};
    int ans = solution.reversePairs(nums);
    return 0;
}
