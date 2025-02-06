# Arithmetic Expression Evaluator

## Overview

This document explains the implementation of an arithmetic expression evaluator that follows operator precedence and handles multiple-digit numbers and brackets. The code uses **queues** to process operations in the correct order and a function to extract multi-digit numbers. The final implementation supports:

1. **Single-digit arithmetic operations** (Code1.cpp)
2. **Brackets for precedence handling** (Code2.cpp)
3. **Multi-digit numbers** (Code3.cpp)

## Full Code Links

- [Code1.cpp (Single-digit arithmetic)](code1.cpp)
- [Code2.cpp (Brackets added)](code2.cpp)
- [Code3.cpp (Multi-digit numbers)](code3.cpp)

---

## Code Explanation

### Step 1: Handling Single-Digit Arithmetic Operations

The first version (`code1.cpp`) processes expressions where operands are single digits. It evaluates multiplication (`*`), division (`/`), modulus (`%`), addition (`+`), and subtraction (`-`) in the correct order.

#### **Core Logic**

- Uses **queues** to store operators (`*, /, %, +, -`).
- Iterates over the string and applies operations sequentially.
- Modifies the expression iteratively until only a single number remains.

**Example Input:**

```
3+5*2-8/4
```

**Processing Order:**

1. `5*2 = 10` → `3+10-8/4`
2. `8/4 = 2` → `3+10-2`
3. `3+10 = 13` → `13-2`
4. `13-2 = 11`

---

### Step 2: Handling Brackets for Operator Precedence

In `code2.cpp`, **brackets** (`()`) are added, which means evaluating inner expressions first.

#### **Bracket Processing Logic**

- The program detects `(` and extracts the subexpression.
- Evaluates the operation inside brackets first.
- Replaces the bracketed expression with the computed result before continuing with the rest of the equation.

**Example Input:**

```
(3+5)*2-(8/4+6)
```

**Processing Order:**

1. Evaluate `(3+5) = 8` → `8*2-(8/4+6)`
2. Evaluate `8/4 = 2` → `8*2-(2+6)`
3. Evaluate `(2+6) = 8` → `8*2-8`
4. `8*2 = 16` → `16-8`
5. `16-8 = 8`

**Key Code Segment:**

```cpp
if(s[i] == '(' and ok) {
    char ch1 = s[i+1];
    char op = s[i+2];
    char ch2 = s[i+3];
    int m;
    if(op == '*') m = (ch1 - '0') * (ch2 - '0');
    else if(op == '/') m = (ch1 - '0') / (ch2 - '0');
    else if(op == '+') m = (ch1 - '0') + (ch2 - '0');
    else if(op == '-') m = (ch1 - '0') - (ch2 - '0');
    curr+= to_string(m);
    ok = false;
}
```

---

### Step 3: Handling Multi-Digit Numbers

The final version (`code3.cpp`) extends the previous versions by processing **multi-digit numbers**.

#### **Key Improvements:**

- A helper function `digits()` extracts multi-digit numbers from an expression.
- Instead of assuming single-digit operands, the code properly detects **full numbers** before an operator.
- Uses `stoi()` to convert substrings into integer values.

#### **Key Code Segment:**

```cpp
string digits(int i, string s, int dir) {
    string ans = "";
    if(dir == 1) { //move right
        while(i < s.size()) {
            if(isdigit(s[i])) ans += s[i];
            else break;
            i++;
        }
    }
    else { //move left
        while(i >= 0) {
            if(isdigit(s[i])) ans += s[i];
            else break;
            i--;
        }
    }
    return ans;
}
```

**Example Input:**

```
(25+75)*10-50/5+200%7
```

**Processing Order:**

1. Evaluate `(25+75) = 100` → `100*10-50/5+200%7`
2. `100*10 = 1000` → `1000-50/5+200%7`
3. `50/5 = 10` → `1000-10+200%7`
4. `200%7 = 4` → `1000-10+4`
5. `1000+10 = 1004` → `1004-10`
6. `1004-10 = 994`

---

## **Lessons in Compiler Design**

This project teaches fundamental **compiler design** concepts, including:

### **1. Tokenization**

- The program scans the string and identifies **operators** and **operands**.
- Similar to how a **lexer** breaks code into tokens.

### **2. Operator Precedence Handling**

- The use of **queues** enforces the correct execution order of operations.
- Multiplication, division, and modulus are evaluated before addition and subtraction, similar to a compiler's **precedence rules**.

### **3. Parentheses Handling**

- Parentheses force certain calculations to be done first.
- The program **extracts bracketed expressions**, evaluates them, and reinserts the result.

### **4. Multi-Digit Number Handling**

- Instead of assuming **single characters**, a function `digits()` properly extracts entire numbers.
- This simulates **symbol tables** in a compiler that recognize multi-character tokens.

### **5. Stepwise Expression Reduction**

- The input string is iteratively **simplified** until only one number remains.
- Mirrors **abstract syntax trees (ASTs)** used in real-world compilers to represent expressions.

---

## **How to Compile and Run**

```bash
g++ code3.cpp -o evaluator
./evaluator
```

**Example Input:**

```
(25+75)*10-50/5+200%7
```

**Output:**

```
994
```
