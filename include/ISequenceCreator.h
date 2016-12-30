#pragma once

#include <string>


namespace Sequence
{
class ISequenceCreator
{
public:
    ISequenceCreator(std::string start, std::string stop, int difference) :
        _start(start), _stop(stop), _difference(difference)
    {}

    virtual ~ISequenceCreator() {}

    virtual std::string GetNext() = 0;
    virtual bool End() const = 0;

protected:
    std::string _start, _stop;
    int _difference;
};
}
