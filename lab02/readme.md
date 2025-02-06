# Lexical Analyzer for C++ Code

## Overview

This document explains the implementation of a **Lexical Analyzer** that categorizes elements of C++ code into different types, such as **keywords, data types, operators, functions, and others**. The analyzer reads input code, identifies lexemes, and groups them accordingly.

## Full Code Link

- [Lexical Analyzer Code](categorized_lexems.cpp)

---

## **How It Works**

The program scans input C++ code and classifies different tokens using predefined lists:

- **Keywords**: `if, else, for, while, return, true, false, cout, cin`
- **Data Types**: `int, bool, float, double, long long, void`
- **Operators**: `+ - * / = < > ! & | == != && || >= <=`
- **Functions**: Identified using `()` in the token

### **Processing Logic**

1. The input is split into tokens.
2. Each token is checked against the predefined lists.
3. If the token is an operator, function, keyword, data type, or belongs to "others," it is categorized accordingly.

---

## **Key Functions**

### **1. Checking Token Type**

```cpp
bool isKeyword(const string& str) {
    for (int i = 0; i < 10; i++) {
        if (str == key_word[i]) return true;
    }
    return false;
}
```

- This function verifies if a token is a **keyword**.
- Compares the token with a predefined keyword list.

```cpp
bool isOperator(const string& s) {
    if (s.size() == 1) {
        return operators.find(s[0]) != string::npos;
    }
    if (s.size() == 2 && (s == "==" || s == "!=" || s == "&&" || s == "||" || s == ">=" || s == "<=")) {
        return true;
    }
    return false;
}
```

- This function identifies **operators** (single and double-character operators).

```cpp
bool isFunction(const string& s) {
    size_t pos = s.find('(');
    if (pos == string::npos) return false;
    return true;
}
```

- This function checks if a token represents a **function call** by searching for `(`.

### **2. Categorizing Lexemes**

```cpp
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
```

- **Lexems()** categorizes each token into **data types, keywords, operators, functions, or others**.
- If a function is detected, it extracts its name before handling its parameters recursively.

### **3. Processing Input Code**

```cpp
void processInput(const string& input) {
    stringstream ss(input);
    string token;
    while (ss >> token) {
        Lexems(token);
    }
}
```

- The input is read as a string and split into tokens.
- Each token is passed through `Lexems()` for classification.

---

## **Example Inputs and Outputs**

### **Input Code 1:**

```cpp
int main() {
    int k = 1;
    bool ok = true;
    int c = k + 1;
    return 0;
}
```

### **Categorized Output:**

```
Functions: main()
Operators: =, =, +, =
Data Types: int, bool, int
Keywords: return, true
Others: k, ok, c, 1, 1, 0
```

---

### **Input Code 2:**

```cpp
int main() {
    int k = 1;
    bool ok = true;
    int c = k + 1;
    return 0;
}
void fun(int x) {
    int y;
    cin >> y;
    cout << x + y << '\n';
}
```

### **Categorized Output:**

```
Functions: main(), fun()
Operators: =, =, +, =, >>, +
Data Types: int, bool, int, int
Keywords: return, true, cin, cout
Others: k, ok, c, x, y, 1, 1, 0
```

---

## **Lessons in Compiler Design**

This project provides insights into lexical analysis, a crucial part of **compiler design**:

### **1. Tokenization**

- The program scans the input code and breaks it into **tokens**.
- Similar to how a **lexer** in a compiler works.

### **2. Categorization of Tokens**

- Each token is categorized into **keywords, data types, operators, functions, or others**.
- This is similar to the **lexical analysis phase** in a compiler.

### **3. Recognizing Functions**

- The analyzer detects functions based on `(`.
- This technique is used in **parsers** for function identification.

### **4. Operator Recognition**

- Recognizes both **single-character** and **multi-character** operators (`==`, `!=`, `>=`, `<=`, `&&`, `||`).
- This is useful for **syntax analysis** in a compiler.

### **5. Handling User Input**

- Reads and processes **multi-line input** efficiently.
- This mimics how compilers handle **source code parsing**.

---

## **How to Compile and Run**

```bash
g++ lexical_analyzer.cpp -o analyzer
./analyzer
```

**Example Input:**

```cpp
int main() {
    int x = 10;
    if (x > 5) {
        cout << "Large";
    }
}
```

**Output:**

```
Functions: main()
Operators: =, >, <<
Data Types: int
Keywords: if, cout
Others: x, 10, "Large"
```

---

## **Conclusion**

This lexical analyzer simulates **tokenization** in a compiler by:

1. **Extracting tokens** from input code.
2. **Classifying tokens** based on syntax rules.
3. **Handling multi-character tokens** (functions, operators).

By extending this, we can build **parsers** and even a **mini-compiler**!

---
