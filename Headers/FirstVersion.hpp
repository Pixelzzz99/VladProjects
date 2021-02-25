#pragma once
#include "Family.hpp"
#include "TaskGenerator.hpp"

class FirstVersion : public Family
{
private:
    
public:
    void solve() override;
    FirstVersion(TaskGenerator *);
    ~FirstVersion() = default;
    
};
