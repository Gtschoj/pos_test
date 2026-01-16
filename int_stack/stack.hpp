#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <algorithm>

namespace ds {

  class Stack {
  public:
    Stack() = default;
    ~Stack(){delete[] element_;};
    Stack(size_t size, size_t capacity, int64_t* element) :
      size_(size), capacity_(capacity = 10), element_(element) {};

    void push(int64_t d);
    int64_t pop();
    size_t size() const;
    size_t capacity() const;

  private:
    size_t size_ = 0;
    size_t capacity_ = 10;
    int64_t* element_ = nullptr;
    void resize(size_t new_capcity);
  };
} //end namespace ds

#endif
