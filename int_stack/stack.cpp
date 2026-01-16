#include "stack.hpp"

namespace ds {

    void Stack::resize(size_t new_capacity) {
    // int64_t* new_elements = new int64_t[(new_capacity >= capacity_) ?
    // capacity_ * 2 : capacity_ / 2];
    if(new_capacity <= 10) {new_capacity = 10;}
    int64_t* new_elements = new int64_t[new_capacity];
    for(size_t i(0); i < size_; i++) {
      new_elements[i] = element_[i];
    }

    delete[] element_;
    element_ = new_elements;
    capacity_ = new_capacity;

}

 void Stack::push(int64_t d) {
  if(size_ == capacity_) {
    resize(capacity_ * 2);
  }

  element_[size_] = d;

  ++size_;
}

   int64_t Stack::pop() {

    --size_;
    int64_t result = element_[size_];
    if (size_ <= capacity_ / 4 && capacity_ > 10) {
        resize(capacity_ / 2);
    }

    return result;
}

 size_t Stack::size() const {
   return size_;
}

size_t Stack::capacity() const {
  return capacity_;
}


} //end namespace ds
