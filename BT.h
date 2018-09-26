#include <iostream>
#include "node.h"
using namespace std;

struct BT{
  node* root = nullptr;
  node* head = nullptr;

  void constructTree(int data){

    if(!root){
      head=root=GetnewNode(data);
    }

    else if(data < head->data){
      node* current = GetnewNode(data);
      if(!head->left){
        head->left=current;
        head=root;
      }
      else{
        head=head->left;
        constructTree(data);
      }
    }

    else{ //si queremos botar error este else se vuelve else if y else bota throw
      node* current = GetnewNode(data);
      if(!head->right){
        head->right=current;
        head=root;
      }
      else{
        head=head->right;
        constructTree(data);
      }
    }
  }

#define COUNT 10
  void print2DUtil(node *root, int space){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<< "\n";
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data <<endl;

    // Process left child
    print2DUtil(root->left, space);
  }

  // Wrapper over print2DUtil()
  void print2D(node* root)
  {
     // Pass initial space count as 0
     print2DUtil(root, 0);
  }

  void printTree(){
    print2D(root);
  }
};
