//
//  Persistance.hpp
//  csv-persistance
//
//  Created by Valeri Hristov on 10.02.20.
//  Copyright © 2020 Valeri Hristov. All rights reserved.
//

#ifndef Persistance_hpp
#define Persistance_hpp

#include <fstream>
#include <string>

class Persistance {
    public:
        Persistance();
    protected:
        std::ofstream outputFileStream;

    virtual void append(std::string path, std::string text) = 0;
    virtual void replace(std::string path, std::string text) = 0;
    virtual bool erase(std::string path) = 0;
    virtual std::ifstream read(std::string path) = 0;
};

#endif /* Persistance_hpp */
