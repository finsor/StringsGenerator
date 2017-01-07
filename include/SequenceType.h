#pragma once

#include <iostream>
#include <string>

#include "ISequenceType.h"


namespace Sequence
{
class SequenceType : public ISequenceType
{
public:

    SequenceType(std::string variable);
    virtual ~SequenceType() {}

    // Copy constructor and assignment operator
    SequenceType(const ISequenceType& other);
    SequenceType& operator =(const ISequenceType& other);

    operator std::string() const;
    operator const char*() const;

    void operator ++();
    void operator --();

    void operator +=(int n);
    void operator -=(int n);

    bool operator ==(const ISequenceType& other) const;
    bool operator <=(const ISequenceType& other) const;
    bool operator >=(const ISequenceType& other) const;
    bool operator  >(const ISequenceType& other) const;
    bool operator  <(const ISequenceType& other) const;

//    friend std::ostream& operator<<(std::ostream& out, const SequenceType& obj)
//    {
//    out << obj._var;
//
//    return ( out );
//}

private:

    std::string _var;

    void Add(int addition);
    void StripZeroes();

//    void ShiftLeft();
//    void ShiftRight();
};

}


