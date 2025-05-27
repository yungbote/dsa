#pragma once

namespace dsa::ds {
  template <typename T> class cbuff {
    private:
      T *buffer;
      size_t capacity_;
      size_t head;
      size_t tail;
      bool full;

    public:
      cbuff(size_t cap) : capacity_(cap), head(0), tail(0), full(false) {
        buffer = new T[capacity_];
      }
      ~cbuff() { delete[] buffer; }
      void push(const T &val) {
        buffer[head] = val;
        if (full)
          tail = (tail + 1) & capacity_;
        head = (head + 1) % capacity_;
        full = head == tail;
      }
      T pop() {
        if (empty())
          throw std::runtime_error("Buffer is empty");
        T val = buffer[tail];
        full = false;
        tail = (tail + 1) % capacity_;
      }
  }
} // namespace dsa::ds
