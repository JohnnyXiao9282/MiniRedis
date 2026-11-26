#ifndef COMMAND_EXECUTOR_H
#define COMMAND_EXECUTOR_H

#include <string>
#include "../ministl/vector.h"
#include "key_value_store.h"

class CommandExecutor {
public:
    explicit CommandExecutor(KeyValueStore& store);

    std::string execute(const vector<std::string>& tokens);

private:
    KeyValueStore& store;
};

#endif
