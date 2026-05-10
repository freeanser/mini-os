#include "FileSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <exception>

using namespace std;

namespace fs = filesystem;

void FileSystem::createFile(const string &fileName, const string &content)
{
    try
    {
        ofstream newFile(fileName);
        // newFile.exceptions(ofstream::failbit | ofstream::badbit);

        if (!newFile)
        {
            cerr << "Cannot create file (Stream error): " << fileName << "\n";
            return;
        }
        newFile << content << "\n";
        cout << "Created file: " << fileName << "\n";
    }
    catch (const exception &e)
    {
        cerr << "Exception in createFile: " << e.what() << "\n";
    }
}

void FileSystem::readFile(const string &fileName)
{
    try
    {
        ifstream in(fileName);
        if (!in)
        {
            cerr << "Cannot read file (File may not exist): " << fileName << "\n";
            return;
        }
        string line;
        if (getline(in, line))
        {
            cout << "File content: " << line << "\n";
        }
        else
        {
            cerr << "File is empty or could not read line: " << fileName << "\n";
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception in readFile: " << e.what() << "\n";
    }
}

void FileSystem::deleteFile(const string &fileName)
{
    // Using remove from <cstdio> for file deletion
    try
    {
        int result = remove(fileName.c_str());
        if (result == 0)
        {
            cout << "Deleted file: " << fileName << "\n";
        }
        else
        {
            perror("Delete failed");
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception in deleteFile: " << e.what() << "\n";
    }
}

void FileSystem::renameFile(const string &oldName, const string &newName)
{
    try
    {
        int result = rename(oldName.c_str(), newName.c_str());
        if (result == 0)
        {
            cout << "Renamed: " << oldName << " -> " << newName << "\n";
        }
        else
        {
            perror("Rename failed");
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception in renameFile: " << e.what() << "\n";
    }
}

void FileSystem::listDirectory(const string &path)
{
    try
    {
        cout << "Directory listing for: " << fs::absolute(path) << "\n";

        // fs::directory_iterator may throw fs::filesystem_error
        for (const auto &entry : fs::directory_iterator(path))
        {
            cout << "  " << entry.path().filename().string() << "\n";
        }
    }
    catch (const fs::filesystem_error &e)
    {
        cerr << "Filesystem Error in listDirectory: " << e.what() << "\n";
        cerr << "  Code: " << e.code().message() << "\n";
    }
    catch (const exception &e)
    {
        cerr << "General Exception in listDirectory: " << e.what() << "\n";
    }
}

void FileSystem::moveFile(const string &src, const string &dst)
{
    try
    {
        // create_directories catch the case where the destination directory does not exist
        fs::create_directories(fs::path(dst).parent_path());

        // When you call `rename`:
        // * The file’s data blocks on disk don’t move.
        // * The system only updates the pointer (directory entry → inode) from the old path to the new one.
        if (rename(src.c_str(), dst.c_str()) == 0)
        {
            cout << "Moved: " << src << " -> " << dst << "\n";
        }
        else
        {
            perror("Move failed");
        }
    }
    catch (const fs::filesystem_error &e)
    {
        cerr << "Filesystem Error in moveFile: " << e.what() << "\n";
    }
    catch (const exception &e)
    {
        cerr << "Exception in moveFile: " << e.what() << "\n";
    }
    catch (...)
    {
        cerr << "Unknown error moving file\n";
    }
}