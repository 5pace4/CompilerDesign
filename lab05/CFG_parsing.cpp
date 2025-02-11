#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
vector<vector<string>> rules(100);

bool checkString(string curr, const string &target) {
    if (curr == target) return true;
    if (curr.size() > target.size()) return false;

    for (int i = 0; i < curr.size(); i++) {
        string ch(1, curr[i]);
        if (mp.find(ch) != mp.end()) {
            int ruleIndex = mp[ch];

            for (const string &replacement : rules[ruleIndex]) {
                string newString = curr.substr(0, i) + replacement + curr.substr(i + 1);
                if (checkString(newString, target)) {
                    return true;
                }
            }
            return false; 
        }
    }

    return false; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Rule;
    cin >> Rule;
    cin.ignore();

    // grammar rules
    for (int i = 0; i < Rule; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string left, right;
        ss >> left;
        // cerr << left << '\n';
        mp[left] = i; // Map non-terminal to its rule index
        while (ss >> right) {
            rules[i].push_back(right);
        }
    }

    int T;
    cin >> T;

    while (T--) {
        string testStr;
        cin >> testStr;

        if (checkString("S", testStr)) {
            cout << "accepted\n";
        } else {
            cout << "rejected\n";
        }
    }

    return 0;
}
