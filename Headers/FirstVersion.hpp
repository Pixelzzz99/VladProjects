#pragma once
#include "Family.hpp"
#include "TaskGenerator.hpp"

class FirstVersion : public Family
{
private:
    std::string old_text;

public:
    void solve() override;
    FirstVersion(TaskGenerator *);
    ~FirstVersion() = default;
};
