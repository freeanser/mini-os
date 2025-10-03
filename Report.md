## Why Operating Systems Need Process Scheduling

An operating system needs scheduling because many processes want to use the CPU at the same time, but the CPU can only run one process at a given moment. Scheduling decides the order of execution, so the system stays efficient and fair.

---

## How the Code Works

In my code, I designed a simple **priority scheduling** rule:

- Each process has a number called *priority*.  
- A lower number means higher priority.  
- The `sortProcesses` function sorts all processes by this number.  
- The `printProcesses` function then shows the order in which processes will run.

---

### Lines of Code
Current version (approximate, excluding blank lines):  
- `main.cpp` — 31 lines  
- `Process.h` — 29 lines  
- `Process.cpp` — 30 lines  
- `FileSystem.h` — 16 lines  
- `FileSystem.cpp` — 72 lines  
- `Makefile` — 16 lines  

**Total: 194 lines** (use `wc -l` for exact count if required).



## Conclusion

My code demonstrates how an OS can set rules (here, priority) to decide **which process runs first**.