#include<bits/stdc++.h>

using namespace std;

const string operators = "+-*/=<>!&|";
const string data_type[6] = {"int", "bool", "float", "double", "long long", "void"};
const string key_word[10] = {"if", "else", "for", "while", "return", "true", "false", "cout", "cin"};

vector<string> dataType, keyWord, Operator, others, fun;


bool isKeyword(const string& str) {
    for (int i = 0; i < 10; i++) {
        if (str == key_word[i]) return true;
    }
    return false;
}

bool isDataType(const string& str) {
    for (int i = 0; i < 6; i++) {
        if (str == data_type[i]) return true;
    }
    return false;
}

bool isOperator(const string& s) {
    if (s.size() == 1) {
        return operators.find(s[0]) != string::npos;
    }
    if (s.size() == 2 && (s == "==" || s == "!=" || s == "&&" || s == "||" || s == ">=" || s == "<=")) {
        return true;
    }
    return false;
}

bool isFunction(const string& s) {
    size_t pos = s.find('(');
    if (pos == string::npos) return false;
    return true;
}

void Lexems(const string& s) {
    if (isDataType(s)) {
        dataType.push_back(s); 
    }
    else if (isOperator(s)) {
        Operator.push_back(s); 
    }
    else if (isKeyword(s)) {
        keyWord.push_back(s); 
    }
    else if (isFunction(s)) {
        size_t pos = s.find('(');
        string x = s.substr(0, pos+1);
        x+=')';
        fun.push_back(x);
        string temp = s.substr(pos+1, s.size());
        if(temp.size() > 1) Lexems(temp);
    }
    else {
        others.push_back(s); 
    }
}

void show_lexems() {
    cout << "Functions: ";
    for (int i = 0; i < fun.size(); i++) {
        cout << fun[i];
        if (i == fun.size() - 1) cout << '\n';
        else cout << ", ";
    }

    cout << "Operators: ";
    for (int i = 0; i < Operator.size(); i++) {
        cout << Operator[i];
        if (i == Operator.size() - 1) cout << '\n';
        else cout << ", ";
    }

    cout << "Data Types: ";
    for (int i = 0; i < dataType.size(); i++) {
        cout << dataType[i];
        if (i == dataType.size() - 1) cout << '\n';
        else cout << ", ";
    }

    cout << "Keywords: ";
    for (int i = 0; i < keyWord.size(); i++) {
        cout << keyWord[i];
        if (i == keyWord.size() - 1) cout << '\n';
        else cout << ", ";
    }

    cout << "Others: ";
    for (int i = 0; i < others.size(); i++) {
        cout << others[i];
        if (i == others.size() - 1) cout << '\n';
        else cout << ", ";
    }
}

void processInput(const string& input) {
    stringstream ss(input);
    string token;

    while (ss >> token) {
        //cerr << token << '\n';
        Lexems(token);
    }
}

int main() {
    string s;

    while (getline(cin, s)) {
        // cerr << s << '\n';
        processInput(s); 
    }
    show_lexems();

    return 0;
}


/*

input 1:

int main() {
    int k = 1 ;
    bool ok = true ;
    int c = k + 1 ;
    return 0 ;
}

input 2:

int main() {
    int k = 1 ;
    bool ok = true ;
    int c = k + 1 ;
    return 0 ;
}
void fun(int x) {
    int y;
    cin >> y;
    cout << x + y << '\n';
}

*/