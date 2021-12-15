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
public:
    void dfs(vector<vector<int>> &graph, vector<int> &quiet, vector<int> &ans, int x) {
        if (ans[x] != -1) {
            return;
        }
        ans[x] = x;
        for (auto &rich : graph[x]) {
            dfs(graph, quiet, ans, rich);
            if (quiet[ans[rich]] <= quiet[ans[x]]) {
                ans[x] = ans[rich];
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
    {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < richer.size(); ++i) {
            int poor = richer[i][1];
            int rich = richer[i][0];
            graph[poor].emplace_back(rich);
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            dfs(graph, quiet, ans, i);
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    cout << "Hello world";
}
