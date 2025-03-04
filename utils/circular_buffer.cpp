#include "circular_buffer.hpp"

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size) : buffer(size), tail(0), size(size) {}


template <typename T>
void CircularBuffer<T>::push(T val){
    
    tail = (tail + 1) % size;
    buffer[tail] =  val;
}

template <typename T>
T CircularBuffer<T>::pop(){
    T val = buffer[tail];
    tail = (tail - 1) % size;
    return val;
}

template <typename T>
size_t CircularBuffer<T>::getSize() const{
    return size;
}

template <typename T>
double CircularBuffer<T>::getAverage() const{
    double sum = 0;
    for (const T& val : buffer){
        sum += val;
    }
    return sum / size;
}