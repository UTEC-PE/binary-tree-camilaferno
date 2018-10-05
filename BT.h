#include <iostream>
#include "node.h"
#include"iterator.h"
using namespace std;

//In this code we are are assuming that the tree is not empty when functions are called

struct BT{ // Falta destructor, por qué dejaste todo público?
  node* root = nullptr;
  node* head = nullptr;
  int weight = 0;

//Construction of Tree
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
        weight -=1;
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
        weight-=1;
      }
    }
    weight+=1;
  }

//Prints
  void printInOrder(node* it){

      if(it->left){
        printInOrder(it->left);
      }
      cout << it->data << " ";
      if(it->right){
        printInOrder(it->right);
      }

  }

  void printPreOrder(node* it){

      cout << it->data << " ";
      if(it->left){
        printPreOrder(it->left);
      }
      if(it->right){
        printPreOrder(it->right);
      }

  }

  void printPostOrder(node* it){

      if(it->left){
        printPostOrder(it->left);
      }
      if(it->right){
        printPostOrder(it->right);
      }
      cout << it->data << " ";

  }

  void printTree(){
    cout << "In Order: ";
    printInOrder(root);

    cout << endl;

    cout << "Pre Order: ";
    printPreOrder(root);

    cout << endl;

    cout << "Post Order: ";
    printPostOrder(root);

  }

//Remove credits to https://www.youtube.com/watch?v=GaT8uMDtEZo for the algorithm
  int findSmallestInRight(node* it){
    if(it->left != nullptr){
      return findSmallestInRight(it->left);
    }
    else{
      return it->data;
    }
  }

  void removeNode(int data, node* parent){
    if(root->data==data){
      removeRootNode();
    }
    else{
      if(data < parent->data and parent->left != nullptr){
        parent->left->data == data ?
        removeMatch(parent, parent->left, true):
        removeNode(data, parent->left); //itera hasta que apunte al match
      }
      else if(data > parent->data and parent->right != nullptr){
        parent->right->data == data ?
        removeMatch(parent, parent->right, false):
        removeNode(data, parent->right);
      }
      else{
        cout << "Number " << data << " not found";
      }
    }
  }

  void removeRootNode(){
    node* ripPtr = root;
    int rootReplacement;

    //Case no children
    if(root->left==nullptr and root->right==nullptr){
      root=nullptr;
      delete ripPtr;
      weight-=1;
    }
    //Case 1 children
    else if(root->right && root->left==nullptr){//no hay left pero si right
      root = root->right;
      ripPtr->right=nullptr;
      delete ripPtr;
      weight-=1;
    }
    else if(root->left && root->right==nullptr){//no hay right pero si left
      root = root->left;
      ripPtr->left=nullptr;
      delete ripPtr;
      weight-=1;
    }

    //Case 2 children
    else{
      rootReplacement = findSmallestInRight(root->right);
      removeNode(rootReplacement, root);
      root->data =rootReplacement;
    }

  }

  void removeMatch(node* parent, node* match, bool left){
    node* ripPtr;
    int matchReplacement;

    //Case no children
    if(match->left==nullptr and match->right==nullptr){
      ripPtr = match;
      left == true ?
      parent->left= nullptr:
      parent->right=nullptr;
      delete ripPtr;
      weight-=1;
    }

    //Case 1 children
    else if(match->right && match->left==nullptr){//no hay left pero si right
      left == true ?
      parent->left=match->right:
      parent->right=match->right;
      match->right=nullptr;
      ripPtr=match;
      delete ripPtr;
      weight-=1;
    }
    else if(match->left && match->right==nullptr){//no hay right pero si left
      left == true ?
      parent->left=match->left:
      parent->right=match->left;
      match->left=nullptr;
      ripPtr=match;
      delete ripPtr;
      weight-=1;
    }

    //Case 2 children
    else{
      matchReplacement = findSmallestInRight(match->right);
      removeNode(matchReplacement, match);
      match->data =matchReplacement;
    }
  }

  void remove(int data){
    removeNode(data, root);
  }

//Pretty print code found on the internet
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


  void PrintTreeInternet(){
    print2D(root);
  }

  int Printweight(){
    return weight;
  }

};
