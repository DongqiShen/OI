# 剑指offer51 数组中的逆序对

**标签** [归并排序] [树状数组]

### 解题思路
在思考的时候，想到要使用到排序后的索引，这一步可以用**map<int, set<int>>**来实现。key为num的值，set中保存索引。因为map和set都能实现自动排序，效率比较高。其实这没有解决问题，只不过从直接比较值的大小，转换为比较索引的大小，复杂度是一样的。后来想到，在扫描的过程中，需要记录，比当前值小的元素出现的个数，这不就是前缀和吗。但是，每次都要将小于它的前缀和相加一遍，复杂度还是一样。其实这就是树状数组的思想，不过它的前缀和表示一个范围内的元素的前缀和，这样的做法很高效。

### 解法一：归并排序
这个方法有点取巧，用到了归并排序的知识，适用性不太强。如果从算法流程来看的话，确实没有错，不过很难证明。不是很推荐。

```c++
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int mid = left + ((right - left) >> 1);
        int revCount = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int ptr = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[ptr++] = nums[i++];
                revCount += j - mid - 1;
            } else {
                tmp[ptr++] = nums[j++];
            }
        }

        for (int k = i; k <= mid; ++k) {
            tmp[ptr++] = nums[k];
            revCount += j - mid - 1;
        }
        for (int k = j; k <= right; ++k) {
            tmp[ptr++] = nums[k];
        }
        copy(tmp.begin() + left, tmp.begin() + right + 1, nums.begin() + left);
        return revCount;
    }
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};
```

### 解法二：树状数组
应该是树状数组的模版题目，外加一个离散化的过程。其实在思考的时候，想到需要用到前缀和数组，但是每次都要更新前缀和的效率不高，觉得应该用线段树来解决。后来发现这一类题目是树状数组的模版题，知道这个数据结构后就很简单了。这个方法非常小巧和优雅，虽然直接看代码不是很直观，但是建议直接背诵。（不难^_^）。
```c++
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
        // 因为只关心数字之间的大小关系，而对大小本身没什么关系，所以通过二分法
        // 找到他们的大小索引。当然不是严格意义上的索引，因为大小一样的值会被映射到
        // 同一个索引。其实即是把元素组压缩到一个小范围的数组内，便于处理。
        // 注意这里的 +1 很重要，不能出现为0的值，因为0的lowbit还是0，会导致无限循环。
        for (int &num : nums) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        BIT bit(n);
        int ans = 0;
        // 从后向前遍历，每次都是找到，处于这个元素后面比它小的元素的数量。
        for (int i = n - 1; i >= 0; --i) {
            ans += bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return ans;
    }
};
```