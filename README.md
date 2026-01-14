# 📱 ContactFlow (C++)

A robust terminal-based Phonebook Management System built with C++. This project demonstrates core data structures and algorithm concepts.

## 🚀 Key Features
- **Persistent Storage:** Data is saved in `phonebook.csv` and loaded automatically.
- **Binary Search:** High-performance contact lookup ($O(\log N)$).
- **Selection Sort:** Keeps the contact list alphabetically organized.
- **Case-Insensitive:** Search works seamlessly regardless of capitalization.
- **Buffer Management:** Clean input handling using `cin.ignore()`.

## 🛠️ Technical Implementation
- **Structs:** For grouping name and phone number data.
- **File I/O:** Using `fstream` for disk read/write operations.
- **String Manipulation:** Case conversion for better UX.

## 📖 How to Run
1. Compile using `g++ contact.cpp -o contact`
2. Run `./contact`
