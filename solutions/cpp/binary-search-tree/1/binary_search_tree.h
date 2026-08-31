#pragma once

#include <memory>
#include <utility>

namespace binary_search_tree 
{
template<typename T>
class binary_tree 
{
private:
    T _data;
    binary_tree<T>* _parent;
    std::unique_ptr<binary_tree<T>> _left;
    std::unique_ptr<binary_tree<T>> _right;
public:
    binary_tree(const T& data, binary_tree<T>* parent = nullptr)
        : _data(data), _parent(parent) {}
    binary_tree(T&& data, binary_tree<T>* parent = nullptr)
        : _data(std::move(data)), _parent(parent) {}
    const T& data() const 
    {
        return _data;
    }
    const std::unique_ptr<binary_tree>& left() const 
    {
        return _left;
    }
    const std::unique_ptr<binary_tree>& right() const 
    {
        return _right;
    }
    void insert(const T& x) 
    {
        if (x <= _data) 
        {
            if (_left)
                _left->insert(x);
            else
                _left = std::make_unique<binary_tree<T>>(x, this);
        } 
        else 
        {
            if (_right)
                _right->insert(x);
            else
                _right = std::make_unique<binary_tree<T>>(x, this);
        }
    }
    void insert(T&& x) 
    {
        if (x <= _data) 
        {
            if (_left)
                _left->insert(std::move(x));
            else
                _left = std::make_unique<binary_tree<T>>(std::move(x), this);
        } 
        else 
        {
            if (_right)
                _right->insert(std::move(x));
            else
                _right = std::make_unique<binary_tree<T>>(std::move(x), this);
        }
    }
    struct iterator 
    {
        binary_tree<T>* _current = nullptr;
        iterator& operator++() 
        {
            if (!_current)
                return *this;
            if (_current->_right) 
            {
                _current = _current->_right.get();
                while (_current->_left)
                    _current = _current->_left.get();
            } 
            else 
            {
                while (_current->_parent &&
                       _current == _current->_parent->_right.get())
                    _current = _current->_parent;
                _current = _current->_parent;
            }
            return *this;
        }
        iterator operator++(int) 
        {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const iterator& other) const 
        {
            return _current == other._current;
        }
        bool operator!=(const iterator& other) const 
        {
            return !(*this == other);
        }
        const T& operator*() const 
        {
            return _current->_data;
        }
        const T* operator->() const 
        {
            return &_current->_data;
        }
    };
    struct const_iterator 
    {
        const binary_tree<T>* _current = nullptr;
        const_iterator& operator++() 
        {
            if (!_current)
                return *this;
            if (_current->_right) 
            {
                _current = _current->_right.get();
                while (_current->_left)
                    _current = _current->_left.get();
            } 
            else 
            {
                while (_current->_parent &&
                       _current == _current->_parent->_right.get())
                    _current = _current->_parent;
                _current = _current->_parent;
            }
            return *this;
        }
        const_iterator operator++(int) 
        {
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const const_iterator& other) const 
        {
            return _current == other._current;
        }
        bool operator!=(const const_iterator& other) const 
        {
            return !(*this == other);
        }
        const T& operator*() const 
        {
            return _current->_data;
        }

        const T* operator->() const 
        {
            return &_current->_data;
        }
    };
    iterator begin() 
    {
        binary_tree<T>* p = this;
        while (p->_left)
            p = p->_left.get();
        return {p};
    }
    iterator end() 
    {
        return {nullptr};
    }
    const_iterator begin() const 
    {
        const binary_tree<T>* p = this;
        while (p->_left)
            p = p->_left.get();
        return {p};
    }
    const_iterator end() const 
    {
        return {nullptr};
    }
};
}