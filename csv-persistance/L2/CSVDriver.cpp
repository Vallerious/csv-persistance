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
#include <sstream>

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
        throw "Please provide table name.";
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

void CSVDriver::insert(std::string tableName, std::string rowData) {
    if (tableName.empty()) {
        throw "Please provide table name.";
    }
    
    if (rowData.empty()) {
        throw "No data provided to insert";
    }
    
    fs::path p;
    p.append(this->dataDirPath);
    p.append(this->getDatabase());
    
    FileSystem fs;
    if (fs.exist(p)) {
        p.append(tableName);
        p += ".csv";
        
        if (fs.exist(p)) {
            fs.append(p, rowData += "\n");
        } else {
            throw "Table does not exists.";
        }
    } else {
        throw "DB does not exist.";
    }
}

std::ifstream CSVDriver::select(std::string tableName) {
    if (tableName.empty()) {
        throw "Please provide table name.";
    }
    
    fs::path p;
    p.append(this->dataDirPath);
    p.append(this->getDatabase());
    
    FileSystem fs;
    if (fs.exist(p)) {
        p.append(tableName);
        p += ".csv";
        
        if (fs.exist(p)) {
            return fs.read(p);
        } else {
            throw "Table does not exists.";
        }
    } else {
        throw "DB does not exist.";
    }
}

void CSVDriver::erase(std::string tableName, std::string recordId) {
    if (tableName.empty()) {
        throw "Please provide table name.";
    }
    
    fs::path p;
    p.append(this->dataDirPath);
    p.append(this->getDatabase());
    
    FileSystem fs;
    if (fs.exist(p)) {
        p.append(tableName);
        p += ".csv";
        
        if (fs.exist(p)) {
            std::ifstream fileStream = fs.read(p);
            std::string newTableData;
            
            std::string line;
            
            while (std::getline(fileStream, line)) {
                std::istringstream ss(line);
                std::string id;
                
                std::getline(ss, id, ',');
                
                if (id != recordId) {
                    newTableData += (line + "\n");
                }
            }
            
            fs.replace(p, newTableData);
        } else {
            throw "Table does not exists.";
        }
    } else {
        throw "DB does not exist.";
    }
}

void CSVDriver::update(std::string tableName, std::string recordData) {
    if (tableName.empty()) {
        throw "Please provide table name.";
    }
    
    if (recordData.empty()) {
        throw "Please provide record data.";
    }
    
    fs::path p;
    p.append(this->dataDirPath);
    p.append(this->getDatabase());
    
    FileSystem fs;
    if (fs.exist(p)) {
        p.append(tableName);
        p += ".csv";
        
        if (fs.exist(p)) {
            std::ifstream fileStream = fs.read(p);
            std::string newTableData;
            
            std::string line;
            
            // let's get the id from recordData
            std::istringstream rs(recordData);
            std::string recordId;
            std::getline(rs, recordId, ',');
            
            while (std::getline(fileStream, line)) {
                std::istringstream ss(line);
                std::string id;
                
                std::getline(ss, id, ',');
                
                if (id == recordId) {
                    newTableData += (recordData + "\n");
                } else {
                    newTableData += (line + "\n");
                }
            }
            
            fs.replace(p, newTableData);
        } else {
            throw "Table does not exists.";
        }
    } else {
        throw "DB does not exist.";
    }
}
