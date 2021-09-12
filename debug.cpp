/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
**/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution
{
private:
    const int INF = 0x3f3f3f3f; // 表示两条边不连通
    vector<vector<int>> graph;  // 邻接矩阵存图
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int m = times.size();
        graph.resize(n + 1, vector<int>(n + 1, INF));
        for(int i = 0; i < m; ++i){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u][v] = w;
        }
        vector<int> dist(n + 1, INF);
        vector<int> vis(n+1, 0);
        dist[k] = 0;
        // 因为有n个点，除去起点，还有n-1个点，所以做多要循环n-1次
        // 最差情况就是只有起点走向其他节点的一天边
        for(int i = 0; i < n - 1; ++i){
            int x = -1; // x = -1 表示第一次处理，那么就选第一个还没被访问过的节点
            for(int y = 1; y < n + 1; ++y){ 
                // 找到还没有被访问过的节点中，dist中的最小值，并记录这个点为x
                // note: dist[y]的值不为INF的点，不代表这个节点已经被vis过。
                if(!vis[y] && (x == -1 || dist[y] < dist[x])){
                   x = y; 
                }
            }
            vis[x] = 1;
            // 松弛操作。
            for(int y = 1; y < n + 1; ++y){
                if(dist[y] > dist[x] + graph[x][y]){
                    dist[y] = dist[x] + graph[x][y];
                }
            }
        }
        int ret = *max_element(dist.begin() + 1, dist.end());
        return ret == INF ? -1 : ret;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    int ret = solution.networkDelayTime(times, n, k);
    cout<<"Hello world\n";
    return 0;
}