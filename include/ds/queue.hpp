#pragma once

namespace dsa::ds {
  template <typename T> class queue {
    private:
      struct node {
          T data;
          node *next;
          node(const T &val) : data(val), next(nullptr) {}
      };
      node *front_;
      node *back_;
      size_t size_;

    public:
      queue() : front_(nullptr), back_(nullptr), size_(0) {}
      ~queue() {
        while (front_) {
          node *temp = front_;
          front_ = front_->next;
          delete temp;
        }
      }
      void enqueue(const T &val) {
        node *new_node = new node(val);
        if (!back_) {
          front_ = back_ = new_node;
        } else {
          back_->next = new_node;
          back_ = new_node;
        }
        size_++;
      }
      void dequeue(const T &val) {
        if (front_) {
          node *temp = front_;
          front_ = front_->next;
          if (!front_)
            back_ = nullptr;
          delete temp;
          size_--;
        }
      }
      T &front() { return front_->data; }
      bool empty() const { return front_ == nullptr; }
      size_t size() const { return size_; }
  };
} // namespace dsa::ds
