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

    // Function used to generate a sequence as described.
    bool GenerateSequence( std::string start,
                           std::string stop,
                           uint32_t    differenceMultiplication = 1,
                           std::string before       = "",
                           std::string separator    = "\n",
                           std::string after        = "");

private:

    Sequence::ISequenceCreator *_sequenceCreator;

    // Function used to print a sequence, each 2 items separated by $separator
    void PrintSequence(std::string& separator);

    // Function used to generate a real difference:
    //  returns ( start > stop ? ) * $differenceMultiplication
    int Difference(std::string& start,
                   std::string& stop,
                   uint32_t differenceMultiplication) const;

    // Function used to change $_sequenceCreator according to newest request.
    // Returns true if successfully changed, else false.
    bool RememberRequest(std::string& start,
                         std::string& stop,
                         uint32_t differenceMultiplication);

    // Function used to change $_sequenceCreator according to newest request.
    // Returns true if successfully changed, else false.
    bool Register(std::string& start,
                  std::string& stop,
                  int difference);

    // Function used to determine whether a sequence is legal or not.
    bool IsValidSequence(std::string& start,
                         std::string& stop,
                         int difference) const;

    // Function used to determine whether $a and $b are valid values
    //  for a sequence.
    bool CheckValues(std::string& a,
                     std::string& b) const;
};
}
