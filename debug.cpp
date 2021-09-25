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

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    int recursionPathSum(TreeNode* root, unordered_map<int, int>& prefixCount, 
                        int targetSum, int curSum)
    {
        if(root == nullptr){
            return 0;
        }
        int res = 0;
        curSum += root->val;
        if(prefixCount.count(curSum - targetSum)){
            res += prefixCount[curSum - targetSum];
        }
        prefixCount[curSum] += 1;
        res += recursionPathSum(root->left, prefixCount, targetSum, curSum);
        res += recursionPathSum(root->right, prefixCount, targetSum, curSum);
        prefixCount[curSum] -= 1;
        return res;
    }
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        return recursionPathSum(root, prefixCount, targetSum, 0);
    }
};

int main()
{
    Solution solution;
    return 0;
}