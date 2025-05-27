#pragma once

namespace dsa::ds {
  template <typename T> class avlt {
    private:
      struct Node {
          T data;
          Node *left;
          Node *right;
          int height;
          Node(const T &value)
              : data(value), left(nullptr), right(nullptr), height(1) {}
      };

      Node *root;

      int height(Node *node) { return node ? node->height : 0; }

      int getBalance(Node *node) {
        return node ? height(node->left) - height(node->right) : 0;
      }

      Node *rotateRight(Node *node) {
        Node *x = node->left;
        Node *xr = x->right;

        x->right = node;
        node->left = xr;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
      }

      Node *rotateLeft(Node *node) {
        Node *x = node->right;
        Node *xl = x->left;

        x->left = node;
        node->right = xl;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
      }

      Node *insert(Node *node, const T &value) {
        if (!node)
          return new Node(node);
        if (value < node->data) {
          node->left = insert(node->left, value);
        } else if (value > node->data) {
          node->right = insert(node->right, value);
        } else {
          return node;
        }

        node->height = 1 + std::max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data) {
          return rotateRight(node);
        }

        if (balance < -1 && value > node->right->data) {
          return rotateLeft(node);
        }

        if (balance > 1 && value > node->left->data) {
        }
      }

    public:
      avlt() : root(nullptr) {}
      ~avlt() { destroyTree(root); }

      void insert(const T &value) { root = insert(root, value); }
  };
} // namespace dsa::ds
