# SpreadSheet

## Student Records Management System

This project is a **Student Records Management System** implemented in C. It allows users to manage a collection of student records, perform various operations such as sorting, data manipulation, and calculations. The program uses dynamic memory allocation and modular design with separate files for different functionalities.

## Features

### 1. **Spreadsheet Management (`spreadsheet.c`)**
   - Initializes a dynamic array of student records (`struct Students`).
   - Handles memory allocation for storing student data.
   - Provides a menu-driven interface for interacting with the system.
   - Includes error handling for memory allocation failures.

### 2. **Sorting Functions (`ordering.c`)**
   - Provides functionality to sort student records based on various criteria (e.g., name, ID, grades).
   - Implements sorting algorithms to organize data efficiently.

### 3. **Data Manipulation (`data.c`)**
   - Allows adding, deleting, and updating student records.
   - Handles mapping of student data fields for easier access and manipulation.
   - Provides utility functions for managing the student dataset.

### 4. **Calculations (`calc.c`)**
   - Performs calculations on student data, such as:
     - Average grades.
     - Total scores.
     - Statistical analysis of student performance.
   - Supports custom calculations based on user-defined criteria.

## How to Run

1. **Compile the Code**:
   Use the following command to compile the program:
   ```bash
   gcc -o SpreadSheet spreadsheet.c ordering.c data.c calc.c
