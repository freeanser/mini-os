#include "FileSystem.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>

namespace fs = std::filesystem;

void FileSystem::createFile(const std::string& fileName, const std::string& content) {
    std::ofstream out(fileName);
    if (!out) {
        std::cerr << "Cannot create file: " << fileName << "\n";
        return;
    }
    out << content << "\n";
    std::cout << "Created file: " << fileName << "\n";

}

void FileSystem::readFile(const std::string& fileName) {
}

void FileSystem::deleteFile(const std::string& fileName) {
}

void FileSystem::renameFile(const std::string& oldName, const std::string& newName) {
}

void FileSystem::listDirectory(const std::string& path) {
}

void FileSystem::moveFile(const std::string& src, const std::string& dst) {
}
