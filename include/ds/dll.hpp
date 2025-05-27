#pragma once

#include <cstddef>
#include <stdexcept>

namespace dsa::ds {
  template <typename T> class dll {
    private:
      struct node {
          T data;
          node *next;
          node *prev;
          node(const T &val) : data(val), next(nullptr), prev(nullptr) {}
      };
      node *head_;
      node *tail_;
      size_t size_;

    public:
      dll() : head_(nullptr), tail_(nullptr), size_(0) {}
      ~dll() {
        while (head_) {
          node *temp = head_;
          head_ = head_->next;
          delete temp;
        }
      }
      void push_back(const T &val) {
        node *new_node = new node(val);
        if (!tail_) {
          head_ = tail_ = new_node;
        } else {
          tail_->next = new_node;
          new_node->prev = tail_;
          tail_ = new_node;
        }
        size_++
      }
      void push_front(const T &val) {
        node *new_node = new node(val);
        if (!head_) {
          head_ = tail_ = new_node;
        } else {
          new_node->next = head_;
          head_->prev = new_node;
          head_ = new_node;
        }
        size_++;
      }
      size_t size() const { return size_; }
  };
} // namespace dsa::ds
