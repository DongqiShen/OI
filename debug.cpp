/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <algorithm>

using namespace std;
class Solution
{
private:
    // 邻接表：graph[x][y] = c表示x/y=c，需要注意的是分子分母交换位子也是一条边
    unordered_map<string, unordered_map<string, double>> graph;
    // 表示节点的名字（唯一）
    unordered_set<string> nodes;
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        // 建立邻接表
        for(int i = 0; i < n; ++i){
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1.0/value;
            nodes.insert(a);
            nodes.insert(b);
        }
        // floyd算法，找出每个节点之间的（最短）距离，在这道题目里面，两点之间
        // 的权重唯一，要么不存在，存在就是唯一
        // k表示中间节点，从i->k->j的距离
        for(auto &k : nodes){
            for(auto &i : nodes){
                for(auto &j : nodes){
                    // 如果i->k和k->j之间存在边
                    if(graph[i].count(k) && graph[k].count(j)){
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }
        vector<double> ans;
        for(auto& q : queries){
            if(!graph[q[0]][q[1]]){
                ans.push_back(-1.0);
            }else{
                ans.push_back(graph[q[0]][q[1]]);
            }
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    return 0;
}