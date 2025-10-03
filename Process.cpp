#include "Process.h"
#include <iostream>
#include <algorithm>
// using namespace std;

Process::Process(const std::string& n, int p) : name(n), priority(p) {}

std::string Process::getName() const { return name; }
int Process::getPriority() const { return priority; }

// Process:: means “this function belongs to the Process class.”
// In Process.h, you must first declare it, for example:
//      static void sortProcesses(std::vector<Process>& processes);
// The call must be prefixed with the class name:
//      Process::sortProcesses(ps);

void Process::sortProcesses(std::vector<Process>& processes) {
    std::sort(processes.begin(), processes.end(),
              [](const Process& a, const Process& b) {
                  return a.getPriority() < b.getPriority();
              });
}

void Process::printProcesses(const std::vector<Process>& processes) {
    std::cout << "Process Scheduling:\n";
    for (const auto& p : processes) {
        std::cout << "  Running " << p.getName()
                  << " (Priority " << p.getPriority() << ")\n";
    }
}
