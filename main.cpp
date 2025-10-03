#include <iostream>
#include "Process.h"
#include "FileSystem.h"

int main() {
    std::cout << "Hello, OOP mini-OS is running!" << std::endl;

    // Process scheduling demo
    std::vector<Process> ps = {
        {"Process A", 2},
        {"Process B", 1},
        {"Process C", 3}
    };
    Process::sortProcesses(ps);
    Process::printProcesses(ps);

    // File system demo
    FileSystem fs;
    fs.createFile("demo.txt", "Hello from OS!");
    fs.readFile("demo.txt");

    // fs.deleteFile("demo.txt");

    fs.renameFile("demo.txt", "renamed.txt");
    fs.listDirectory(".");
    fs.moveFile("renamed.txt", "out/renamed.txt");

    

    return 0;
}
