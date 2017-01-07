#pragma once

#include <string>
#include <functional>

#include "SequenceCreator.h"


namespace Sequence
{
class SequenceCreationClient
{
public:
    SequenceCreationClient(std::string start,
                           std::string stop,
                           int difference,
                           std::string before       = "",
                           std::string separator    = "\n",
                           std::string after        = "");
    virtual ~SequenceCreationClient();

    const char * Next();

private:

    Sequence::SequenceCreator *_sequenceCreator;

    const char * _before;
    const char * _separator;
    const char * _after;
};
}
