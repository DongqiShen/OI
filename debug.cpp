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
    unsigned long long int P = 1313131;
    vector<unsigned long long int> h;
    vector<unsigned long long int> p;
public:
    string findStr(string s, int len) {
        int n = s.size();
        unordered_set<unsigned long long int> seen;
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            unsigned long long int hash = h[j] - h[i - 1] * p[j - i + 1];
            if (seen.count(hash)) {
                string str = s.substr(i - 1, len);
                return str;
            }
            seen.insert(hash);
        }
        return "";
    }
    string longestDupSubstring(string s)
    {
        int n = s.size();
        h.assign(n+1, 0);
        p.assign(n+1, 0);
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            h[i] = h[i-1] * P + (s[i-1] - 'a');
            p[i] = p[i-1] * P;
        }
        int left = 1;
        int right = n;
        string ans = "";
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            string str = findStr(s, mid);
            if (str.size() > 0) {
                left = mid + 1;
                ans = str;
            } else {
                right = mid;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "banana";
    string ans = solution.longestDupSubstring(s);
    return 0;
}