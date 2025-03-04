#include <bits/stdc++.h>
using namespace std;

#define int long long

bool dfs(int start, string curr, string target, int end, vector<pair<int, char>> adj[]) {
    if (curr == target && start == end) 
        return true;

    if (curr.size() >= target.size()) 
        return false;

    for (auto x : adj[start]) {
        int v = x.first;
        char ch = x.second;

        if (dfs(v, curr + ch, target, end, adj)) 
            return true;
    }

    return false;
}

void _() {
    
    int n;
    cin >> n;
    // vector<int> adj[6]; 
    vector<pair<int, char>> adj[n];

    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        int u = a - 'a';
        int v = c - 'a';

        adj[u].push_back({v, b});
    }
    

    int q; cin >> q;
    while(q--) {
      string target;
      cin >> target;
      cout << (dfs(0, "", target, 2, adj) ? "Accepted" : "Rejected") << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    while (T--) _();

    return 0;
}
