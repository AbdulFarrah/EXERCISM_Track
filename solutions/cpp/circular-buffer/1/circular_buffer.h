#pragma once
#include <vector>
#include <stdexcept>
namespace circular_buffer {
// TODO: add your solution here
template <typename T>
class circular_buffer {
private:
    std::vector<T> buffer;
    size_t read_pos;
    size_t write_pos;
    size_t count;
public:
    circular_buffer(size_t capacity);
    void write(const T& value);
    T read();
    void overwrite(const T& value);
    void clear();
};
template <typename T>
circular_buffer<T>::circular_buffer(size_t capacity)
    : buffer(capacity), read_pos(0), write_pos(0), count(0){}

template <typename T>
void circular_buffer<T>::write(const T& value)
{
    if(buffer.size()==count) throw::std::domain_error("");
    buffer[write_pos] = value;
    write_pos=(write_pos+1)%buffer.size();
    count++;
}
template <typename T>
T circular_buffer<T>::read()
{
    if(count==0) throw::std::domain_error("");
    T value=buffer[read_pos];
    read_pos=(read_pos+1)%buffer.size();
    count--;
    return value;
}
template <typename T>
void circular_buffer<T>::overwrite(const T& value)
{
    if(buffer.size()==count)
    {
        read_pos=(read_pos+1)%buffer.size();
        buffer[write_pos] = value;
        write_pos=(write_pos+1)%buffer.size();
    }
    else if(buffer.size()!=count) write(value);
}
template <typename T>
void circular_buffer<T>::clear()
{
    read_pos=0;write_pos=0;count=0;
}
}  // namespace circular_buffer
