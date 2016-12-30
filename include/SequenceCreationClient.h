#pragma once

#include <string>

#include "ISequenceCreator.h"


namespace Sequence
{
class SequenceCreationClient
{
public:
    SequenceCreationClient() :
        _sequenceCreator(nullptr)
    {}

    virtual ~SequenceCreationClient();

    bool IsValidSequence(std::string& start, std::string& stop, int difference) const;
    bool Sign(std::string start, std::string stop, int difference);
    bool End() const;

    std::string Next();

private:

    Sequence::ISequenceCreator *_sequenceCreator;

};
}
