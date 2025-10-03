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
}

void FileSystem::renameFile(const std::string& oldName, const std::string& newName) {
}

void FileSystem::listDirectory(const std::string& path) {
}

void FileSystem::moveFile(const std::string& src, const std::string& dst) {
}
