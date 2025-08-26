# Expression Calculator (C++)

## 📌 Overview

A minimalist stack-based expression calculator in C++ that converts and evaluates math expressions.  
Handles operator precedence and parentheses by implementing infix-to-postfix conversion and postfix evaluation with array-based stack logic (no STL, only `iostream`).

---

## 🛠 Features

- Converts infix expressions to postfix using a stack (array-based)
- Evaluates postfix expressions using a stack (array-based)
- Handles standard arithmetic operators: `+`, `-`, `*`, `/`, `^`
- Fully respects parentheses and operator precedence
- Command-line input and output
- Only uses standard C++ (`iostream`); no extra headers or STL

---

## 📂 Data Structures Used

- **Arrays:** Used to simulate stack operations for both conversion and evaluation
- **Custom stack logic:** Manual implementation for stack push/pop
- **Simple character arrays:** To store infix, postfix, and operator stacks

---

## 🚀 Running Locally

This repository contains the source code for my Data Structures project submission: an array-based Expression Calculator in C++.

**To run locally:**

1. **Download or clone the repository:**
    ```
    git clone https://github.com/your-username/expression-calculator.git
    cd expression-calculator
    ```

2. **Compile the C++ program:**
    ```
    g++ calculator.cpp -o calculator
    ```

3. **Run the executable:**
    ```
    ./calculator
    ```

> _This project is submitted as part of my Design of Data Structures in C++._

