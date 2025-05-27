#pragma once

namespace dsa::ds {
  template <typename T> class stack {
    private:
      struct node {
          T data;
          node *next;
          node(const T &val) : data(val), next(nullptr) {}
      };
      node *top_;
      size_t size_;

    public:
      stack() : top_(nullptr), size_t(0) {}
      ~stack() {
        while (top_) {
          node *temp = top_;
          top_ = top_->next;
          delete temp;
        }
      }
      void push(const T &val) {
        node *new_node = new node(val);
        new_node->next = top_;
        top_ = new_node;
        size_++;
      }
      void pop() {
        if (top_) {
          node *temp = top_;
          top_ = top_->next;
          delete temp;
          size_--;
        }
      }
      T &top() { return top_->data; }
      bool empty() const { return top_ == nullptr; }
      size_t size() const { return size_; }
  };
} // namespace dsa::ds
