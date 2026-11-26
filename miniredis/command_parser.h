#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include "../ministl/vector.h"

class CommandParser {
public:
    vector<std::string> tokenize(const std::string& line) const;
};

#endif
