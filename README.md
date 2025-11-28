---

# 🎓 Student Result Management System (C++)

A simple **console-based Student Result Management System** built using C++.
This project helps manage students, courses, marks, grades, and GPA calculations using structured programming concepts such as **structs, sorting, searching, and modular functions**.

---

## 📌 Features

### ✅ **Course Management**

* Add courses based on **Year + Semester**
* Prevents adding duplicate courses
* Stores course name, credit, semester & year

### ✅ **Student Management**

* Add student with:

  * ID
  * Name
  * Year
  * Semester
  * Marks for each course of that semester
* Prevents duplicate student IDs
* Automatically sorts students by ID using **Quick Sort**

### ✅ **Search System**

* Search student result using:

  * Student ID
  * Year
  * Semester
* Uses **Binary Search** for fast lookup

### ✅ **Edit Student Details**

* Edit name, year, semester
* Update marks
* Add courses to a particular student
* Delete specific courses
* Updates and re-sorts automatically

### ✅ **GPA & Grade Calculation**

* Grade mapping:

  * A+ → 4.00
  * A → 3.75
  * A- → 3.50
  * ... down to F → 0.00
* Calculates GPA based on:

  ```
  GPA = Total Grade Points / Total Credits
  ```

---

## 🛠️ Technologies Used

* **C++ Standard Library**
* Structs
* Functions
* Vectors
* Quick Sort
* Binary Search

---

## 🧩 System Flowchart

```
               ┌─────────────────────┐
               │     User Input      │
               └──────────┬──────────┘
                          │
             ┌────────────▼────────────┐
             │     Main Menu System     │
             └───┬───────────┬─────────┘
                 │           │
       ┌─────────▼───┐   ┌──▼──────────┐
       │ Add Courses │   │ Add Student │
       └────────────┘   └──────────────┘
                 │           │
       ┌─────────▼──────────▼───────────┐
       │   Search / Edit Student Data     │
       └──────────────────────────────────┘
```

---

## 🧾 Menu Options

```
1. Add Courses for Semester + Year
2. Add Student
3. Search Result by ID + Year + Semester
4. Edit Student Details
0. Exit
```

---

## 🚀 How to Run

### **Compile**

```bash
g++ main.cpp -o student_system
```

### **Run**

```bash
./student_system
```

Works on:

* Linux
* macOS
* Windows (using MinGW / Dev-C++ / CodeBlocks)

---

## 📂 Project Structure

```
├── main.cpp
├── README.md
```

---

## 📘 Example Output

```
===== STUDENT RESULT =====
ID       : 221-15-1234
Name     : Arpa Bhowmick
Year     : 2
Semester : Spring

--- Marks & Grades ---
CSE231 : 85 (A+, 4.00), Credit: 3
MAT221 : 78 (A, 3.75), Credit: 3
PHY211 : 67 (B+, 3.25), Credit: 3

Final GPA : 3.66
```

---

## 🎯 Learning Objectives

This project helps practice:

* Data structures in C++
* Sorting (Quick Sort)
* Searching (Binary Search)
* Struct-based data modeling
* Input handling
* GPA calculation logic
* CRUD operations in console applications

---

## 📌 Future Improvements

* Save & load data from files
* GUI version using Qt
* Use OOP (Classes instead of Structs)
* Add authentication system

---

## 🤝 Contributing

Pull requests and suggestions are welcome!

---

## 📄 License

This project is open-source and free to use.

---
