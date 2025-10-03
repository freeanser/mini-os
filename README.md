# Operational Simulation of a Mini Operating System (C++ OOP Demo)

A **C++17** project demonstrating a "mini operating system" concept using **Object-Oriented Programming (OOP)**.  
This project simulates two classic OS modules — *Process Management* and *File System* — by implementing **process scheduling** and **basic file operations** (create/read/delete/rename/move/list).

---

## Structure

```
mini-os/
├── main.cpp         # Entry point: demo of process scheduling + file operations
├── Process.h        # Declaration of Process class (name, priority, sort/print methods)
├── Process.cpp      # Implementation of Process class
├── FileSystem.h     # Declaration of FileSystem class (CRUD, rename, move, list)
├── FileSystem.cpp   # Implementation of FileSystem class (using <filesystem> and std::rename)
└── Makefile         # Build script (g++ -std=c++17)
```

---

## Requirements

- g++ 9+ or any compiler supporting **C++17**
- OS: Linux / macOS / WSL

---

## Build & Run

```bash
make          # build the mini_os executable
./mini_os     # run demo
make clean    # remove executable
```

---

## Features

### 1. Process Management
- **Sorting**: sort by *priority* (ascending order)
- **Printing**: print processes in scheduling order
- Interfaces: `Process::sortProcesses`, `Process::printProcesses`

### 2. File System
- **Create**: `createFile(name, content)`
- **Read**: `readFile(name)` (read one line for demo)
- **Delete**: `deleteFile(name)`
- **Rename**: `renameFile(oldName, newName)`
- **List**: `listDirectory(path)` (display absolute path + file list)
- **Move**: `moveFile(src, dst)` (uses `create_directories` then `std::rename`)

> **Why Move/Rename uses `std::rename`?**  
> On the same filesystem, **rename/move simply updates the directory entry pointing to an inode** —  
> it does not actually move the physical data blocks. That’s why it’s very fast and almost atomic.
