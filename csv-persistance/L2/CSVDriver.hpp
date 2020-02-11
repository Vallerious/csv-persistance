//
//  CSVDriver.hpp
//  csv-persistance
//
//  Created by Valeri Hristov on 10.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#ifndef CSVDriver_hpp
#define CSVDriver_hpp

#include "DBDriver.hpp"

class CSVDriver : public DBDriver {
public:
    CSVDriver();

    void createDB(std::string dbName);
    void createTable(std::string tableName, std::string initialData);
    void createTable(std::string tableName);
    void insert(std::string tableName, std::string rowData);
    std::ifstream select(std::string tableName);
    void erase(std::string tableName, std::string recordId);
    void update(std::string tableName, std::string rowData);
};

#endif /* CSVDriver_hpp */
