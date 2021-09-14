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

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
        // 邻接表，adj[i]，i是它里面所有节点的前驱
        vector<vector<int>> adj(numCourses);
        // 入度，表示i节点有 indeg[i]个前驱
        vector<int> indeg(numCourses, 0);
        int n = prerequisites.size();
        for(int i = 0; i < n; ++i){
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            adj[from].push_back(to);
            indeg[to]++;
        }
        queue<int> q;
        vector<int> vis(numCourses, 0);
        // 找到没有前驱的节点入队
        for(int i = 0; i < numCourses; ++i){
            if(!indeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int no = q.front();
            q.pop();
            if(vis[no]){
                continue;
            }
            vis[no] = 1;
            // 遍历no节点的所有后驱，由于删除了这些边，所以入度都要减1
            // 当一个点的入度为0时，证明它所有前驱已经访问过了，所以该节点入队
            for(int i = 0; i < adj[no].size(); ++i){
                int to = adj[no][i];
                --indeg[to];
                if(!indeg[to]){
                    q.push(to);
                }
            }
        }
        // 如果有入度不为0的点，证明存在环
        for(int i = 0; i < numCourses; ++i){
            if(indeg[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}