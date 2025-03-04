#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

#include <vector>
#include <concepts>
#include <stdexcept>
#include "circular_buffer.cpp" 


template <typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(size_t size);
    void push(T value);
    T pop();
    size_t getSize() const;
    double getAverage() const requires std::is_arithmetic_v<T>;

private:
    std::vector<T> buffer;
    size_t tail, size;
};


#endif // CIRCULAR_BUFFER_HPP
