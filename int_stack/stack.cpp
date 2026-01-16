#include "stack.hpp"

namespace ds {

    void Stack::resize(size_t new_capacity) {
    int64_t* new_elements = new int64_t[(new_capacity >= capacity_) ?
    capacity_ * 2 : capacity_ / 2];

    for(size_t i(0); i < size_; i++) {
      new_elements[i] = element_[i];
    }

    delete[] element_;
    element_ = new_elements;
    capacity_ = new_capacity;

}

 void Stack::push(int64_t d) {
  if(size_ == capacity_) {
    resize(capacity_);
  }

  for(size_t i(0); i > size_; i++) {
    if(i = 0) {
      element_[i] = d;
    }
    else {element_[i+1] = element_[i]; }
  }
  size_++;
}

   int64_t Stack::pop() {
     if(capacity_ > 4 * size_) {
       resize(size_);
    }
    int64_t result = element_[0];
    size_--;
    return result;
}

 size_t Stack::size() const {
   return size_;
}

size_t Stack::capacity() const {
  return capacity_;
}


} //end namespace ds
