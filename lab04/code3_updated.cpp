#include <bits/stdc++.h>

using namespace std;
#define int long long

string getNum(int i, string &s, int dir) {
    string res = "";
    if (dir == 1) {
        while (i < s.size() && isdigit(s[i])) res += s[i], i++;
    } else {
        while (i >= 0 && isdigit(s[i])) res = s[i] + res, i--;
    }
    return res;
}


int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

void processOp(char op, queue<char> &q, string &s, int (*opFunc)(int, int), bool print = true) {
    while (!q.empty()) {
        q.pop();
        string res = "";
        bool done = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == op && !done) {
                string x = getNum(i - 1, s, 0);
                for (int k = 0; k < x.size(); k++) res.pop_back();
                string y = getNum(i + 1, s, 1);
                for (int k = 0; k < y.size(); k++) i++;
                res += to_string(opFunc(stoi(x), stoi(y)));
                done = true;
            } 
            else res += s[i];
        }
        s = res;
        if (print) cout << s << '\n';
    }
}

void solveBrackets(string &s) {
    while (s.find('(') != string::npos) { 
        int last = -1, close = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') last = i;
            if (s[i] == ')' && last != -1) {
                close = i;
                break;
            }
        }
        if (last == -1 || close == -1) break;

        string in = s.substr(last + 1, close - last - 1), temp = in;
        queue<char> mulQ, divQ, modQ, addQ, subQ;

        for (char x : in) {
            if (x == '*') mulQ.push(x);
            else if (x == '/') divQ.push(x);
            else if (x == '%') modQ.push(x);
            else if (x == '+') addQ.push(x);
            else if (x == '-') subQ.push(x);
        }

        processOp('*', mulQ, temp, mul, false);
        processOp('/', divQ, temp, divi, false);
        processOp('%', modQ, temp, mod, false);
        processOp('+', addQ, temp, add, false);
        processOp('-', subQ, temp, sub, false);

        s = s.substr(0, last) + temp + s.substr(close + 1);
        cout << s << '\n'; 
    }
}

void solve() {
    string s;
    cin >> s;
    cout << s << '\n';

    queue<char> mulQ, divQ, addQ, subQ, modQ;
    for (char x : s) {
        if (x == '*') mulQ.push(x);
        else if (x == '/') divQ.push(x);
        else if (x == '%') modQ.push(x);
        else if (x == '+') addQ.push(x);
        else if (x == '-') subQ.push(x);
    }

    solveBrackets(s);
    processOp('*', mulQ, s, mul);
    processOp('/', divQ, s, divi);
    processOp('%', modQ, s, mod);
    processOp('+', addQ, s, add);
    processOp('-', subQ, s, sub);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
