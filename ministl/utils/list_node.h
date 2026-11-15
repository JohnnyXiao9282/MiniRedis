#pragma once

template <typename K, typename V>
struct ListNode {
    K key;
    V value;
    ListNode* next;

    ListNode(const K& k, const V& v) {
        key = k;
        value = v;
        next = nullptr;
    }
};
