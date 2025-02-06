# **CompilerDesign (CSE-432)**

## 🏫 **Course Information**

- **Course Name:** Compiler Design (Sessional)
- **Course Code:** CSE-432
- **Total Credit:** 0.75

👨‍🏫 **Instructors:**

1. **Asim Dey** – Assistant Professor, Dept. of CSE, CUET
2. **Md. Al-Mamun Provath** – Lecturer, Dept. of CSE, CUET

---

## 📖 **Introduction**

This repository contains all the lab assignments and implementation codes for the **Compiler Design (Sessional) CSE-432** course.

A **compiler** is a fundamental component in computer science that translates high-level programming languages into machine code. This course aims to provide hands-on experience in developing different phases of a compiler, from lexical analysis to code generation. Through these labs, students will gain insights into how modern programming languages are processed, analyzed, and executed by computers.

This repository is designed to help students understand and implement key concepts of compiler design. Each lab focuses on different stages of compiler construction, including **lexical analysis, syntax analysis, semantic analysis, intermediate code generation, and optimization**.

The structure of this repository ensures that all lab materials, including **source codes, test cases, reports, and documentation**, are well-organized for ease of use.

---

## 📂 **Repository Structure**

```
📦 CompilerDesign
 ┣ 📂 lab01    # Lexical Analysis (Generate Lexems)
 ┣ 📂 lab02    # Lexical Analyzer (Categorized Lexems)
 ┣ 📂 lab04    # Arithmetic Expression Evaluator
 ┣ 📜 .gitignore
 ┣ 📜 README.md
```

Each lab directory contains:

- **Source Code** (`.c`, `.cpp` files)
- **README.md** explaining the lab objectives
- **Test Cases** (`.txt` files for input/output examples)
- **Output Screenshots** (if applicable)
- **Reports** (PDF or `.md` files containing explanations)

---

## 🏛️ **Lab Details**

### 📌 **[Lab 01 - Lexical Analysis (Generate Lexems)](lab01/)**

**📅 Conducted Date:** _13-12-2024_

**📜 Description:**  
Lexical analysis is the first phase of a compiler. In this lab, we:

- Implement a **Lexical Analyzer** that reads a C program and extracts tokens.
- Identify **keywords, operators, identifiers, constants, and special characters**.
- Use **finite automata** techniques to recognize tokens.
- Store the results in a structured format.

**🚀 Key Concepts:** Tokenization, Regular Expressions, Finite Automata.

---

### 📌 **[Lab 02 - Lexical Analyzer (Categorized Lexems)](lab02/)**

**📅 Conducted Date:** _07-01-2025_

**📜 Description:**  
In this lab, we:

- Implement of a Lexical Analyzer that categorizes elements of C++ code into different types, such as keywords, data types, operators, functions, and others.
<!-- - Implement a **Recursive Descent Parser**.
- Construct **Parse Trees** from input expressions.
- Check for **grammatical correctness** of C statements.
- Handle **expression parsing** and simple grammar validation. -->

**🚀 Key Concepts:** Tokenization, Lexems, Parse Tree, Expression Parsing.

---

### 📌 **[Lab 04 - Arithmetic Expression Evaluator](lab04/)**

**📅 Conducted Date:** _06-02-2025_

**📜 Description:**  
This lab focuses on implementing an **arithmetic expression evaluator** that follows operator precedence and supports multi-digit numbers and brackets. The code is structured into three versions:

- **Single-digit arithmetic operations** (`Code1.cpp`)
- **Brackets for precedence handling** (`Code2.cpp`)
- **Multi-digit numbers** (`Code3.cpp`)

**🚀 Key Concepts:** Operator Precedence, Queue-based Processing, Expression Parsing.

---

## ⚙️ **How to Compile and Run the Programs**

### **For C Programs**

```bash
gcc filename.c -o output
./output
```

### **For C++ Programs**

```bash
g++ filename.cpp -o output
./output
```

---

## ✨ **Additional Resources**

- 📘 [Compiler Design Book - Alfred V. Aho, Jeffrey D. Ullman](https://www.amazon.com/Compilers-Principles-Techniques-Alfred-Aho/dp/0321486811)
- 🔗 [Compiler Design Notes](#)
- 🎥 [Video Tutorials](#)
- 📄 [Lecture Slides](#)

---

## 🎯 **Contributing**

Contributions are welcome! Feel free to:

- Submit issues for bugs.
- Improve documentation.
- Add optimized solutions.

To contribute:

```bash
git clone https://github.com/yourusername/CompilerDesign.git
cd CompilerDesign
git checkout -b feature-branch
# Make your changes
git commit -m "Added new feature"
git push origin feature-branch
```

Then submit a **Pull Request (PR)**.

---

## 📜 **License**

This project is for **educational purposes only**. Please give credit when using any materials from this repository.

---

## 🎯 **Final Thoughts**

This repository serves as a comprehensive guide to the **Compiler Design (CSE-432) Sessional Course**. By working through these labs, students will:

1. Gain a deeper understanding of **compiler internals**.
2. Develop the ability to implement **various compiler phases**.
3. Improve their programming and problem-solving skills.
4. Learn about **code optimization and generation**.

💡 _Mastering compiler design is an essential step towards understanding programming languages and building efficient software tools!_ 🚀

---

### **🚀 Happy Learning and Coding!** 🎯
