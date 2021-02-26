#pragma once
#include <string>
class TaskGenerator
{
private:
    std::string txt_;   
    std::string generateGraph(int len);

public:
    std::string getString();
    TaskGenerator(int len);
    ~TaskGenerator() = default;
};
