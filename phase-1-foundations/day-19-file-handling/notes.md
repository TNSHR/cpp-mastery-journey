# Day 19 - File Handling in C++

---

# Objective

Learn how to permanently store data using files.

---

# Why File Handling?

Variables exist only in RAM.

Example

int marks = 95;

When the program ends

↓

RAM is cleared

↓

Data is lost.

File Handling stores data permanently on disk.

---

# File Stream Classes

1. ifstream

Used to read files.

Example

std::ifstream file("students.txt");

---

2. ofstream

Used to write files.

Example

std::ofstream file("students.txt");

---

3. fstream

Can read and write.

Example

std::fstream file("students.txt");

---

# File Modes

ios::out

Write Mode

Existing file contents are overwritten.

---

ios::app

Append Mode

Adds data at the end of the file.

---

ios::in

Read Mode

Reads existing file contents.

---

# Important Functions

file.is_open()

Checks whether a file opened successfully.

---

file.close()

Closes the file.

Always close files after use.

---

# Project Architecture

main.cpp

↓

Student

↓

FileManager

↓

students.txt

---

# Student Class

Stores

- ID
- Name
- Marks

---

# FileManager Class

Responsible for

- Saving Students
- Reading Students
- Appending Students

---

# Reading File

std::ifstream

↓

Read Line

↓

Create Student

↓

Store in Vector

---

# Writing File

Vector

↓

ofstream

↓

students.txt

---

# Appending

Existing File

↓

ios::app

↓

New Record Added

---

# Benefits

✔ Permanent Storage

✔ Easy Data Sharing

✔ Backup

✔ Real-world Applications

---

# Real-world Examples

Banking

Hospital

School Management

Inventory System

Payroll

Library Management

Attendance System

---

# Best Practices

✔ Check is_open()

✔ Close every file

✔ Use classes

✔ Keep file operations separate

✔ Validate data

✔ Handle errors

---

# Common Mistakes

❌ Forgetting close()

❌ Using wrong file mode

❌ Ignoring open failure

❌ Mixing business logic with file logic

❌ Writing everything in main()

---

# Interview Questions

1. Difference between ifstream and ofstream?

2. What is ios::app?

3. What does is_open() do?

4. Why use FileManager?

5. Why separate .h and .cpp?

6. Difference between text and binary files?

7. Why use vector while reading?

---

# Summary

Today we learned

✔ File Streams

✔ Reading Files

✔ Writing Files

✔ Appending Files

✔ File Modes

✔ FileManager Design

✔ Professional Project Structure