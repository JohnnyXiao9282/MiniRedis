#pragma once 
#include <cstddef>
#include <functional>
#include "utils/list_node.h"

template <typename K, typename V>
class hashmap {
private:
    static const std::size_t SIZE = 16;
    vector<ListNode<K, V>*> buckets;
    std::size_t count;

    std::size_t hash(const K& key) const;
    void initialBuckets(std::size_t number);
    void rehash();
    void freeAll();
    void copyFrom(const hashmap& other);

public:
    hashmap();
    hashmap(const hashmap& other);
    hash& operator=(const hashmap& other);
    ~hashmap();

    void put(const K& key, const V& value);
    bool get(const K& key, V& value) const;
    bool contains(const K& key) const;
    void remove(const K& key);
    
    std::size_t size() const;
    bool empty() const;


};
