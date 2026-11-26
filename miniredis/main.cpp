#include <iostream>
#include <string>
#include <vector>

#include "key_value_store.cpp"
#include "command_parser.cpp"
#include "command_executor.cpp"

int main() {
    KeyValueStore store;
    CommandParser parser;
    CommandExecutor executor(store);

    std::string line;
    std::cout << "> " << std::flush;
    while (std::getline(std::cin, line)) {
        std::vector<std::string> tokens = parser.tokenize(line);
        if (!tokens.empty()) {
            std::string result = executor.execute(tokens);
            if (!result.empty()) {
                std::cout << result << std::endl;
            }
        }
        std::cout << "> " << std::flush;
    }

    return 0;
}
