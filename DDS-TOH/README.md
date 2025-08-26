# Tower of Hanoi Visualizer (C++)

## 📌 Overview

A minimal, command-line visualizer for the classic Tower of Hanoi puzzle, written in C++.  
It recursively solves the problem and visually displays each move using ASCII art for intuitive understanding.

---

## 🛠 Features

- Solves Tower of Hanoi with recursion  
- Visualizes rods (`|`) and disks as centered `*` bars  
- Shows each move step-by-step in the terminal  
- User selects the number of disks (up to 20 by default)  
- Only uses standard C++ with `iostream`—no STL required  

---

## 📂 Data Structures Used

- **Static 2D array:** Represents rods and the disks present on them  
- **Recursion:** For move logic  
- **Simple counters:** To manage and track disk stacks on rods  

---

## 🚀 Running Locally

This repository contains the source code for my Data Structures project submission: a command-line Tower of Hanoi visualizer in C++.

**To run locally:**

1. **Download or clone the repository:**
    ```
    git clone https://github.com/your-username/tower-of-hanoi-visualizer.git
    cd tower-of-hanoi-visualizer
    ```

2. **Compile the C++ program:**
    ```
    g++ hanoi.cpp -o hanoi
    ```

3. **Run the executable:**
    ```
    ./hanoi
    ```

> _This project is submitted as part of my Design of Data Structures in C++._

---

