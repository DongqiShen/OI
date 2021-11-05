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
    int MAX = 2002;
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for(int i = n - 1; i >= 0; --i){
            for(int j = i + 1; j < n; ++j){
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            }
        }
        vector<int> f(n, 2002);
        for(int i = 0; i < n; ++i){
            if(dp[0][i]){
                f[i] = 0;
            }else{
                for(int j = 0; j < i; ++j){
                    if(dp[j+1][i]){
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[n-1];
    }
};

int main()
{
    Solution solution;
    string s = "aab";
    return 0;
}
