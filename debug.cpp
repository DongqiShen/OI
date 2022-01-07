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
    const int MOD = 1e9 + 7;
    vector<vector<int>> path = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (maxMove == 0) {
            return 0;
        }
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        // 初始化
        for (int i = 0; i < m; ++i) {
            dp[i][0][1] += 1;
            dp[i][n-1][1] += 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j][1] += 1;
            dp[m-1][j][1] += 1;
        }
        for (int move = 1; move <= maxMove; ++move) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (auto &dir: path) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            dp[i][j][move] = (dp[i][j][move] % MOD + dp[x][y][move-1] % MOD) % MOD;
                        }
                    }
                }
            }
        
        }
        int ans = 0;
        for (int step = 1; step <= maxMove; ++step) {
            ans = (ans % MOD + dp[startRow][startColumn][step] % MOD) % MOD;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0;
    int startColumn = 0;
    int ans = solution.findPaths(m, n, maxMove, startRow, startColumn);
    return 0;
}