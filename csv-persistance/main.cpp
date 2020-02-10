//
//  main.cpp
//  csv-persistance
// Features:
// - Should support multiple DBs and tables.
// - Can list DBs and when DB is selected it should list tables.
// - Should support SQL like syntax for querying the DB. (insert, select, update, delete)
// - Should support joins with two tables.
// - Should have some validation on insert and update.
//
//  Created by Valeri Hristov on 7.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#include <iostream>
#include "L1/FileSystem.hpp"

int main(int argc, const char * argv[]) {
    FileSystem fs;
    std::string path = "/var/db-persister/data/test.txt";
    
    fs.append(path, "THis is the new hit");
    
    std::ifstream streamcheto = fs.read(path);
    
    return 0;
}
