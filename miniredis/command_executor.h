#ifndef COMMAND_EXECUTOR_H
#define COMMAND_EXECUTOR_H

#include <string>
#include <vector>
#include "key_value_store.h"

class CommandExecutor {
public:
    explicit CommandExecutor(KeyValueStore& store);

    std::string execute(const std::vector<std::string>& tokens);

private:
    KeyValueStore& store;
};

#endif
