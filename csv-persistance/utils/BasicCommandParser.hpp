//
//  BasicCommandParser.hpp
//  csv-persistance
//
//  Created by Valeri Hristov on 11.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#ifndef BasicCommandParser_hpp
#define BasicCommandParser_hpp

#include "CommandParser.hpp"

class BasicCommandParser : public CommandParser {
public:
    BasicCommandParser(std::string commandLine);
};

#endif /* BasicCommandParser_hpp */
