//
//  BasicCommandParser.cpp
//  csv-persistance
//
//  Created by Valeri Hristov on 11.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#include "BasicCommandParser.hpp"

#include <sstream>

BasicCommandParser::BasicCommandParser(std::string commandLine): CommandParser() {
    std::stringstream ss(commandLine);
    std::string command;
    ss >> command;
    
    std::vector<std::string> args;
    
    std::string argument;
    
    while (ss >> argument) {
        args.push_back(argument);
    }
    
    this->setCommand(command);
    this->setArguments(args);
}


