#pragma once

namespace Regex
{
class IDelimiter
{
public:

    // Function to get the delimiter.
    virtual char Trigger() const = 0;
};
}
