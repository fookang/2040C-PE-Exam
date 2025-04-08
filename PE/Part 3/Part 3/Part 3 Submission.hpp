#pragma once
#ifndef TREE_H
#define TREE_H

#include <string>

using std::string;

template <typename T>
std::string my_to_string(const T& t) {
  return std::to_string(t);
}

template <>
std::string my_to_string(const std::string& t) {
  return "\"" + t + "\"";
}

template <typename T> struct Node {
  T element;
  int height;
  Node<T> *left;
  Node<T> *right;



  Node(T element)
      : element{element}, height{0}, left{nullptr}, right{nullptr} {}
  Node(T element, int height)
      : element{element}, height{height}, left{nullptr}, right{nullptr} {}

  // feel free to add attributes
};

template <typename T> class Tree {
private:
  size_t m_size;
  Node<T> *m_root;


public:
  // Constructor
  Tree();

  // Rule of three:
  // If a class requires a user-defined destructor, a user-defined copy
  // constructor, or a user-defined copy assignment operator, it almost
  // certainly requires all three.

  // Destructor
  ~Tree();

  // Returns a pointer to the root
  Node<T> *root();

  // Checks whether the tree is empty
  bool empty() const;

  // Returns the number of elements
  size_t size() const;

  // Returns the height of the tree
  int height() const;

  // Inserts the specified element
  void insert(T element);
  void remove(T element);

  // Checks whether the container contains the specified element
  bool contains(T element) const;

  // Returns the maximum element
  T max() const;

  // Returns the minimum element
  T min() const;

  // Returns the successor of the specified element
  T successor(T element);

  // Convert each element in the tree to string in pre-order.
  string pre_order();

  // Convert each element in the tree to string in order.
  string in_order();

  // Convert each element in the tree to string in post-order.
  string post_order();

  // Returns a string equivalent of the tree
  string to_string(bool with_height = true) const {
    return m_to_string(with_height, m_root, 0);
  }

  // Returns the parent of the element, you can assume that the element is not the root
  T parent(T element);

private:

  string m_to_string(bool with_height, Node<T> *node, int ident) const {
    string res;
    if (node == nullptr) {
      return res;
    }
    if (node->right != nullptr) {
      res += m_to_string(with_height, node->right, ident + 2);
    }
    for (int i = 0; i < ident; i++) {
      res += " ";
    }
    res += my_to_string(node->element);
    if (with_height) {
      res += "(h=" + my_to_string(node->height) + ")";
    }
    res += "\n";
    if (node->left != nullptr) {
      res += m_to_string(with_height, node->left, ident + 2);
    }
    return res;
  }
    int m_height(Node<T>* node) const;
    void m_update_height(Node<T>* node);
    Node<T>* m_insert(Node<T>* node, T element);
    T m_successor(Node<T>* curr, Node<T>* succ, T element) const;


    
    // Feel free to declare helper functions here, if necessary
    
    // Helper for parents function
    T _parent(T element, T parent, Node<T>* node);

    Node<T>* _remove(T element, Node<T>* node);
  };

// Constructor
template <typename T> Tree<T>::Tree() {
    m_root = nullptr;
    m_size = 0;
  // TODO: Implement this method
}

// Destructor
template <typename T> Tree<T>::~Tree() {
  // TODO: Implement this method
}

// Returns a pointer to the root
template <typename T> Node<T> *Tree<T>::root() {
  // TODO: Implement this method
  return m_root;
}

// Checks whether the tree is empty
template <typename T> bool Tree<T>::empty() const {
  // TODO: Implement this method
    return (m_size == 0);
}

// Returns the number of elements
template <typename T> size_t Tree<T>::size() const {
  // TODO: Implement this method
  return m_size;
}

// Returns the height of the tree
template <typename T> int Tree<T>::height() const {
  // TODO: Implement this method
  return m_root->height;
}

// Inserts an element
template <typename T> void Tree<T>::insert(T element) {
    m_root = m_insert(m_root, element);
}



// Checks whether the container contains the specified element
template <typename T> bool Tree<T>::contains(T element) const {
  // TODO: Implement this method
  return false;
}

// Returns the maximum element
template <typename T> T Tree<T>::max() const {
  // TODO: Implement this method
  throw std::runtime_error("not implemented");
}

// Returns the minimum element
template <typename T> T Tree<T>::min() const {
  // TODO: Implement this method
  throw std::runtime_error("not implemented");
}

// Returns the successor of the specified element
template <typename T> T Tree<T>::successor(T element) {
    return m_successor(m_root, nullptr, element);
}

template <typename T>
string _pre_order(Node<T> *node) {
  return my_to_string(node->element)
    + (node->left == nullptr ? "" : " " + _pre_order(node->left))
    + (node->right == nullptr ? "" : " " + _pre_order(node->right));
}

template <typename T>
string Tree<T>::pre_order() {
  if (m_root == nullptr) {
    return "";
  }
  return _pre_order(m_root);
}

template <typename T>
string Tree<T>::in_order() {
  // TODO: Implement this method
  return "";
}

template <typename T>
string Tree<T>::post_order() {
  // TODO: Implement this method
  return "";
}

template <typename T> void Tree<T>::m_update_height(Node<T>* node) {
    if (!node) return;
    node->height = std::max(m_height(node->left), m_height(node->right)) + 1;
}

template <typename T>
T Tree<T>::m_successor(Node<T>* curr, Node<T>* succ, T element) const {
    // Base case
    if (curr == nullptr) {
        if (succ == nullptr) {
             throw std::out_of_range("element greater than max in tree");
        }
        return succ->element;
    }

    // Inductive case
    if (element < curr->element) {
        return m_successor(curr->left, curr, element);
    }
    return m_successor(curr->right, succ, element);
}

template <typename T> Node<T>* Tree<T>::m_insert(Node<T>* node, T element) {
    // Base case
    if (node == nullptr) {
        node = new Node<T>{ element };
        m_update_height(node);
        m_size++;
        return node;
    }

    // Ignore duplicates
    if (element == node->element) {
        return node;
    }

    // Inductive case
    if (element < node->element) {
        node->left = m_insert(node->left, element);
    }
    else if (element > node->element) {
        node->right = m_insert(node->right, element);
    }

    m_update_height(node);
    return node;
}


template <typename T> int Tree<T>::m_height(Node<T>* node) const {
    return node == nullptr ? -1 : node->height;
}

template <typename T> T Tree<T>::_parent(T element, T parent, Node<T>* node) {
    if (!node) throw std::runtime_error("element not found");
    if (node->element == element) {
        return parent;
    }
    if (element < node->element) {
        return _parent(element, node->element, node->left);
    }
    return _parent(element, node->element, node->right);
}


template <typename T> T Tree<T>::parent(T element) {
    if (!m_root) throw std::runtime_error("element not found");
    if (m_root->element == element) {
        return -1;
    }
    if (element < m_root->element) {
        return _parent(element, m_root->element, m_root->left);
    }
    return _parent(element, m_root->element, m_root->right);
}

template <typename T> Node<T>* Tree<T>::_remove(T element, Node<T>* node) {
    if (!node) return nullptr;

    if (element == node->element) {
        int children = 0;
        if (node->left) children++;
        if (node->right) children++;

        // no children
        if (children == 0) {
            delete node;
            m_size--;
            return nullptr;
        }
        // 1 children
        if (children == 1) {
            if (node->left) {
                Node<T>* temp = node->left;
                delete node;
                m_size--;
                m_update_height(temp);
                return temp;
            }
            // If right children present only
            if (node->right) {
                Node<T>* temp = node->right;
                delete node;
                m_size--;
                m_update_height(temp);
                return temp;
            }
        }
        //2 children
        else {
            T succ = successor(node->element);
            remove(succ);
            Node<T>* newNode = new Node<T>(succ);
            newNode->left = node->left;
            newNode->right = node->right;
            delete node;
            m_size--;
            m_update_height(newNode);
            return newNode;

        }
    }

    // element is not node
    if (element > node->element) {
        node->right = _remove(element, node->right);
        m_update_height(node);
        return node;
    }

    node->left = _remove(element, node->left);
    m_update_height(node);
    return node;
}

template <typename T> void Tree<T>::remove(T element) {
    if (!m_root) return;

    // element is not m_root
    if (element > m_root->element) {
        m_root->right = _remove(element, m_root->right);
        m_update_height(m_root);
        return;
    }    
    if (element < m_root->element) {
        m_root->left = _remove(element, m_root->left);
        m_update_height(m_root);
        return;
    }

    int children = 0;
    if (m_root->left) children++;
    if (m_root->right) children++;

    if (m_root->element == element && children == 0) {
        delete m_root;
        m_root = nullptr;
        m_size = 0;
        return;
    }
    
    if (m_root->element == element && children == 1) {
        // If left children present only
        if (m_root->left) {
            Node<T>* temp = m_root;
            m_root = m_root->left;
            delete temp;
            m_size--;
            m_update_height(m_root);
            return;
        }
        // If right children present only
        if (m_root->right) {
            Node<T>* temp = m_root;
            m_root = m_root->right;
            delete temp;
            m_size--;
            m_update_height(m_root);
            return;
        }
    }
        
    if (m_root->element == element && children == 2) {
        T succ = successor(m_root->element);
        remove(succ);
        Node<T>* newhead = new Node<T>(succ);
        newhead->left = m_root->left;
        newhead->right = m_root->right;
        delete m_root;
        m_root = newhead;
        m_size--;
        m_update_height(m_root);
        return;
    }
    return;
}

#endif
