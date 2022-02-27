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
#include <list>
#include <regex>

#include "LeetCode_Helper_Func.h"

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
public:
    void backtrack(string &s, int idx, vector<string> &substr) {
        if (idx == s.size()) {
            ans.emplace_back(substr);
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            string str = s.substr(idx, i - idx + 1);
            string rev_str = str;
            reverse(rev_str.begin(), rev_str.end());
            if (rev_str == str && !str.empty()) {
                substr.emplace_back(str);
                backtrack(s, i + 1, substr);
                substr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> substr;
        backtrack(s, 0, substr);
        return ans;
    }
};

int main()
{
    string input = "input.txt";
    ifstream fin(input);
    vector<vector<int>> vec = to_vvi(fin);

    return 0;
}
