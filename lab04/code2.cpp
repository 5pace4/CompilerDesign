#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve_equation() {
   string s; cin >> s;
   queue<char>mul, div, add, sub, mod, bracket;

   for(auto x:s) {
    if(x == '*') mul.push(x);
    else if(x == '/') div.push(x);
    else if( x == '%') mod.push(x);
    else if(x == '+') add.push(x);
    else if(x == '-') sub.push(x);
    else if(x == '(') bracket.push(x);
   }

   while(!bracket.empty()) {
     bracket.pop();
     string curr = "";
     bool ok = true;
     for(int i = 0; i < s.size(); i++) {
       // cerr << s[i] << '\n';
       if(s[i] == '(' and ok) {
         char ch1 = s[i+1];
         char op = s[i+2];
         char ch2 = s[i+3];
         int m;
         if(op == '*') {
            m = (ch1 - '0') * (ch2 - '0');
            mul.pop();
         }
         else if(op == '/') {
            m = (ch1 - '0') / (ch2 - '0');
            div.pop();
         }
         else if(op == '%') {
            m = (ch1 - '0') % (ch2 - '0');
            mod.pop();
         }
         else if(op == '+') {
            m = (ch1 - '0') + (ch2 - '0');
            add.pop();
         }
         else if(op == '%') {
            m = (ch1 - '0') - (ch2 - '0');
            sub.pop();
         }
         curr+= to_string(m);
         // cout << ch << ' ';
         ok = false;
         while(s[i]  != ')' and i < s.size()) i++;
       }
       else if(s[i] != ')' && s[i] != ')') curr+=s[i];
     }
     cout << curr << '\n';
     s.clear();
     s = curr;
   }

   while(!mul.empty()) {
     mul.pop();
     string curr = "";
     bool ok = true;
     for(int i = 0; i < s.size(); i++) {
       // cout << s[i] << '\n';
       if(s[i] == '*' and ok) {
         char ch = curr.back();
         curr.pop_back();
         int m = (ch - '0') * (s[++i] - '0');
         curr+= to_string(m);
         // cout << ch << ' ';
         ok = false;
       }
       else curr+=s[i];
     }
     cout << curr << '\n';
     s.clear();
     s = curr;
   }

   while(!div.empty()) {
     div.pop();
     string curr = "";
     bool ok = true;
     for(int i = 0; i < s.size(); i++) {
       // cout << s[i] << '\n';
       if(s[i] == '/' and ok) {
         char ch = curr.back();
         curr.pop_back();
         int m = (ch - '0') / (s[++i] - '0');
         curr+= to_string(m);
         // cout << ch << ' ';
         ok = false;
       }
       else curr+=s[i];
     }
     cout << curr << '\n';
     s.clear();
     s = curr;
   }

    while(!mod.empty()) {
     mod.pop();
     string curr = "";
     bool ok = true;
     for(int i = 0; i < s.size(); i++) {
       // cout << s[i] << '\n';
       if(s[i] == '%' and ok) {
         char ch = curr.back();
         curr.pop_back();
         int m = (ch - '0') % (s[++i] - '0');
         curr+= to_string(m);
         // cout << ch << ' ';
         ok = false;
       }
       else curr+=s[i];
     }
     cout << curr << '\n';
     s.clear();
     s = curr;
   }

   while(!add.empty()) {
     add.pop();
     string curr = "";
     bool ok = true;
     for(int i = 0; i < s.size(); i++) {
       // cout << s[i] << '\n';
       if(s[i] == '+' and ok) {
         char ch = curr.back();
         curr.pop_back();
         int m = (ch - '0') + (s[++i] - '0');
         curr+= to_string(m);
         // cout << ch << ' ';
         ok = false;
       }
       else curr+=s[i];
     }
     cout << curr << '\n';
     s.clear();
     s = curr;
   }

   while(!sub.empty()) {
     sub.pop();
     string curr = "";
     bool ok = true;
     for(int i = 0; i < s.size(); i++) {
       // cout << s[i] << '\n';
       if(s[i] == '-' and ok) {
         char ch = curr.back();
         curr.pop_back();
         int m = (ch - '0') - (s[++i] - '0');
         curr+= to_string(m);
         // cout << ch << ' ';
         ok = false;
       }
       else curr+=s[i];
     }
     cout << curr << '\n';
     s.clear();
     s = curr;
   }


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // string s; cin >> s;
    solve_equation();
    return 0;
}
