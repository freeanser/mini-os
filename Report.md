# Operational Simulation of a Simple Operating System

## Objective
This C++ project simulates fundamental aspects of an operating system by emulating process scheduling and basic file system operations. The purpose of this report is to explain the objective, implemented functions, code composition, and overall significance of the program.

## Purpose
The goal is to show how operating systems handle two key areas:
- **Process Management**: scheduling tasks based on priority.
- **File Management**: creating, reading, deleting, renaming, moving, and listing files.

## Why Operating Systems Need Process Scheduling
An operating system needs scheduling because many processes want to use the CPU at the same time, but the CPU can only run one process at a given moment. Scheduling decides the order of execution, so the system stays efficient and fair.

## Functions

1. **Process Management**
   - **Class Process**: Represents a process with a name and priority.
   - **sortProcesses()**: Sorts processes by priority, simulating task scheduling.
   - **printProcesses()**: Prints scheduled processes in execution order.

2. **File Management**
   - **createFile()**: Creates a new file and writes content into it.
   - **readFile()**: Reads and prints content from a file.
   - **deleteFile()**: Deletes a specified file.
   - **renameFile()**: Renames an existing file, mimicking OS file organization.
   - **listDirectory()**: Lists files in a given directory, simulating directory listing.
   - **moveFile()**: Moves a file from one location to another, implemented with `std::rename`.

3. **System Calls and Abstraction**
   - The `main.cpp` program acts as the entry point, demonstrating calls to process scheduling and file system functions.  
   - These calls illustrate how system calls provide a high-level abstraction for interacting with OS resources.

## Code Composition

The project follows an **Object-Oriented Programming (OOP)** structure and is written in about **200 lines of code**, organized as:

- `main.cpp`: Program entry, demonstrates features.  
- `Process.h / Process.cpp`: Defines and implements process management functions.  
- `FileSystem.h / FileSystem.cpp`: Defines and implements file operations using `<filesystem>`.  
- `Makefile`: Automates compilation and execution with g++.
The code is compiled with **C++17** and requires only a standard compiler (e.g., g++).

## Lines of Code
Current version (approximate, excluding blank lines):  
- `main.cpp` — 30 lines  
- `Process.h` — 29 lines  
- `Process.cpp` — 30 lines  
- `FileSystem.h` — 16 lines  
- `FileSystem.cpp` — 72 lines  
- `Makefile` — 16 lines  
**Total: 193 lines** 

## Conclusion
This project provides a simplified but effective simulation of basic operating system concepts. By scheduling processes and performing file operations, the program highlights how an OS coordinates tasks and manages storage. While not a real OS, it offers valuable educational insights into the abstractions and functionality of actual systems. The modular design, process encapsulation, and file system APIs reflect how operating systems manage complexity while exposing a simple interface to users.