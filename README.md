# Employee Management System

This project is a console-based Employee Management System built in C++. It provides a simple, intuitive interface for managing employee data, including adding, editing, removing, and displaying employee details.

## Features

- **User Authentication**: Secure user registration and login system.
- **Employee CRUD Operations**: Easily add, edit, remove, and view employee details.
- **Persistent Data Storage**: Employee data is saved and managed using file operations.
- **Work Hours Tracking**: Automatically generates or tracks work hours for each employee per month.
- **Interactive Console UI**: Clear and user-friendly console interactions with centered text and formatted outputs.

## Technology Stack

- **Language**: C++
- **Standard Libraries**: `<iostream>`, `<fstream>`, `<iomanip>`, `<map>`, `<string>`, `<vector>`, `<ctime>`, `<cstdlib>`, `<conio.h>`
- **Development Environment**: Compatible with Windows (due to usage of Windows-specific headers like `<windows.h>`)

## Setup Instructions

### Requirements
- C++ compiler (e.g., MinGW, Visual Studio)

### Compilation
1. Compile the program:
```bash
g++ main.cpp -o EmployeeManagementSystem
```
2. Run the executable:
```bash
./EmployeeManagementSystem
```

## Usage

Upon running, you'll be prompted to register or log in:

- **Register**: Set up a new account.
- **Login**: Use existing credentials to manage employees.

### Employee Operations

- **Add Employee**: Enter employee details like ID, name, designation, and more.
- **Remove Employee**: Delete employee records using their ID.
- **Display Employee Details**: Retrieve detailed information about an individual employee.
- **Display Employee List**: Show a formatted list of all employees.
- **Edit Employee Details**: Update existing employee information.
- **Hours Worked**: View or generate work hours for the previous month.

