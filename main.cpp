#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <filesystem>  
#include <cstdio>
using namespace std;
namespace fs = std::filesystem;

// ---- Process management ----
struct Process {
    string name;
    int priority;
};

// Sort processes by priority (lower value means higher priority)
void sortProcesses(vector<Process>& processes) {
    sort(processes.begin(), processes.end(),
         [](const Process& a, const Process& b) {
             return a.priority < b.priority;
         });
}

// Print the process scheduling order
void printProcesses(const vector<Process>& processes) {
    cout << "Process Scheduling:\n";
    for (const auto& p : processes) {
        cout << "  Running " << p.name << " (Priority " << p.priority << ")\n";
    }
}

int main() {
    cout << "Hello, mini-OS project is running!" << endl;
    
    // Demo: process scheduling
    vector<Process> ps = {
        {"Process A", 2},
        {"Process B", 1},
        {"Process C", 3}
    };
    sortProcesses(ps);
    printProcesses(ps);

    return 0;
}
