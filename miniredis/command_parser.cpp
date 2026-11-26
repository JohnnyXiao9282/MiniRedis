#include "command_parser.h"
#include <sstream>

std::vector<std::string> CommandParser::tokenize(const std::string& line) const {
    std::istringstream stream(line);

    std::vector<std::string> tokens;
    std::string token;

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;
}
