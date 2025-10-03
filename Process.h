#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>

// using namespace std;

// struct → public
// class → private
class Process {
public:
    // Constructor
    Process(const std::string& n, int p);

    // Getters
    std::string getName() const;
    int getPriority() const;

    // Static methods for managing processes
    static void sortProcesses(std::vector<Process>& processes);
    static void printProcesses(const std::vector<Process>& processes);

private:
    std::string name;
    int priority;
};

#endif
