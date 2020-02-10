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
};

#endif /* CSVDriver_hpp */
