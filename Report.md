# Operational Simulation of a Simple Operating System

## Objective
This C++17 project simulates fundamental aspects of an operating system by emulating **Process Management** (Priority Scheduling) and **File System Management**. The project utilizes Object-Oriented Programming (OOP) principles and `std::filesystem` to demonstrate how an OS coordinates tasks and manages storage resources safely.

## Purpose of the Operating System
The primary purpose of this simulation is to demonstrate:
1.  **Resource Abstraction**: Hiding complex hardware operations (like disk I/O) behind simple APIs.
2.  **Task Scheduling**: Managing CPU execution order based on process priority to ensure critical tasks run first.
3.  **System Stability**: Implementing robust error handling (`try-catch` blocks) to ensure the system remains operational even when runtime errors occur (e.g., missing files or permission issues).

## Implemented Functions

### 1. Process Management (Module: `Process`)
Simulates a CPU scheduler that decides execution order based on priority.
-   **Structure**: A `Process` class encapsulates a process's `name` and `priority`.
-   **Scheduling Algorithm**: 
    -   `Process::sortProcesses()`: Implements a priority-based sorting algorithm (Ascending order: Lower numeric value = Higher priority logic, or simply sorted by priority level).
-   **Execution Tracking**:
    -   `Process::printProcesses()`: Displays the queue of processes in the order they will be executed.

### 2. File System Management (Module: `FileSystem`)
Simulates disk operations using the modern C++17 `<filesystem>` library. All operations are wrapped in **error handling blocks** to prevent system crashes.
-   **File Creation**: `createFile()` establishes new file streams and writes initial content.
-   **File Reading**: `readFile()` opens input streams to retrieve data, verifying file existence.
-   **File Deletion**: `deleteFile()` interfaces with `std::remove` to delete files.
-   **File Renaming**: `renameFile()` changes file identifiers using `std::rename`.
-   **Directory Listing**: `listDirectory()` utilizes `directory_iterator` to enumerate files in a path.
-   **File Moving**: `moveFile()` combines directory creation (`create_directories`) and renaming logic to simulate moving files across paths.

### 3. Error Handling & Robustness (New Feature)
-   **Exception Safety**: Critical I/O operations in `FileSystem.cpp` and the main execution loop in `main.cpp` are protected by `try-catch` blocks.
-   **Failure Recovery**: The system catches specific exceptions (e.g., `fs::filesystem_error`, `std::exception`) and prints descriptive error messages instead of terminating unexpectedly.

## Code Composition & Lines of Code (LOC)
The project is modularized into header files (`.h`) for declarations and source files (`.cpp`) for implementations. 

**Total Lines of Code: ~295 lines**

| File | Approx. Lines | Description |
| :--- | :--- | :--- |
| `main.cpp` | 52 | Entry point; global error catching & demos features. |
| `FileSystem.cpp` | 152 | Implements file operations with robust `try-catch`. |
| `Process.cpp` | 30 | Implements sorting and printing logic. |
| `Process.h` | 29 | Class definition for Process. |
| `FileSystem.h` | 16 | Class definition for FileSystem. |
| `Makefile` | 16 | Build script for compilation. |

## Conclusion
This project successfully models the "Manager" role of an operating system. By integrating priority scheduling with a robust, exception-safe file system, the simulation demonstrates how actual operating systems maintain stability and order while serving user requests.