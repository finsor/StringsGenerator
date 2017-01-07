#pragma once

#include <string>


namespace Sequence
{
class ISequenceType
{
public:

    ISequenceType() {}
    virtual ~ISequenceType() {}

    virtual operator std::string() const = 0;
    virtual operator const char*() const = 0;

    virtual void operator ++() = 0;
    virtual void operator --() = 0;

    virtual void operator +=(int n) = 0;
    virtual void operator -=(int n) = 0;

    virtual bool operator ==(const ISequenceType& other) const = 0;
    virtual bool operator <=(const ISequenceType& other) const = 0;
    virtual bool operator >=(const ISequenceType& other) const = 0;
    virtual bool operator  >(const ISequenceType& other) const = 0;
    virtual bool operator  <(const ISequenceType& other) const = 0;

};
}

