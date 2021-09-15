/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 第一个二分法寻找旋转的点的坐标
        int n = nums.size();
        int left = 0, right = n;
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= nums[0]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        // 根据target的大小，选择它所在范围的原数组的坐标
        if (target >= nums[0]){
            left = 0;
        }else{
            right = n;
        }
        // 第二个二分，比较明确，在升序的数组找目标值
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] > target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return ((left < n) && (nums[left] == target)) ? left : -1;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {3, 1};
    int target = 1;
    int ret = solution.search(nums, target);
    return 0;
}