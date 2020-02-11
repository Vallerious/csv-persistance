//
//  CommandParser.cpp
//  csv-persistance
//
//  Created by Valeri Hristov on 11.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#include "CommandParser.hpp"

std::string CommandParser::getCommand() const {
    return this->command;
}

void CommandParser::setCommand(std::string command) {
    this->command = command;
}

std::vector<std::string> CommandParser::getArguments() const {
    return this->arguments;
}

void CommandParser::setArguments(std::vector<std::string> arguments) {
    this->arguments = arguments;
}
