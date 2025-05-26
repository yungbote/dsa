#pragma once

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <u/swap.hpp>

namespace dsa::ds {
  template <typename T> class vector {
    private:
      T *data_;
      size_t size_;
      size_t capacity_;

    public:
      vector() : data_(nullptr), size_(0), capacity_(0) {}
      vector(const vector &other)
          : data_(new T[other.capacity_]), size_(other.size_),
            capacity_(other.capacity_) {
        for (size_t i = 0; i < size_; ++i)
          data_[i] = other.data_[i];
      }
      vector(vector &&other) noexcept
          : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
      }
      vector &operator=(const vector &other) {
        if (this != &other) {
          T *new_data = new T[other.capacity_];
          for (size_t i = 0; i < other.size_; ++i)
            new_data[i] = other.data_[i];
          delete[] data_;
          data_ = new_data;
          size_ = other.size_;
          capacity_ = other.capacity_;
        }
        return *this;
      }
      vector &operator=(vector &&other) noexcept {
        if (this != &other) {
          delete[] data_;
          data_ = other.data_;
          size_ = other.size_;
          capacity_ = other.capacity_;
          other.data_ = nullptr;
          other.size_ = 0;
          other.capacity_ = 0;
        }
        return *this;
      }
      vector(std::initializer_list<T> list)
          : data_(new T[list.size()]), size_(list.size()),
            capacity_(list.size()) {
        size_t i = 0;
        for (const T &val : list) {
          data_[i++] = val;
        }
      }
      ~vector() { delete[] data_; }

      void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
          T *new_data = new T[new_capacity];
          for (size_t i = 0; i < size_; ++i)
            new_data[i] = data_[i];
          delete[] data_;
          data_ = new_data;
          capacity_ = new_capacity;
        }
      }

      void resize(size_t new_size) {
        if (new_size < size_) {
          for (size_t i = new_size; i < size_; ++i)
            data_[i].~T();
          size_ = new_size;
        } else if (new_size > size_) {
          reserve(new_size);
          for (size_t i = size_; i < new_size; ++i)
            data_[i] = T();
          size_ = new_size;
        }
      }

      void resize(size_t new_size, const T &value) {
        if (new_size < size_) {
          for (size_t i = new_size; i < size_; ++i)
            data_[i].~T();
          size_ = new_size;
        } else if (new_size > size_) {
          reserve(new_size);
          for (size_t i = size_; i < new_size; ++i)
            data_[i] = value;
          size_ = new_size;
        }
      }

      void push_back(const T &val) {
        if (size_ >= capacity_) {
          size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
          T *new_data = new T[new_capacity];
          for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
          }
          delete[] data_;
          data_ = new_data;
          capacity_ = new_capacity;
        }
        data_[size_++] = val;
      }

      void pop_back() {
        if (size_ > 0) {
          --size_;
          data_[size_].~T();
        }
      }

      void clear() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
      }

      void swap(vector &other) noexcept {
        dsa::u::swap(data_, other.data_);
        dsa::u::swap(size_, other.size_);
        dsa::u::swap(capacity_, other.capacity_);
      }

      T &operator[](size_t index) { return data_[index]; }
      const T &operator[](size_t index) const { return data_[index]; }

      T &front() { return data_[0]; }
      const T &front() const { return data_[0]; }

      T &back() { return data_[size_ - 1]; }
      const T &back() const { return data_[size_ - 1]; }

      T &at(size_t index) {
        if (index >= size_)
          throw std::out_of_range("dsa::ds::vector::at - index out of range");
        return data_[index];
      }
      const T &at(size_t index) const {
        if (index >= size_)
          throw std::out_of_range("dsa::ds::vector::at - index out of range");
        return data_[index];
      }

      size_t size() const { return size_; }
      size_t capacity() const { return capacity_; }
      bool empty() const { return size_ == 0; }

      T *begin() { return data_; }
      const T *begin() const { return data_; }

      T *end() { return data_ + size_; }
      const T *end() const { return data_ + size_; }

      T *data() { return data_; }
      const T *data() const { return data_; }
  };
} // namespace dsa::ds
