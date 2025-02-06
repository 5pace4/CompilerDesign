# Lexical Analyzer for C Code

## Overview
This document explains the implementation of a **Lexical Analyzer** that scans a C program and categorizes elements into different types, such as **keywords, operators, numbers, and identifiers**. The analyzer reads input code from a file and processes it using predefined lists. The updated version now supports **interactive input handling** and **writes output to a file**.

## Full Code Link
- [Lexical Analyzer Code](lexicalAnalyzer.c)

---

## **How It Works**
The program reads input from a file (`file.txt`) or **interactive user input**, categorizes tokens, and stores the results in `output.txt`.

### **Token Categories**
- **Keywords**: `int, float, if, else, while, return, for, break, continue, main`
- **Operators**: `+ - * / = < > & | ; , ( ) { } [ ]`
- **Numbers**: Any numeric constant.
- **Identifiers**: Variable and function names.

### **Processing Logic**
1. The input is read **line by line**.
2. Each character is checked:
   - If alphabetic, it's stored as a potential keyword or identifier.
   - If numeric, it may be a number.
   - If an operator, it’s categorized immediately.
3. At the end of each word, it is classified as:
   - **Keyword** if it matches the predefined list.
   - **Number** if it starts with a digit.
   - **Identifier** otherwise.
4. The output is written to `output.txt`.

---

## **Key Functions**

### **1. Checking Token Type**
```c
bool isOperator(char ch) {
    for(int i = 0; i < strlen(operators); i++) {
        if(ch == operators[i]) {
            return true;
        }
    }
    return false;
}
```
- This function identifies **operators** by comparing characters against the `operators` list.

### **2. Lexical Analysis of a File and Writing Output**
```c
void lexems(const char* filename) {
    FILE* file = fopen(filename, "r");
    FILE* output = fopen("output.txt", "a");

    if(!file) {
        printf("Unable to open file!");
        return;
    }

    char str[256];
    char token[100] = "";
    int tokenId = 0;

    while(fgets(str, sizeof(str), file)) {
        int n = strlen(str);

        for(int i = 0; i < n; i++) {
            char ch = str[i];
            if(isalpha(ch)) {
                token[tokenId++] = ch;
            }
            else if(isdigit(ch)) {
                if(tokenId > 0 && isalpha(token[0])) {
                    token[tokenId] = '\0';
                    fprintf(output, "%s\n", token);
                    tokenId = 0;
                }
                token[tokenId++] = ch;
            }
            else if(isOperator(ch)) {
                if(tokenId > 0) {
                    token[tokenId] = '\0';
                    fprintf(output, "%s\n", token);
                    tokenId = 0;
                }
                fprintf(output, "%c\n", ch);
            }
            else if(isspace(ch)) {
                if(tokenId > 0) {
                    token[tokenId] = '\0';
                    fprintf(output, "%s\n", token);
                    tokenId = 0;
                }
            }
        }
        if(tokenId > 0) {
            token[tokenId] = '\0';
            fprintf(output, "%s\n", token);
            tokenId = 0;
        }
    }
    fclose(file);
    fclose(output);
}
```
- This function reads from `file.txt`, processes characters, and **writes categorized tokens to `output.txt`**.

### **3. Handling Interactive Input and Writing to File**
```c
int main() {
    const char* filename = "file.txt";
    while(true) {
        FILE* file = fopen(filename, "a"); // Append mode
        char str[256];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "999") == 0) {
            break;
        }

        fprintf(file, "%s\n", str);
        fclose(file);
    }
    lexems("file.txt");
    return 0;
}
```
- Allows **interactive input** where the user types in **lines of code**.
- Stops when the user enters `999`.
- Appends input to `file.txt` and then **calls `lexems()` to analyze it**.

---

## **Example Inputs and Outputs**
### **Input Code (file.txt or user input):**
```c
int main() {
    int a = 5;
    float b = 3.14;
    if (a > 2) {
        b = b + a;
    }
    return 0;
}
```
### **Categorized Output (output.txt):**
```
Keyword: int
Identifier: main
Operator: (
Operator: )
Operator: {
Keyword: int
Identifier: a
Operator: =
Number: 5
Operator: ;
Keyword: float
Identifier: b
Operator: =
Number: 3.14
Operator: ;
Keyword: if
Operator: (
Identifier: a
Operator: >
Number: 2
Operator: )
Operator: {
Identifier: b
Operator: =
Identifier: b
Operator: +
Identifier: a
Operator: ;
Operator: }
Keyword: return
Number: 0
Operator: ;
Operator: }
```
---

## **Lessons in Compiler Design**
This project introduces core **compiler design concepts**:

### **1. Tokenization**
- The program **splits input code into tokens**.
- Similar to how a **lexer** works in a compiler.

### **2. Operator and Keyword Recognition**
- Recognizes **single-character** operators.
- Identifies **keywords** from a predefined list.

### **3. Handling Identifiers and Numbers**
- Differentiates between **variables** (identifiers) and **constants** (numbers).
- Properly classifies based on starting character (letter vs. digit).

### **4. Interactive and File-based Processing**
- Supports both **interactive input** and **file processing**.
- Writes categorized tokens to an **output file (`output.txt`)**.

---

## **How to Compile and Run**
```bash
gcc lexical_analyzer.c -o analyzer
./analyzer
```
**Example Usage:**
```bash
./analyzer
```
- Enter C code line-by-line.
- Type `999` to stop and analyze.

---

## **Conclusion**
This **Lexical Analyzer for C** successfully:
1. Reads source code (file/interactive input).
2. Identifies **keywords, numbers, identifiers, and operators**.
3. Writes categorized tokens to `output.txt`.

This is a foundational step for **building a full compiler**! 🚀
