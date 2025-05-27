#pragma once

namespace dsa::ds {
  template <typename T> class deque {
    private:
      struct node {
          T data;
          node *next;
          node *prev;
          node(const T &val) : data(val), next(nullptr), prev(nullptr) {}
      };
      node *front_;
      node *back_;
      size_t size_;

    public:
      deque() : front_(nullptr), back_(nullptr), size_(0) {}
      ~deque() {
        while (front_) {
          node *temp = front_;
          front_ = front_->next;
          delete temp;
        }
      }
      void push_front(const T &val) {
        node *new_node = new node(val);
        if (!front_) {
          front_ = back_ = new_node;
        } else {
          new_node->next = front_;
          front_->prev = new_node;
          front_ = new_node;
        }
        size_++;
      }
      void push_back(const T &val) {
        node *new_node = new node(val);
        if (!back_) {
          front_ = rear_ = new_node;
        } else {
          new_node->prev = back_;
          back_->next = new_node;
          back_ = new_node;
        }
        size_++;
      }
      void pop_front() {
        if (!front_)
          return;
        node *temp = front_;
        front_ = front_->next;
        if (front_) {
          front_->prev = nullptr;
        } else {
          back_ = nullptr;
        }
        delete temp;
        size_--;
      }
      void pop_back() {
        if (!back_)
          return;
        node *temp = back_;
        back_ = back_->prev;
        if (back_) {
          back_->next = nullptr;
        } else {
          front_ = nullptr;
        }
        size_--;
      }
      T &front() { return front_->data; }
      T &back() { return back_->data; }
      bool empty() const { return front_ == nullptr; }
      size_t size() const { return size_; }
  };
} // namespace dsa::ds
