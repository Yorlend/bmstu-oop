#pragma once

#include <fstream>
#include "iloader.hpp"

class TxtFileLoader : public ILoader
{
public:
    TxtFileLoader(const std::string& filename);
    ~TxtFileLoader();

    virtual size_t loadSize() override;
    virtual Vector loadVector() override;
    virtual std::string loadString() override;

private:
    std::ifstream stream;
};
