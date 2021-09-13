/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
**/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 递归版
class Solution
{

public:
    int sum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if(root == nullptr){
            return root;
        }
        // 先处理右节点，再处理中间节点，最后是左节点，是反转的中序遍历。
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};

class Solution2
{
public:
    TreeNode *convertBST(TreeNode* root){
        if(root == nullptr){
            return root;
        }
        int sum = 0;
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while(cur || !stk.empty()){ // 当栈为空以及没有待处理的节点后结束
            while(cur){ // 以这个节点为父节点，从上到下把右节点一次压入栈
                stk.push(cur);
                cur = cur->right;
            }
            // 栈顶为最右的节点，累加它的值并更新。然后处理左节点
            cur = stk.top();
            stk.pop();
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
        }
        return root;
    }
};

int main()
{
    return 0;
}