//
//  CommandParser.hpp
//  csv-persistance
//
//  Created by Valeri Hristov on 11.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#ifndef CommandParser_hpp
#define CommandParser_hpp

#include <string>
#include <vector>

class CommandParser {
private:
    std::string command;
    std::vector<std::string> arguments;
public:
    CommandParser(std::string command, std::vector<std::string> arguments): command(command), arguments(arguments) {}
    CommandParser() {};
    
    std::string getCommand() const;
    void setCommand(std::string command);
    std::vector<std::string> getArguments() const;
    void setArguments(std::vector<std::string> arguments);
};

#endif /* CommandParser_hpp */
