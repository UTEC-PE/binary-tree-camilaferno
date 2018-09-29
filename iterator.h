#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>


class Iterator {
    private:
        node* current;

    public:
        Iterator():current(nullptr){};
        Iterator(node* node): current(node){};
        stack<node*> st;

        Iterator operator++(){
          if(it->left){
            current = st.push;
            operator++(it->left);
          }
          current=stack.top;
          stack.pop;
          if(root->right){
            it = stack.push;
            operator++(it->right);
          }

          return current->data;
        };

};

#endif
