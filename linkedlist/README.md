<div align="center">

# 🔗 Linked List Implementations in C++

### *A collection of manually implemented linked list data structures and algorithms in C++*

<p>

<img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=cplusplus"/>
<img src="https://img.shields.io/badge/Data%20Structures-Linked%20Lists-success?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge"/>
<img src="https://img.shields.io/badge/STL-Not%20Used-red?style=for-the-badge"/>

</p>

---

### 📚 Explore the Implementations

| 🔗 Implementation | 📖 Description |
|:-----------------:|:--------------|
| [📌 Singly Linked List](#-singly-linked-list) | Standard linked list with sorting, searching and recursive operations |
| [🔄 Circular Linked List](#-circular-linked-list) | Last node points back to the head |
| [↔️ Doubly Linked List](#️-doubly-linked-list) | Bidirectional linked list supporting forward & backward traversal |
| [🌐 Multi Linked List](#-multi-linked-list-course--student-management-system) | Course & Student Enrollment Management System |

---

</div>

# 🚀 Project Overview

This directory contains multiple implementations of linked lists built completely from scratch using **C++**.

The objective of these implementations is to understand how linked lists work internally by manually manipulating pointers without using the Standard Template Library (STL).

---

# 📊 Project Statistics

| Item | Count |
|------|------:|
| 📂 Programs | **4** |
| 🧩 Data Structures | **4** |
| ⚙️ Operations Implemented | **30+** |
| 💻 Language | **C++** |
| 📦 STL Containers | **None** |

---

# 📌 Singly Linked List

<details>
<summary><b>Click to view implementation details</b></summary>

## Features

- ✅ Recursive Insertion
- ✅ Iterative Insertion
- ✅ Sorted Insertion
- ✅ Unique Insertion
- ✅ Search
- ✅ Delete
- ✅ Reverse
- ✅ Bubble Sort
- ✅ Selection Sort
- ✅ Recursive Display
- ✅ Insert at Specific Position

---

### Concepts Covered

✔ Dynamic Memory Allocation

✔ Pointer Manipulation

✔ Node Traversal

✔ Recursive Functions

✔ Sorting on Linked Lists

✔ Position Based Insertion

---

### Core Operations

```cpp
insert()
search()
delete()
reverse()
bubbleSort()
selectionSort()
recursiveDisplay()
```

</details>

---

# 🔄 Circular Linked List

<details>
<summary><b>Click to view implementation details</b></summary>

## Features

- ✅ Circular Node Linking
- ✅ Insert
- ✅ Search
- ✅ Delete
- ✅ Circular Traversal

---

### Concepts Covered

✔ Last node pointing to Head

✔ Circular Traversal

✔ Head Deletion

✔ Single Node Case

✔ Pointer Updating

---

### Core Operations

```cpp
insert()
search()
delete()
display()
```

</details>

---

# ↔️ Doubly Linked List

<details>
<summary><b>Click to view implementation details</b></summary>

## Features

- ✅ Forward Traversal
- ✅ Backward Traversal
- ✅ Search
- ✅ Delete
- ✅ Reverse
- ✅ Find Minimum
- ✅ Find Maximum
- ✅ Quick Sort

---

### Concepts Covered

✔ Previous Pointer

✔ Bidirectional Traversal

✔ Tail Pointer

✔ Quick Sort on Linked List

✔ Reverse Traversal

---

### Core Operations

```cpp
insert()
search()
delete()
reverse()
quickSort()
findMin()
findMax()
```

</details>

---

# 🌐 Multi Linked List (Course & Student Management System)

<details open>
<summary><b>Click to view complete implementation</b></summary>

## 📖 Description

This project implements a **Multi Linked List** to simulate a **Course Enrollment Management System**.

Each **Course Node** maintains a pointer to another linked list containing the students enrolled in that course.

Instead of storing everything in a single list, the program creates a **Linked List of Linked Lists**, making it a practical example of a multi-linked structure.

---

## 🏗 Structure

```
Course List

CS101 ─────────────► CS102 ─────────────► CS103
  │                    │                    │
  ▼                    ▼                    ▼
S1 → S2 → S3        S4 → S5          S6 → S7 → S8
```

---

## Node Design

### Course Node

```cpp
struct C_node
{
    string course_no;
    C_node* next;
    S_node* student_list;
};
```

### Student Node

```cpp
struct S_node
{
    string seat_no;
    S_node* next;
};
```

---

## Implemented Operations

### 📘 Course Management

- ✅ Add Course
- ✅ Delete Course
- ✅ Search Course
- ✅ Display Courses

---

### 👨‍🎓 Student Management

- ✅ Enroll Student
- ✅ Remove Student from One Course
- ✅ Remove Student from Every Course
- ✅ Search Student in Specific Course
- ✅ Search Student Across All Courses
- ✅ Display Students of a Course

---

### 📊 Display Functions

- ✅ Display Every Course
- ✅ Display Students of Selected Course
- ✅ Display Complete Enrollment Record

---

## Highlights

✔ Duplicate Course Detection

✔ Duplicate Student Detection

✔ Dynamic Student Lists

✔ Automatic Memory Cleanup

✔ Nested Linked Lists

✔ Practical University Enrollment Simulation

---

### Example

```
CS101 :
23K-1234
23K-1001
23K-1111

CS102 :
23K-1015
23K-1077
```

Each course owns its own linked list of enrolled students.

</details>

---

# 📚 Skills Demonstrated

- Dynamic Memory Allocation
- Linked List Traversal
- Nested Linked Lists
- Pointer Manipulation
- Recursive Programming
- Sorting Algorithms
- Searching Algorithms
- Memory Management
- Data Organization

---

# ⭐ Repository Highlights

- 💯 Built completely from scratch
- 🚫 No STL containers used
- 📖 Menu-driven implementations
- 🧠 Educational and beginner-friendly
- ⚡ Focused on understanding pointers and memory management

---

<div align="center">

### ⭐ If you found these implementations helpful, consider starring the repository!

**Happy Coding! 🚀**

</div>
