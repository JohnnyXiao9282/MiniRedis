#pragma once
#include <cassert>
#include "vector.h"

template <typename T>
vector<T>::vector() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template <typename T>
vector<T>::vector(const vector& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = nullptr;

    if (capacity_ > 0) {
        data_ = new T[capacity_];

        for (std::size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& other) {
    if (this == &other) {
       return *this; 
    }

    delete[] data_;
    data_ = nullptr;
    size_ = other.size_;
    capacity_ = other.capacity_;

    if (capacity_ > 0) {
        data_ = new T[capacity_];

        for (std::size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    return *this;
}

template <typename T>
vector<T>::~vector() {
    delete[] data_;
}

template <typename T>
void vector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        grow();
    }

    data_[size_] = value;
    size_++;
}

template <typename T>
void vector<T>::pop_back() {
    assert(size_ > 0 && "Cannot pop back on an empty vector.");
    size_--;
}

template <typename T>
void vector<T>::clear() {
    size_ = 0;
}

template <typename T>
T& vector<T>::operator[](std::size_t index) {
    return data_[index];
}

template <typename T>
const T& vector<T>::operator[](std::size_t index) const {
    return data_[index];
}

template <typename T>
std::size_t vector<T>::size() const {
    return size_;
}

template <typename T>
bool vector<T>::empty() const {
    return size_ == 0;
}

template <typename T> 
T* vector<T>::begin() {
    return data_;
}

template <typename T> 
const T* vector<T>::begin() const {
    return data_;
}

template <typename T>
T* vector<T>::end() {
    return data_ + size_;
}

template <typename T>
const T* vector<T>::end() const {
    return data_ + size_;
}

template <typename T>
void vector<T>::grow() {
    std::size_t newCapacity;

    if (capacity_ == 0) {
        newCapacity = 1;
    } else {
        newCapacity = capacity_ * 2;
    }

    T* newData = new T[newCapacity];
    
    for (std::size_t i = 0; i < size_; i++) {
        newData[i] = data_[i];
    }

    delete[] data_;
    data_ = newData;
    capacity_ = newCapacity;
}




















