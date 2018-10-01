#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

using namespace std;
template <typename T>
class Iterator {
private:
  stack<node*> st;
  node* current;
  node* prev;

public:
  Iterator(): current(nullptr), prev(nullptr){}
  Iterator(node* root): current(root), prev(nullptr){
    st.push(current);
    while (current->left) {
      current=current->left;
      st.push(current);
    }
  };

  Iterator<T> operator++(){
    if (!current) throw "end";

    if (!(current->left || current->right) ||
        (current->left && current->right && prev==current->right) ||
        (!current->right && current->left && prev==current->left) ||
        prev==current->right){
      do{
        prev = st.top();
        st.pop();
        if (st.empty()) {
          cout<<"empty";
          current=nullptr;
          return *this;
        }
        current = st.top();
      }
      while (prev==current->right);
      return *this;
    }


    if (current->left && prev!=current->left){
      current = current->left;
      st.push(current);
      return *this;
    }

    
    if (current->right && prev!=current->right){
      current = current->right;
      st.push(current);
      while (current->left) {
        current=current->left;
        st.push(current);
      }
        return *this;
    }
    current=nullptr;
    return *this;
  };

  T operator*(){
    if (!current){
      throw "null";
    }
    return current->data;
  };

};


#endif
