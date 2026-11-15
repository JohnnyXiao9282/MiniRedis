#pragma once
#include "hashmap.h"

template <typename K, typename V>
std::size_t hashmap<K, V>::hash(const K& key) const {
    return std::hash<K>{}(key) % buckets.size();
}