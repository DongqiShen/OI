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
private:
    unordered_set<string> rawans;
    int maxlen = 0;
public:
    void backtrack(string s, int idx, string cur, int leftcount, int left, int right){
        if(idx == s.size()){
            if(leftcount == 0){
                rawans.insert(cur);
                maxlen = max(int(cur.size()), maxlen);
            }
            return;
        }
        if (left < 0 || right < 0 || (left + right) > (s.size() - idx)) {
            return;
        }
        char ch = s[idx];
        if(ch != '(' && ch != ')'){
            cur.push_back(ch);
            backtrack(s, idx+1, cur, leftcount, left, right);
        }else if(ch == '('){
            cur.push_back(ch);
            backtrack(s, idx+1, cur, leftcount+1, left, right);
            cur.pop_back();
            backtrack(s, idx+1, cur, leftcount, left-1, right);
        }else if(ch == ')'){
            if(leftcount > 0){
                cur.push_back(ch);
                backtrack(s, idx+1, cur, leftcount-1, left, right);
                cur.pop_back();
            }
            backtrack(s, idx+1, cur, leftcount, left, right-1);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int n = s.size();
        int left = 0;
        int right = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                left++;
            }else if(s[i] == ')'){
                if(left > 0){
                    left--;
                }else{
                    right++;
                }
            }
        }
        vector<string> ans;
        string cur = "";
        int leftcount = 0;
        backtrack(s, 0, cur, leftcount, left, right);
        if (rawans.empty()) {
            ans.emplace_back("");
            return ans;
        }
        for(auto str: rawans){
            if(str.size() == maxlen){
                ans.emplace_back(str);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "((((((((((((((((((((aaaaa";
    vector<string> ans = solution.removeInvalidParentheses(s);
    return 0;
}
