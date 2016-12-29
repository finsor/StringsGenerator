#pragma once

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <Windows.h>
#include <Wincrypt.h>

#include "IRandom.h"


namespace Random
{
class CSRandom : public IRandom
{
public:
    CSRandom();
    virtual ~CSRandom();

    uint32_t Generate() const;
    uint32_t Generate(uint32_t minimum, uint32_t maximum) const;

private:
    HCRYPTPROV _crypto_provider_handle;

    void Create();
    void Destroy();
};
}
