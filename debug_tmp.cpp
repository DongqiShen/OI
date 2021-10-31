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
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> ans;
    unordered_set<string> tmp;
    int targetLen;

public:
    void backtrack(string s, int idx, string str, int left)
    {
        if (idx == s.size()) {
            if (left == 0 && str.size() == targetLen) {
                tmp.insert(str);
            }
            return;
        }
        char ch = s[idx];
        if (ch != '(' && ch != ')') {
            str.push_back(ch);
            backtrack(s, idx + 1, str, left);
        } else {
            if (ch == ')') {
                if (left > 0) {
                    str.push_back(ch);
                    backtrack(s, idx + 1, str, left - 1);
                    str.pop_back();
                    backtrack(s, idx + 1, str, left);
                } else {
                    backtrack(s, idx + 1, str, left);
                }
            } else {
                str.push_back(ch);
                backtrack(s, idx + 1, str, left + 1);
                str.pop_back();
                backtrack(s, idx + 1, str, left);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left += 1;
            } else if (s[i] == ')') {
                if (left > 0) {
                    left--;
                } else {
                    right++;
                }
            }
        }
        targetLen = s.size() - left - right;
        backtrack(s, 0, "", 0);
        if (tmp.size() == 0) {
            vector<string> ans;
            ans.push_back("");
            return ans;
        }
        vector<string> ans(tmp.begin(), tmp.end());
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = ")(f";
    vector<string> ans = solution.removeInvalidParentheses(s);
    return 0;
}
