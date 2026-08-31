#pragma once
#include <stdexcept>

namespace linked_list {

template <typename T>
struct Node {
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(const T& value) : data(value) {}
};

template <typename T>
class List {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;

public:
    T pop();
    T shift();
    int count() const;
    void unshift(const T&);
    void push(const T&);
    void erase(const T&);
};

template <typename T>
void List<T>::push(const T& val)
{
    Node<T>* node = new Node<T>(val);
    if (!tail)
        head = tail = node;
    else 
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    size++;
}

template <typename T>
void List<T>::unshift(const T& val)
{
    Node<T>* node = new Node<T>(val);
    if (!head)
        head = tail = node;
    else 
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
}

template <typename T>
T List<T>::pop()
{
    if (!tail)
        throw std::out_of_range("");
    Node<T>* temp = tail;
    T value = temp->data;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    size--;
    return value;
}

template <typename T>
T List<T>::shift()
{
    if (!head)
        throw std::out_of_range("");
    Node<T>* temp = head;
    T value = temp->data;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
    size--;
    return value;
}

template <typename T>
int List<T>::count() const
{
    return size;
}

template <typename T>
void List<T>::erase(const T& val)
{
    Node<T>* current = head;
    while (current && current->data != val)
        current = current->next;
    if (!current)
        return;
    if (current->prev)
        current->prev->next = current->next;
    else
        head = current->next;
    if (current->next)
        current->next->prev = current->prev;
    else
        tail = current->prev;
    delete current;
    size--;
}
} // namespace linked_list