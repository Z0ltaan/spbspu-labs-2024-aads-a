#ifndef CONSTITER_HPP
#define CONSTITER_HPP

#include <iterator>
#include "treeNode.hpp"

namespace isaychev
{
  template < class Key, class Value, class Compare >
  class BSTree;

  template < class Key, class Value, class Compare >
  class ConstTreeIter: public std::iterator< std::bidirectional_iterator_tag, Key, Value, Compare >
  {
    using this_t = ConstTreeIter< Key, Value, Compare >;
    using node_t = detail::TreeNode< Key, Value >;

   public:
    ConstTreeIter();

    this_t & operator++();
    this_t operator++(int);
    this_t & operator--();
    this_t operator--(int);

    bool operator==(const this_t & rhs);
    bool operator!=(const this_t & rhs);

    const std::pair< Key, Value > & operator*() const;
    const std::pair< Key, Value > * operator->() const;

   private:
    node_t * current_;
    friend class BSTree< Key, Value, Compare >;

    explicit ConstTreeIter(node_t * node);

    node_t * traverse_left(node_t * node);
    node_t * traverse_right(node_t * node);
    void go_up();
  };

  template < class Key, class Value, class Compare >
  ConstTreeIter< Key, Value, Compare >::ConstTreeIter():
   current_(nullptr)
  {}

  template < class Key, class Value, class Compare >
  ConstTreeIter< Key, Value, Compare >::ConstTreeIter(node_t * node):
   current_(node)
  {}

  template < class Key, class Value, class Compare >
  detail::TreeNode< Key, Value > * ConstTreeIter< Key, Value, Compare >::traverse_left(node_t * root)
  {
    if (root)
    {
      while (root->left)
      {
        root = root->left;
      }
    }
    return root;
  }

  template < class Key, class Value, class Compare >
  void ConstTreeIter< Key, Value, Compare >::go_up()
  {
    current_ = current_->parent;
  }

  template < class Key, class Value, class Compare >
  ConstTreeIter< Key, Value, Compare > & ConstTreeIter< Key, Value, Compare >::operator++()
  {
    if (!current_)
    {
      return *this;
    }
    else if (current_->right)
    {
      current_= traverse_left(current_->right);
    }
    else
    {
      if (current_->parent)
      {
        while (current_->parent && current_ == current_->parent->right)
        {
          go_up();
        }
        go_up();
      }
      else
      {
        current_ = nullptr;
      }
    }
    return *this;
  }

  template < class Key, class Value, class Compare >
  ConstTreeIter< Key, Value, Compare > ConstTreeIter< Key, Value, Compare >::operator++(int)
  {
    auto iter = *this;
    ++(*this);
    return iter;
  }

  template < class Key, class Value, class Compare >
  detail::TreeNode< Key, Value > * ConstTreeIter< Key, Value, Compare >::traverse_right(node_t * root)
  {
    if (!root)
    {
      return root;
    }
    return root->right ? traverse_right(root->right) : root;
  }

  template < class Key, class Value, class Compare >
  ConstTreeIter< Key, Value, Compare > & ConstTreeIter< Key, Value, Compare >::operator--()
  {
    if (!current_)
    {
      return *this;
    }
    else if (current_->left)
    {
      current_= traverse_right(current_->right);
    }
    else
    {
      if (current_->parent)
      {
        while (current_->parent && current_ == current_->parent->left)
        {
          go_up();
        }
        go_up();
      }
      else
      {
        current_ = nullptr;
      }
    }
    return *this;
  }

  template < class Key, class Value, class Compare >
  ConstTreeIter< Key, Value, Compare > ConstTreeIter< Key, Value, Compare >::operator--(int)
  {
    auto iter = *this;
    --(*this);
    return iter;
  }

  template < class Key, class Value, class Compare >
  bool ConstTreeIter< Key, Value, Compare >::operator==(const this_t & rhs)
  {
    return current_ == rhs.current_;
  }

  template < class Key, class Value, class Compare >
  bool ConstTreeIter< Key, Value, Compare >::operator!=(const this_t & rhs)
  {
    return current_ != rhs.current_;
  }

  template < class Key, class Value, class Compare >
  const std::pair< Key, Value > & ConstTreeIter< Key, Value, Compare >::operator*() const
  {
    return current_->data;
  }

  template < class Key, class Value, class Compare >
  const std::pair< Key, Value > * ConstTreeIter< Key, Value, Compare >::operator->() const
  {
    return std::addressof(current_->data);
  }

  template < class Key, class Value, class Compare >
  class TreeIter: public std::iterator< std::bidirectional_iterator_tag, Key, Value, Compare >
  {
    using this_t = TreeIter< Key, Value, Compare >;
    using node_t = detail::TreeNode< Key, Value >;

   public:
    TreeIter();

    this_t & operator++();
    this_t operator++(int);
    this_t & operator--();
    this_t operator--(int);

    bool operator==(const this_t & rhs);
    bool operator!=(const this_t & rhs);

    std::pair< Key, Value > & operator*();
    const std::pair< Key, Value > & operator*() const;
    std::pair< Key, Value > * operator->();
    const std::pair< Key, Value > * operator->() const;

   private:
    node_t * current_;
    friend class BSTree< Key, Value, Compare >;

    explicit TreeIter(node_t * node);

    node_t * traverse_left(node_t * node);
    node_t * traverse_right(node_t * node);
    void go_up();
  };

  template < class Key, class Value, class Compare >
  TreeIter< Key, Value, Compare >::TreeIter():
   current_(nullptr)
  {}

  template < class Key, class Value, class Compare >
  TreeIter< Key, Value, Compare >::TreeIter(node_t * node):
   current_(node)
  {}

  template < class Key, class Value, class Compare >
  detail::TreeNode< Key, Value > * TreeIter< Key, Value, Compare >::traverse_left(node_t * root)
  {
    if (root)
    {
      while (root->left)
      {
        root = root->left;
      }
    }
    return root;
  }

  template < class Key, class Value, class Compare >
  void TreeIter< Key, Value, Compare >::go_up()
  {
    current_ = current_->parent;
  }

  template < class Key, class Value, class Compare >
  TreeIter< Key, Value, Compare > & TreeIter< Key, Value, Compare >::operator++()
  {
    if (!current_)
    {
      return *this;
    }
    else if (current_->right)
    {
      current_= traverse_left(current_->right);
    }
    else
    {
      if (current_->parent)
      {
        while (current_->parent && current_ == current_->parent->right)
        {
          go_up();
        }
        go_up();
      }
      else
      {
        current_ = nullptr;
      }
    }
    return *this;
  }

  template < class Key, class Value, class Compare >
  TreeIter< Key, Value, Compare > TreeIter< Key, Value, Compare >::operator++(int)
  {
    auto iter = *this;
    ++(*this);
    return iter;
  }

  template < class Key, class Value, class Compare >
  detail::TreeNode< Key, Value > * TreeIter< Key, Value, Compare >::traverse_right(node_t * root)
  {
    if (!root)
    {
      return root;
    }
    return root->right ? traverse_right(root->right) : root;
  }

  template < class Key, class Value, class Compare >
  TreeIter< Key, Value, Compare > & TreeIter< Key, Value, Compare >::operator--()
  {
    if (!current_)
    {
      return *this;
    }
    else if (current_->left)
    {
      current_= traverse_right(current_->right);
    }
    else
    {
      if (current_->parent)
      {
        while (current_->parent && current_ == current_->parent->left)
        {
          go_up();
        }
        go_up();
      }
      else
      {
        current_ = nullptr;
      }
    }
    return *this;
  }

  template < class Key, class Value, class Compare >
  TreeIter< Key, Value, Compare > TreeIter< Key, Value, Compare >::operator--(int)
  {
    auto iter = *this;
    --(*this);
    return iter;
  }

  template < class Key, class Value, class Compare >
  bool TreeIter< Key, Value, Compare >::operator==(const this_t & rhs)
  {
    return current_ == rhs.current_;
  }

  template < class Key, class Value, class Compare >
  bool TreeIter< Key, Value, Compare >::operator!=(const this_t & rhs)
  {
    return current_ != rhs.current_;
  }

  template < class Key, class Value, class Compare >
  std::pair< Key, Value > & TreeIter< Key, Value, Compare >::operator*()
  {
    return current_->data;
  }

  template < class Key, class Value, class Compare >
  const std::pair< Key, Value > & TreeIter< Key, Value, Compare >::operator*() const
  {
    return current_->data;
  }

  template < class Key, class Value, class Compare >
  std::pair< Key, Value > * TreeIter< Key, Value, Compare >::operator->()
  {
    return std::addressof(current_->data);
  }

  template < class Key, class Value, class Compare >
  const std::pair< Key, Value > * TreeIter< Key, Value, Compare >::operator->() const
  {
    return std::addressof(current_->data);
  }
}

#endif