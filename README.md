
# Smart Expense Tracker (C++)

An intermediate-level, object-oriented Command Line Interface (CLI) application built in C++17 to track daily expenses, filter records by category, and maintain data persistence using file streams.

## 🚀 Features
- **Data Persistence**: Automatically saves and loads your entries from a local flat-file database (`expenses.txt`).
- **Input Validation**: Hardened against unexpected menu inputs, text types, and negative financial amounts.
- **Smart Analytics**: Filter history by specific categories instantly and view comprehensive runtime statistics.
- **Formatted Layout**: Clean, structured tabular console display leveraging C++ standard library manipulators.

## 🏗️ Architecture Design
The project is built around clean Object-Oriented Programming (OOP) and structural principles:
- **`Expense.h`**: A lightweight Data Structure (`struct`) acting as the primary model.
- **`Tracker.h / .cpp`**: The Core Engine handling Business Logic, custom filtering algorithms, and sequential File I/O.
- **`main.cpp`**: The Controller Layer executing an optimized event loop for handling console actions.

