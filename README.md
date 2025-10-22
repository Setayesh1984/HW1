# 🎓 HW1 - Score Thief (C++ Project)

This project simulates a secure student record management system using dynamic memory (pointers) in C++.
It allows adding, deleting, searching, updating, and displaying student records safely with full input validation.


## 🧩 Features

- ➕ **Add new student file** with name, ID, GPA, units, and security code  
- ❌ **Delete a student record** by ID  
- 🔍 **Search for a student** using their ID  
- ✏️ **Update GPA and number of units**  
- 📋 **Display all student files neatly**  
- 🧠 **Validation:** prevents duplicate IDs or security codes  
- 💾 **Dynamic memory management:** all nodes are properly freed at program exit  


## 🧱 Project Structure

├── include/
│   └── student.hpp       → Header file (structs and function declarations)
├── src/
│   ├── main.cpp          → Main program (menu and logic)
│   └── student.cpp       → Function implementations
├── CMakeLists.txt        → CMake configuration file
└── README.md             → Project documentation


## 🧮 Concepts Covered


Structs and pointers

Dynamic memory management (new / delete)

Input validation using cin.fail() and numeric_limits

Modular code design with header/source separation


## 👤 Author

Setayesh Asgari
Course: Object-Oriented Programming (OOP)
Instructor: Abdoli


[repository link](https://github.com/Setayesh1984/HW1.git)