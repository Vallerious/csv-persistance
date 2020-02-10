//
//  CSVDriver.cpp
//  csv-persistance
//
//  Created by Valeri Hristov on 10.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#include "CSVDriver.hpp"
#include "../L1/FileSystem.hpp"

#include <filesystem>

namespace fs = std::__fs::filesystem;

CSVDriver::CSVDriver() : DBDriver("/var/db-persister/data") {}

void CSVDriver::createDB(std::string dbName) {
    fs::path p;
    p.append(this->dataDirPath);
    p.append(dbName);
    
    FileSystem fs;
    if (!fs.exist(p)) {
        fs.createDir(p);
        fs.append(p, "");
    }
}

void CSVDriver::createTable(std::string tableName, std::string initialData) {
    if (tableName.empty()) {
        return;
    }
    
    fs::path p;
    p.append(this->dataDirPath);
    p.append(this->getDatabase());
    
    FileSystem fs;
    if (fs.exist(p)) {
        p.append(tableName);
        p += ".csv";
        
        if (!fs.exist(p)) {
            fs.append(p, initialData += "\n");
        } else {
            throw "Table already exists.";
        }
    } else {
        throw "DB does not exist.";
    }
}

void CSVDriver::createTable(std::string tableName) {
    this->createTable(tableName, "");
}
