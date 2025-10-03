#include "FileSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>

namespace fs = std::filesystem;

void FileSystem::createFile(const std::string& fileName, const std::string& content) {
    std::ofstream newFile(fileName);
    if (!newFile) {
        std::cerr << "Cannot create file: " << fileName << "\n";
        return;
    }
    newFile << content << "\n";
    std::cout << "Created file: " << fileName << "\n";

}


void FileSystem::readFile(const std::string& fileName) {
    std::ifstream in(fileName);
    if (!in) {
        std::cerr << "Cannot read file: " << fileName << "\n";
        return;
    }
    std::string line;
    std::getline(in, line);
    std::cout << "File content: " << line << "\n";
}

void FileSystem::deleteFile(const std::string& fileName) {
    int result = std::remove(fileName.c_str());
    if ( result == 0) {
        std::cout << "Deleted file: " << fileName << "\n";
    } else {
        perror("Delete failed");
    }
}

void FileSystem::renameFile(const std::string& oldName, const std::string& newName) {
    int result = std::rename(oldName.c_str(), newName.c_str());
    if (result == 0) {
        std::cout << "Renamed: " << oldName << " -> " << newName << "\n";
    } else {
        perror("Rename failed");
    }
}

void FileSystem::listDirectory(const std::string& path) {
    std::cout << "Directory listing for: " << fs::absolute(path) << "\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << "  " << entry.path().filename().string() << "\n";
    }
}

void FileSystem::moveFile(const std::string& src, const std::string& dst) {
    try {
        fs::create_directories(fs::path(dst).parent_path());

        // When you call `std::rename`:
        // * The file’s data blocks on disk don’t move.
        // * The system only updates the pointer (directory entry → inode) from the old path to the new one.
        if (std::rename(src.c_str(), dst.c_str()) == 0) {
            std::cout << "Moved: " << src << " -> " << dst << "\n";
        } else {
            perror("Move failed");
        }
    } catch (...) {
        std::cerr << "Error moving file\n";
    }
}

