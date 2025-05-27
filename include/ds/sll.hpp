#pragma once

#include <cstddef>
#include <stdexcept>
#include <u/swap.hpp>

namespace dsa::ds {
  template <typename T> class sll {
    private:
      struct node {
          T data;
          node *next;
          node(const T &val) : data(val), next(nullptr) {}
      };
      node *head_;
      size_t size_;

    public:
      sll() : head_(nullptr), size_(0) {}
      ~sll() {
        while (head_) {
          node *temp = head_;
          head = head_->next;
          delete temp;
        }
      }
      void push_front(const T &val) {
        node *new_node = new node(val);
        new_node->next = head_;
        head_ = new_node;
        size_++
      }
      void push_back(const T &val) {
        node *new_node = new node(val);
        if (!head_) {
          head_ = new_node;
        } else {
          node *current = head_;
          while (current->next)
            current = current->next;
          current->next = new_node;
        }
        size_++;
      }
      bool empty() const { return head_ == nullptr; }
      size_t size() const { return size_; }
  };
} // namespace dsa::ds
