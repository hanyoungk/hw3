#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private:
    std::vector<T> vec;
};


#endif

//implementations
template <typename T>
Stack<T>::Stack() : std::vector<T>() //inherits from vector
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
bool Stack<T>::empty() const
{
    // if(vec.empty()) {
    //     return 
    // }
    return vec.empty();

}

template <typename T>
size_t Stack<T>::size() const
{
    return vec.size();
}

template <typename T>
void Stack<T>::push(const T& item)
{
    vec.push_back(item);
}

template <typename T>
void Stack<T>::pop()  // throws std::underflow_error if empty
{
    if(vec.empty()) {
        throw std::underflow_error("underflow error at pop()");
    }
    else {
        vec.pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const // throws std::underflow_error if empty
{
    if(vec.empty()) {
        throw std::underflow_error("underflow error at top()");
    }
    else {
        return vec.back();
    }

}
