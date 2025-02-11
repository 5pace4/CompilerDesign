# **CFG Parsing Using Recursion in C++**

## **Overview**
This document explains a C++ program that determines whether a given string is **accepted** or **rejected** based on a given **Context-Free Grammar (CFG)** using recursion.

---

## **Table of Contents**
1. [Problem Description](#problem-description)
2. [Understanding the Input and Output](#understanding-the-input-and-output)
3. [Key Concepts](#key-concepts)
4. [Implementation Details](#implementation-details)
5. [Code Explanation](#code-explanation)
6. [Complexity Analysis](#complexity-analysis)
7. [Example Runs](#example-runs)
8. [Possible Enhancements](#possible-enhancements)

---

## **Problem Description**
Given a CFG, we need to determine whether a string is **accepted** (derivable from the start symbol) or **rejected** (not derivable). The rules and strings are provided in a structured input format.

---

## **Understanding the Input and Output**

### **Input Format**
1. The first line contains an integer **Rule**, representing the number of production rules.
2. The next `Rule` lines contain **CFG production rules** in the format:
   ```
   Non-terminal Production1 Production2 ... ProductionN
   ```
   - The first symbol on each line is the **non-terminal**.
   - The remaining symbols are **possible expansions** of that non-terminal.
3. An integer `T` follows, representing the **number of test cases**.
4. The next `T` lines contain **test strings** to check against the grammar.

### **Output Format**
- Print `"accepted"` if the string can be derived from the grammar.
- Print `"rejected"` otherwise.

### **Example Input**
```
3
S AB
A aA a
B bB b
2
aaabb
baa
```

### **Example Output**
```
accepted
rejected
```

---

## **Key Concepts**

### **Context-Free Grammar (CFG)**
A **CFG** consists of:
- **Non-terminals** (e.g., `S`, `A`, `B`)
- **Terminals** (e.g., `a`, `b`)
- **Production rules** (e.g., `A → aA | a`)
- **Start Symbol** (e.g., `S`)

### **Recursive Expansion**
- A non-terminal (e.g., `A`) is replaced with **each possible production** and checked recursively.
- If a valid expansion matches the target string, the string is **accepted**.

---

## **Implementation Details**

### **Data Structures Used**
| Data Structure | Purpose |
|--------------|---------|
| `map<string, int> mp` | Maps non-terminals to their index in the rule list. |
| `vector<vector<string>> rules` | Stores production rules for each non-terminal. |

### **Recursive Function**
```cpp
bool checkString(string curr, const string &target);
```
- **Base Case**: If `curr == target`, return `true`.
- If `curr` is **longer** than `target`, return `false`.
- Find the first **non-terminal** and try **all possible replacements**.
- Recursively expand and check if the target string is reachable.

---

## **Code Explanation**

### **C++ Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
vector<vector<string>> rules(100);

bool checkString(string curr, const string &target) {
    if (curr == target) return true;
    if (curr.size() > target.size()) return false;

    // Find first non-terminal in current string
    for (int i = 0; i < curr.size(); i++) {
        string ch(1, curr[i]); // Convert char to string
        if (mp.find(ch) != mp.end()) { // If it's a non-terminal
            int ruleIndex = mp[ch];

            // Try replacing the non-terminal with its production rules
            for (const string &replacement : rules[ruleIndex]) {
                string newString = curr.substr(0, i) + replacement + curr.substr(i + 1);
                if (checkString(newString, target)) {
                    return true;
                }
            }
            return false; // If no valid expansion works, reject
        }
    }
    return false; // If no non-terminals remain and it's not the target, reject
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int Rule;
    cin >> Rule;
    cin.ignore();

    // Reading grammar rules
    for (int i = 0; i < Rule; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string left, right;
        ss >> left;
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
```

---

## **Complexity Analysis**

| Operation | Complexity |
|-----------|------------|
| Reading Grammar Rules | **O(R)** (where R = number of rules) |
| Checking a string | **O(2ⁿ)** (Worst-case recursion depth) |
| Overall Complexity | **Exponential (Backtracking-based CFG Parsing)** |

---

## **Example Runs**

### **Input 1**
```
3
S AB
A aA a
B bB b
2
aaabb
baa
```

### **Output 1**
```
accepted
rejected
```

### **Input 2**
```
2
S aS b
2
ab
aa
```

### **Output 2**
```
accepted
rejected
```

---

## **Possible Enhancements**

### ✅ **Optimization using Memoization**
- Store already computed values to **reduce redundant recursion calls**.

### ✅ **Breadth-First Search (BFS) for Iterative Parsing**
- Instead of recursion, use **BFS** to explore derivations **level-by-level**.

### ✅ **Parsing Table (LL(1) Parsing)**
- Convert CFG to **LL(1) parsing table** for **efficient** top-down parsing.

---

## **Conclusion**
This C++ program correctly determines whether a string is **accepted** or **rejected** based on a given CFG using **recursive expansion**. The solution explores **all possible derivations**, ensuring correctness but potentially having **high time complexity**.

For large grammars, consider **memoization**, **BFS-based parsing**, or **LL(1) table-driven parsing** for efficiency.

