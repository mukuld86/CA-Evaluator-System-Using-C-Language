# CA Evaluator System

The **CA Evaluator System** is a simple console-based program written in C that helps manage continuous assessment (CA) records of students. It allows the user to create, search, modify, delete, and display student records. Each student record includes the student's name, ID, course name, and CA score.

## 🛠 Features

- 📥 Create new student records
- 🔍 Search for existing records by student ID
- ✏️ Modify a student’s CA score
- ❌ Delete a student record
- 📋 Display all records in a tabular format

## 🧾 Record Format

Each record is saved in a file named `ca_records.txt` in the following format:


## 📂 Files

- `ca_records.txt`: Stores all student records
- `temp.txt`: Used as a temporary file for update and delete operations

## 💻 How to Run

1. **Compile the code** using any C compiler like GCC:
   ```bash
   gcc ca_evaluator.c -o ca_evaluator
