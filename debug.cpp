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
    const int INF = 0x3f3f3f3f;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        int m = flights.size();
        vector<int> dist(n, INF);
        dist[src] = 0;
        vector<vector<int>> graph(n, vector<int>(n, INF));
        for (int i = 0; i < m; ++i) {
            int from = flights[i][0];
            int to = flights[i][1];
            int weight = flights[i][2];
            graph[from][to] = weight;
        }
        for (int i = 0; i <= k; ++i) {
            vector<int> dist_clone(dist.begin(), dist.end());
            for (int j = 0; j < m; ++j) {
                int from = flights[j][0];
                int to = flights[j][1];
                int weight = flights[j][2];
                dist[to] = min(dist[to], graph[from][to] + dist_clone[from]);
            }
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};

int main()
{
    Solution solution;
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 1;
    int ans = solution.findCheapestPrice(n, flights, src, dst, k);
    return 0;
}