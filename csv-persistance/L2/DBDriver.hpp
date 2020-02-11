//
//  DBDriver.hpp
//  csv-persistance
//
//  Created by Valeri Hristov on 10.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#ifndef DBDriver_hpp
#define DBDriver_hpp

#include <string>
#include <fstream>

class DBDriver {
private:
    std::string database;
protected:
    std::string dataDirPath;
    
    DBDriver(std::string dataDirPath);
public:
    virtual void use(std::string dbName);
    virtual void createDB(std::string dbName) = 0;
    virtual void createTable(std::string tableName, std::string initialData) = 0;
    virtual void createTable(std::string tableName) = 0;
    virtual void insert(std::string tableName, std::string rowData) = 0;
    virtual std::ifstream select(std::string tableName) = 0;
    virtual void erase(std::string tableName, std::string recordId) = 0;
    virtual void update(std::string tableName, std::string rowData) = 0;
    std::string getDatabase();
};

#endif /* DBDriver_hpp */
