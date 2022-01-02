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

using ll = long long int;

vector<ll> tree;
int n;

int lowbit(int x) {
    return x & -x;
}

ll query(ll x) {
    ll ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(ll x, ll k) {
    while (x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
}

void add_range(ll l, ll r, ll k) {
    add(l, k);
    add(r + 1, -k);
}

int main()
{
    int _n, q;
    cin>>_n>>q;
    n = _n + 1;
    tree.assign(n, 0);
    vector<int> arr(n);
    for (int i = 1; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = 1; i < n; ++i) {
        int diff = arr[i] - arr[i-1];
        add(i, diff);
    }
    int l, r, x, type;
    vector<ll> ans;
    for (int i = 0; i < q; ++i) {
        cin>>type;
        if (type == 1) {
            cin>>l>>r>>x;
            add_range(l, r, x);
        } else if (type == 2) {
            cin>>x;
            ll rtn = query(x);
            ans.emplace_back(rtn);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<"\n";
    }
    return 0;
}