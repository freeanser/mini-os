#include "FileSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <exception>

namespace fs = std::filesystem;

void FileSystem::createFile(const std::string &fileName, const std::string &content)
{
    try
    {
        std::ofstream newFile(fileName);
        // newFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        if (!newFile)
        {
            std::cerr << "Cannot create file (Stream error): " << fileName << "\n";
            return;
        }
        newFile << content << "\n";
        std::cout << "Created file: " << fileName << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in createFile: " << e.what() << "\n";
    }
}

void FileSystem::readFile(const std::string &fileName)
{
    try
    {
        std::ifstream in(fileName);
        if (!in)
        {
            std::cerr << "Cannot read file (File may not exist): " << fileName << "\n";
            return;
        }
        std::string line;
        if (std::getline(in, line))
        {
            std::cout << "File content: " << line << "\n";
        }
        else
        {
            std::cerr << "File is empty or could not read line: " << fileName << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in readFile: " << e.what() << "\n";
    }
}

void FileSystem::deleteFile(const std::string &fileName)
{
    // Using std::remove from <cstdio> for file deletion
    try
    {
        int result = std::remove(fileName.c_str());
        if (result == 0)
        {
            std::cout << "Deleted file: " << fileName << "\n";
        }
        else
        {
            perror("Delete failed");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in deleteFile: " << e.what() << "\n";
    }
}

void FileSystem::renameFile(const std::string &oldName, const std::string &newName)
{
    try
    {
        int result = std::rename(oldName.c_str(), newName.c_str());
        if (result == 0)
        {
            std::cout << "Renamed: " << oldName << " -> " << newName << "\n";
        }
        else
        {
            perror("Rename failed");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in renameFile: " << e.what() << "\n";
    }
}

void FileSystem::listDirectory(const std::string &path)
{
    try
    {
        std::cout << "Directory listing for: " << fs::absolute(path) << "\n";

        // fs::directory_iterator may throw fs::filesystem_error
        for (const auto &entry : fs::directory_iterator(path))
        {
            std::cout << "  " << entry.path().filename().string() << "\n";
        }
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Filesystem Error in listDirectory: " << e.what() << "\n";
        std::cerr << "  Code: " << e.code().message() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "General Exception in listDirectory: " << e.what() << "\n";
    }
}

void FileSystem::moveFile(const std::string &src, const std::string &dst)
{
    try
    {
        // create_directories catch the case where the destination directory does not exist
        fs::create_directories(fs::path(dst).parent_path());

        // When you call `std::rename`:
        // * The file’s data blocks on disk don’t move.
        // * The system only updates the pointer (directory entry → inode) from the old path to the new one.
        if (std::rename(src.c_str(), dst.c_str()) == 0)
        {
            std::cout << "Moved: " << src << " -> " << dst << "\n";
        }
        else
        {
            perror("Move failed");
        }
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Filesystem Error in moveFile: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception in moveFile: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Unknown error moving file\n";
    }
}