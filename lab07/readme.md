# Predictive Parser Implementation in C++

## Overview

This project implements a **Predictive Parsing Table-based LL(1) Parser** in C++. The parser is designed to handle a given grammar and parse input strings accordingly using a stack-based approach.

## Features

- Implements **LL(1) parsing** using a **predictive parsing table**.
- Uses a **stack-based approach** to parse the input.
- Provides **detailed output of the parsing process**.
- Handles **matching terminals**, **expanding non-terminals**, and **handling errors**.
- Supports **ε-productions** (empty productions).

## Grammar Used

The following **context-free grammar (CFG)** is used:

```plaintext
E  -> T e
e  -> + T e | ε
T  -> F t
t  -> * F t | ε
F  -> id | ( E )
```

Where:

- `E` is the start symbol.
- `e` represents `E'`.
- `t` represents `T'`.
- `id` represents an identifier.
- `ε` (epsilon) represents an empty production.

## Predictive Parsing Table

The parsing table used in this program is:
![Parsing Table](/lab07/image/image.png)

## Expected Output

![Expected Ouput](/lab07/image/ouput_format.png)

**Nota Bene:**```Demonstrator asked to show only matched, stack and input column in ouput.```

## Explanation of Code

### 1. **Parsing Table Construction**

```cpp
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
```

This `map` stores the parsing table, mapping each non-terminal and terminal pair to its respective production rule.

### 2. **Checking Terminal Symbols**

```cpp
bool isTerminal(char c) {
    return !isupper(c) && c != 'e' && c != 't';
}
```

This function checks if a character is a terminal (not a non-terminal like `E`, `T`, `F`, `e`, `t`).

### 3. **Stack-based Parsing Algorithm**

```cpp
stack<char> parsingStack;
parsingStack.push('$');
parsingStack.push('E');
```

The parsing stack is initialized with the end marker `$` and the start symbol `E`.

### 4. **Handling Empty (ε) Productions**

```cpp
if (production != "ε") {
    for (int i = production.length() - 1; i >= 0; i--) {
        if (production[i] != ' ') {
            parsingStack.push(production[i]);
        }
    }
}
```

If a production rule is `ε`, the non-terminal is removed from the stack without pushing new symbols.

### 5. **Error Handling**

```cpp
else {
    cout << "No production Rule. REJECT!" << endl;
    return;
}
```

If no rule is found in the parsing table, the input is rejected with an error message.

## Example Input & Output

#### Input:

```plaintext
i+i*i
```

#### Output:

```plaintext
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
```

## Error Handling

- If the stack contains a non-terminal but no rule is found for the current input symbol, an **error is displayed**.
- If unexpected symbols appear in the input, an **error message is shown**.

## Author

- **TOFAYEL AHMMED BABU**

## License

This project is open-source and available under the MIT License.

## Conclusion

This project demonstrates how an **LL(1) predictive parser** can be implemented in C++ using a **parsing table and stack-based approach**. The parser successfully recognizes **arithmetic expressions with + and \*** operations, handling parentheses and identifiers efficiently.
