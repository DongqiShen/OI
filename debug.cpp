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
    vector<string> ans;
public:
    void backtrack(string num, int idx, long long prev, long long cur, int target, string exp){
        if(idx == num.size()){
            if(cur == target){
                ans.emplace_back(exp);
            }
            return;
        }
        string strNum = "";
        for(int i = idx; i < num.size(); ++i){
            if(num[idx] == '0' && i > idx){
                break;
            }
            strNum.push_back(num[i]);
            long long intNum = stoull(strNum);
            if(idx == 0){
                backtrack(num, i + 1, intNum, intNum, target, exp + strNum);
            }else{
                backtrack(num, i + 1, intNum, cur + intNum, target, exp + "+" + strNum);
                backtrack(num, i + 1, -intNum, cur - intNum, target, exp + "-" + strNum);
                long long tmp = prev * intNum;
                backtrack(num, i + 1, tmp, (cur-prev) + tmp, target, exp + "*" + strNum);
            }
        }
    }
    vector<string> addOperators(string num, int target)
    {
        string exp = "";
        backtrack(num, 0, 0, 0, target, exp);
        return ans;
    }
};
int main()
{
    Solution solution;
    string num = "123";
    int target = 6;
    vector<string> ans = solution.addOperators(num, target);
    return 0;
}
