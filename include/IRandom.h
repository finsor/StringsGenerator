#pragma once

#include <cstdint>

namespace Random
{
class IRandom
{
public:

    IRandom() {}
    virtual ~IRandom() {}

    virtual uint32_t Generate() const = 0;
    virtual uint32_t Generate(uint32_t minimum, uint32_t maximum) const = 0;

};
}
