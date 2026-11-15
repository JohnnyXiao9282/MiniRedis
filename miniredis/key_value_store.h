#pragma once
#include <string>
#include "../ministl/hashmap.h"

class KeyValueStore {
private:
    hashmap<std::string, std::string> store;

public:
    void set(const std::string& key, const std::string& value);
    bool get(const std::string& key, std::string& value) const;
    bool del(const std::string& key);
    bool exists(const std::string& key) const;
};
