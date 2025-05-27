#pragma once

namespace dsa::ds {
  template <typename T> class bst {
    private:
      struct Node {
          T data;
          Node *left;
          Node *right;
          Node(const T &value) : data(value), left(nullptr), right(nullptr) {}
      };

      Node *root;

      void destroyTree(Node *node) {
        if (node) {
          destroyTree(node->left);
          destroyTree(node->right);
          delete node;
        }
      }

      Node *findMin(Node *node) {
        while (node->left)
          node = node->left;
        return node;
      }

      Node *insert(Node *node, const T &value) {
        if (!node)
          return new Node(value);
        if (value < node->data) {
          node->left = insert(node->left, value);
        } else {
          node->right = insert(node->right, value);
        }
        return node;
      }

      bool search(Node *node, const T &value) {
        if (!node)
          return false;
        if (node->data == value)
          return true;
        if (value < node->data)
          return search(node->left, value);
        return search(node->right, value);
      }

      Node *remove(Node *node, const T &value) {
        if (!node)
          return nullptr;
        if (value < node->data) {
          node->left = remove(node->left, value);
        } else if (value > node->data) {
          node->right = remove(node->right, value);
        } else {
          if (!node->left) {
            Node *temp = node->right;
            delete node;
            return temp;
          } else if (!node->right) {
            Node *temp = node->left;
            delete node;
            return temp;
          }
          Node *temp = findMin(node->right);
          node->data = temp->data;
          node->right = remove(node->right, temp->data);
        }
        return node;
      }

    public:
      bst() : root(nullptr) {}
      ~bst() { destroyTree(root); }

      void insert(const T &value) { root = insert(root, value); }
      bool search(const T &value) { return search(root, value); }
      void remove(const T &value) { root = remove(root, value); }
  };
} // namespace dsa::ds
