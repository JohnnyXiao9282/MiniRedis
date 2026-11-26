#include "key_value_store.h"

void KeyValueStore::set(const std::string& key, const std::string& value) {
    store.put(key, value);
}

bool KeyValueStore::get(const std::string& key, std::string& value) const {
    return store.get(key, value);
}

bool KeyValueStore::del(const std::string& key) {
    if (!store.contains(key)) {
        return false;
    }
    store.remove(key);
    return true;
}

bool KeyValueStore::exists(const std::string& key) const {
    return store.contains(key);
}
