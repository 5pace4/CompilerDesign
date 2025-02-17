#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
vector<vector<string>> rules(100);
unordered_map<string, bool> dp; // Memoization storage

bool checkString(string curr, const string &target) {
    if (curr == target) return true;

    int cnt = 0;
    for (auto x : curr) if (x >= 'a' && x <= 'z') cnt++;
    if (cnt > target.size()) return false;

    if (dp.find(curr) != dp.end()) return dp[curr];

    for (int i = 0; i < curr.size(); i++) {
        string ch(1, curr[i]);

        if (mp.find(ch) != mp.end()) {
            int ruleIdx = mp[ch];

            for (const string &replace : rules[ruleIdx]) {
                string newStr = curr.substr(0, i) + replace + curr.substr(i + 1);

                if (replace == "$") { 
                    // cerr << newStr << '\n'; //debugging
                    newStr.erase(i, 1);
                    // cerr << newStr << '\n'; //debugging
                }

                if (checkString(newStr, target)) {
                    return dp[curr] = true; 
                }
            }
            return dp[curr] = false; 
        }
    }

    return dp[curr] = false; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Rule;
    cin >> Rule;
    cin.ignore();

    // Read grammar rules
    for (int i = 0; i < Rule; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string left, right;
        ss >> left;
        mp[left] = i; // Map non-terminal to rule index
        while (ss >> right) {
            rules[i].push_back(right);
        }
    }

    int T = 1;
    cin >> T;

    while (T--) {
        string testStr;
        cin >> testStr;
        dp.clear(); 

        if (checkString("S", testStr)) {
            cout << "accepted\n";
        } 
        else {
            cout << "rejected\n";
        }
    }

    return 0;
}
