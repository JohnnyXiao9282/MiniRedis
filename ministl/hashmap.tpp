#pragma once
#include "hashmap.h"
#include "hash.h"

template <typename K, typename V>
std::size_t hashmap<K, V>::hash(const K& key) const {
    return ::hash<K>{}(key) % buckets.size();
}