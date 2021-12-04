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

struct cmp {
    bool operator()(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> idxArr(n, 0);
        priority_queue<pair<int, vector<int>>,  vector<pair<int, vector<int>>>, cmp> pq;
        set<vector<int>> seen;
        seen.insert(idxArr);
        int tmpSum = 0;
        for (int i = 0; i < n; ++i) {
            tmpSum += mat[i][0];
        }
        pq.emplace(tmpSum, idxArr);
        while (k > 1) {
            k--;
            auto [curSum, idxs] = pq.top();
            pq.pop();
            for (int i = 0; i < n; ++i) {
                if (idxs[i] + 1 > m - 1) {
                    continue;
                }
                idxs[i] += 1;
                if (seen.count(idxs)) {
                    idxs[i] -= 1;
                    continue;
                }
                int newSum = curSum - mat[i][idxs[i]-1] + mat[i][idxs[i]];
                pq.emplace(newSum, idxs);
                seen.insert(idxs);
                idxs[i] -= 1;
            }
        }
        return pq.top().first;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    int k = 5;
    int ans = solution.kthSmallest(mat, k);
    cout << "Hello world";
}
