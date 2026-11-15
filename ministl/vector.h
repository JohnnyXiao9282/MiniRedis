#include <cstddef>

template <typename T>
class vector {
private:

public:
    vector();
    ~vector();
    vector& operator=(const vector& other);
    void clear();
    void push_back(const T& value);
    void pop_back();

    T& opeartor[](std::size_t index);
    // const T& operator[](std::size_t index) const;


}