#include "command_executor.h"

CommandExecutor::CommandExecutor(KeyValueStore& store) : store(store) {
}

std::string CommandExecutor::execute(const vector<std::string>& tokens) {
    const std::string& command = tokens[0];
    std::size_t size = tokens.size();

    if (command == "set" && size == 3) {
        store.set(tokens[1], tokens[2]);
        return "";
    }

    if (command == "get" && size == 2) {
        std::string value;
        if (store.get(tokens[1], value)) {
            return value;
        } else {
            return "";
        }
    }

    if (command == "del" && size == 2) {
        store.del(tokens[1]);
        return "";
    }

    if (command == "exists" && size == 2) {
        std::string value;
        if (store.get(tokens[1], value)) {
            return tokens[1] + " : " + value;
        } else {
            return "";
        }
    }

    return "Error: Unknown Command";
}
