#include <iostream>
#include <vector>
#include <exception>
#include "Process.h"
#include "FileSystem.h"

using namespace std;

int main()
{
    try
    {
        cout << "Hello, OOP mini-OS is running!" << endl;

        // Process scheduling demo
        vector<Process> ps = {
            {"Process A", 2},
            {"Process B", 1},
            {"Process C", 3}};

        // catch exceptions from static methods as well
        Process::sortProcesses(ps);
        Process::printProcesses(ps);

        // File system demo
        FileSystem fs;

        // catch exceptions from file operations as well
        fs.createFile("demo.txt", "Hello from OS!");
        fs.readFile("demo.txt");
        fs.deleteFile("demo.txt");

        fs.createFile("demo.txt", "Hello from OS!");
        fs.renameFile("demo.txt", "renamed.txt");

        // test listing current directory
        fs.listDirectory(".");

        // test moving file
        fs.moveFile("renamed.txt", "newdir/renamed.txt");
    }
    catch (const exception &e)
    {
        cerr << "CRITICAL ERROR: Uncaught exception in main: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        cerr << "CRITICAL ERROR: Unknown exception occurred in main.\n";
        return 1;
    }

    return 0;
}