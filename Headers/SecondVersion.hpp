#pragma once
#include "Family.hpp"
#include "TaskGenerator.hpp"

class SecondVersion : public Family
{
private:
    std::string old_text;

public:
    void solve() override;
    SecondVersion(TaskGenerator *);
    ~SecondVersion() = default;
};
