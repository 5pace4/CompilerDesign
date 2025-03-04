#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>

using namespace std;


map<pair<char, char>, string> parsingTable = {
    {{'E', 'i'}, "T e"},
    {{'E', '('}, "T e"},
    {{'e', '+'}, "+ T e"},
    {{'e', ')'}, "ε"},
    {{'e', '$'}, "ε"},
    {{'T', 'i'}, "F t"},
    {{'T', '('}, "F t"},
    {{'t', '+'}, "ε"},
    {{'t', '*'}, "* F t"},
    {{'t', ')'}, "ε"},
    {{'t', '$'}, "ε"},
    {{'F', 'i'}, "i"},
    {{'F', '('}, "( E )"}
};

bool isTerminal(char c) {
    return !isupper(c) && c != 'e' && c != 't';
}

void parse(string input) {
    stack<char> parsingStack;
    parsingStack.push('$'); 
    parsingStack.push('E'); 

    int index = 0;
    input += '$'; 
    string matced = "";
    while (!parsingStack.empty()) {
        stack<char> tempStack = parsingStack;
        string st = "";
        while (!tempStack.empty()) {
            st += tempStack.top();
            tempStack.pop();
        }
        cout << matced << " " << st << " " << input.substr(index) << endl;

        char top = parsingStack.top();
        char currentInput = input[index];

        if (top == currentInput) {
            matced += currentInput;
            parsingStack.pop();
            index++;
        } 
        // else if (isTerminal(top) || top == '$') {
        //     cout << "Rejected" << endl;
        //     return;
        // } 
        else {
            if (parsingTable.find({top, currentInput}) != parsingTable.end()) {
                string production = parsingTable[{top, currentInput}];
                // cout << "Output: " << top << " -> " << production << endl;
                parsingStack.pop();
                if (production != "ε") {
                    for (int i = production.length() - 1; i >= 0; i--) {
                        if (production[i] != ' ') {
                            parsingStack.push(production[i]);
                        }
                    }
                }
            } 
            else {
                cout << "No production Rule. REJECT!" << endl;
                return;
            }
        }
    }
    // cout << matced << '\n';
    // cout << input << '\n';
    if (matced == input) {
        cout << "Accept" << endl;
    } else {
        cout << "Reject" << endl;
    }
}

int main() {
    string input;
    cin >> input;

    parse(input);

    return 0;
}

/*
input:
i+i*i
output:
 E$ i+i*i$
 Te$ i+i*i$
 Fte$ i+i*i$
 ite$ i+i*i$
i te$ +i*i$
i e$ +i*i$
i +Te$ +i*i$
i+ Te$ i*i$
i+ Fte$ i*i$
i+ ite$ i*i$
i+i te$ *i$
i+i *Fte$ *i$
i+i* Fte$ i$
i+i* ite$ i$
i+i*i te$ $
i+i*i e$ $
i+i*i $ $
Accept
*/