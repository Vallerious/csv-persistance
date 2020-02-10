//
//  FileSystem.hpp
//  csv-persistance
//
//  Created by Valeri Hristov on 10.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#ifndef FileSystem_hpp
#define FileSystem_hpp

#include "Persistance.hpp"

class FileSystem : public Persistance {
public:
    FileSystem();
    void append(std::string filePath, std::string text);
    void replace(std::string filePath, std::string text);
    bool erase(std::string filePath);
    std::ifstream read(std::string filePath);
};

#endif /* FileSystem_hpp */
