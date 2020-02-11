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
#include <sstream>
#include "L2/CSVDriver.hpp"

int main(int argc, const char * argv[]) {
    CSVDriver csv;
    
    csv.createDB("valio");
    csv.use("valio");
    
    try {
//        csv.createTable("creatures", "id,type,health");
//        csv.insert("creatures", "2,rimlqnin,200");
//        csv.insert("creatures", "3,gruk,250");

//        std::ifstream fileStream = csv.select("creatures");
//        std::string temp;
//        while (std::getline(fileStream, temp)) {
//            std::cout << temp << std::endl;
//        }
//        csv.insert("creatures", "3,bulgarin,1000");
        csv.update("creatures", "3,hungarian,900");
    } catch (const char* err) {
        std::cerr << err << std::endl;
    }
    
    return 0;
}
