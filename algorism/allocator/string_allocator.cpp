// Copyright (c) 2024 Gapry.
// Licensed under the MIT License.
// See LICENSE file in the project root for full license information.

export module algorism.string_allocator;

import algorism.default_allocator;

namespace algorism {

export template<typename T>
class string_allocator : public default_allocator {
  struct Node {
    T*    data;
    Node* next;

    Node(T* data, Node* next = nullptr)
      : data(data)
      , next(next) {
    }
  };

  Node*                                 head;
  Node*                                 tail;
  typename default_allocator::size_type node_capacity;

public:
  using super = default_allocator;

  string_allocator()
    : head(nullptr)
    , tail(nullptr)
    , node_capacity(32) {
  }

  ~string_allocator() {
    Node* current = head;
    while (current) {
      Node* next = current->next;
      super::deallocate(current->data, node_capacity);
      delete current;
      current = next;
    }
  }

  T* allocate(super::size_type n) {
    if (!head) {
      head = tail = new Node(static_cast<T*>(super::allocate(n * sizeof(T))));
    } else {
      Node* new_node = new Node(static_cast<T*>(super::allocate(n * sizeof(T))));
      tail->next     = new_node;
      tail           = new_node;
    }
    return tail->data;
  }

  void deallocate(T* p, super::size_type n) {
  }

  void construct(T* p, const T& value) {
    new (p) T(value);
  }

  void destroy(T* p) {
    p->~T();
  }
};

} // namespace algorism
