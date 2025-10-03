#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>

class FileSystem {
public:
    void createFile(const std::string& fileName, const std::string& content);
    void readFile(const std::string& fileName);
    void deleteFile(const std::string& fileName);
    void renameFile(const std::string& oldName, const std::string& newName);
    void listDirectory(const std::string& path = ".");
    void moveFile(const std::string& src, const std::string& dst);
};

#endif
