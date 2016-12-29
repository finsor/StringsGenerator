#include "CSRandom.h"

#include <stdexcept>

#include "Formatter.h"

#include <Windows.h>
#include <Wincrypt.h>


Random::CSRandom::CSRandom()
{
    Create();
}

Random::CSRandom::~CSRandom()
{
    Destroy();

#ifdef PRINT_DESTRUCTOR
    std::cout << "~Random" << std::endl;
#endif // PRINT_DESTRUCTOR
}

uint32_t
Random::CSRandom::Generate() const
{
    uint32_t rand;
    if ( 0 != CryptGenRandom(_crypto_provider_handle, sizeof(uint32_t), (PBYTE)&rand) )
    {
        std::string ex = StringHelper::Formatter() <<
                         "Failed to generate a random: " <<
                         GetLastError();
    }
    return ( rand );
}

uint32_t
Random::CSRandom::Generate(uint32_t minimum, uint32_t maximum) const
{
    return ( Generate() % (maximum+1 - minimum) + minimum );
}


/* private */

void
Random::CSRandom::Create()
{
    if( 0 == CryptAcquireContext(&_crypto_provider_handle, "random", NULL, PROV_RSA_FULL, 0) )
    {
        if ( (unsigned)NTE_BAD_KEYSET == GetLastError() )
        {
            if( 0 ==
                    CryptAcquireContext(
                        &_crypto_provider_handle, "random", NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET) )
            {
                std::string ex = StringHelper::Formatter() <<
                                 "A cryptographic service handle could not be acquired: " <<
                                 GetLastError();

                throw std::runtime_error(ex);
            }
        }
        else
        {
            std::string ex = StringHelper::Formatter() <<
                             "A cryptographic service handle could not be acquired: " <<
                             GetLastError();

            throw std::runtime_error(ex);
        }
    }
}

void
Random::CSRandom::Destroy()
{
    if ( 0 == CryptReleaseContext(_crypto_provider_handle,0) )
    {
        std::string ex = StringHelper::Formatter() <<
                         "Failed to release cryptographic provider handle: " <<
                         GetLastError();

        throw std::runtime_error(ex);
    }
}
