//
//  FileSystem.cpp
//  csv-persistance
//
//  Created by Valeri Hristov on 10.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#include "FileSystem.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

FileSystem::FileSystem() {}

void FileSystem::append(std::string filePath, std::string text) {
    this->outputFileStream.open(filePath, std::fstream::app);
    this->outputFileStream << text;
    this->outputFileStream.close();
}

void FileSystem::replace(std::string filePath, std::string text) {
    this->outputFileStream.open(filePath, std::fstream::trunc);
    this->outputFileStream << text;
    this->outputFileStream.close();
}

bool FileSystem::erase(std::string filePath) {
    return remove(filePath.c_str()) == 0;
}

std::ifstream FileSystem::read(std::string filePath) {
    std::ifstream inputStr;
    inputStr.open(filePath);
    
    return inputStr;
}

bool FileSystem::exist(std::string filePath) {
    struct stat info;
    
    return stat(filePath.c_str(), &info) == 0;
}

bool FileSystem::createDir(std::string dirPath) {
    return mkdir(dirPath.c_str(), S_IRWXU);
}
