#pragma once
#include <cstddef>
#include <string>

template <typename K>
struct hash;   

template <>
struct hash<std::string> {
    std::size_t operator()(const std::string& key) const {
        std::size_t h = 14695981039346656037ULL;   
        for (char c : key) {
            h ^= static_cast<unsigned char>(c);
            h *= 1099511628211ULL;                  
        }
        return h;
    }
};

template <>
struct hash<int> {
    std::size_t operator()(int key) const {
        return static_cast<std::size_t>(key);      
    }
};