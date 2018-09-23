#include <iostream>
using namespace std;

struct node{
  int data;
  struct node* left;
  struct node* right;
};

node* GetnewNode(int idata){
  node* newNode = new node();
  newNode -> data = idata;
  newNode -> left = nullptr;
  newNode -> right = nullptr;

  return newNode;
}

node* constructTree(node* root, int data){
  if(!root){
    root=GetnewNode(data);
  }
  else if(data<=root->data){
    root->left=constructTree(root->left, data);
  }
  else{ //si queremos botar error este else se vuelve else if y else bota throw
    root->right=constructTree(root->right, data);
  }
  return root;
}

bool Search(node* root, int data){
  if(root == nullptr) return false;
  else if(root->data==data) return true;
  else if(data <= root->data) return Search(root->left,data);
  else return Search(root->right, data);
}

int main(int argc, char const *argv[]) {

  node* root = nullptr;
  root = constructTree(root, 3);
  root = constructTree(root, 2);
  root = constructTree(root, 1);

  if(Search(root, 2)) cout << "found";
  else cout << "Not";

  // int myarray[]={3,2,1};
  // int size = sizeof(myarray)/sizeof(*myarray);
  // constructTree(int myarray,size);

  return 0;
}
