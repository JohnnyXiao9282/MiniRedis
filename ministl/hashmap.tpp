#pragma once
#include "hashmap.h"
#include "hash.h"

template <typename K, typename V>
std::size_t hashmap<K, V>::hash(const K& key) const {
    return ::hash<K>{}(key) % buckets.size();
}

template <typename K, typename V>
void hashmap<K, V>::initialBuckets(std::size_t number) {
    buckets.clear();
    for (std::size_t i = 0; i < number; i++) {
        buckets.push_back(nullptr);
    }
}

template <typename K, typename V>
hashmap<K, V>::hashmap() {
    count = 0;
    initialBuckets(SIZE);
}

template <typename K, typename V>
hashmap<K, V>::hashmap(const hashmap& other) {
    count = 0;
    copyFrom(other);
}

template <typename K, typename V>
hashmap<K, V>& hashmap<K, V>::operator=(const hashmap& other) {
    if (this == &other) {
        return *this;
    }

    freeAll();
    copyFrom(other);
    return *this;
}

template <typename K, typename V>
hashmap<K, V>::~hashmap() {
    freeAll();
}

template <typename K, typename V>
void hashmap<K, V>::put(const K& key, const V& value) {
    std::size_t bucket = hash(key);
    ListNode<K, V>* head = buckets[bucket];
    ListNode<K, V>* current = head;

    while (current) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    ListNode<K, V>* newNode = new ListNode<K, V>(key, value);
    newNode->next = head;
    buckets[bucket] = newNode;
    count++;

    if (count * 4 > buckets.size() * 3) {
        rehash();
    }
}

template <typename K, typename V>
bool hashmap<K, V>::get(const K& key, V& value) const {
    std::size_t bucket = hash(key);
    ListNode<K, V>* current = buckets[bucket];

    while (current) {
        if (current->key == key) {
            value = current->value;
            return true;
        }
        current = current->next;
    }

    return false;
}

template <typename K, typename V>
bool hashmap<K, V>::contains(const K& key) const {
    std::size_t bucket = hash(key);
    ListNode<K, V>* current = buckets[bucket];

    while (current) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }

    return false;
}


template <typename K, typename V>
void hashmap<K, V>::remove(const K& key) {
    std::size_t bucket = hash(key);
    ListNode<K, V>* head = buckets[bucket];

    if (!head) {
        return;
    }

    if (head->key == key) {
        buckets[bucket] = head->next;
        delete head;
        count--;
        return;
    }

    ListNode<K, V>* current = head;
    while (current->next) {
        if (current->next->key == key) {
            ListNode<K, V>* target = current->next;
            current->next = target->next;
            delete target;
            count--;
            return;
        }
        current = current->next;
    }
}

template <typename K, typename V>
std::size_t hashmap<K, V>::size() const {
    return count;
}

template <typename K, typename V>
bool hashmap<K, V>::empty() const {
    return count == 0;
}

template <typename K, typename V>
void hashmap<K, V>::rehash() {
    vector<ListNode<K, V>*> oldBuckets = buckets;
    std::size_t oldSize = oldBuckets.size();
    std::size_t newSize = oldSize * 2;
    initialBuckets(newSize);

    for (std::size_t i = 0; i < oldSize; i++) {
        ListNode<K, V>* current = oldBuckets[i];

        while (current) {
            ListNode<K, V>* next = current->next;
            std::size_t bucket = hash(current->key);
            current->next = buckets[bucket];
            buckets[bucket] = current;
            current = next;
        }
    }
}

template <typename K, typename V>
void hashmap<K, V>::freeAll() {
    for (std::size_t i = 0; i < buckets.size(); i++) {
        ListNode<K, V>* current = buckets[i];
        
        while (current) {
            ListNode<K, V>* next = current->next;
            delete current;
            current = next;
        }
        buckets[i] = nullptr;
    }

    count = 0;
}

template <typename K, typename V>
void hashmap<K, V>::copyFrom(const hashmap& other) {
    initialBuckets(other.buckets.size());

    for (std::size_t i = 0; i < other.buckets.size(); i++) {
        ListNode<K, V>* otherHead = other.buckets[i];

        if (!otherHead) {
            continue;
        }

        ListNode<K, V>* head = new ListNode<K, V>(otherHead->key, otherHead->value);
        buckets[i] = head;

        ListNode<K, V>* current = head;
        ListNode<K, V>* otherCurrent = otherHead->next;

        while (otherCurrent) {
            current->next = new ListNode<K, V>(otherCurrent->key, otherCurrent->value);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

    count = other.count;
}

