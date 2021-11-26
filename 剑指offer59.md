# 剑指offer59 滑动窗口的最大值

**标签** [滑动窗口] [最大堆]

### 解题思路
解法一：题意很简单，但是直接做肯定会超时，所以得用数据结构优化。由于求最大值，很容易想到最大堆。如果只把值放入优先队列的话，就无法判断这个值的位置，所以需要将位置索引也放入优先队列。如果位置索引表示在滑动窗口外面，直接弹出，直到符合要求。
解法二：看完后发现很简单，但是自己想又是另外一回事。首先，在队列中保存的是索引，索引代表的值单调递减。因为假设索引$i < j, nums[i] < nums[j]$，且都在滑动窗口中，那么i是永远都不会取到的。同时需要判断，这个队列头部的索引是否还在滑动窗口中。
要明确一点，索引携带的信息大于数组中的数字。因为用索引可以表示数组中的数字，但是数组中的数字不能反过来推出索引。想到这一点，应该就能想到解法一。

### 解法一： 优先队列
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        if (n == 0) {
            return ans;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i], i);
        }
        ans.emplace_back(pq.top().first);
        for (int i = k; i < n; ++i) {
            pq.emplace(nums[i], i);
            while(pq.top().second <= i - k){
                pq.pop();
            }
            ans.emplace_back(pq.top().first);
        }
        return ans;
    }
};
```

### 解法二：双端队列保存单调队列
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        if (n == 0) {
            return ans;
        }
        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for (int i = k; i < n; ++i) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (dq.front() <= i - k) {
                dq.pop_front();
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
```