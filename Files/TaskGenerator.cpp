#include "TaskGenerator.hpp"
#include <string>

TaskGenerator::TaskGenerator(int len)
{
    txt_ = generateGraph(len);
}

std::string TaskGenerator::generateGraph(int len)
{
    std::string res;
    for (int i = 0; i < len; i++){
        int x = rand() % 27;
        if (x == 26) res.push_back(' ');
        else 
        res.push_back('a' + x - 1);
    }    
    return res;
}

std::string TaskGenerator::getString()
{
    return this->txt_;
}