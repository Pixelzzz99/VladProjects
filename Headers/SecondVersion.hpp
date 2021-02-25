#pragma once
#include "Family.hpp"
#include "TaskGenerator.hpp"

class SecondVersion : public Family
{
private:

public:
    void solve() override;
    SecondVersion(TaskGenerator *);
    ~SecondVersion() = default;
};
