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

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        vector<vector<int>> ans(n);
        vector<int> idxs(n, -1);
        for (int i = 0; i < n; ++i) {
            int empty = 0;
            int equal = 0;
            int k = people[i][1];
            int j = 0;
            while (empty + equal < k) {
                if (idxs[j] == -1) {
                    empty += 1;
                }
                if (idxs[j] != -1 && people[i][0] == people[idxs[j]][0]) {
                    equal += 1;
                }
                j++;
            }
            while (idxs[j] != -1) {
                j += 1;
            }
            idxs[j] = i;
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = people[idxs[i]];
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> ans = solution.reconstructQueue(people);
    cout << "Hello world";
}
