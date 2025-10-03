#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <filesystem>  
#include <cstdio>
#include "Process.h"
using namespace std;

int main() {
    cout << "Hello, mini-OS project is running!\n";
    
    // Demo: Process Scheduling
    vector<Process> ps = {
        {"Process A", 2},
        {"Process B", 1},
        {"Process C", 3}
    };
    // Process:: means “this function belongs to the Process class.”
    Process::sortProcesses(ps);
    Process::printProcesses(ps);

    return 0;
}
