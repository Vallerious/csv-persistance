//
//  DBDriver.cpp
//  csv-persistance
//
//  Created by Valeri Hristov on 10.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#include "DBDriver.hpp"

DBDriver::DBDriver(std::string dataDirPath)  {
   this->dataDirPath = dataDirPath;
}

void DBDriver::use(std::string dbName) {
    this->database = dbName;
}

std::string DBDriver::getDatabase() {
    return this->database;
}
