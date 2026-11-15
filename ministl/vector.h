#pragma once
#include <cstddef>

template <typename T>
class vector {
private:

public:
    vector();
    vector(const vector& other);
    ~vector();
    vector& operator=(const vector& other);
    void clear();
    void push_back(const T& value);
    void pop_back();

    T& operator[](std::size_t index);
    // For read only index access
    const T& operator[](std::size_t index) const;

    std::size_t size() const;
    bool empty() const;

    T* begin();
    T* end();

    // Read only access
    const T* begin() const;
    const T* end() const;

private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;

    void grow();
};

#include "vector.tpp"